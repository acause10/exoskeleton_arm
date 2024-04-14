#ifndef _ROS_SERVICE_enableSkinCellEventPub_h
#define _ROS_SERVICE_enableSkinCellEventPub_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs_events
{

static const char ENABLESKINCELLEVENTPUB[] = "tum_ics_skin_msgs_events/enableSkinCellEventPub";

  class enableSkinCellEventPubRequest : public ros::Msg
  {
    public:
      typedef const char* _topicName_type;
      _topicName_type topicName;
      typedef bool _enable_type;
      _enable_type enable;

    enableSkinCellEventPubRequest():
      topicName(""),
      enable(0)
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
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.real = this->enable;
      *(outbuffer + offset + 0) = (u_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable);
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
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.base = 0;
      u_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable = u_enable.real;
      offset += sizeof(this->enable);
     return offset;
    }

    virtual const char * getType() override { return ENABLESKINCELLEVENTPUB; };
    virtual const char * getMD5() override { return "67fd202f5483585e8c48ee512a52e9aa"; };

  };

  class enableSkinCellEventPubResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    enableSkinCellEventPubResponse():
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

    virtual const char * getType() override { return ENABLESKINCELLEVENTPUB; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class enableSkinCellEventPub {
    public:
    typedef enableSkinCellEventPubRequest Request;
    typedef enableSkinCellEventPubResponse Response;
  };

}
#endif
