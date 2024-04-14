#ifndef _ROS_tum_ics_lacquey_gripper_msgs_GripperState_h
#define _ROS_tum_ics_lacquey_gripper_msgs_GripperState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_lacquey_gripper_msgs
{

  class GripperState : public ros::Msg
  {
    public:
      typedef const char* _state_type;
      _state_type state;
      typedef int64_t _stateId_type;
      _stateId_type stateId;

    GripperState():
      state(""),
      stateId(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_state = strlen(this->state);
      varToArr(outbuffer + offset, length_state);
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_state);
      offset += length_state;
      union {
        int64_t real;
        uint64_t base;
      } u_stateId;
      u_stateId.real = this->stateId;
      *(outbuffer + offset + 0) = (u_stateId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stateId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stateId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stateId.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_stateId.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_stateId.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_stateId.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_stateId.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->stateId);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_state;
      arrToVar(length_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state-1]=0;
      this->state = (char *)(inbuffer + offset-1);
      offset += length_state;
      union {
        int64_t real;
        uint64_t base;
      } u_stateId;
      u_stateId.base = 0;
      u_stateId.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stateId.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stateId.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stateId.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_stateId.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_stateId.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_stateId.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_stateId.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->stateId = u_stateId.real;
      offset += sizeof(this->stateId);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_lacquey_gripper_msgs/GripperState"; };
    virtual const char * getMD5() override { return "6806ba1ebf38d757b7a04e49116d3b97"; };

  };

}
#endif
