#ifndef _ROS_tum_ics_skin_msgs_events_SkinCellEventFlagsArray_h
#define _ROS_tum_ics_skin_msgs_events_SkinCellEventFlagsArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs_events/SkinCellEventFlags.h"

namespace tum_ics_skin_msgs_events
{

  class SkinCellEventFlagsArray : public ros::Msg
  {
    public:
      uint32_t flag_length;
      typedef tum_ics_skin_msgs_events::SkinCellEventFlags _flag_type;
      _flag_type st_flag;
      _flag_type * flag;

    SkinCellEventFlagsArray():
      flag_length(0), st_flag(), flag(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->flag_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flag_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->flag_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->flag_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flag_length);
      for( uint32_t i = 0; i < flag_length; i++){
      offset += this->flag[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t flag_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      flag_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      flag_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      flag_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->flag_length);
      if(flag_lengthT > flag_length)
        this->flag = (tum_ics_skin_msgs_events::SkinCellEventFlags*)realloc(this->flag, flag_lengthT * sizeof(tum_ics_skin_msgs_events::SkinCellEventFlags));
      flag_length = flag_lengthT;
      for( uint32_t i = 0; i < flag_length; i++){
      offset += this->st_flag.deserialize(inbuffer + offset);
        memcpy( &(this->flag[i]), &(this->st_flag), sizeof(tum_ics_skin_msgs_events::SkinCellEventFlags));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs_events/SkinCellEventFlagsArray"; };
    virtual const char * getMD5() override { return "077697284c2c1b5c7b4e7242a612d6a0"; };

  };

}
#endif
