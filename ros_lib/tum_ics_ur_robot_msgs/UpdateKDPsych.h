#ifndef _ROS_SERVICE_UpdateKDPsych_h
#define _ROS_SERVICE_UpdateKDPsych_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_ur_robot_msgs
{

static const char UPDATEKDPSYCH[] = "tum_ics_ur_robot_msgs/UpdateKDPsych";

  class UpdateKDPsychRequest : public ros::Msg
  {
    public:
      float kpd[2];

    UpdateKDPsychRequest():
      kpd()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->kpd[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->kpd[i]));
      }
     return offset;
    }

    virtual const char * getType() override { return UPDATEKDPSYCH; };
    virtual const char * getMD5() override { return "99b3245fe3a3c6888a3bcd029e2b24dc"; };

  };

  class UpdateKDPsychResponse : public ros::Msg
  {
    public:
      typedef bool _confirmation_type;
      _confirmation_type confirmation;

    UpdateKDPsychResponse():
      confirmation(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_confirmation;
      u_confirmation.real = this->confirmation;
      *(outbuffer + offset + 0) = (u_confirmation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->confirmation);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_confirmation;
      u_confirmation.base = 0;
      u_confirmation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->confirmation = u_confirmation.real;
      offset += sizeof(this->confirmation);
     return offset;
    }

    virtual const char * getType() override { return UPDATEKDPSYCH; };
    virtual const char * getMD5() override { return "f27299616d4eae5b55699f532a896283"; };

  };

  class UpdateKDPsych {
    public:
    typedef UpdateKDPsychRequest Request;
    typedef UpdateKDPsychResponse Response;
  };

}
#endif
