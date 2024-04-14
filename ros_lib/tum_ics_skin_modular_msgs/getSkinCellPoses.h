#ifndef _ROS_SERVICE_getSkinCellPoses_h
#define _ROS_SERVICE_getSkinCellPoses_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_modular_msgs/SkinCellPose.h"

namespace tum_ics_skin_modular_msgs
{

static const char GETSKINCELLPOSES[] = "tum_ics_skin_modular_msgs/getSkinCellPoses";

  class getSkinCellPosesRequest : public ros::Msg
  {
    public:
      uint32_t cellId_length;
      typedef int32_t _cellId_type;
      _cellId_type st_cellId;
      _cellId_type * cellId;

    getSkinCellPosesRequest():
      cellId_length(0), st_cellId(), cellId(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->cellId_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cellId_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cellId_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cellId_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cellId_length);
      for( uint32_t i = 0; i < cellId_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_cellIdi;
      u_cellIdi.real = this->cellId[i];
      *(outbuffer + offset + 0) = (u_cellIdi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cellIdi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cellIdi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cellIdi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cellId[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t cellId_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cellId_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cellId_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cellId_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cellId_length);
      if(cellId_lengthT > cellId_length)
        this->cellId = (int32_t*)realloc(this->cellId, cellId_lengthT * sizeof(int32_t));
      cellId_length = cellId_lengthT;
      for( uint32_t i = 0; i < cellId_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_cellId;
      u_st_cellId.base = 0;
      u_st_cellId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cellId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_cellId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_cellId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_cellId = u_st_cellId.real;
      offset += sizeof(this->st_cellId);
        memcpy( &(this->cellId[i]), &(this->st_cellId), sizeof(int32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return GETSKINCELLPOSES; };
    virtual const char * getMD5() override { return "33b509be697fb1a069fccba656762bcc"; };

  };

  class getSkinCellPosesResponse : public ros::Msg
  {
    public:
      uint32_t pose_length;
      typedef tum_ics_skin_modular_msgs::SkinCellPose _pose_type;
      _pose_type st_pose;
      _pose_type * pose;
      typedef bool _ok_type;
      _ok_type ok;

    getSkinCellPosesResponse():
      pose_length(0), st_pose(), pose(nullptr),
      ok(0)
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

    virtual const char * getType() override { return GETSKINCELLPOSES; };
    virtual const char * getMD5() override { return "583ef7458d6bd04cc4533062c5e6ac5d"; };

  };

  class getSkinCellPoses {
    public:
    typedef getSkinCellPosesRequest Request;
    typedef getSkinCellPosesResponse Response;
  };

}
#endif
