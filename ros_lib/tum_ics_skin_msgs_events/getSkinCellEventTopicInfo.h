#ifndef _ROS_SERVICE_getSkinCellEventTopicInfo_h
#define _ROS_SERVICE_getSkinCellEventTopicInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs_events/SkinCellEventConfigArray.h"

namespace tum_ics_skin_msgs_events
{

static const char GETSKINCELLEVENTTOPICINFO[] = "tum_ics_skin_msgs_events/getSkinCellEventTopicInfo";

  class getSkinCellEventTopicInfoRequest : public ros::Msg
  {
    public:
      typedef const char* _topicName_type;
      _topicName_type topicName;

    getSkinCellEventTopicInfoRequest():
      topicName("")
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
     return offset;
    }

    virtual const char * getType() override { return GETSKINCELLEVENTTOPICINFO; };
    virtual const char * getMD5() override { return "74b3306276d42621c8d9905fba018178"; };

  };

  class getSkinCellEventTopicInfoResponse : public ros::Msg
  {
    public:
      typedef tum_ics_skin_msgs_events::SkinCellEventConfigArray _events_type;
      _events_type events;
      typedef bool _ok_type;
      _ok_type ok;

    getSkinCellEventTopicInfoResponse():
      events(),
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->events.serialize(outbuffer + offset);
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
      offset += this->events.deserialize(inbuffer + offset);
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

    virtual const char * getType() override { return GETSKINCELLEVENTTOPICINFO; };
    virtual const char * getMD5() override { return "cfbd96d8072551c97c7692b03e47686d"; };

  };

  class getSkinCellEventTopicInfo {
    public:
    typedef getSkinCellEventTopicInfoRequest Request;
    typedef getSkinCellEventTopicInfoResponse Response;
  };

}
#endif
