#ifndef _ROS_SERVICE_getSkinCellEventThresholds_h
#define _ROS_SERVICE_getSkinCellEventThresholds_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs_events/SkinCellEventThresholds.h"

namespace tum_ics_skin_msgs_events
{

static const char GETSKINCELLEVENTTHRESHOLDS[] = "tum_ics_skin_msgs_events/getSkinCellEventThresholds";

  class getSkinCellEventThresholdsRequest : public ros::Msg
  {
    public:
      uint32_t cellId_length;
      typedef int32_t _cellId_type;
      _cellId_type st_cellId;
      _cellId_type * cellId;

    getSkinCellEventThresholdsRequest():
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

    virtual const char * getType() override { return GETSKINCELLEVENTTHRESHOLDS; };
    virtual const char * getMD5() override { return "33b509be697fb1a069fccba656762bcc"; };

  };

  class getSkinCellEventThresholdsResponse : public ros::Msg
  {
    public:
      uint32_t thresholds_length;
      typedef tum_ics_skin_msgs_events::SkinCellEventThresholds _thresholds_type;
      _thresholds_type st_thresholds;
      _thresholds_type * thresholds;
      typedef bool _ok_type;
      _ok_type ok;

    getSkinCellEventThresholdsResponse():
      thresholds_length(0), st_thresholds(), thresholds(nullptr),
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->thresholds_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->thresholds_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->thresholds_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->thresholds_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->thresholds_length);
      for( uint32_t i = 0; i < thresholds_length; i++){
      offset += this->thresholds[i].serialize(outbuffer + offset);
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
      uint32_t thresholds_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      thresholds_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      thresholds_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      thresholds_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->thresholds_length);
      if(thresholds_lengthT > thresholds_length)
        this->thresholds = (tum_ics_skin_msgs_events::SkinCellEventThresholds*)realloc(this->thresholds, thresholds_lengthT * sizeof(tum_ics_skin_msgs_events::SkinCellEventThresholds));
      thresholds_length = thresholds_lengthT;
      for( uint32_t i = 0; i < thresholds_length; i++){
      offset += this->st_thresholds.deserialize(inbuffer + offset);
        memcpy( &(this->thresholds[i]), &(this->st_thresholds), sizeof(tum_ics_skin_msgs_events::SkinCellEventThresholds));
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

    virtual const char * getType() override { return GETSKINCELLEVENTTHRESHOLDS; };
    virtual const char * getMD5() override { return "bbeffab8eb828b6106dcc8ae8b781f20"; };

  };

  class getSkinCellEventThresholds {
    public:
    typedef getSkinCellEventThresholdsRequest Request;
    typedef getSkinCellEventThresholdsResponse Response;
  };

}
#endif
