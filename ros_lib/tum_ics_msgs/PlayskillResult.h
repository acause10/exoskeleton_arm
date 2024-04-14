#ifndef _ROS_tum_ics_msgs_PlayskillResult_h
#define _ROS_tum_ics_msgs_PlayskillResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_msgs
{

  class PlayskillResult : public ros::Msg
  {
    public:
      typedef int32_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _result_string_type;
      _result_string_type result_string;

    PlayskillResult():
      result_code(0),
      result_string("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_result_code;
      u_result_code.real = this->result_code;
      *(outbuffer + offset + 0) = (u_result_code.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_result_code.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_result_code.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_result_code.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->result_code);
      uint32_t length_result_string = strlen(this->result_string);
      varToArr(outbuffer + offset, length_result_string);
      offset += 4;
      memcpy(outbuffer + offset, this->result_string, length_result_string);
      offset += length_result_string;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_result_code;
      u_result_code.base = 0;
      u_result_code.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_result_code.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_result_code.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_result_code.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->result_code = u_result_code.real;
      offset += sizeof(this->result_code);
      uint32_t length_result_string;
      arrToVar(length_result_string, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_result_string; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_result_string-1]=0;
      this->result_string = (char *)(inbuffer + offset-1);
      offset += length_result_string;
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_msgs/PlayskillResult"; };
    virtual const char * getMD5() override { return "ace4f2d8372b898059142bfee89f2af2"; };

  };

}
#endif
