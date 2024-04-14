#ifndef _ROS_SERVICE_createSkinCellEventPub_h
#define _ROS_SERVICE_createSkinCellEventPub_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs_events/SkinCellEventConfig.h"

namespace tum_ics_skin_msgs_events
{

static const char CREATESKINCELLEVENTPUB[] = "tum_ics_skin_msgs_events/createSkinCellEventPub";

  class createSkinCellEventPubRequest : public ros::Msg
  {
    public:
      typedef const char* _topicName_type;
      _topicName_type topicName;
      uint32_t event_length;
      typedef tum_ics_skin_msgs_events::SkinCellEventConfig _event_type;
      _event_type st_event;
      _event_type * event;

    createSkinCellEventPubRequest():
      topicName(""),
      event_length(0), st_event(), event(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_topicName = strlen(this->topicName);
      varToArr(outbuffer + offset, length_topicName);
      offset += 4;
      memcpy(outbuffer + offset, this->topicName, length_topicName);
      offset += length_topicName;
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
      uint32_t length_topicName;
      arrToVar(length_topicName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topicName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topicName-1]=0;
      this->topicName = (char *)(inbuffer + offset-1);
      offset += length_topicName;
      uint32_t event_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      event_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      event_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      event_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->event_length);
      if(event_lengthT > event_length)
        this->event = (tum_ics_skin_msgs_events::SkinCellEventConfig*)realloc(this->event, event_lengthT * sizeof(tum_ics_skin_msgs_events::SkinCellEventConfig));
      event_length = event_lengthT;
      for( uint32_t i = 0; i < event_length; i++){
      offset += this->st_event.deserialize(inbuffer + offset);
        memcpy( &(this->event[i]), &(this->st_event), sizeof(tum_ics_skin_msgs_events::SkinCellEventConfig));
      }
     return offset;
    }

    virtual const char * getType() override { return CREATESKINCELLEVENTPUB; };
    virtual const char * getMD5() override { return "0bbcd958de31e55301446e13c927a34f"; };

  };

  class createSkinCellEventPubResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    createSkinCellEventPubResponse():
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

    virtual const char * getType() override { return CREATESKINCELLEVENTPUB; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class createSkinCellEventPub {
    public:
    typedef createSkinCellEventPubRequest Request;
    typedef createSkinCellEventPubResponse Response;
  };

}
#endif
