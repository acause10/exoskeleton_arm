#ifndef _ROS_tum_ics_ur_robot_msgs_RobotTF_h
#define _ROS_tum_ics_ur_robot_msgs_RobotTF_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_ur_robot_msgs
{

  class RobotTF : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      float tf_data[7];

    RobotTF():
      header(),
      tf_data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 7; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tf_data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 7; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tf_data[i]));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_ur_robot_msgs/RobotTF"; };
    virtual const char * getMD5() override { return "d4eb6687727f90c5e398417cb2e5752c"; };

  };

}
#endif
