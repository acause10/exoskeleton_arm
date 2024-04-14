#include "ros/ros.h"
#include <cstdlib>
#include <std_srvs/SetBool.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "attach_servo_node");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<std_srvs::SetBool>("attaching_servo");
  std_srvs::SetBool srv;
  
  bool attach;
  std::cin >> attach;
  srv.request.data = attach;
  
  if (client.call(srv))
  {
    ROS_INFO("Servo is: %s", srv.response.message.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service servo_attach");
    return 1;
  }

  return 0;
}