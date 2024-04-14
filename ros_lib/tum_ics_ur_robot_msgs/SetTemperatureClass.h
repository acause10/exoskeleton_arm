#ifndef _ROS_SERVICE_SetTemperatureClass_h
#define _ROS_SERVICE_SetTemperatureClass_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_ur_robot_msgs
{

static const char SETTEMPERATURECLASS[] = "tum_ics_ur_robot_msgs/SetTemperatureClass";

  class SetTemperatureClassRequest : public ros::Msg
  {
    public:
      typedef int32_t _classID_type;
      _classID_type classID;

    SetTemperatureClassRequest():
      classID(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_classID;
      u_classID.real = this->classID;
      *(outbuffer + offset + 0) = (u_classID.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_classID.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_classID.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_classID.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->classID);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_classID;
      u_classID.base = 0;
      u_classID.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_classID.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_classID.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_classID.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->classID = u_classID.real;
      offset += sizeof(this->classID);
     return offset;
    }

    virtual const char * getType() override { return SETTEMPERATURECLASS; };
    virtual const char * getMD5() override { return "4c896dd9083e68e02bbc6e246f7582ed"; };

  };

  class SetTemperatureClassResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetTemperatureClassResponse():
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

    virtual const char * getType() override { return SETTEMPERATURECLASS; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetTemperatureClass {
    public:
    typedef SetTemperatureClassRequest Request;
    typedef SetTemperatureClassResponse Response;
  };

}
#endif
