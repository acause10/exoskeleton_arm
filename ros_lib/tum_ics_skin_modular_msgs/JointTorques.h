#ifndef _ROS_tum_ics_skin_modular_msgs_JointTorques_h
#define _ROS_tum_ics_skin_modular_msgs_JointTorques_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_skin_modular_msgs
{

  class JointTorques : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t tau_length;
      typedef float _tau_type;
      _tau_type st_tau;
      _tau_type * tau;

    JointTorques():
      header(),
      tau_length(0), st_tau(), tau(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->tau_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tau_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tau_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tau_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tau_length);
      for( uint32_t i = 0; i < tau_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tau[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t tau_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tau_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tau_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tau_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tau_length);
      if(tau_lengthT > tau_length)
        this->tau = (float*)realloc(this->tau, tau_lengthT * sizeof(float));
      tau_length = tau_lengthT;
      for( uint32_t i = 0; i < tau_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_tau));
        memcpy( &(this->tau[i]), &(this->st_tau), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_modular_msgs/JointTorques"; };
    virtual const char * getMD5() override { return "a2006553feb86829b3a9401048f25583"; };

  };

}
#endif
