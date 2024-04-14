#ifndef _ROS_tum_ics_skin_msgs_SkinCellNeighbors_h
#define _ROS_tum_ics_skin_msgs_SkinCellNeighbors_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs
{

  class SkinCellNeighbors : public ros::Msg
  {
    public:
      typedef int32_t _cellId_type;
      _cellId_type cellId;
      uint32_t neighId_length;
      typedef int32_t _neighId_type;
      _neighId_type st_neighId;
      _neighId_type * neighId;

    SkinCellNeighbors():
      cellId(0),
      neighId_length(0), st_neighId(), neighId(nullptr)
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
      *(outbuffer + offset + 0) = (this->neighId_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->neighId_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->neighId_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->neighId_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neighId_length);
      for( uint32_t i = 0; i < neighId_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_neighIdi;
      u_neighIdi.real = this->neighId[i];
      *(outbuffer + offset + 0) = (u_neighIdi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_neighIdi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_neighIdi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_neighIdi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neighId[i]);
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
      uint32_t neighId_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      neighId_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      neighId_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      neighId_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->neighId_length);
      if(neighId_lengthT > neighId_length)
        this->neighId = (int32_t*)realloc(this->neighId, neighId_lengthT * sizeof(int32_t));
      neighId_length = neighId_lengthT;
      for( uint32_t i = 0; i < neighId_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_neighId;
      u_st_neighId.base = 0;
      u_st_neighId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_neighId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_neighId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_neighId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_neighId = u_st_neighId.real;
      offset += sizeof(this->st_neighId);
        memcpy( &(this->neighId[i]), &(this->st_neighId), sizeof(int32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs/SkinCellNeighbors"; };
    virtual const char * getMD5() override { return "378e9d8c773b9f85245d68e517b8984b"; };

  };

}
#endif
