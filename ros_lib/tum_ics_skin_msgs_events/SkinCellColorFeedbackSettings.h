#ifndef _ROS_tum_ics_skin_msgs_events_SkinCellColorFeedbackSettings_h
#define _ROS_tum_ics_skin_msgs_events_SkinCellColorFeedbackSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs_events
{

  class SkinCellColorFeedbackSettings : public ros::Msg
  {
    public:
      typedef int32_t _cellId_type;
      _cellId_type cellId;
      typedef int32_t _delay_type;
      _delay_type delay;
      typedef float _proxThresh_type;
      _proxThresh_type proxThresh;
      typedef float _forceThresh_type;
      _forceThresh_type forceThresh;
      typedef int32_t _idleColor_type;
      _idleColor_type idleColor;
      typedef int32_t _proxColor_type;
      _proxColor_type proxColor;
      typedef int32_t _forceColor_type;
      _forceColor_type forceColor;

    SkinCellColorFeedbackSettings():
      cellId(0),
      delay(0),
      proxThresh(0),
      forceThresh(0),
      idleColor(0),
      proxColor(0),
      forceColor(0)
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
      } u_delay;
      u_delay.real = this->delay;
      *(outbuffer + offset + 0) = (u_delay.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delay.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delay.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delay.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delay);
      offset += serializeAvrFloat64(outbuffer + offset, this->proxThresh);
      offset += serializeAvrFloat64(outbuffer + offset, this->forceThresh);
      union {
        int32_t real;
        uint32_t base;
      } u_idleColor;
      u_idleColor.real = this->idleColor;
      *(outbuffer + offset + 0) = (u_idleColor.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_idleColor.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_idleColor.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_idleColor.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idleColor);
      union {
        int32_t real;
        uint32_t base;
      } u_proxColor;
      u_proxColor.real = this->proxColor;
      *(outbuffer + offset + 0) = (u_proxColor.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_proxColor.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_proxColor.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_proxColor.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->proxColor);
      union {
        int32_t real;
        uint32_t base;
      } u_forceColor;
      u_forceColor.real = this->forceColor;
      *(outbuffer + offset + 0) = (u_forceColor.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_forceColor.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_forceColor.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_forceColor.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->forceColor);
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
      } u_delay;
      u_delay.base = 0;
      u_delay.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delay.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delay.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delay.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->delay = u_delay.real;
      offset += sizeof(this->delay);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->proxThresh));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->forceThresh));
      union {
        int32_t real;
        uint32_t base;
      } u_idleColor;
      u_idleColor.base = 0;
      u_idleColor.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_idleColor.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_idleColor.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_idleColor.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->idleColor = u_idleColor.real;
      offset += sizeof(this->idleColor);
      union {
        int32_t real;
        uint32_t base;
      } u_proxColor;
      u_proxColor.base = 0;
      u_proxColor.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_proxColor.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_proxColor.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_proxColor.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->proxColor = u_proxColor.real;
      offset += sizeof(this->proxColor);
      union {
        int32_t real;
        uint32_t base;
      } u_forceColor;
      u_forceColor.base = 0;
      u_forceColor.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_forceColor.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_forceColor.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_forceColor.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->forceColor = u_forceColor.real;
      offset += sizeof(this->forceColor);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs_events/SkinCellColorFeedbackSettings"; };
    virtual const char * getMD5() override { return "f3daadd9b838fb55ac0c8d2cdaf98474"; };

  };

}
#endif
