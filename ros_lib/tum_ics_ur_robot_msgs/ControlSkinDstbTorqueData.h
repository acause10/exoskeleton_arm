#ifndef _ROS_tum_ics_ur_robot_msgs_ControlSkinDstbTorqueData_h
#define _ROS_tum_ics_ur_robot_msgs_ControlSkinDstbTorqueData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_ur_robot_msgs
{

  class ControlSkinDstbTorqueData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _time_type;
      _time_type time;
      typedef int64_t _activeCells_type;
      _activeCells_type activeCells;
      typedef int64_t _numOfCells_type;
      _numOfCells_type numOfCells;
      typedef float _T_skin_type;
      _T_skin_type T_skin;
      typedef float _T_total_type;
      _T_total_type T_total;
      typedef float _T_ctrl_type;
      _T_ctrl_type T_ctrl;
      float q[6];
      float qp[6];
      float qpp[6];
      float tau[6];
      float tau_ref[6];
      float tau_err[6];

    ControlSkinDstbTorqueData():
      header(),
      time(0),
      activeCells(0),
      numOfCells(0),
      T_skin(0),
      T_total(0),
      T_ctrl(0),
      q(),
      qp(),
      qpp(),
      tau(),
      tau_ref(),
      tau_err()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->time);
      union {
        int64_t real;
        uint64_t base;
      } u_activeCells;
      u_activeCells.real = this->activeCells;
      *(outbuffer + offset + 0) = (u_activeCells.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_activeCells.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_activeCells.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_activeCells.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_activeCells.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_activeCells.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_activeCells.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_activeCells.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->activeCells);
      union {
        int64_t real;
        uint64_t base;
      } u_numOfCells;
      u_numOfCells.real = this->numOfCells;
      *(outbuffer + offset + 0) = (u_numOfCells.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_numOfCells.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_numOfCells.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_numOfCells.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_numOfCells.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_numOfCells.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_numOfCells.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_numOfCells.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->numOfCells);
      offset += serializeAvrFloat64(outbuffer + offset, this->T_skin);
      offset += serializeAvrFloat64(outbuffer + offset, this->T_total);
      offset += serializeAvrFloat64(outbuffer + offset, this->T_ctrl);
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
      offset += serializeAvrFloat64(outbuffer + offset, this->tau[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tau_ref[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tau_err[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time));
      union {
        int64_t real;
        uint64_t base;
      } u_activeCells;
      u_activeCells.base = 0;
      u_activeCells.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_activeCells.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_activeCells.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_activeCells.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_activeCells.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_activeCells.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_activeCells.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_activeCells.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->activeCells = u_activeCells.real;
      offset += sizeof(this->activeCells);
      union {
        int64_t real;
        uint64_t base;
      } u_numOfCells;
      u_numOfCells.base = 0;
      u_numOfCells.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_numOfCells.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_numOfCells.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_numOfCells.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_numOfCells.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_numOfCells.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_numOfCells.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_numOfCells.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->numOfCells = u_numOfCells.real;
      offset += sizeof(this->numOfCells);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->T_skin));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->T_total));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->T_ctrl));
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tau[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tau_ref[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tau_err[i]));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_ur_robot_msgs/ControlSkinDstbTorqueData"; };
    virtual const char * getMD5() override { return "53e9c9cfc5c614d0597680e8968480d2"; };

  };

}
#endif
