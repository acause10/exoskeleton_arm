#ifndef _ROS_tum_ics_skin_msgs_events_SkinCellEventValue_h
#define _ROS_tum_ics_skin_msgs_events_SkinCellEventValue_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs_events/EventType.h"

namespace tum_ics_skin_msgs_events
{

  class SkinCellEventValue : public ros::Msg
  {
    public:
      typedef tum_ics_skin_msgs_events::EventType _type_type;
      _type_type type;
      typedef int32_t _patchId_type;
      _patchId_type patchId;
      typedef int32_t _cellId_type;
      _cellId_type cellId;
      typedef int64_t _ts_type;
      _ts_type ts;
      typedef float _value_type;
      _value_type value;

    SkinCellEventValue():
      type(),
      patchId(0),
      cellId(0),
      ts(0),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->type.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_patchId;
      u_patchId.real = this->patchId;
      *(outbuffer + offset + 0) = (u_patchId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_patchId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_patchId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_patchId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->patchId);
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
        int64_t real;
        uint64_t base;
      } u_ts;
      u_ts.real = this->ts;
      *(outbuffer + offset + 0) = (u_ts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ts.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ts.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ts.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ts.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ts.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ts);
      offset += serializeAvrFloat64(outbuffer + offset, this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->type.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_patchId;
      u_patchId.base = 0;
      u_patchId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_patchId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_patchId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_patchId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->patchId = u_patchId.real;
      offset += sizeof(this->patchId);
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
        int64_t real;
        uint64_t base;
      } u_ts;
      u_ts.base = 0;
      u_ts.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ts.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ts.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ts.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ts.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ts.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ts.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ts.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ts = u_ts.real;
      offset += sizeof(this->ts);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->value));
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs_events/SkinCellEventValue"; };
    virtual const char * getMD5() override { return "8938a03c080a2032cec6074fce500317"; };

  };

}
#endif
