#ifndef _ROS_tum_ics_skin_modular_msgs_SkinCellValues_h
#define _ROS_tum_ics_skin_modular_msgs_SkinCellValues_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_modular_msgs
{

  class SkinCellValues : public ros::Msg
  {
    public:
      typedef int32_t _cellId_type;
      _cellId_type cellId;
      uint32_t values_length;
      typedef float _values_type;
      _values_type st_values;
      _values_type * values;

    SkinCellValues():
      cellId(0),
      values_length(0), st_values(), values(nullptr)
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
      *(outbuffer + offset + 0) = (this->values_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->values_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->values_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->values_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->values_length);
      for( uint32_t i = 0; i < values_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->values[i]);
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
      uint32_t values_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->values_length);
      if(values_lengthT > values_length)
        this->values = (float*)realloc(this->values, values_lengthT * sizeof(float));
      values_length = values_lengthT;
      for( uint32_t i = 0; i < values_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_values));
        memcpy( &(this->values[i]), &(this->st_values), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_modular_msgs/SkinCellValues"; };
    virtual const char * getMD5() override { return "4d2807b05e4749c73528d8d9a20b5ced"; };

  };

}
#endif
