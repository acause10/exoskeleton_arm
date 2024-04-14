#ifndef _ROS_tum_ics_msgs_JointPositions_h
#define _ROS_tum_ics_msgs_JointPositions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_msgs
{

  class JointPositions : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      float q[6];

    JointPositions():
      header(),
      q()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->q[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q[i]));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_msgs/JointPositions"; };
    virtual const char * getMD5() override { return "54ee7ec1a341c167b704714674f54ba8"; };

  };

}
#endif
