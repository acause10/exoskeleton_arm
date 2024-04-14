#ifndef _ROS_SERVICE_setUdr_h
#define _ROS_SERVICE_setUdr_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs
{

static const char SETUDR[] = "tum_ics_skin_msgs/setUdr";

  class setUdrRequest : public ros::Msg
  {
    public:
      uint32_t cellId_length;
      typedef int32_t _cellId_type;
      _cellId_type st_cellId;
      _cellId_type * cellId;
      typedef int32_t _udr_type;
      _udr_type udr;

    setUdrRequest():
      cellId_length(0), st_cellId(), cellId(nullptr),
      udr(0)
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
      union {
        int32_t real;
        uint32_t base;
      } u_udr;
      u_udr.real = this->udr;
      *(outbuffer + offset + 0) = (u_udr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_udr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_udr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_udr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->udr);
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
      union {
        int32_t real;
        uint32_t base;
      } u_udr;
      u_udr.base = 0;
      u_udr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_udr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_udr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_udr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->udr = u_udr.real;
      offset += sizeof(this->udr);
     return offset;
    }

    virtual const char * getType() override { return SETUDR; };
    virtual const char * getMD5() override { return "ff3be92433cd02cd69e2a7791d88437c"; };

  };

  class setUdrResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    setUdrResponse():
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

    virtual const char * getType() override { return SETUDR; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class setUdr {
    public:
    typedef setUdrRequest Request;
    typedef setUdrResponse Response;
  };

}
#endif
