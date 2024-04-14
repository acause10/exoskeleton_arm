#ifndef _ROS_SERVICE_setCmd_h
#define _ROS_SERVICE_setCmd_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs
{

static const char SETCMD[] = "tum_ics_skin_msgs/setCmd";

  class setCmdRequest : public ros::Msg
  {
    public:
      typedef const char* _cmd_type;
      _cmd_type cmd;

    setCmdRequest():
      cmd("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_cmd = strlen(this->cmd);
      varToArr(outbuffer + offset, length_cmd);
      offset += 4;
      memcpy(outbuffer + offset, this->cmd, length_cmd);
      offset += length_cmd;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_cmd;
      arrToVar(length_cmd, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_cmd; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_cmd-1]=0;
      this->cmd = (char *)(inbuffer + offset-1);
      offset += length_cmd;
     return offset;
    }

    virtual const char * getType() override { return SETCMD; };
    virtual const char * getMD5() override { return "43a54fa49066cddcf148717d9d4a6353"; };

  };

  class setCmdResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    setCmdResponse():
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

    virtual const char * getType() override { return SETCMD; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class setCmd {
    public:
    typedef setCmdRequest Request;
    typedef setCmdResponse Response;
  };

}
#endif
