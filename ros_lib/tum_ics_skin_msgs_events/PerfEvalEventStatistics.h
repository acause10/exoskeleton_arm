#ifndef _ROS_tum_ics_skin_msgs_events_PerfEvalEventStatistics_h
#define _ROS_tum_ics_skin_msgs_events_PerfEvalEventStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_skin_msgs_events
{

  class PerfEvalEventStatistics : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _totalDataPktCnt_type;
      _totalDataPktCnt_type totalDataPktCnt;
      typedef int32_t _totalEventPktCnt_type;
      _totalEventPktCnt_type totalEventPktCnt;
      typedef int32_t _totalEventCnt_type;
      _totalEventCnt_type totalEventCnt;
      typedef int32_t _totalEventProx_type;
      _totalEventProx_type totalEventProx;
      typedef int32_t _totalEventForce_type;
      _totalEventForce_type totalEventForce;
      typedef int32_t _totalEventAcc_type;
      _totalEventAcc_type totalEventAcc;
      typedef int32_t _totalEventTemp_type;
      _totalEventTemp_type totalEventTemp;
      typedef int32_t _totalActiveCells_type;
      _totalActiveCells_type totalActiveCells;
      typedef int32_t _activeCellsProx_type;
      _activeCellsProx_type activeCellsProx;
      typedef int32_t _activeCellsForce_type;
      _activeCellsForce_type activeCellsForce;
      typedef int32_t _activeCellsAcc_type;
      _activeCellsAcc_type activeCellsAcc;
      uint32_t totalEventTypeCnt_length;
      typedef int32_t _totalEventTypeCnt_type;
      _totalEventTypeCnt_type st_totalEventTypeCnt;
      _totalEventTypeCnt_type * totalEventTypeCnt;
      uint32_t totalEventsPerPktCnt_length;
      typedef int32_t _totalEventsPerPktCnt_type;
      _totalEventsPerPktCnt_type st_totalEventsPerPktCnt;
      _totalEventsPerPktCnt_type * totalEventsPerPktCnt;

    PerfEvalEventStatistics():
      header(),
      totalDataPktCnt(0),
      totalEventPktCnt(0),
      totalEventCnt(0),
      totalEventProx(0),
      totalEventForce(0),
      totalEventAcc(0),
      totalEventTemp(0),
      totalActiveCells(0),
      activeCellsProx(0),
      activeCellsForce(0),
      activeCellsAcc(0),
      totalEventTypeCnt_length(0), st_totalEventTypeCnt(), totalEventTypeCnt(nullptr),
      totalEventsPerPktCnt_length(0), st_totalEventsPerPktCnt(), totalEventsPerPktCnt(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_totalDataPktCnt;
      u_totalDataPktCnt.real = this->totalDataPktCnt;
      *(outbuffer + offset + 0) = (u_totalDataPktCnt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_totalDataPktCnt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_totalDataPktCnt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_totalDataPktCnt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totalDataPktCnt);
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventPktCnt;
      u_totalEventPktCnt.real = this->totalEventPktCnt;
      *(outbuffer + offset + 0) = (u_totalEventPktCnt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_totalEventPktCnt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_totalEventPktCnt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_totalEventPktCnt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totalEventPktCnt);
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventCnt;
      u_totalEventCnt.real = this->totalEventCnt;
      *(outbuffer + offset + 0) = (u_totalEventCnt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_totalEventCnt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_totalEventCnt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_totalEventCnt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totalEventCnt);
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventProx;
      u_totalEventProx.real = this->totalEventProx;
      *(outbuffer + offset + 0) = (u_totalEventProx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_totalEventProx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_totalEventProx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_totalEventProx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totalEventProx);
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventForce;
      u_totalEventForce.real = this->totalEventForce;
      *(outbuffer + offset + 0) = (u_totalEventForce.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_totalEventForce.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_totalEventForce.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_totalEventForce.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totalEventForce);
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventAcc;
      u_totalEventAcc.real = this->totalEventAcc;
      *(outbuffer + offset + 0) = (u_totalEventAcc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_totalEventAcc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_totalEventAcc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_totalEventAcc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totalEventAcc);
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventTemp;
      u_totalEventTemp.real = this->totalEventTemp;
      *(outbuffer + offset + 0) = (u_totalEventTemp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_totalEventTemp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_totalEventTemp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_totalEventTemp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totalEventTemp);
      union {
        int32_t real;
        uint32_t base;
      } u_totalActiveCells;
      u_totalActiveCells.real = this->totalActiveCells;
      *(outbuffer + offset + 0) = (u_totalActiveCells.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_totalActiveCells.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_totalActiveCells.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_totalActiveCells.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totalActiveCells);
      union {
        int32_t real;
        uint32_t base;
      } u_activeCellsProx;
      u_activeCellsProx.real = this->activeCellsProx;
      *(outbuffer + offset + 0) = (u_activeCellsProx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_activeCellsProx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_activeCellsProx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_activeCellsProx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->activeCellsProx);
      union {
        int32_t real;
        uint32_t base;
      } u_activeCellsForce;
      u_activeCellsForce.real = this->activeCellsForce;
      *(outbuffer + offset + 0) = (u_activeCellsForce.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_activeCellsForce.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_activeCellsForce.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_activeCellsForce.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->activeCellsForce);
      union {
        int32_t real;
        uint32_t base;
      } u_activeCellsAcc;
      u_activeCellsAcc.real = this->activeCellsAcc;
      *(outbuffer + offset + 0) = (u_activeCellsAcc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_activeCellsAcc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_activeCellsAcc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_activeCellsAcc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->activeCellsAcc);
      *(outbuffer + offset + 0) = (this->totalEventTypeCnt_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->totalEventTypeCnt_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->totalEventTypeCnt_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->totalEventTypeCnt_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totalEventTypeCnt_length);
      for( uint32_t i = 0; i < totalEventTypeCnt_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventTypeCnti;
      u_totalEventTypeCnti.real = this->totalEventTypeCnt[i];
      *(outbuffer + offset + 0) = (u_totalEventTypeCnti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_totalEventTypeCnti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_totalEventTypeCnti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_totalEventTypeCnti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totalEventTypeCnt[i]);
      }
      *(outbuffer + offset + 0) = (this->totalEventsPerPktCnt_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->totalEventsPerPktCnt_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->totalEventsPerPktCnt_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->totalEventsPerPktCnt_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totalEventsPerPktCnt_length);
      for( uint32_t i = 0; i < totalEventsPerPktCnt_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventsPerPktCnti;
      u_totalEventsPerPktCnti.real = this->totalEventsPerPktCnt[i];
      *(outbuffer + offset + 0) = (u_totalEventsPerPktCnti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_totalEventsPerPktCnti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_totalEventsPerPktCnti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_totalEventsPerPktCnti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totalEventsPerPktCnt[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_totalDataPktCnt;
      u_totalDataPktCnt.base = 0;
      u_totalDataPktCnt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_totalDataPktCnt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_totalDataPktCnt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_totalDataPktCnt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->totalDataPktCnt = u_totalDataPktCnt.real;
      offset += sizeof(this->totalDataPktCnt);
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventPktCnt;
      u_totalEventPktCnt.base = 0;
      u_totalEventPktCnt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_totalEventPktCnt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_totalEventPktCnt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_totalEventPktCnt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->totalEventPktCnt = u_totalEventPktCnt.real;
      offset += sizeof(this->totalEventPktCnt);
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventCnt;
      u_totalEventCnt.base = 0;
      u_totalEventCnt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_totalEventCnt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_totalEventCnt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_totalEventCnt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->totalEventCnt = u_totalEventCnt.real;
      offset += sizeof(this->totalEventCnt);
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventProx;
      u_totalEventProx.base = 0;
      u_totalEventProx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_totalEventProx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_totalEventProx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_totalEventProx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->totalEventProx = u_totalEventProx.real;
      offset += sizeof(this->totalEventProx);
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventForce;
      u_totalEventForce.base = 0;
      u_totalEventForce.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_totalEventForce.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_totalEventForce.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_totalEventForce.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->totalEventForce = u_totalEventForce.real;
      offset += sizeof(this->totalEventForce);
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventAcc;
      u_totalEventAcc.base = 0;
      u_totalEventAcc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_totalEventAcc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_totalEventAcc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_totalEventAcc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->totalEventAcc = u_totalEventAcc.real;
      offset += sizeof(this->totalEventAcc);
      union {
        int32_t real;
        uint32_t base;
      } u_totalEventTemp;
      u_totalEventTemp.base = 0;
      u_totalEventTemp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_totalEventTemp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_totalEventTemp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_totalEventTemp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->totalEventTemp = u_totalEventTemp.real;
      offset += sizeof(this->totalEventTemp);
      union {
        int32_t real;
        uint32_t base;
      } u_totalActiveCells;
      u_totalActiveCells.base = 0;
      u_totalActiveCells.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_totalActiveCells.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_totalActiveCells.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_totalActiveCells.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->totalActiveCells = u_totalActiveCells.real;
      offset += sizeof(this->totalActiveCells);
      union {
        int32_t real;
        uint32_t base;
      } u_activeCellsProx;
      u_activeCellsProx.base = 0;
      u_activeCellsProx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_activeCellsProx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_activeCellsProx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_activeCellsProx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->activeCellsProx = u_activeCellsProx.real;
      offset += sizeof(this->activeCellsProx);
      union {
        int32_t real;
        uint32_t base;
      } u_activeCellsForce;
      u_activeCellsForce.base = 0;
      u_activeCellsForce.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_activeCellsForce.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_activeCellsForce.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_activeCellsForce.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->activeCellsForce = u_activeCellsForce.real;
      offset += sizeof(this->activeCellsForce);
      union {
        int32_t real;
        uint32_t base;
      } u_activeCellsAcc;
      u_activeCellsAcc.base = 0;
      u_activeCellsAcc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_activeCellsAcc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_activeCellsAcc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_activeCellsAcc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->activeCellsAcc = u_activeCellsAcc.real;
      offset += sizeof(this->activeCellsAcc);
      uint32_t totalEventTypeCnt_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      totalEventTypeCnt_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      totalEventTypeCnt_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      totalEventTypeCnt_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->totalEventTypeCnt_length);
      if(totalEventTypeCnt_lengthT > totalEventTypeCnt_length)
        this->totalEventTypeCnt = (int32_t*)realloc(this->totalEventTypeCnt, totalEventTypeCnt_lengthT * sizeof(int32_t));
      totalEventTypeCnt_length = totalEventTypeCnt_lengthT;
      for( uint32_t i = 0; i < totalEventTypeCnt_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_totalEventTypeCnt;
      u_st_totalEventTypeCnt.base = 0;
      u_st_totalEventTypeCnt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_totalEventTypeCnt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_totalEventTypeCnt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_totalEventTypeCnt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_totalEventTypeCnt = u_st_totalEventTypeCnt.real;
      offset += sizeof(this->st_totalEventTypeCnt);
        memcpy( &(this->totalEventTypeCnt[i]), &(this->st_totalEventTypeCnt), sizeof(int32_t));
      }
      uint32_t totalEventsPerPktCnt_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      totalEventsPerPktCnt_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      totalEventsPerPktCnt_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      totalEventsPerPktCnt_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->totalEventsPerPktCnt_length);
      if(totalEventsPerPktCnt_lengthT > totalEventsPerPktCnt_length)
        this->totalEventsPerPktCnt = (int32_t*)realloc(this->totalEventsPerPktCnt, totalEventsPerPktCnt_lengthT * sizeof(int32_t));
      totalEventsPerPktCnt_length = totalEventsPerPktCnt_lengthT;
      for( uint32_t i = 0; i < totalEventsPerPktCnt_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_totalEventsPerPktCnt;
      u_st_totalEventsPerPktCnt.base = 0;
      u_st_totalEventsPerPktCnt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_totalEventsPerPktCnt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_totalEventsPerPktCnt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_totalEventsPerPktCnt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_totalEventsPerPktCnt = u_st_totalEventsPerPktCnt.real;
      offset += sizeof(this->st_totalEventsPerPktCnt);
        memcpy( &(this->totalEventsPerPktCnt[i]), &(this->st_totalEventsPerPktCnt), sizeof(int32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs_events/PerfEvalEventStatistics"; };
    virtual const char * getMD5() override { return "cc8b37dc8b5bc05b6eaae7e4085267fa"; };

  };

}
#endif
