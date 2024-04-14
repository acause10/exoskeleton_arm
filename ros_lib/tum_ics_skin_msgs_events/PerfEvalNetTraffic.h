#ifndef _ROS_tum_ics_skin_msgs_events_PerfEvalNetTraffic_h
#define _ROS_tum_ics_skin_msgs_events_PerfEvalNetTraffic_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs_events
{

  class PerfEvalNetTraffic : public ros::Msg
  {
    public:
      typedef float _tx_type;
      _tx_type tx;
      typedef float _rx_type;
      _rx_type rx;

    PerfEvalNetTraffic():
      tx(0),
      rx(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->tx);
      offset += serializeAvrFloat64(outbuffer + offset, this->rx);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rx));
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs_events/PerfEvalNetTraffic"; };
    virtual const char * getMD5() override { return "4462b1abee62ffced2723b0f04961f60"; };

  };

}
#endif
