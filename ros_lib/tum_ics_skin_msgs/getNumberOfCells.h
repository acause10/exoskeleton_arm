#ifndef _ROS_SERVICE_getNumberOfCells_h
#define _ROS_SERVICE_getNumberOfCells_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs
{

static const char GETNUMBEROFCELLS[] = "tum_ics_skin_msgs/getNumberOfCells";

  class getNumberOfCellsRequest : public ros::Msg
  {
    public:

    getNumberOfCellsRequest()
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

    virtual const char * getType() override { return GETNUMBEROFCELLS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class getNumberOfCellsResponse : public ros::Msg
  {
    public:
      typedef int32_t _numberOfCells_type;
      _numberOfCells_type numberOfCells;
      typedef bool _ok_type;
      _ok_type ok;

    getNumberOfCellsResponse():
      numberOfCells(0),
      ok(0)
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
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    virtual const char * getType() override { return GETNUMBEROFCELLS; };
    virtual const char * getMD5() override { return "83860b810ad032cbfc14134c406aaf32"; };

  };

  class getNumberOfCells {
    public:
    typedef getNumberOfCellsRequest Request;
    typedef getNumberOfCellsResponse Response;
  };

}
#endif
