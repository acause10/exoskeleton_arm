#ifndef _ROS_SERVICE_setSkinCellEventThresholds_h
#define _ROS_SERVICE_setSkinCellEventThresholds_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs_events/SkinCellEventThresholds.h"

namespace tum_ics_skin_msgs_events
{

static const char SETSKINCELLEVENTTHRESHOLDS[] = "tum_ics_skin_msgs_events/setSkinCellEventThresholds";

  class setSkinCellEventThresholdsRequest : public ros::Msg
  {
    public:
      uint32_t thresholds_length;
      typedef tum_ics_skin_msgs_events::SkinCellEventThresholds _thresholds_type;
      _thresholds_type st_thresholds;
      _thresholds_type * thresholds;

    setSkinCellEventThresholdsRequest():
      thresholds_length(0), st_thresholds(), thresholds(nullptr)
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
     return offset;
    }

    virtual const char * getType() override { return SETSKINCELLEVENTTHRESHOLDS; };
    virtual const char * getMD5() override { return "bff52d2f09d4d927388661cd99a95e80"; };

  };

  class setSkinCellEventThresholdsResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    setSkinCellEventThresholdsResponse():
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

    virtual const char * getType() override { return SETSKINCELLEVENTTHRESHOLDS; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class setSkinCellEventThresholds {
    public:
    typedef setSkinCellEventThresholdsRequest Request;
    typedef setSkinCellEventThresholdsResponse Response;
  };

}
#endif
