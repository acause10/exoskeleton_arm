#include "ros/ros.h"
#include <Eigen/Dense>
#include "tum_ics_skin_msgs/SkinCellDataArray.h"
#include <Eigen/Geometry>
#include "std_msgs/Float64MultiArray.h"
#include <string>
#include <sstream>
#include <tum_ics_skin_descr/Patch/TfMarkerDataPatches.h>
#include <QApplication>
#include <QFileInfo>


using namespace tum_ics_skin_descr;
using namespace Eigen;

int main( int argc, char** argv )
{
    ros::init(argc, argv, "skin_control",
              ros::init_options::AnonymousName);
    ros::NodeHandle n;
    ros::Rate r(100);
    
    // Publishers
    ros::Publisher grav_pub = n.advertise<std_msgs::Float64MultiArray>("gravitational_vector", 100);
    ros::Publisher force_pub = n.advertise<std_msgs::Float64MultiArray>("force_readings", 100);


    QApplication a(argc, argv);
    QString configFilePath = QString(argv[1]);
    QFileInfo fi(configFilePath);
    
    if(!fi.absoluteDir().exists())
    {
        qCritical("Invalid path '%s'",configFilePath.toLatin1().data());
        return -1;
    }

    Patch::TfMarkerDataPatches tfPatches;

    if(!tfPatches.loadFromParam(configFilePath,"~patch_list"))
    {
        return -1;
    }

    tfPatches.createDataConnections();
    tfPatches.enableDataConnctions();

    // Publishers:
    std_msgs::Float64MultiArray grav_publisher;
    std_msgs::Float64MultiArray force_publisher;
    
    while(ros::ok())
    {
        Vector3d acc;
        acc << tfPatches.patch(0)->dataFromId(1).acc.at(0),
               tfPatches.patch(0)->dataFromId(1).acc.at(1),
               tfPatches.patch(0)->dataFromId(1).acc.at(2); // get grav vals


        // Force readings from all force sensors in skin cell (id 4) of the 
        // second skin patch
        Vector3d bottom_force_1;          
        bottom_force_1 << tfPatches.patch(1)->dataFromId(4).force.at(0),
                       tfPatches.patch(1)->dataFromId(4).force.at(1),
                       tfPatches.patch(1)->dataFromId(4).force.at(2); 
        
        // Force readings from all force sensors in skin cell (id 14) of the 
        // second skin patch
        Vector3d bottom_force_2;          
        bottom_force_2 << tfPatches.patch(1)->dataFromId(14).force.at(0),
                       tfPatches.patch(1)->dataFromId(14).force.at(1),
                       tfPatches.patch(1)->dataFromId(14).force.at(2); 
                
        // Force readings from all force sensors in skin cell (id 15) of the 
        // second skin patch
        Vector3d bottom_force_3;          
        bottom_force_3 << tfPatches.patch(1)->dataFromId(15).force.at(0),
                       tfPatches.patch(1)->dataFromId(15).force.at(1),
                       tfPatches.patch(1)->dataFromId(15).force.at(2); 
        
        force_publisher.data.clear();
        for (int i = 0; i <= 2; i++)
        {
            force_publisher.data.push_back(bottom_force_1[i]);
        }

        for (int i = 0; i <= 2; i++)
        {
            force_publisher.data.push_back(bottom_force_2[i]);
        }

        for (int i = 0; i <= 2; i++)
        {
            force_publisher.data.push_back(bottom_force_3[i]);
        }

        // Force readings from all force sensors in skin cell (id 5) of the 
        // second skin patch
        Vector3d top_force_1;          
        top_force_1 << tfPatches.patch(3)->dataFromId(5).force.at(0),
                       tfPatches.patch(3)->dataFromId(5).force.at(1),
                       tfPatches.patch(3)->dataFromId(5).force.at(2); 
        
        // Force readings from all force sensors in skin cell (id 9) of the 
        // second skin patch
        Vector3d top_force_2;          
        top_force_2 << tfPatches.patch(3)->dataFromId(9).force.at(0),
                       tfPatches.patch(3)->dataFromId(9).force.at(1),
                       tfPatches.patch(3)->dataFromId(9).force.at(2); 
                
        // Force readings from all force sensors in skin cell (id 10) of the 
        // second skin patch
        Vector3d top_force_3;          
        top_force_3 << tfPatches.patch(3)->dataFromId(10).force.at(0),
                       tfPatches.patch(3)->dataFromId(10).force.at(1),
                       tfPatches.patch(3)->dataFromId(10).force.at(2); 
        
        for (int i = 0; i <= 2; i++)
        {
            force_publisher.data.push_back(top_force_1[i]);
        }

        for (int i = 0; i <= 2; i++)
        {
            force_publisher.data.push_back(top_force_2[i]);
        }

        for (int i = 0; i <= 2; i++)
        {
            force_publisher.data.push_back(top_force_3[i]);
        }

        // Pushing gravity values
        grav_publisher.data.clear();
        for (int i = 0; i <= 2; i++)
        {
            grav_publisher.data.push_back(acc[i]);
        }

        ROS_WARN_STREAM("Mean force from cell 4: " << (bottom_force_1[0]+bottom_force_1[1]+bottom_force_1[2])/3);
        //ROS_WARN_STREAM("Mean force from cell 14: " << (bottom_force_2[0]+bottom_force_2[1]+bottom_force_2[2])/3);
        //ROS_WARN_STREAM("Mean force from cell 15: " << (bottom_force_3[0]+bottom_force_3[1]+bottom_force_3[2])/3);

        //ROS_WARN_STREAM("Mean force from cell 5: " << (top_force_1[0]+top_force_1[1]+top_force_1[2])/3);
        //ROS_WARN_STREAM("Mean force from cell 9: " << (top_force_2[0]+top_force_2[1]+top_force_2[2])/3);
        ROS_WARN_STREAM("Mean force from cell 10: " << (top_force_3[0]+top_force_3[1]+top_force_3[2])/3);

        // Publishing values
        grav_pub.publish(grav_publisher);
        force_pub.publish(force_publisher);

        ros::spinOnce();
        r.sleep();
    }

    qDebug("exit");

    return 0;
}