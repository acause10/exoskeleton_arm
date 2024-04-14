#ifndef _ROS_tum_ics_ur_robot_msgs_Special_cmd_h
#define _ROS_tum_ics_ur_robot_msgs_Special_cmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_ur_robot_msgs
{

  class Special_cmd : public ros::Msg
  {
    public:
      uint32_t s_command_types_length;
      typedef char* _s_command_types_type;
      _s_command_types_type st_s_command_types;
      _s_command_types_type * s_command_types;

    Special_cmd():
      s_command_types_length(0), st_s_command_types(), s_command_types(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->s_command_types_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->s_command_types_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->s_command_types_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->s_command_types_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->s_command_types_length);
      for( uint32_t i = 0; i < s_command_types_length; i++){
      uint32_t length_s_command_typesi = strlen(this->s_command_types[i]);
      varToArr(outbuffer + offset, length_s_command_typesi);
      offset += 4;
      memcpy(outbuffer + offset, this->s_command_types[i], length_s_command_typesi);
      offset += length_s_command_typesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t s_command_types_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      s_command_types_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      s_command_types_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      s_command_types_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->s_command_types_length);
      if(s_command_types_lengthT > s_command_types_length)
        this->s_command_types = (char**)realloc(this->s_command_types, s_command_types_lengthT * sizeof(char*));
      s_command_types_length = s_command_types_lengthT;
      for( uint32_t i = 0; i < s_command_types_length; i++){
      uint32_t length_st_s_command_types;
      arrToVar(length_st_s_command_types, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_s_command_types; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_s_command_types-1]=0;
      this->st_s_command_types = (char *)(inbuffer + offset-1);
      offset += length_st_s_command_types;
        memcpy( &(this->s_command_types[i]), &(this->st_s_command_types), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_ur_robot_msgs/Special_cmd"; };
    virtual const char * getMD5() override { return "c4d664e515ed76e74960f32caec59784"; };

  };

}
#endif
