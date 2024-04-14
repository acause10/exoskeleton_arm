#ifndef _ROS_SERVICE_getGripperState_h
#define _ROS_SERVICE_getGripperState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_lacquey_gripper_msgs
{

static const char GETGRIPPERSTATE[] = "tum_ics_lacquey_gripper_msgs/getGripperState";

  class getGripperStateRequest : public ros::Msg
  {
    public:

    getGripperStateRequest()
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

    virtual const char * getType() override { return GETGRIPPERSTATE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class getGripperStateResponse : public ros::Msg
  {
    public:
      uint32_t states_length;
      typedef char* _states_type;
      _states_type st_states;
      _states_type * states;
      typedef const char* _currentState_type;
      _currentState_type currentState;

    getGripperStateResponse():
      states_length(0), st_states(), states(nullptr),
      currentState("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->states_length);
      for( uint32_t i = 0; i < states_length; i++){
      uint32_t length_statesi = strlen(this->states[i]);
      varToArr(outbuffer + offset, length_statesi);
      offset += 4;
      memcpy(outbuffer + offset, this->states[i], length_statesi);
      offset += length_statesi;
      }
      uint32_t length_currentState = strlen(this->currentState);
      varToArr(outbuffer + offset, length_currentState);
      offset += 4;
      memcpy(outbuffer + offset, this->currentState, length_currentState);
      offset += length_currentState;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->states_length);
      if(states_lengthT > states_length)
        this->states = (char**)realloc(this->states, states_lengthT * sizeof(char*));
      states_length = states_lengthT;
      for( uint32_t i = 0; i < states_length; i++){
      uint32_t length_st_states;
      arrToVar(length_st_states, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_states; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_states-1]=0;
      this->st_states = (char *)(inbuffer + offset-1);
      offset += length_st_states;
        memcpy( &(this->states[i]), &(this->st_states), sizeof(char*));
      }
      uint32_t length_currentState;
      arrToVar(length_currentState, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_currentState; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_currentState-1]=0;
      this->currentState = (char *)(inbuffer + offset-1);
      offset += length_currentState;
     return offset;
    }

    virtual const char * getType() override { return GETGRIPPERSTATE; };
    virtual const char * getMD5() override { return "ff0be24d823aa1cfde92641488f9e02a"; };

  };

  class getGripperState {
    public:
    typedef getGripperStateRequest Request;
    typedef getGripperStateResponse Response;
  };

}
#endif
