#ifndef _ROS_SERVICE_setGripperState_h
#define _ROS_SERVICE_setGripperState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_lacquey_gripper_msgs
{

static const char SETGRIPPERSTATE[] = "tum_ics_lacquey_gripper_msgs/setGripperState";

  class setGripperStateRequest : public ros::Msg
  {
    public:
      typedef const char* _newState_type;
      _newState_type newState;

    setGripperStateRequest():
      newState("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_newState = strlen(this->newState);
      varToArr(outbuffer + offset, length_newState);
      offset += 4;
      memcpy(outbuffer + offset, this->newState, length_newState);
      offset += length_newState;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_newState;
      arrToVar(length_newState, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_newState; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_newState-1]=0;
      this->newState = (char *)(inbuffer + offset-1);
      offset += length_newState;
     return offset;
    }

    virtual const char * getType() override { return SETGRIPPERSTATE; };
    virtual const char * getMD5() override { return "99fe01dfe585dc3e99fcbbc1365932c3"; };

  };

  class setGripperStateResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    setGripperStateResponse():
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

    virtual const char * getType() override { return SETGRIPPERSTATE; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class setGripperState {
    public:
    typedef setGripperStateRequest Request;
    typedef setGripperStateResponse Response;
  };

}
#endif
