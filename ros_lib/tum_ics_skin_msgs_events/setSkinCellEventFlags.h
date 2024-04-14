#ifndef _ROS_SERVICE_setSkinCellEventFlags_h
#define _ROS_SERVICE_setSkinCellEventFlags_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs_events/SkinCellEventFlags.h"

namespace tum_ics_skin_msgs_events
{

static const char SETSKINCELLEVENTFLAGS[] = "tum_ics_skin_msgs_events/setSkinCellEventFlags";

  class setSkinCellEventFlagsRequest : public ros::Msg
  {
    public:
      uint32_t flags_length;
      typedef tum_ics_skin_msgs_events::SkinCellEventFlags _flags_type;
      _flags_type st_flags;
      _flags_type * flags;

    setSkinCellEventFlagsRequest():
      flags_length(0), st_flags(), flags(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->flags_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flags_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->flags_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->flags_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flags_length);
      for( uint32_t i = 0; i < flags_length; i++){
      offset += this->flags[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t flags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      flags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      flags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      flags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->flags_length);
      if(flags_lengthT > flags_length)
        this->flags = (tum_ics_skin_msgs_events::SkinCellEventFlags*)realloc(this->flags, flags_lengthT * sizeof(tum_ics_skin_msgs_events::SkinCellEventFlags));
      flags_length = flags_lengthT;
      for( uint32_t i = 0; i < flags_length; i++){
      offset += this->st_flags.deserialize(inbuffer + offset);
        memcpy( &(this->flags[i]), &(this->st_flags), sizeof(tum_ics_skin_msgs_events::SkinCellEventFlags));
      }
     return offset;
    }

    virtual const char * getType() override { return SETSKINCELLEVENTFLAGS; };
    virtual const char * getMD5() override { return "706771234d417f41fc43aea23d9e4556"; };

  };

  class setSkinCellEventFlagsResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    setSkinCellEventFlagsResponse():
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

    virtual const char * getType() override { return SETSKINCELLEVENTFLAGS; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class setSkinCellEventFlags {
    public:
    typedef setSkinCellEventFlagsRequest Request;
    typedef setSkinCellEventFlagsResponse Response;
  };

}
#endif
