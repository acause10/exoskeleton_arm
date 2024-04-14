#ifndef _ROS_tum_ics_skin_msgs_events_SkinCellEventValueArray_h
#define _ROS_tum_ics_skin_msgs_events_SkinCellEventValueArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs_events/SkinCellEventValue.h"

namespace tum_ics_skin_msgs_events
{

  class SkinCellEventValueArray : public ros::Msg
  {
    public:
      uint32_t event_length;
      typedef tum_ics_skin_msgs_events::SkinCellEventValue _event_type;
      _event_type st_event;
      _event_type * event;

    SkinCellEventValueArray():
      event_length(0), st_event(), event(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->event_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->event_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->event_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->event_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->event_length);
      for( uint32_t i = 0; i < event_length; i++){
      offset += this->event[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t event_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      event_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      event_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      event_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->event_length);
      if(event_lengthT > event_length)
        this->event = (tum_ics_skin_msgs_events::SkinCellEventValue*)realloc(this->event, event_lengthT * sizeof(tum_ics_skin_msgs_events::SkinCellEventValue));
      event_length = event_lengthT;
      for( uint32_t i = 0; i < event_length; i++){
      offset += this->st_event.deserialize(inbuffer + offset);
        memcpy( &(this->event[i]), &(this->st_event), sizeof(tum_ics_skin_msgs_events::SkinCellEventValue));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs_events/SkinCellEventValueArray"; };
    virtual const char * getMD5() override { return "7d94d217e899c6fdebebf431cc399fef"; };

  };

}
#endif
