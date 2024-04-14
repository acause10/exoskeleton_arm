#ifndef _ROS_SERVICE_PlaySkill_h
#define _ROS_SERVICE_PlaySkill_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_msgs
{

static const char PLAYSKILL[] = "tum_ics_msgs/PlaySkill";

  class PlaySkillRequest : public ros::Msg
  {
    public:
      typedef const char* _skill_id_type;
      _skill_id_type skill_id;
      float pose_d[6];
      typedef float _duration_type;
      _duration_type duration;

    PlaySkillRequest():
      skill_id(""),
      pose_d(),
      duration(0)
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
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->pose_d[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->duration);
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
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pose_d[i]));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->duration));
     return offset;
    }

    virtual const char * getType() override { return PLAYSKILL; };
    virtual const char * getMD5() override { return "5c8c7bde8cd51adb4b665e1d13f1b7b3"; };

  };

  class PlaySkillResponse : public ros::Msg
  {
    public:
      typedef int32_t _request_result_id_type;
      _request_result_id_type request_result_id;
      typedef const char* _request_result_label_type;
      _request_result_label_type request_result_label;

    PlaySkillResponse():
      request_result_id(0),
      request_result_label("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_request_result_id;
      u_request_result_id.real = this->request_result_id;
      *(outbuffer + offset + 0) = (u_request_result_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_request_result_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_request_result_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_request_result_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->request_result_id);
      uint32_t length_request_result_label = strlen(this->request_result_label);
      varToArr(outbuffer + offset, length_request_result_label);
      offset += 4;
      memcpy(outbuffer + offset, this->request_result_label, length_request_result_label);
      offset += length_request_result_label;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_request_result_id;
      u_request_result_id.base = 0;
      u_request_result_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_request_result_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_request_result_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_request_result_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->request_result_id = u_request_result_id.real;
      offset += sizeof(this->request_result_id);
      uint32_t length_request_result_label;
      arrToVar(length_request_result_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_request_result_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_request_result_label-1]=0;
      this->request_result_label = (char *)(inbuffer + offset-1);
      offset += length_request_result_label;
     return offset;
    }

    virtual const char * getType() override { return PLAYSKILL; };
    virtual const char * getMD5() override { return "ce9d42c08c5914bf6fe334c461764887"; };

  };

  class PlaySkill {
    public:
    typedef PlaySkillRequest Request;
    typedef PlaySkillResponse Response;
  };

}
#endif
