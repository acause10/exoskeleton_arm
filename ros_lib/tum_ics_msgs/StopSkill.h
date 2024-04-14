#ifndef _ROS_SERVICE_StopSkill_h
#define _ROS_SERVICE_StopSkill_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_msgs
{

static const char STOPSKILL[] = "tum_ics_msgs/StopSkill";

  class StopSkillRequest : public ros::Msg
  {
    public:
      typedef const char* _skill_id_type;
      _skill_id_type skill_id;
      typedef int32_t _special_command_type;
      _special_command_type special_command;

    StopSkillRequest():
      skill_id(""),
      special_command(0)
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
      union {
        int32_t real;
        uint32_t base;
      } u_special_command;
      u_special_command.real = this->special_command;
      *(outbuffer + offset + 0) = (u_special_command.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_special_command.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_special_command.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_special_command.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->special_command);
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
      union {
        int32_t real;
        uint32_t base;
      } u_special_command;
      u_special_command.base = 0;
      u_special_command.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_special_command.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_special_command.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_special_command.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->special_command = u_special_command.real;
      offset += sizeof(this->special_command);
     return offset;
    }

    virtual const char * getType() override { return STOPSKILL; };
    virtual const char * getMD5() override { return "d0c5c062e3a8d66b1691d852e7e5b1fe"; };

  };

  class StopSkillResponse : public ros::Msg
  {
    public:
      typedef int32_t _request_result_id_type;
      _request_result_id_type request_result_id;
      typedef const char* _request_result_label_type;
      _request_result_label_type request_result_label;

    StopSkillResponse():
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

    virtual const char * getType() override { return STOPSKILL; };
    virtual const char * getMD5() override { return "ce9d42c08c5914bf6fe334c461764887"; };

  };

  class StopSkill {
    public:
    typedef StopSkillRequest Request;
    typedef StopSkillResponse Response;
  };

}
#endif
