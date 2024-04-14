#ifndef _ROS_SERVICE_getSkinCellNeighbors_h
#define _ROS_SERVICE_getSkinCellNeighbors_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs/SkinCellNeighbors.h"

namespace tum_ics_skin_msgs
{

static const char GETSKINCELLNEIGHBORS[] = "tum_ics_skin_msgs/getSkinCellNeighbors";

  class getSkinCellNeighborsRequest : public ros::Msg
  {
    public:
      uint32_t cellId_length;
      typedef int32_t _cellId_type;
      _cellId_type st_cellId;
      _cellId_type * cellId;

    getSkinCellNeighborsRequest():
      cellId_length(0), st_cellId(), cellId(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->cellId_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cellId_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cellId_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cellId_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cellId_length);
      for( uint32_t i = 0; i < cellId_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_cellIdi;
      u_cellIdi.real = this->cellId[i];
      *(outbuffer + offset + 0) = (u_cellIdi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cellIdi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cellIdi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cellIdi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cellId[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t cellId_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cellId_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cellId_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cellId_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cellId_length);
      if(cellId_lengthT > cellId_length)
        this->cellId = (int32_t*)realloc(this->cellId, cellId_lengthT * sizeof(int32_t));
      cellId_length = cellId_lengthT;
      for( uint32_t i = 0; i < cellId_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_cellId;
      u_st_cellId.base = 0;
      u_st_cellId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cellId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_cellId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_cellId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_cellId = u_st_cellId.real;
      offset += sizeof(this->st_cellId);
        memcpy( &(this->cellId[i]), &(this->st_cellId), sizeof(int32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return GETSKINCELLNEIGHBORS; };
    virtual const char * getMD5() override { return "33b509be697fb1a069fccba656762bcc"; };

  };

  class getSkinCellNeighborsResponse : public ros::Msg
  {
    public:
      uint32_t neighs_length;
      typedef tum_ics_skin_msgs::SkinCellNeighbors _neighs_type;
      _neighs_type st_neighs;
      _neighs_type * neighs;
      typedef bool _ok_type;
      _ok_type ok;

    getSkinCellNeighborsResponse():
      neighs_length(0), st_neighs(), neighs(nullptr),
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->neighs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->neighs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->neighs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->neighs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neighs_length);
      for( uint32_t i = 0; i < neighs_length; i++){
      offset += this->neighs[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t neighs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      neighs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      neighs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      neighs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->neighs_length);
      if(neighs_lengthT > neighs_length)
        this->neighs = (tum_ics_skin_msgs::SkinCellNeighbors*)realloc(this->neighs, neighs_lengthT * sizeof(tum_ics_skin_msgs::SkinCellNeighbors));
      neighs_length = neighs_lengthT;
      for( uint32_t i = 0; i < neighs_length; i++){
      offset += this->st_neighs.deserialize(inbuffer + offset);
        memcpy( &(this->neighs[i]), &(this->st_neighs), sizeof(tum_ics_skin_msgs::SkinCellNeighbors));
      }
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    virtual const char * getType() override { return GETSKINCELLNEIGHBORS; };
    virtual const char * getMD5() override { return "79c26a65f15420ab3e755e9b08799d1f"; };

  };

  class getSkinCellNeighbors {
    public:
    typedef getSkinCellNeighborsRequest Request;
    typedef getSkinCellNeighborsResponse Response;
  };

}
#endif
