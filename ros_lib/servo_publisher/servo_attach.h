#ifndef _ROS_SERVICE_servo_attach_h
#define _ROS_SERVICE_servo_attach_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace servo_publisher
{

static const char SERVO_ATTACH[] = "servo_publisher/servo_attach";

  class servo_attachRequest : public ros::Msg
  {
    public:
      typedef bool _servo_attach_bool_type;
      _servo_attach_bool_type servo_attach_bool;

    servo_attachRequest():
      servo_attach_bool(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_servo_attach_bool;
      u_servo_attach_bool.real = this->servo_attach_bool;
      *(outbuffer + offset + 0) = (u_servo_attach_bool.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->servo_attach_bool);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_servo_attach_bool;
      u_servo_attach_bool.base = 0;
      u_servo_attach_bool.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->servo_attach_bool = u_servo_attach_bool.real;
      offset += sizeof(this->servo_attach_bool);
     return offset;
    }

    virtual const char * getType() override { return SERVO_ATTACH; };
    virtual const char * getMD5() override { return "1780cb17a15c46ad2593be5875f4549b"; };

  };

  class servo_attachResponse : public ros::Msg
  {
    public:
      typedef const char* _done_type;
      _done_type done;

    servo_attachResponse():
      done("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_done = strlen(this->done);
      varToArr(outbuffer + offset, length_done);
      offset += 4;
      memcpy(outbuffer + offset, this->done, length_done);
      offset += length_done;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_done;
      arrToVar(length_done, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_done; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_done-1]=0;
      this->done = (char *)(inbuffer + offset-1);
      offset += length_done;
     return offset;
    }

    virtual const char * getType() override { return SERVO_ATTACH; };
    virtual const char * getMD5() override { return "6f6f8833c91017f802acaa131839007d"; };

  };

  class servo_attach {
    public:
    typedef servo_attachRequest Request;
    typedef servo_attachResponse Response;
  };

}
#endif
