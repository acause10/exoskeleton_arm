#ifndef _ROS_tum_ics_skin_msgs_SkinCellJointStates_h
#define _ROS_tum_ics_skin_msgs_SkinCellJointStates_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs
{

  class SkinCellJointStates : public ros::Msg
  {
    public:
      float q[6];

    SkinCellJointStates():
      q()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->q[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q[i]));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs/SkinCellJointStates"; };
    virtual const char * getMD5() override { return "27aed73eaad0f84efd59d8d5706998a4"; };

  };

}
#endif
