#include "ros/ros.h"
#include "math.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/Bool.h"
#include <exo_control/exo_pos_control.h>
#include "tum_ics_skin_msgs/SkinCellDataArray.h"
#include <Eigen/Dense>
#include <exo_control/exo_force_control.h>

//Elbow
#define MAX_ANGLE_EL 1.745329252
#define MIN_ANGLE_EL 0.174532925

Eigen::Vector3d cb_gvec;

double mean_force_cell4 = 0.0;
double mean_force_cell14 = 0.0;
double mean_force_cell15 = 0.0;

double mean_force_cell5 = 0.0;
double mean_force_cell9 = 0.0;
double mean_force_cell10 = 0.0;

double initialForceCell4 = 0.0;
double initialForceCell5 = 0.0;
double initialForceCell9 = 0.0;
double initialForceCell10 = 0.0;
double initialForceCell14 = 0.0;
double initialForceCell15 = 0.0;

bool init_forces = false;

double deg2rad(double degree){
    return (degree * 3.14159265359/180);
}

double rad2deg(double radian){
    return (radian * 180 / 3.14159265359);
}

void setInitialForces_cb(const std_msgs::Bool msg){
    initialForceCell4 = mean_force_cell4;
    initialForceCell5 = mean_force_cell5;
    initialForceCell9 = mean_force_cell9;
    initialForceCell10 = mean_force_cell10;
    initialForceCell14 = mean_force_cell14;
    initialForceCell15 = mean_force_cell15;

    ROS_WARN_STREAM("Cell4 " << initialForceCell4);
    ROS_WARN_STREAM("Cell5: " << initialForceCell5);
    ROS_WARN_STREAM("Cell9: " << initialForceCell9);
    ROS_WARN_STREAM("Cell10: " << initialForceCell10);
    ROS_WARN_STREAM("Cell14: " << initialForceCell14);
    ROS_WARN_STREAM("Cell15: " << initialForceCell15);

    init_forces = msg.data;
}

void getGVector_cb(const std_msgs::Float64MultiArray msg){
    
    cb_gvec[0] = msg.data[0];
    cb_gvec[1] = msg.data[1];
    cb_gvec[2] = msg.data[2];
}

void getForceVector_cb(const std_msgs::Float64MultiArray msg){
    
    //Assign data to specific cells of patch 1 and avarage over the force values
    mean_force_cell4 = (msg.data[0] + msg.data[1] + msg.data[2])/3;
    mean_force_cell14 = (msg.data[3] + msg.data[4] + msg.data[5])/3;
    mean_force_cell15 = (msg.data[6] + msg.data[7] + msg.data[8])/3;

    //Assign data to specific cells of patch 3 and avarage over the force values
    mean_force_cell5 = (msg.data[9] + msg.data[10] + msg.data[11])/3;
    mean_force_cell9 = (msg.data[12] + msg.data[13] + msg.data[14])/3;
    mean_force_cell10 = (msg.data[15] + msg.data[16] + msg.data[17])/3;
}

int main( int argc, char** argv )
{
    ros::init(argc, argv, "exo_control",
            ros::init_options::AnonymousName);
    ros::NodeHandle n;
    ros::Rate r(200);

    ros::Publisher floater_pub = n.advertise<std_msgs::Float64>("q_control_publisher", 100);
    ros::Publisher state_pub = n.advertise<std_msgs::Float64MultiArray>("q_state", 100);
    ros::Publisher desired_pub = n.advertise<std_msgs::Float64MultiArray>("q_des", 100);
    
    // Subscribers for the published values from skin patches
    ros::Subscriber gVec_sub = n.subscribe<std_msgs::Float64MultiArray>("gravitational_vector", 100,  getGVector_cb);
    ros::Subscriber force_sub = n.subscribe<std_msgs::Float64MultiArray>("force_readings", 100,  getForceVector_cb);
    ros::Subscriber initializer_sub = n.subscribe<std_msgs::Bool>("init_forces", 100, setInitialForces_cb);
    
    double delta_t = 1/(double)200; 

    double L1;
    std::string ns="~L1";
    std::stringstream s;
    s.str("");
    s<<ns;
    ros::param::get(s.str(),L1);
    double L2;
    ns="~L2";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),L2);
    double L3;
    ns="~L3";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),L3);
    double m2;
    ns="~m2";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),m2);
    double m3;
    ns="~m3";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),m3);
    double b1;
    ns="~b1";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),b1);
    double b2;
    ns="~b2";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),b2);
    double k1;
    ns="~k1";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),k1);
    double k2;
    ns="~k2";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),k2);
    double theta1;
    ns="~theta1";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),theta1);
    double theta2;
    ns="~theta2";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),theta2);
    double I233;
    ns="~I233";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),I233);
    double I222;
    ns="~I222";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),I222);
    double I311;
    ns="~I311";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),I311);
    double I322;
    ns="~I322";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),I322);
    double I333;
    ns="~I333";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),I333);
    double g;
    ns="~g";
    s.str("");
    s<<ns;
    ros::param::get(s.str(),g);
    
    //init params 
    double q1 = deg2rad(0); 
    double qd1 = 0;
    double qdd1 = 0;

    //init params
    double q2 = deg2rad(37.5);
    double qd2 = 0;
    double qdd2 = 0;

    //init q vectors
    Eigen::Vector2d q = {q1, q2};
    Eigen::Vector2d qd = {qd1, qd2};
    Eigen::Vector2d qdd = {qdd1, qdd2};

    // static g 
    double gx = cb_gvec[0];
    double gy = cb_gvec[1];
    double gz = 0;

    //Tao Init
    Eigen::Vector2d tao = {0,0};

    //Dynamic Model Matrices
    Eigen::MatrixXd m_matrix(2,2);
    Eigen::MatrixXd c_matrix(2,2);
    Eigen::MatrixXd g_matrix(2,1);
    Eigen::MatrixXd b_matrix(2,2);

    ExoControllers::PosControl posControl(L1, L2, m2, b1, k1, theta1, gx, gy);
    Vector3d qEnd;
    qEnd << deg2rad(45), 0.0, 0.0;
    double timeEnd = 5;
    posControl.init(qEnd, timeEnd);
    
    ExoControllers::ForceControl forceControl(L3);
    Eigen::Vector2d W_des = {0,0};
    Eigen::Vector2d Ws = {0,0};
    forceControl.init(W_des);

    std_msgs::Float64 floater; 
    std_msgs::Float64MultiArray q_state;
    std_msgs::Float64MultiArray q_desire;

    //Threshold for activation of controler
    double base_val_top = 0.07;
    double base_val_bottom = 0.136;

    //Bottom
    double threshold_Cell4 = initialForceCell4 + base_val_bottom;
    double threshold_Cell14 = initialForceCell14 + base_val_bottom;
    double threshold_Cell15 = initialForceCell15 + base_val_bottom;

    //Top
    double threshold_Cell5 = initialForceCell5 + base_val_top;
    double threshold_Cell9 = initialForceCell9 + base_val_top;
    double threshold_Cell10 = initialForceCell10 + base_val_top;   


    while(ros::ok())
    {   
        gx = cb_gvec[0];
        gy = cb_gvec[1];
        //tao = posControl.update(delta_t, q1, qd1, qdd1);

        //Dynamic Equations
        m_matrix << I222 + I322 + (I311 - I322 - pow(L3,2)*m3)*pow(sin(q[1]),2) + pow(L2,2)*m2/4 + pow(L2,2)*m3 + 2*L2*L3*m3*cos(q[1]) + pow(L3,2)*m3, 0,
                    0, I333 + pow(L3,2)*m3;

        double part_term = ((I311-I322-pow(L3,2))*cos(q[1]) - L2*L3*m3);
        c_matrix << sin(q[1])*qd[1]*part_term, sin(q[1])*qd[1]*part_term,
                    sin(q[1])*qd[1]*(-1)*part_term, 0;

        g_matrix << (m2/2)*(-L2*gx*sin(q[0]) + L2*gy*cos(q[0])) + m3*(L2*(-gx*sin(q[0]) + gy*cos(q[0])*cos(q[1])) + L3*(-gx*sin(q[0])*cos(q[1]) + gy*cos(q[0])*cos(q[1]))) + k1*(-theta1+ q[0]),
                    L3*m3*(-gz*cos(q[1]) - sin(q[1])*(gx*cos(q[0]) + gy*sin(q[0]))) + k2*(-theta2 + q[1]);

        b_matrix << b1, 0,
                    0, b2;

        //Activation of the Wrench
        if(((init_forces) && (mean_force_cell10 > threshold_Cell10))) //mean_force_cell5 > threshold_Cell5 ) || (mean_force_cell9 > threshold_Cell9) || 
        {
            double mean_force_patch3 = (mean_force_cell5 + mean_force_cell9 + mean_force_cell10)/3;
            Ws << mean_force_patch3*6, 0;
            ROS_WARN_STREAM("Upper movement");
        }
        else if(((init_forces) && (mean_force_cell4 > threshold_Cell4 ))) //|| (mean_force_cell14 > threshold_Cell14) || (mean_force_cell15 > threshold_Cell15))
        {
            double mean_force_patch1 = (mean_force_cell4 + mean_force_cell14 + mean_force_cell15)/3;
            Ws << - mean_force_patch1*4, 0;

            ROS_WARN_STREAM("Lower movement");
        }
        else
        {
            Ws << 0,0;
            ROS_WARN_STREAM("Ws = 0");
        }

        // Force controller:
        tao = forceControl.update(Ws) + g_matrix;
        qdd = m_matrix.inverse()*(tao -  g_matrix - c_matrix*q -b_matrix*qd);
        qd = delta_t*qdd + qd;

        // Stop the servo from going above 75 and below 0 degrees; +/- 0.0001 is because the servo
        // stops moving if we only set the derivatives to 0.
        //Elbow safty function
        if (q[0] > MAX_ANGLE_EL){ // The servo motor should not go above 100°

            qdd[0] = 0;
            qd[0] = 0;
            q[0] = MAX_ANGLE_EL - 0.0001;
        
        }
        else if(q[0] < MIN_ANGLE_EL){ // The servo motor should not go below 10°
        
            qdd[0] = 0;
            qd[0] = 0;
            q[0] = MIN_ANGLE_EL + 0.001;
        }
        
        
        //Update q value
        q = delta_t*qd + q;

        q_state.data.clear();
        q_state.data.push_back(q[0]);
        q_state.data.push_back(qd[0]);
        q_state.data.push_back(qdd[0]);
        q_state.data.push_back(q[1]);
        q_state.data.push_back(qd[1]);
        q_state.data.push_back(qdd[1]);

        q_desire.data.clear();
        q_desire.data.push_back(posControl.getter()[0]);
        q_desire.data.push_back(posControl.getter()[1]);
        q_desire.data.push_back(posControl.getter()[2]);

        state_pub.publish(q_state);
        desired_pub.publish(q_desire);

        floater.data = q[0];
        floater_pub.publish(floater);

        // See the output angle
        //ROS_WARN_STREAM("loop");
        // ROS_WARN_STREAM("qd1: " << qd[1]);
        // ROS_WARN_STREAM("qdd1: " << qdd[1]);
        // ROS_WARN_STREAM("q0: " << q[0]);
        // ROS_WARN_STREAM("qd0: " << qd[0]);
        // ROS_WARN_STREAM("qdd0: " << qdd[0]);
        
        
        ros::spinOnce();
        r.sleep();
    }
    
    return 0; 

}
