#ifndef _ROS_tum_ics_skin_msgs_events_SkinCellEventThresholds_h
#define _ROS_tum_ics_skin_msgs_events_SkinCellEventThresholds_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs_events
{

  class SkinCellEventThresholds : public ros::Msg
  {
    public:
      typedef int32_t _cellId_type;
      _cellId_type cellId;
      uint32_t prox_length;
      typedef float _prox_type;
      _prox_type st_prox;
      _prox_type * prox;
      uint32_t force_length;
      typedef float _force_type;
      _force_type st_force;
      _force_type * force;
      uint32_t acc_length;
      typedef float _acc_type;
      _acc_type st_acc;
      _acc_type * acc;
      uint32_t temp_length;
      typedef float _temp_type;
      _temp_type st_temp;
      _temp_type * temp;

    SkinCellEventThresholds():
      cellId(0),
      prox_length(0), st_prox(), prox(nullptr),
      force_length(0), st_force(), force(nullptr),
      acc_length(0), st_acc(), acc(nullptr),
      temp_length(0), st_temp(), temp(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_cellId;
      u_cellId.real = this->cellId;
      *(outbuffer + offset + 0) = (u_cellId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cellId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cellId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cellId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cellId);
      *(outbuffer + offset + 0) = (this->prox_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->prox_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->prox_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->prox_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->prox_length);
      for( uint32_t i = 0; i < prox_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->prox[i]);
      }
      *(outbuffer + offset + 0) = (this->force_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->force_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->force_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->force_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force_length);
      for( uint32_t i = 0; i < force_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->force[i]);
      }
      *(outbuffer + offset + 0) = (this->acc_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->acc_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->acc_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->acc_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acc_length);
      for( uint32_t i = 0; i < acc_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->acc[i]);
      }
      *(outbuffer + offset + 0) = (this->temp_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->temp_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->temp_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->temp_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temp_length);
      for( uint32_t i = 0; i < temp_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->temp[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_cellId;
      u_cellId.base = 0;
      u_cellId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cellId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cellId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cellId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cellId = u_cellId.real;
      offset += sizeof(this->cellId);
      uint32_t prox_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      prox_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      prox_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      prox_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->prox_length);
      if(prox_lengthT > prox_length)
        this->prox = (float*)realloc(this->prox, prox_lengthT * sizeof(float));
      prox_length = prox_lengthT;
      for( uint32_t i = 0; i < prox_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_prox));
        memcpy( &(this->prox[i]), &(this->st_prox), sizeof(float));
      }
      uint32_t force_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      force_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      force_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      force_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->force_length);
      if(force_lengthT > force_length)
        this->force = (float*)realloc(this->force, force_lengthT * sizeof(float));
      force_length = force_lengthT;
      for( uint32_t i = 0; i < force_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_force));
        memcpy( &(this->force[i]), &(this->st_force), sizeof(float));
      }
      uint32_t acc_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      acc_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      acc_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      acc_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->acc_length);
      if(acc_lengthT > acc_length)
        this->acc = (float*)realloc(this->acc, acc_lengthT * sizeof(float));
      acc_length = acc_lengthT;
      for( uint32_t i = 0; i < acc_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_acc));
        memcpy( &(this->acc[i]), &(this->st_acc), sizeof(float));
      }
      uint32_t temp_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      temp_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      temp_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      temp_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->temp_length);
      if(temp_lengthT > temp_length)
        this->temp = (float*)realloc(this->temp, temp_lengthT * sizeof(float));
      temp_length = temp_lengthT;
      for( uint32_t i = 0; i < temp_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_temp));
        memcpy( &(this->temp[i]), &(this->st_temp), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs_events/SkinCellEventThresholds"; };
    virtual const char * getMD5() override { return "95fa5accee0ad2dc5e185ec56ecb2b84"; };

  };

}
#endif
