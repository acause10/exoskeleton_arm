#ifndef _ROS_tum_ics_ur_robot_msgs_PlotRobotData_h
#define _ROS_tum_ics_ur_robot_msgs_PlotRobotData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_ur_robot_msgs
{

  class PlotRobotData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      float q[6];
      float qp[6];
      float Xef_0[6];
      float Xd_0[6];
      float torques[6];

    PlotRobotData():
      header(),
      q(),
      qp(),
      Xef_0(),
      Xd_0(),
      torques()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->q[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->qp[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xef_0[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xd_0[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->torques[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qp[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xef_0[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xd_0[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->torques[i]));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_ur_robot_msgs/PlotRobotData"; };
    virtual const char * getMD5() override { return "4a05fca20a9067e4f88fadb5ed6b391a"; };

  };

}
#endif
