#ifndef _ROS_tum_ics_msgs_PlayskillGoal_h
#define _ROS_tum_ics_msgs_PlayskillGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_msgs
{

  class PlayskillGoal : public ros::Msg
  {
    public:
      typedef int32_t _skill_id_type;
      _skill_id_type skill_id;
      uint32_t pose_d_length;
      typedef float _pose_d_type;
      _pose_d_type st_pose_d;
      _pose_d_type * pose_d;
      uint32_t velocity_d_length;
      typedef float _velocity_d_type;
      _velocity_d_type st_velocity_d;
      _velocity_d_type * velocity_d;
      uint32_t duration_length;
      typedef float _duration_type;
      _duration_type st_duration;
      _duration_type * duration;
      typedef int32_t _priority_type;
      _priority_type priority;
      uint32_t special_flags_length;
      typedef int32_t _special_flags_type;
      _special_flags_type st_special_flags;
      _special_flags_type * special_flags;

    PlayskillGoal():
      skill_id(0),
      pose_d_length(0), st_pose_d(), pose_d(nullptr),
      velocity_d_length(0), st_velocity_d(), velocity_d(nullptr),
      duration_length(0), st_duration(), duration(nullptr),
      priority(0),
      special_flags_length(0), st_special_flags(), special_flags(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_skill_id;
      u_skill_id.real = this->skill_id;
      *(outbuffer + offset + 0) = (u_skill_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_skill_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_skill_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_skill_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->skill_id);
      *(outbuffer + offset + 0) = (this->pose_d_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pose_d_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pose_d_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pose_d_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose_d_length);
      for( uint32_t i = 0; i < pose_d_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->pose_d[i]);
      }
      *(outbuffer + offset + 0) = (this->velocity_d_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity_d_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocity_d_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocity_d_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_d_length);
      for( uint32_t i = 0; i < velocity_d_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity_d[i]);
      }
      *(outbuffer + offset + 0) = (this->duration_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration_length);
      for( uint32_t i = 0; i < duration_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->duration[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_priority;
      u_priority.real = this->priority;
      *(outbuffer + offset + 0) = (u_priority.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_priority.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_priority.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_priority.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->priority);
      *(outbuffer + offset + 0) = (this->special_flags_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->special_flags_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->special_flags_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->special_flags_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->special_flags_length);
      for( uint32_t i = 0; i < special_flags_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_special_flagsi;
      u_special_flagsi.real = this->special_flags[i];
      *(outbuffer + offset + 0) = (u_special_flagsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_special_flagsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_special_flagsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_special_flagsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->special_flags[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_skill_id;
      u_skill_id.base = 0;
      u_skill_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_skill_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_skill_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_skill_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->skill_id = u_skill_id.real;
      offset += sizeof(this->skill_id);
      uint32_t pose_d_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pose_d_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pose_d_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pose_d_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pose_d_length);
      if(pose_d_lengthT > pose_d_length)
        this->pose_d = (float*)realloc(this->pose_d, pose_d_lengthT * sizeof(float));
      pose_d_length = pose_d_lengthT;
      for( uint32_t i = 0; i < pose_d_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_pose_d));
        memcpy( &(this->pose_d[i]), &(this->st_pose_d), sizeof(float));
      }
      uint32_t velocity_d_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocity_d_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocity_d_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocity_d_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocity_d_length);
      if(velocity_d_lengthT > velocity_d_length)
        this->velocity_d = (float*)realloc(this->velocity_d, velocity_d_lengthT * sizeof(float));
      velocity_d_length = velocity_d_lengthT;
      for( uint32_t i = 0; i < velocity_d_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_velocity_d));
        memcpy( &(this->velocity_d[i]), &(this->st_velocity_d), sizeof(float));
      }
      uint32_t duration_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      duration_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      duration_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      duration_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->duration_length);
      if(duration_lengthT > duration_length)
        this->duration = (float*)realloc(this->duration, duration_lengthT * sizeof(float));
      duration_length = duration_lengthT;
      for( uint32_t i = 0; i < duration_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_duration));
        memcpy( &(this->duration[i]), &(this->st_duration), sizeof(float));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_priority;
      u_priority.base = 0;
      u_priority.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_priority.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_priority.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_priority.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->priority = u_priority.real;
      offset += sizeof(this->priority);
      uint32_t special_flags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      special_flags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      special_flags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      special_flags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->special_flags_length);
      if(special_flags_lengthT > special_flags_length)
        this->special_flags = (int32_t*)realloc(this->special_flags, special_flags_lengthT * sizeof(int32_t));
      special_flags_length = special_flags_lengthT;
      for( uint32_t i = 0; i < special_flags_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_special_flags;
      u_st_special_flags.base = 0;
      u_st_special_flags.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_special_flags.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_special_flags.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_special_flags.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_special_flags = u_st_special_flags.real;
      offset += sizeof(this->st_special_flags);
        memcpy( &(this->special_flags[i]), &(this->st_special_flags), sizeof(int32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_msgs/PlayskillGoal"; };
    virtual const char * getMD5() override { return "72325cb050b7a59a957cfc95ecbc0c8e"; };

  };

}
#endif
