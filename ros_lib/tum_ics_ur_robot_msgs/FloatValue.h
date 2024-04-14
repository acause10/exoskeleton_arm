#ifndef _ROS_tum_ics_ur_robot_msgs_FloatValue_h
#define _ROS_tum_ics_ur_robot_msgs_FloatValue_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_ur_robot_msgs
{

  class FloatValue : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _time_type;
      _time_type time;
      typedef float _value_type;
      _value_type value;

    FloatValue():
      header(),
      time(0),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->time);
      offset += serializeAvrFloat64(outbuffer + offset, this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->value));
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_ur_robot_msgs/FloatValue"; };
    virtual const char * getMD5() override { return "d5087cbf20069f21dbc6580d173f7d25"; };

  };

}
#endif
