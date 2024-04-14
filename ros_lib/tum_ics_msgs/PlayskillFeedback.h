#ifndef _ROS_tum_ics_msgs_PlayskillFeedback_h
#define _ROS_tum_ics_msgs_PlayskillFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_msgs
{

  class PlayskillFeedback : public ros::Msg
  {
    public:
      uint32_t pose_length;
      typedef float _pose_type;
      _pose_type st_pose;
      _pose_type * pose;
      uint32_t velocity_length;
      typedef float _velocity_type;
      _velocity_type st_velocity;
      _velocity_type * velocity;
      uint32_t torque_length;
      typedef float _torque_type;
      _torque_type st_torque;
      _torque_type * torque;
      uint32_t error_pose_length;
      typedef float _error_pose_type;
      _error_pose_type st_error_pose;
      _error_pose_type * error_pose;
      uint32_t error_velocity_length;
      typedef float _error_velocity_type;
      _error_velocity_type st_error_velocity;
      _error_velocity_type * error_velocity;
      typedef int32_t _action_status_type;
      _action_status_type action_status;
      typedef int32_t _current_action_type;
      _current_action_type current_action;
      typedef const char* _current_action_label_type;
      _current_action_label_type current_action_label;
      typedef int32_t _current_special_cmd_type;
      _current_special_cmd_type current_special_cmd;

    PlayskillFeedback():
      pose_length(0), st_pose(), pose(nullptr),
      velocity_length(0), st_velocity(), velocity(nullptr),
      torque_length(0), st_torque(), torque(nullptr),
      error_pose_length(0), st_error_pose(), error_pose(nullptr),
      error_velocity_length(0), st_error_velocity(), error_velocity(nullptr),
      action_status(0),
      current_action(0),
      current_action_label(""),
      current_special_cmd(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pose_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pose_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pose_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pose_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose_length);
      for( uint32_t i = 0; i < pose_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->pose[i]);
      }
      *(outbuffer + offset + 0) = (this->velocity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_length);
      for( uint32_t i = 0; i < velocity_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity[i]);
      }
      *(outbuffer + offset + 0) = (this->torque_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->torque_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->torque_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->torque_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->torque_length);
      for( uint32_t i = 0; i < torque_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->torque[i]);
      }
      *(outbuffer + offset + 0) = (this->error_pose_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->error_pose_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->error_pose_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->error_pose_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error_pose_length);
      for( uint32_t i = 0; i < error_pose_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->error_pose[i]);
      }
      *(outbuffer + offset + 0) = (this->error_velocity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->error_velocity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->error_velocity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->error_velocity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error_velocity_length);
      for( uint32_t i = 0; i < error_velocity_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->error_velocity[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_action_status;
      u_action_status.real = this->action_status;
      *(outbuffer + offset + 0) = (u_action_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_action_status.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_action_status.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_action_status.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->action_status);
      union {
        int32_t real;
        uint32_t base;
      } u_current_action;
      u_current_action.real = this->current_action;
      *(outbuffer + offset + 0) = (u_current_action.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_action.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_action.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_action.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_action);
      uint32_t length_current_action_label = strlen(this->current_action_label);
      varToArr(outbuffer + offset, length_current_action_label);
      offset += 4;
      memcpy(outbuffer + offset, this->current_action_label, length_current_action_label);
      offset += length_current_action_label;
      union {
        int32_t real;
        uint32_t base;
      } u_current_special_cmd;
      u_current_special_cmd.real = this->current_special_cmd;
      *(outbuffer + offset + 0) = (u_current_special_cmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_special_cmd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_special_cmd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_special_cmd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_special_cmd);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t pose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pose_length);
      if(pose_lengthT > pose_length)
        this->pose = (float*)realloc(this->pose, pose_lengthT * sizeof(float));
      pose_length = pose_lengthT;
      for( uint32_t i = 0; i < pose_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_pose));
        memcpy( &(this->pose[i]), &(this->st_pose), sizeof(float));
      }
      uint32_t velocity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocity_length);
      if(velocity_lengthT > velocity_length)
        this->velocity = (float*)realloc(this->velocity, velocity_lengthT * sizeof(float));
      velocity_length = velocity_lengthT;
      for( uint32_t i = 0; i < velocity_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_velocity));
        memcpy( &(this->velocity[i]), &(this->st_velocity), sizeof(float));
      }
      uint32_t torque_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      torque_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      torque_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      torque_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->torque_length);
      if(torque_lengthT > torque_length)
        this->torque = (float*)realloc(this->torque, torque_lengthT * sizeof(float));
      torque_length = torque_lengthT;
      for( uint32_t i = 0; i < torque_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_torque));
        memcpy( &(this->torque[i]), &(this->st_torque), sizeof(float));
      }
      uint32_t error_pose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      error_pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      error_pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      error_pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->error_pose_length);
      if(error_pose_lengthT > error_pose_length)
        this->error_pose = (float*)realloc(this->error_pose, error_pose_lengthT * sizeof(float));
      error_pose_length = error_pose_lengthT;
      for( uint32_t i = 0; i < error_pose_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_error_pose));
        memcpy( &(this->error_pose[i]), &(this->st_error_pose), sizeof(float));
      }
      uint32_t error_velocity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      error_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      error_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      error_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->error_velocity_length);
      if(error_velocity_lengthT > error_velocity_length)
        this->error_velocity = (float*)realloc(this->error_velocity, error_velocity_lengthT * sizeof(float));
      error_velocity_length = error_velocity_lengthT;
      for( uint32_t i = 0; i < error_velocity_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_error_velocity));
        memcpy( &(this->error_velocity[i]), &(this->st_error_velocity), sizeof(float));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_action_status;
      u_action_status.base = 0;
      u_action_status.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_action_status.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_action_status.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_action_status.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->action_status = u_action_status.real;
      offset += sizeof(this->action_status);
      union {
        int32_t real;
        uint32_t base;
      } u_current_action;
      u_current_action.base = 0;
      u_current_action.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_action.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_action.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_action.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_action = u_current_action.real;
      offset += sizeof(this->current_action);
      uint32_t length_current_action_label;
      arrToVar(length_current_action_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_current_action_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_current_action_label-1]=0;
      this->current_action_label = (char *)(inbuffer + offset-1);
      offset += length_current_action_label;
      union {
        int32_t real;
        uint32_t base;
      } u_current_special_cmd;
      u_current_special_cmd.base = 0;
      u_current_special_cmd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_special_cmd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_special_cmd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_special_cmd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_special_cmd = u_current_special_cmd.real;
      offset += sizeof(this->current_special_cmd);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_msgs/PlayskillFeedback"; };
    virtual const char * getMD5() override { return "66945826e30223231e8ea2012c3ad876"; };

  };

}
#endif
