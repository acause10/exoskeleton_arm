#ifndef _ROS_tum_ics_skin_msgs_ActiveCells_h
#define _ROS_tum_ics_skin_msgs_ActiveCells_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_skin_msgs
{

  class ActiveCells : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _nActiveCells_type;
      _nActiveCells_type nActiveCells;

    ActiveCells():
      header(),
      nActiveCells(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->nActiveCells);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->nActiveCells));
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs/ActiveCells"; };
    virtual const char * getMD5() override { return "4ae32d6732c1580c2c9dd30a7103e694"; };

  };

}
#endif
