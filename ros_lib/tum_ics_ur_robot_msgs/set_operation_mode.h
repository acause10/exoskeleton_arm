#ifndef _ROS_SERVICE_set_operation_mode_h
#define _ROS_SERVICE_set_operation_mode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_ur_robot_msgs
{

static const char SET_OPERATION_MODE[] = "tum_ics_ur_robot_msgs/set_operation_mode";

  class set_operation_modeRequest : public ros::Msg
  {
    public:
      typedef int64_t _mode_id_type;
      _mode_id_type mode_id;

    set_operation_modeRequest():
      mode_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_mode_id;
      u_mode_id.real = this->mode_id;
      *(outbuffer + offset + 0) = (u_mode_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mode_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mode_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mode_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_mode_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_mode_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_mode_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_mode_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->mode_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_mode_id;
      u_mode_id.base = 0;
      u_mode_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mode_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mode_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mode_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_mode_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_mode_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_mode_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_mode_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->mode_id = u_mode_id.real;
      offset += sizeof(this->mode_id);
     return offset;
    }

    virtual const char * getType() override { return SET_OPERATION_MODE; };
    virtual const char * getMD5() override { return "016f744b85a0eb6a841d4d50f5a2162b"; };

  };

  class set_operation_modeResponse : public ros::Msg
  {
    public:
      typedef int64_t _mode_id_reply_type;
      _mode_id_reply_type mode_id_reply;

    set_operation_modeResponse():
      mode_id_reply(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_mode_id_reply;
      u_mode_id_reply.real = this->mode_id_reply;
      *(outbuffer + offset + 0) = (u_mode_id_reply.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mode_id_reply.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mode_id_reply.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mode_id_reply.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_mode_id_reply.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_mode_id_reply.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_mode_id_reply.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_mode_id_reply.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->mode_id_reply);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_mode_id_reply;
      u_mode_id_reply.base = 0;
      u_mode_id_reply.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mode_id_reply.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mode_id_reply.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mode_id_reply.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_mode_id_reply.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_mode_id_reply.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_mode_id_reply.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_mode_id_reply.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->mode_id_reply = u_mode_id_reply.real;
      offset += sizeof(this->mode_id_reply);
     return offset;
    }

    virtual const char * getType() override { return SET_OPERATION_MODE; };
    virtual const char * getMD5() override { return "e224786037a98567a19e3b9aba73401b"; };

  };

  class set_operation_mode {
    public:
    typedef set_operation_modeRequest Request;
    typedef set_operation_modeResponse Response;
  };

}
#endif
