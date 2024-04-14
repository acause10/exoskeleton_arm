#ifndef _ROS_tum_ics_skin_msgs_events_PerfEvalNetLoads_h
#define _ROS_tum_ics_skin_msgs_events_PerfEvalNetLoads_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs_events/PerfEvalNetTraffic.h"

namespace tum_ics_skin_msgs_events
{

  class PerfEvalNetLoads : public ros::Msg
  {
    public:
      typedef tum_ics_skin_msgs_events::PerfEvalNetTraffic _lo_type;
      _lo_type lo;
      typedef tum_ics_skin_msgs_events::PerfEvalNetTraffic _eth4_type;
      _eth4_type eth4;

    PerfEvalNetLoads():
      lo(),
      eth4()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->lo.serialize(outbuffer + offset);
      offset += this->eth4.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->lo.deserialize(inbuffer + offset);
      offset += this->eth4.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs_events/PerfEvalNetLoads"; };
    virtual const char * getMD5() override { return "8109f60c631b56ed0b4697c70366f3ce"; };

  };

}
#endif
