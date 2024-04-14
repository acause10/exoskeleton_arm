#ifndef _ROS_SERVICE_GetContactFlag_h
#define _ROS_SERVICE_GetContactFlag_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_ur_robot_msgs
{

static const char GETCONTACTFLAG[] = "tum_ics_ur_robot_msgs/GetContactFlag";

  class GetContactFlagRequest : public ros::Msg
  {
    public:

    GetContactFlagRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return GETCONTACTFLAG; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetContactFlagResponse : public ros::Msg
  {
    public:
      typedef bool _skin_contact_type;
      _skin_contact_type skin_contact;

    GetContactFlagResponse():
      skin_contact(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_skin_contact;
      u_skin_contact.real = this->skin_contact;
      *(outbuffer + offset + 0) = (u_skin_contact.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->skin_contact);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_skin_contact;
      u_skin_contact.base = 0;
      u_skin_contact.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->skin_contact = u_skin_contact.real;
      offset += sizeof(this->skin_contact);
     return offset;
    }

    virtual const char * getType() override { return GETCONTACTFLAG; };
    virtual const char * getMD5() override { return "60d9e7d7aac879c50f13b0255204eb5d"; };

  };

  class GetContactFlag {
    public:
    typedef GetContactFlagRequest Request;
    typedef GetContactFlagResponse Response;
  };

}
#endif
