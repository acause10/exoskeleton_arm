#ifndef _ROS_SERVICE_GetActiveSkill_h
#define _ROS_SERVICE_GetActiveSkill_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_msgs
{

static const char GETACTIVESKILL[] = "tum_ics_msgs/GetActiveSkill";

  class GetActiveSkillRequest : public ros::Msg
  {
    public:

    GetActiveSkillRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return GETACTIVESKILL; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetActiveSkillResponse : public ros::Msg
  {
    public:
      typedef const char* _skill_name_type;
      _skill_name_type skill_name;

    GetActiveSkillResponse():
      skill_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_skill_name = strlen(this->skill_name);
      varToArr(outbuffer + offset, length_skill_name);
      offset += 4;
      memcpy(outbuffer + offset, this->skill_name, length_skill_name);
      offset += length_skill_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_skill_name;
      arrToVar(length_skill_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_skill_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_skill_name-1]=0;
      this->skill_name = (char *)(inbuffer + offset-1);
      offset += length_skill_name;
     return offset;
    }

    virtual const char * getType() override { return GETACTIVESKILL; };
    virtual const char * getMD5() override { return "4ffbe25d06b46942798f323de2c082e0"; };

  };

  class GetActiveSkill {
    public:
    typedef GetActiveSkillRequest Request;
    typedef GetActiveSkillResponse Response;
  };

}
#endif
