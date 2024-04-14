#ifndef _ROS_SERVICE_SendNewAction_h
#define _ROS_SERVICE_SendNewAction_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_msgs
{

static const char SENDNEWACTION[] = "tum_ics_msgs/SendNewAction";

  class SendNewActionRequest : public ros::Msg
  {
    public:
      typedef bool _trigger_type;
      _trigger_type trigger;

    SendNewActionRequest():
      trigger(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_trigger;
      u_trigger.real = this->trigger;
      *(outbuffer + offset + 0) = (u_trigger.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->trigger);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_trigger;
      u_trigger.base = 0;
      u_trigger.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->trigger = u_trigger.real;
      offset += sizeof(this->trigger);
     return offset;
    }

    virtual const char * getType() override { return SENDNEWACTION; };
    virtual const char * getMD5() override { return "f6d1152a533bdef9ec687318c8e489b0"; };

  };

  class SendNewActionResponse : public ros::Msg
  {
    public:
      typedef bool _confirm_type;
      _confirm_type confirm;

    SendNewActionResponse():
      confirm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_confirm;
      u_confirm.real = this->confirm;
      *(outbuffer + offset + 0) = (u_confirm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->confirm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_confirm;
      u_confirm.base = 0;
      u_confirm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->confirm = u_confirm.real;
      offset += sizeof(this->confirm);
     return offset;
    }

    virtual const char * getType() override { return SENDNEWACTION; };
    virtual const char * getMD5() override { return "b37994baa157ef8535427a2de0e06206"; };

  };

  class SendNewAction {
    public:
    typedef SendNewActionRequest Request;
    typedef SendNewActionResponse Response;
  };

}
#endif
