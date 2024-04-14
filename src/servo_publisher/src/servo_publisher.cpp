#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "std_srvs/Empty.h"
#include "std_srvs/SetBool.h"
#include <sstream>
using namespace std;

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */

  // Inicijaliziramo ROS i specificiramo ime cvora (moraju biti unikatna).
  ros::init(argc, argv, "servo_publisher");

  /**S
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */

  // Kreiramo handler za cvor ovog procesa.
  // Prvi kreiran ce inicijalizirati cvor, te posljednji kreiran ce ocistit
  // sve resurse koje je cvor koristio.
  ros::NodeHandle n;

  ros::ServiceClient motor_client = n.serviceClient<std_srvs::SetBool::Request, std_srvs::SetBool::Response>("attaching_servo");

  std_srvs::SetBool srv;

  bool attach;
  int attachment_variable;
  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */

  // Govorimo masteru da cemo objavljivati poruke tipa std_msgs/Float64 na topic
  // "floater". Ovo dozvoljava masteru da kaze bilo kojem cvoru koji slusa na "floater"
  // da cemo objaviti podatke na taj topic. Drugi argument je velicina naseg objavljujuceg
  // queuea. Ako objavljujemo prebrzo bufferovat ce max 1000 poruka prije nego
  // pocne bacati starije

  //NodeHAndle::advertise() vraca ros::Publisher objekt koji ima 2 svrhe:
  // 1 - sadrzi publish() metodu koja nam dozvoljava objaviti poruke na topic
  // s kojim je kreiran, 2 - kada ode izvan scopea, automatski ce unadvertiseovati
  ros::Publisher floater_pub = n.advertise<std_msgs::Float64>("q_control_publisher", 100);

  // Frekvencija kojom loopamo. Pratit ce koliko dugo je proslo od posljednjeg
  // poziva Rate::sleep() -u, i zaspat dovoljno vremena.
  //ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  //int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    //std_msgs::String msg;
    std_msgs::Float64 floater; 

    std::cout << "Input for attachment: ";
    std::cin >> attachment_variable;
    std::cout << "Your input: " << attachment_variable;

    if(attachment_variable == 1)
    {
      attach = true;
    }
    else
    {
      attach = false;
    }

    srv.request.data = attach;

    if (motor_client.call(srv))
    {
      ROS_INFO("Called!");
    }
    else
    {
      ROS_ERROR("Failed to call client!");
    }

    //std::stringstream ss;
    //ss << "hello world " << count;
    //msg.data = ss.str();
    
    //COMMENTED FLOATER
    ROS_INFO("Passing float value: ");
    float q;
    cin >> q;
    floater.data = q;
    ROS_INFO("Passed value: %f", floater.data);

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    floater_pub.publish(floater);

    ros::spinOnce();

    //loop_rate.sleep();
    //++count;
  }


  return 0;
}