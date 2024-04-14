#ifndef _ROS_SERVICE_enableEventGenerator_h
#define _ROS_SERVICE_enableEventGenerator_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs_events
{

static const char ENABLEEVENTGENERATOR[] = "tum_ics_skin_msgs_events/enableEventGenerator";

  class enableEventGeneratorRequest : public ros::Msg
  {
    public:
      typedef bool _enable_type;
      _enable_type enable;

    enableEventGeneratorRequest():
      enable(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.real = this->enable;
      *(outbuffer + offset + 0) = (u_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.base = 0;
      u_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable = u_enable.real;
      offset += sizeof(this->enable);
     return offset;
    }

    virtual const char * getType() override { return ENABLEEVENTGENERATOR; };
    virtual const char * getMD5() override { return "8c1211af706069c994c06e00eb59ac9e"; };

  };

  class enableEventGeneratorResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    enableEventGeneratorResponse():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    virtual const char * getType() override { return ENABLEEVENTGENERATOR; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class enableEventGenerator {
    public:
    typedef enableEventGeneratorRequest Request;
    typedef enableEventGeneratorResponse Response;
  };

}
#endif
