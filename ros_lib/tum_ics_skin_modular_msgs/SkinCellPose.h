#ifndef _ROS_tum_ics_skin_modular_msgs_SkinCellPose_h
#define _ROS_tum_ics_skin_modular_msgs_SkinCellPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace tum_ics_skin_modular_msgs
{

  class SkinCellPose : public ros::Msg
  {
    public:
      typedef int32_t _cellId_type;
      _cellId_type cellId;
      typedef int32_t _jointId_type;
      _jointId_type jointId;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;

    SkinCellPose():
      cellId(0),
      jointId(0),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_cellId;
      u_cellId.real = this->cellId;
      *(outbuffer + offset + 0) = (u_cellId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cellId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cellId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cellId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cellId);
      union {
        int32_t real;
        uint32_t base;
      } u_jointId;
      u_jointId.real = this->jointId;
      *(outbuffer + offset + 0) = (u_jointId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_jointId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_jointId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_jointId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->jointId);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_cellId;
      u_cellId.base = 0;
      u_cellId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cellId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cellId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cellId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cellId = u_cellId.real;
      offset += sizeof(this->cellId);
      union {
        int32_t real;
        uint32_t base;
      } u_jointId;
      u_jointId.base = 0;
      u_jointId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_jointId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_jointId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_jointId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->jointId = u_jointId.real;
      offset += sizeof(this->jointId);
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_modular_msgs/SkinCellPose"; };
    virtual const char * getMD5() override { return "fdd133cf9ac5584a9219984cee6b41fe"; };

  };

}
#endif
