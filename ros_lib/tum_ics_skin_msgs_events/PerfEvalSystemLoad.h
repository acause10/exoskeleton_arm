#ifndef _ROS_tum_ics_skin_msgs_events_PerfEvalSystemLoad_h
#define _ROS_tum_ics_skin_msgs_events_PerfEvalSystemLoad_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "tum_ics_skin_msgs_events/PerfEvalCpuUsages.h"
#include "tum_ics_skin_msgs_events/PerfEvalNetLoads.h"

namespace tum_ics_skin_msgs_events
{

  class PerfEvalSystemLoad : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef tum_ics_skin_msgs_events::PerfEvalCpuUsages _cpu_type;
      _cpu_type cpu;
      typedef tum_ics_skin_msgs_events::PerfEvalNetLoads _net_type;
      _net_type net;

    PerfEvalSystemLoad():
      header(),
      cpu(),
      net()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->cpu.serialize(outbuffer + offset);
      offset += this->net.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->cpu.deserialize(inbuffer + offset);
      offset += this->net.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs_events/PerfEvalSystemLoad"; };
    virtual const char * getMD5() override { return "9e7ff45fad10cb8d7d78b79eb41b97f6"; };

  };

}
#endif
