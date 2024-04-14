#ifndef _ROS_SERVICE_createSkinCellValuesPub_h
#define _ROS_SERVICE_createSkinCellValuesPub_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_modular_msgs
{

static const char CREATESKINCELLVALUESPUB[] = "tum_ics_skin_modular_msgs/createSkinCellValuesPub";

  class createSkinCellValuesPubRequest : public ros::Msg
  {
    public:
      typedef const char* _topicName_type;
      _topicName_type topicName;
      uint32_t cellIds_length;
      typedef int32_t _cellIds_type;
      _cellIds_type st_cellIds;
      _cellIds_type * cellIds;
      uint32_t valueInds_length;
      typedef int32_t _valueInds_type;
      _valueInds_type st_valueInds;
      _valueInds_type * valueInds;
      typedef bool _singleCell_type;
      _singleCell_type singleCell;
      typedef bool _singleValue_type;
      _singleValue_type singleValue;

    createSkinCellValuesPubRequest():
      topicName(""),
      cellIds_length(0), st_cellIds(), cellIds(nullptr),
      valueInds_length(0), st_valueInds(), valueInds(nullptr),
      singleCell(0),
      singleValue(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_topicName = strlen(this->topicName);
      varToArr(outbuffer + offset, length_topicName);
      offset += 4;
      memcpy(outbuffer + offset, this->topicName, length_topicName);
      offset += length_topicName;
      *(outbuffer + offset + 0) = (this->cellIds_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cellIds_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cellIds_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cellIds_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cellIds_length);
      for( uint32_t i = 0; i < cellIds_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_cellIdsi;
      u_cellIdsi.real = this->cellIds[i];
      *(outbuffer + offset + 0) = (u_cellIdsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cellIdsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cellIdsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cellIdsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cellIds[i]);
      }
      *(outbuffer + offset + 0) = (this->valueInds_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->valueInds_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->valueInds_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->valueInds_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->valueInds_length);
      for( uint32_t i = 0; i < valueInds_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_valueIndsi;
      u_valueIndsi.real = this->valueInds[i];
      *(outbuffer + offset + 0) = (u_valueIndsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_valueIndsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_valueIndsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_valueIndsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->valueInds[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_singleCell;
      u_singleCell.real = this->singleCell;
      *(outbuffer + offset + 0) = (u_singleCell.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->singleCell);
      union {
        bool real;
        uint8_t base;
      } u_singleValue;
      u_singleValue.real = this->singleValue;
      *(outbuffer + offset + 0) = (u_singleValue.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->singleValue);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_topicName;
      arrToVar(length_topicName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topicName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topicName-1]=0;
      this->topicName = (char *)(inbuffer + offset-1);
      offset += length_topicName;
      uint32_t cellIds_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cellIds_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cellIds_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cellIds_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cellIds_length);
      if(cellIds_lengthT > cellIds_length)
        this->cellIds = (int32_t*)realloc(this->cellIds, cellIds_lengthT * sizeof(int32_t));
      cellIds_length = cellIds_lengthT;
      for( uint32_t i = 0; i < cellIds_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_cellIds;
      u_st_cellIds.base = 0;
      u_st_cellIds.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cellIds.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_cellIds.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_cellIds.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_cellIds = u_st_cellIds.real;
      offset += sizeof(this->st_cellIds);
        memcpy( &(this->cellIds[i]), &(this->st_cellIds), sizeof(int32_t));
      }
      uint32_t valueInds_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      valueInds_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      valueInds_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      valueInds_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->valueInds_length);
      if(valueInds_lengthT > valueInds_length)
        this->valueInds = (int32_t*)realloc(this->valueInds, valueInds_lengthT * sizeof(int32_t));
      valueInds_length = valueInds_lengthT;
      for( uint32_t i = 0; i < valueInds_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_valueInds;
      u_st_valueInds.base = 0;
      u_st_valueInds.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_valueInds.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_valueInds.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_valueInds.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_valueInds = u_st_valueInds.real;
      offset += sizeof(this->st_valueInds);
        memcpy( &(this->valueInds[i]), &(this->st_valueInds), sizeof(int32_t));
      }
      union {
        bool real;
        uint8_t base;
      } u_singleCell;
      u_singleCell.base = 0;
      u_singleCell.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->singleCell = u_singleCell.real;
      offset += sizeof(this->singleCell);
      union {
        bool real;
        uint8_t base;
      } u_singleValue;
      u_singleValue.base = 0;
      u_singleValue.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->singleValue = u_singleValue.real;
      offset += sizeof(this->singleValue);
     return offset;
    }

    virtual const char * getType() override { return CREATESKINCELLVALUESPUB; };
    virtual const char * getMD5() override { return "09d5367bc441d85887a7dff1047ec706"; };

  };

  class createSkinCellValuesPubResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    createSkinCellValuesPubResponse():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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

    virtual const char * getType() override { return CREATESKINCELLVALUESPUB; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class createSkinCellValuesPub {
    public:
    typedef createSkinCellValuesPubRequest Request;
    typedef createSkinCellValuesPubResponse Response;
  };

}
#endif
