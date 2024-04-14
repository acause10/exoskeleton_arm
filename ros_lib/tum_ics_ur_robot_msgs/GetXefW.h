#ifndef _ROS_SERVICE_GetXefW_h
#define _ROS_SERVICE_GetXefW_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_ur_robot_msgs
{

static const char GETXEFW[] = "tum_ics_ur_robot_msgs/GetXefW";

  class GetXefWRequest : public ros::Msg
  {
    public:

    GetXefWRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return GETXEFW; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetXefWResponse : public ros::Msg
  {
    public:
      float xef_w[3];

    GetXefWResponse():
      xef_w()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->xef_w[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->xef_w[i]));
      }
     return offset;
    }

    virtual const char * getType() override { return GETXEFW; };
    virtual const char * getMD5() override { return "766935bbbedae6caf2637e0f1d12f57a"; };

  };

  class GetXefW {
    public:
    typedef GetXefWRequest Request;
    typedef GetXefWResponse Response;
  };

}
#endif
