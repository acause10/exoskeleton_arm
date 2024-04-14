#ifndef EXO_ROBOT_FORCECONTROL_H
#define EXO_ROBOT_FORCECONTROL_H

#include <ros/ros.h>
#include <Eigen/Dense>

using namespace Eigen;
using std::string;

namespace ExoControllers{
    
    class ForceControl{
        private:
            ros::NodeHandle n;
            double m_L3;
            double m_kp;
            bool m_startFlag;
            Eigen::Vector2d m_W_des;
            Eigen::Vector2d m_tao;
            
        public:
            ForceControl(double L3);
            ~ForceControl();
            bool init(Eigen::Vector2d W_des);
            Eigen::Vector2d update(Eigen::Vector2d Ws);

    };
}

#endif