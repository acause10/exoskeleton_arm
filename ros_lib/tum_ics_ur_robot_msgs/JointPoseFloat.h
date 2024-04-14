#ifndef _ROS_tum_ics_ur_robot_msgs_JointPoseFloat_h
#define _ROS_tum_ics_ur_robot_msgs_JointPoseFloat_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_ur_robot_msgs
{

  class JointPoseFloat : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int64_t _waypoint_type;
      _waypoint_type waypoint;
      float q[6];
      typedef float _acc_type;
      _acc_type acc;
      typedef float _vel_type;
      _vel_type vel;
      typedef float _totaltime_type;
      _totaltime_type totaltime;
      typedef float _round_type;
      _round_type round;

    JointPoseFloat():
      header(),
      waypoint(0),
      q(),
      acc(0),
      vel(0),
      totaltime(0),
      round(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_waypoint;
      u_waypoint.real = this->waypoint;
      *(outbuffer + offset + 0) = (u_waypoint.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_waypoint.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_waypoint.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_waypoint.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_waypoint.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_waypoint.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_waypoint.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_waypoint.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->waypoint);
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->q[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->acc);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->totaltime);
      offset += serializeAvrFloat64(outbuffer + offset, this->round);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_waypoint;
      u_waypoint.base = 0;
      u_waypoint.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_waypoint.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_waypoint.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_waypoint.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_waypoint.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_waypoint.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_waypoint.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_waypoint.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->waypoint = u_waypoint.real;
      offset += sizeof(this->waypoint);
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q[i]));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->acc));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->totaltime));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->round));
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_ur_robot_msgs/JointPoseFloat"; };
    virtual const char * getMD5() override { return "25a548028d5dce89a6aa1364cf350df9"; };

  };

}
#endif
