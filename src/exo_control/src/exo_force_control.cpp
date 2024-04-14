#include<exo_control/exo_force_control.h>

namespace ExoControllers{

    ForceControl::ForceControl(double L3)
    {
        ROS_INFO_STREAM("Force Controller Created");
        
        std::string ns="~force_ctrl";
        std::stringstream s;
        s.str("");
        s<<ns<<"/kp";
        ros::param::get(s.str(),m_kp);
        ROS_WARN_STREAM("force m_kp: \n"<<m_kp);

        m_L3 = L3;
        m_startFlag = false;
        m_tao << 0,0;
    }

    ForceControl::~ForceControl()
    {
    }

    bool ForceControl::init(Eigen::Vector2d W_des)
    {
        m_W_des = W_des;
        m_startFlag = false;        
        return true;
    }

    Eigen::Vector2d ForceControl::update(Eigen::Vector2d Ws)
    {
        if(!m_startFlag)
        {
            m_startFlag = true;
        }

        Eigen::Vector2d delta_Ws = {0,0};

        delta_Ws = m_kp*(Ws - m_W_des);
        m_tao = m_L3*delta_Ws;
        
        //ROS_WARN_STREAM("Produced torque: " << m_tao);

        return m_tao;
    }

}
