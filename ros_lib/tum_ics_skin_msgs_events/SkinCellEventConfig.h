#ifndef _ROS_tum_ics_skin_msgs_events_SkinCellEventConfig_h
#define _ROS_tum_ics_skin_msgs_events_SkinCellEventConfig_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs_events/EventType.h"

namespace tum_ics_skin_msgs_events
{

  class SkinCellEventConfig : public ros::Msg
  {
    public:
      typedef int32_t _cellId_type;
      _cellId_type cellId;
      uint32_t type_length;
      typedef tum_ics_skin_msgs_events::EventType _type_type;
      _type_type st_type;
      _type_type * type;

    SkinCellEventConfig():
      cellId(0),
      type_length(0), st_type(), type(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_cellId;
      u_cellId.real = this->cellId;
      *(outbuffer + offset + 0) = (u_cellId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cellId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cellId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cellId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cellId);
      *(outbuffer + offset + 0) = (this->type_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->type_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->type_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type_length);
      for( uint32_t i = 0; i < type_length; i++){
      offset += this->type[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_cellId;
      u_cellId.base = 0;
      u_cellId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cellId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cellId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cellId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cellId = u_cellId.real;
      offset += sizeof(this->cellId);
      uint32_t type_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      type_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      type_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      type_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->type_length);
      if(type_lengthT > type_length)
        this->type = (tum_ics_skin_msgs_events::EventType*)realloc(this->type, type_lengthT * sizeof(tum_ics_skin_msgs_events::EventType));
      type_length = type_lengthT;
      for( uint32_t i = 0; i < type_length; i++){
      offset += this->st_type.deserialize(inbuffer + offset);
        memcpy( &(this->type[i]), &(this->st_type), sizeof(tum_ics_skin_msgs_events::EventType));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs_events/SkinCellEventConfig"; };
    virtual const char * getMD5() override { return "5041033989c26cca5e5e7910fac4cb25"; };

  };

}
#endif
