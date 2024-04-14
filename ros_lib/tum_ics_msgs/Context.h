#ifndef _ROS_tum_ics_msgs_Context_h
#define _ROS_tum_ics_msgs_Context_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/String.h"

namespace tum_ics_msgs
{

  class Context : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::String _objType_type;
      _objType_type objType;

    Context():
      header(),
      objType()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->objType.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->objType.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_msgs/Context"; };
    virtual const char * getMD5() override { return "d985b58368b9c4a3870e497edbead208"; };

  };

}
#endif
