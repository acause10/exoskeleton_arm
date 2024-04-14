#ifndef _ROS_tum_ics_skin_msgs_events_SkinCellEventFlags_h
#define _ROS_tum_ics_skin_msgs_events_SkinCellEventFlags_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs_events
{

  class SkinCellEventFlags : public ros::Msg
  {
    public:
      typedef int32_t _cellId_type;
      _cellId_type cellId;
      typedef int32_t _mask_type;
      _mask_type mask;

    SkinCellEventFlags():
      cellId(0),
      mask(0)
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
      } u_mask;
      u_mask.real = this->mask;
      *(outbuffer + offset + 0) = (u_mask.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mask.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mask.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mask.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mask);
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
      } u_mask;
      u_mask.base = 0;
      u_mask.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mask.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mask.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mask.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mask = u_mask.real;
      offset += sizeof(this->mask);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs_events/SkinCellEventFlags"; };
    virtual const char * getMD5() override { return "d99799118a9139319423e71b1b2e2724"; };

  };

}
#endif
