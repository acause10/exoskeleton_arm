#include "ros/ros.h"
#include "std_msgs/Bool.h"
using namespace std;


int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "init_forces_publisher");

  ros::NodeHandle n;

  ros::Publisher init_pub = n.advertise<std_msgs::Bool>("init_forces", 100);

  std_msgs::Bool setForces; 
  setForces.data = true;

   ROS_INFO("Enter key to initialize forces: ");
   char q;
   cin >> q;
   ROS_INFO("initialized force readings");

  init_pub.publish(setForces);
  ROS_WARN_STREAM("executed");

  ros::spinOnce();

  return 0;
}