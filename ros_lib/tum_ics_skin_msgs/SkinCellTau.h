#ifndef _ROS_tum_ics_skin_msgs_SkinCellTau_h
#define _ROS_tum_ics_skin_msgs_SkinCellTau_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs
{

  class SkinCellTau : public ros::Msg
  {
    public:
      float tau[6];

    SkinCellTau():
      tau()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tau[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tau[i]));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs/SkinCellTau"; };
    virtual const char * getMD5() override { return "19c835669d5b5335aa022a28b96e590c"; };

  };

}
#endif
