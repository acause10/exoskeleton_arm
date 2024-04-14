#ifndef _ROS_SERVICE_getSkinCellEventFlags_h
#define _ROS_SERVICE_getSkinCellEventFlags_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs_events/SkinCellEventFlags.h"

namespace tum_ics_skin_msgs_events
{

static const char GETSKINCELLEVENTFLAGS[] = "tum_ics_skin_msgs_events/getSkinCellEventFlags";

  class getSkinCellEventFlagsRequest : public ros::Msg
  {
    public:
      uint32_t cellId_length;
      typedef int32_t _cellId_type;
      _cellId_type st_cellId;
      _cellId_type * cellId;

    getSkinCellEventFlagsRequest():
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

    virtual const char * getType() override { return GETSKINCELLEVENTFLAGS; };
    virtual const char * getMD5() override { return "33b509be697fb1a069fccba656762bcc"; };

  };

  class getSkinCellEventFlagsResponse : public ros::Msg
  {
    public:
      uint32_t flags_length;
      typedef tum_ics_skin_msgs_events::SkinCellEventFlags _flags_type;
      _flags_type st_flags;
      _flags_type * flags;
      typedef bool _ok_type;
      _ok_type ok;

    getSkinCellEventFlagsResponse():
      flags_length(0), st_flags(), flags(nullptr),
      ok(0)
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

    virtual const char * getType() override { return GETSKINCELLEVENTFLAGS; };
    virtual const char * getMD5() override { return "62ef5442de0530769f72f98970ead7c5"; };

  };

  class getSkinCellEventFlags {
    public:
    typedef getSkinCellEventFlagsRequest Request;
    typedef getSkinCellEventFlagsResponse Response;
  };

}
#endif
