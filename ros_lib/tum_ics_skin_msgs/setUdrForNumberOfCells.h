#ifndef _ROS_SERVICE_setUdrForNumberOfCells_h
#define _ROS_SERVICE_setUdrForNumberOfCells_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs
{

static const char SETUDRFORNUMBEROFCELLS[] = "tum_ics_skin_msgs/setUdrForNumberOfCells";

  class setUdrForNumberOfCellsRequest : public ros::Msg
  {
    public:
      typedef int32_t _numberOfCells_type;
      _numberOfCells_type numberOfCells;
      typedef int32_t _udr_type;
      _udr_type udr;

    setUdrForNumberOfCellsRequest():
      numberOfCells(0),
      udr(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_numberOfCells;
      u_numberOfCells.real = this->numberOfCells;
      *(outbuffer + offset + 0) = (u_numberOfCells.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_numberOfCells.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_numberOfCells.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_numberOfCells.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->numberOfCells);
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
      union {
        int32_t real;
        uint32_t base;
      } u_numberOfCells;
      u_numberOfCells.base = 0;
      u_numberOfCells.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_numberOfCells.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_numberOfCells.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_numberOfCells.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->numberOfCells = u_numberOfCells.real;
      offset += sizeof(this->numberOfCells);
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

    virtual const char * getType() override { return SETUDRFORNUMBEROFCELLS; };
    virtual const char * getMD5() override { return "a2feafc2570181a6cbf7ebf2731f2caf"; };

  };

  class setUdrForNumberOfCellsResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    setUdrForNumberOfCellsResponse():
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

    virtual const char * getType() override { return SETUDRFORNUMBEROFCELLS; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class setUdrForNumberOfCells {
    public:
    typedef setUdrForNumberOfCellsRequest Request;
    typedef setUdrForNumberOfCellsResponse Response;
  };

}
#endif
