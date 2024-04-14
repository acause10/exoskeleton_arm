#ifndef _ROS_tum_ics_msgs_ActiveSkill_h
#define _ROS_tum_ics_msgs_ActiveSkill_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_msgs
{

  class ActiveSkill : public ros::Msg
  {
    public:
      typedef const char* _skill_id_type;
      _skill_id_type skill_id;

    ActiveSkill():
      skill_id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_skill_id = strlen(this->skill_id);
      varToArr(outbuffer + offset, length_skill_id);
      offset += 4;
      memcpy(outbuffer + offset, this->skill_id, length_skill_id);
      offset += length_skill_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_skill_id;
      arrToVar(length_skill_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_skill_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_skill_id-1]=0;
      this->skill_id = (char *)(inbuffer + offset-1);
      offset += length_skill_id;
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_msgs/ActiveSkill"; };
    virtual const char * getMD5() override { return "d578921e927c6e6a448131a8e442257c"; };

  };

}
#endif
