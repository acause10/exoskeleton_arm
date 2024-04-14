#ifndef _ROS_tum_ics_ur_robot_msgs_JointPoseInt_h
#define _ROS_tum_ics_ur_robot_msgs_JointPoseInt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_ur_robot_msgs
{

  class JointPoseInt : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _waypoint_type;
      _waypoint_type waypoint;
      int32_t q[6];
      typedef int32_t _acc_type;
      _acc_type acc;
      typedef int32_t _vel_type;
      _vel_type vel;
      typedef int32_t _totaltime_type;
      _totaltime_type totaltime;
      typedef int32_t _round_type;
      _round_type round;

    JointPoseInt():
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
        int32_t real;
        uint32_t base;
      } u_waypoint;
      u_waypoint.real = this->waypoint;
      *(outbuffer + offset + 0) = (u_waypoint.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_waypoint.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_waypoint.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_waypoint.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->waypoint);
      for( uint32_t i = 0; i < 6; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_qi;
      u_qi.real = this->q[i];
      *(outbuffer + offset + 0) = (u_qi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_qi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_qi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_qi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->q[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_acc;
      u_acc.real = this->acc;
      *(outbuffer + offset + 0) = (u_acc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acc);
      union {
        int32_t real;
        uint32_t base;
      } u_vel;
      u_vel.real = this->vel;
      *(outbuffer + offset + 0) = (u_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel);
      union {
        int32_t real;
        uint32_t base;
      } u_totaltime;
      u_totaltime.real = this->totaltime;
      *(outbuffer + offset + 0) = (u_totaltime.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_totaltime.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_totaltime.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_totaltime.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totaltime);
      union {
        int32_t real;
        uint32_t base;
      } u_round;
      u_round.real = this->round;
      *(outbuffer + offset + 0) = (u_round.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_round.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_round.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_round.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->round);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_waypoint;
      u_waypoint.base = 0;
      u_waypoint.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_waypoint.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_waypoint.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_waypoint.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->waypoint = u_waypoint.real;
      offset += sizeof(this->waypoint);
      for( uint32_t i = 0; i < 6; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_qi;
      u_qi.base = 0;
      u_qi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_qi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_qi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_qi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->q[i] = u_qi.real;
      offset += sizeof(this->q[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_acc;
      u_acc.base = 0;
      u_acc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acc = u_acc.real;
      offset += sizeof(this->acc);
      union {
        int32_t real;
        uint32_t base;
      } u_vel;
      u_vel.base = 0;
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vel = u_vel.real;
      offset += sizeof(this->vel);
      union {
        int32_t real;
        uint32_t base;
      } u_totaltime;
      u_totaltime.base = 0;
      u_totaltime.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_totaltime.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_totaltime.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_totaltime.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->totaltime = u_totaltime.real;
      offset += sizeof(this->totaltime);
      union {
        int32_t real;
        uint32_t base;
      } u_round;
      u_round.base = 0;
      u_round.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_round.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_round.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_round.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->round = u_round.real;
      offset += sizeof(this->round);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_ur_robot_msgs/JointPoseInt"; };
    virtual const char * getMD5() override { return "915d9879f50cb99e88a905c1efb13546"; };

  };

}
#endif
