#ifndef _ROS_tum_ics_ur_robot_msgs_ControlData_h
#define _ROS_tum_ics_ur_robot_msgs_ControlData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_ur_robot_msgs
{

  class ControlData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _time_type;
      _time_type time;
      float q[6];
      float qp[6];
      float qpp[6];
      float qd[6];
      float qpd[6];
      float qppd[6];
      float Dq[6];
      float Dqp[6];
      float Xef_0[6];
      float Xd_0[6];
      float DX[6];
      float Xefp_0[6];
      float Xdp_0[6];
      float DXp[6];
      float torques[6];
      float force[3];
      float moment[3];
      typedef int64_t _sFlag_type;
      _sFlag_type sFlag;

    ControlData():
      header(),
      time(0),
      q(),
      qp(),
      qpp(),
      qd(),
      qpd(),
      qppd(),
      Dq(),
      Dqp(),
      Xef_0(),
      Xd_0(),
      DX(),
      Xefp_0(),
      Xdp_0(),
      DXp(),
      torques(),
      force(),
      moment(),
      sFlag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->time);
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->q[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->qp[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->qpp[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->qd[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->qpd[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->qppd[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Dq[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Dqp[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xef_0[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xd_0[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->DX[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xefp_0[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xdp_0[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->DXp[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->torques[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->force[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->moment[i]);
      }
      union {
        int64_t real;
        uint64_t base;
      } u_sFlag;
      u_sFlag.real = this->sFlag;
      *(outbuffer + offset + 0) = (u_sFlag.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sFlag.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sFlag.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sFlag.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sFlag.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sFlag.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sFlag.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sFlag.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sFlag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time));
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qp[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qpp[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qd[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qpd[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->qppd[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Dq[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Dqp[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xef_0[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xd_0[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->DX[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xefp_0[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xdp_0[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->DXp[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->torques[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->force[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->moment[i]));
      }
      union {
        int64_t real;
        uint64_t base;
      } u_sFlag;
      u_sFlag.base = 0;
      u_sFlag.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sFlag.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sFlag.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sFlag.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sFlag.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sFlag.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sFlag.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sFlag.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sFlag = u_sFlag.real;
      offset += sizeof(this->sFlag);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_ur_robot_msgs/ControlData"; };
    virtual const char * getMD5() override { return "18b0f6da75e6071937d359e940f230e9"; };

  };

}
#endif
