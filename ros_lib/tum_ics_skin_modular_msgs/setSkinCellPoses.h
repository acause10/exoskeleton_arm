#ifndef _ROS_SERVICE_setSkinCellPoses_h
#define _ROS_SERVICE_setSkinCellPoses_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_modular_msgs/SkinCellPose.h"

namespace tum_ics_skin_modular_msgs
{

static const char SETSKINCELLPOSES[] = "tum_ics_skin_modular_msgs/setSkinCellPoses";

  class setSkinCellPosesRequest : public ros::Msg
  {
    public:
      uint32_t pose_length;
      typedef tum_ics_skin_modular_msgs::SkinCellPose _pose_type;
      _pose_type st_pose;
      _pose_type * pose;

    setSkinCellPosesRequest():
      pose_length(0), st_pose(), pose(nullptr)
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
      offset += this->pose[i].serialize(outbuffer + offset);
      }
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
        this->pose = (tum_ics_skin_modular_msgs::SkinCellPose*)realloc(this->pose, pose_lengthT * sizeof(tum_ics_skin_modular_msgs::SkinCellPose));
      pose_length = pose_lengthT;
      for( uint32_t i = 0; i < pose_length; i++){
      offset += this->st_pose.deserialize(inbuffer + offset);
        memcpy( &(this->pose[i]), &(this->st_pose), sizeof(tum_ics_skin_modular_msgs::SkinCellPose));
      }
     return offset;
    }

    virtual const char * getType() override { return SETSKINCELLPOSES; };
    virtual const char * getMD5() override { return "ca3384c9c15a911ca8aa4adb0a97dff3"; };

  };

  class setSkinCellPosesResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    setSkinCellPosesResponse():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    virtual const char * getType() override { return SETSKINCELLPOSES; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class setSkinCellPoses {
    public:
    typedef setSkinCellPosesRequest Request;
    typedef setSkinCellPosesResponse Response;
  };

}
#endif
