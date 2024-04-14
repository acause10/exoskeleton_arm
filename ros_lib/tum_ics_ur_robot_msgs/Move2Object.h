#ifndef _ROS_SERVICE_Move2Object_h
#define _ROS_SERVICE_Move2Object_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_ur_robot_msgs
{

static const char MOVE2OBJECT[] = "tum_ics_ur_robot_msgs/Move2Object";

  class Move2ObjectRequest : public ros::Msg
  {
    public:
      typedef int32_t _objID_type;
      _objID_type objID;

    Move2ObjectRequest():
      objID(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_objID;
      u_objID.real = this->objID;
      *(outbuffer + offset + 0) = (u_objID.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_objID.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_objID.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_objID.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->objID);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_objID;
      u_objID.base = 0;
      u_objID.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_objID.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_objID.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_objID.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->objID = u_objID.real;
      offset += sizeof(this->objID);
     return offset;
    }

    virtual const char * getType() override { return MOVE2OBJECT; };
    virtual const char * getMD5() override { return "fec8d8703012171cff840b46713a45ce"; };

  };

  class Move2ObjectResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    Move2ObjectResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return MOVE2OBJECT; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class Move2Object {
    public:
    typedef Move2ObjectRequest Request;
    typedef Move2ObjectResponse Response;
  };

}
#endif
