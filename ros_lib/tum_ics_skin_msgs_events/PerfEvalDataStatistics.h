#ifndef _ROS_tum_ics_skin_msgs_events_PerfEvalDataStatistics_h
#define _ROS_tum_ics_skin_msgs_events_PerfEvalDataStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_skin_msgs_events
{

  class PerfEvalDataStatistics : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _totalProxChange_type;
      _totalProxChange_type totalProxChange;
      typedef float _totalForceChange_type;
      _totalForceChange_type totalForceChange;
      typedef float _totalAccChange_type;
      _totalAccChange_type totalAccChange;
      typedef int32_t _numOfActiveCells_type;
      _numOfActiveCells_type numOfActiveCells;
      typedef int32_t _numOfActiveProx_type;
      _numOfActiveProx_type numOfActiveProx;
      typedef int32_t _numOfActiveForce_type;
      _numOfActiveForce_type numOfActiveForce;
      typedef int32_t _numOfActiveTemp_type;
      _numOfActiveTemp_type numOfActiveTemp;

    PerfEvalDataStatistics():
      header(),
      totalProxChange(0),
      totalForceChange(0),
      totalAccChange(0),
      numOfActiveCells(0),
      numOfActiveProx(0),
      numOfActiveForce(0),
      numOfActiveTemp(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->totalProxChange);
      offset += serializeAvrFloat64(outbuffer + offset, this->totalForceChange);
      offset += serializeAvrFloat64(outbuffer + offset, this->totalAccChange);
      union {
        int32_t real;
        uint32_t base;
      } u_numOfActiveCells;
      u_numOfActiveCells.real = this->numOfActiveCells;
      *(outbuffer + offset + 0) = (u_numOfActiveCells.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_numOfActiveCells.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_numOfActiveCells.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_numOfActiveCells.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->numOfActiveCells);
      union {
        int32_t real;
        uint32_t base;
      } u_numOfActiveProx;
      u_numOfActiveProx.real = this->numOfActiveProx;
      *(outbuffer + offset + 0) = (u_numOfActiveProx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_numOfActiveProx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_numOfActiveProx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_numOfActiveProx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->numOfActiveProx);
      union {
        int32_t real;
        uint32_t base;
      } u_numOfActiveForce;
      u_numOfActiveForce.real = this->numOfActiveForce;
      *(outbuffer + offset + 0) = (u_numOfActiveForce.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_numOfActiveForce.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_numOfActiveForce.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_numOfActiveForce.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->numOfActiveForce);
      union {
        int32_t real;
        uint32_t base;
      } u_numOfActiveTemp;
      u_numOfActiveTemp.real = this->numOfActiveTemp;
      *(outbuffer + offset + 0) = (u_numOfActiveTemp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_numOfActiveTemp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_numOfActiveTemp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_numOfActiveTemp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->numOfActiveTemp);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->totalProxChange));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->totalForceChange));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->totalAccChange));
      union {
        int32_t real;
        uint32_t base;
      } u_numOfActiveCells;
      u_numOfActiveCells.base = 0;
      u_numOfActiveCells.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_numOfActiveCells.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_numOfActiveCells.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_numOfActiveCells.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->numOfActiveCells = u_numOfActiveCells.real;
      offset += sizeof(this->numOfActiveCells);
      union {
        int32_t real;
        uint32_t base;
      } u_numOfActiveProx;
      u_numOfActiveProx.base = 0;
      u_numOfActiveProx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_numOfActiveProx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_numOfActiveProx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_numOfActiveProx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->numOfActiveProx = u_numOfActiveProx.real;
      offset += sizeof(this->numOfActiveProx);
      union {
        int32_t real;
        uint32_t base;
      } u_numOfActiveForce;
      u_numOfActiveForce.base = 0;
      u_numOfActiveForce.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_numOfActiveForce.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_numOfActiveForce.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_numOfActiveForce.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->numOfActiveForce = u_numOfActiveForce.real;
      offset += sizeof(this->numOfActiveForce);
      union {
        int32_t real;
        uint32_t base;
      } u_numOfActiveTemp;
      u_numOfActiveTemp.base = 0;
      u_numOfActiveTemp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_numOfActiveTemp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_numOfActiveTemp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_numOfActiveTemp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->numOfActiveTemp = u_numOfActiveTemp.real;
      offset += sizeof(this->numOfActiveTemp);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs_events/PerfEvalDataStatistics"; };
    virtual const char * getMD5() override { return "092d180319a614fafa11b60c3138696a"; };

  };

}
#endif
