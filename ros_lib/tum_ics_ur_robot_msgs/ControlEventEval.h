#ifndef _ROS_tum_ics_ur_robot_msgs_ControlEventEval_h
#define _ROS_tum_ics_ur_robot_msgs_ControlEventEval_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_ur_robot_msgs
{

  class ControlEventEval : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _time_type;
      _time_type time;
      typedef int64_t _jointEventCnt_type;
      _jointEventCnt_type jointEventCnt;
      typedef int64_t _forceEventCnt_type;
      _forceEventCnt_type forceEventCnt;
      typedef float _deltaForce_type;
      _deltaForce_type deltaForce;
      typedef int64_t _activeCells_type;
      _activeCells_type activeCells;
      uint32_t extForce_length;
      typedef float _extForce_type;
      _extForce_type st_extForce;
      _extForce_type * extForce;
      uint32_t prox_length;
      typedef float _prox_type;
      _prox_type st_prox;
      _prox_type * prox;
      uint32_t force1_length;
      typedef float _force1_type;
      _force1_type st_force1;
      _force1_type * force1;
      uint32_t force2_length;
      typedef float _force2_type;
      _force2_type st_force2;
      _force2_type * force2;
      uint32_t force3_length;
      typedef float _force3_type;
      _force3_type st_force3;
      _force3_type * force3;
      uint32_t totalForce_length;
      typedef float _totalForce_type;
      _totalForce_type st_totalForce;
      _totalForce_type * totalForce;
      float q[6];
      float qp[6];
      float qpp[6];
      float skinTau[6];
      float tau[6];

    ControlEventEval():
      header(),
      time(0),
      jointEventCnt(0),
      forceEventCnt(0),
      deltaForce(0),
      activeCells(0),
      extForce_length(0), st_extForce(), extForce(nullptr),
      prox_length(0), st_prox(), prox(nullptr),
      force1_length(0), st_force1(), force1(nullptr),
      force2_length(0), st_force2(), force2(nullptr),
      force3_length(0), st_force3(), force3(nullptr),
      totalForce_length(0), st_totalForce(), totalForce(nullptr),
      q(),
      qp(),
      qpp(),
      skinTau(),
      tau()
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
      } u_jointEventCnt;
      u_jointEventCnt.real = this->jointEventCnt;
      *(outbuffer + offset + 0) = (u_jointEventCnt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_jointEventCnt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_jointEventCnt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_jointEventCnt.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_jointEventCnt.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_jointEventCnt.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_jointEventCnt.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_jointEventCnt.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->jointEventCnt);
      union {
        int64_t real;
        uint64_t base;
      } u_forceEventCnt;
      u_forceEventCnt.real = this->forceEventCnt;
      *(outbuffer + offset + 0) = (u_forceEventCnt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_forceEventCnt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_forceEventCnt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_forceEventCnt.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_forceEventCnt.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_forceEventCnt.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_forceEventCnt.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_forceEventCnt.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->forceEventCnt);
      offset += serializeAvrFloat64(outbuffer + offset, this->deltaForce);
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
      *(outbuffer + offset + 0) = (this->extForce_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->extForce_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->extForce_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->extForce_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->extForce_length);
      for( uint32_t i = 0; i < extForce_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->extForce[i]);
      }
      *(outbuffer + offset + 0) = (this->prox_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->prox_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->prox_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->prox_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->prox_length);
      for( uint32_t i = 0; i < prox_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->prox[i]);
      }
      *(outbuffer + offset + 0) = (this->force1_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->force1_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->force1_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->force1_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force1_length);
      for( uint32_t i = 0; i < force1_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->force1[i]);
      }
      *(outbuffer + offset + 0) = (this->force2_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->force2_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->force2_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->force2_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force2_length);
      for( uint32_t i = 0; i < force2_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->force2[i]);
      }
      *(outbuffer + offset + 0) = (this->force3_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->force3_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->force3_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->force3_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force3_length);
      for( uint32_t i = 0; i < force3_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->force3[i]);
      }
      *(outbuffer + offset + 0) = (this->totalForce_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->totalForce_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->totalForce_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->totalForce_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->totalForce_length);
      for( uint32_t i = 0; i < totalForce_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->totalForce[i]);
      }
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
      offset += serializeAvrFloat64(outbuffer + offset, this->skinTau[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tau[i]);
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
      } u_jointEventCnt;
      u_jointEventCnt.base = 0;
      u_jointEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_jointEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_jointEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_jointEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_jointEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_jointEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_jointEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_jointEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->jointEventCnt = u_jointEventCnt.real;
      offset += sizeof(this->jointEventCnt);
      union {
        int64_t real;
        uint64_t base;
      } u_forceEventCnt;
      u_forceEventCnt.base = 0;
      u_forceEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_forceEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_forceEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_forceEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_forceEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_forceEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_forceEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_forceEventCnt.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->forceEventCnt = u_forceEventCnt.real;
      offset += sizeof(this->forceEventCnt);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->deltaForce));
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
      uint32_t extForce_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      extForce_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      extForce_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      extForce_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->extForce_length);
      if(extForce_lengthT > extForce_length)
        this->extForce = (float*)realloc(this->extForce, extForce_lengthT * sizeof(float));
      extForce_length = extForce_lengthT;
      for( uint32_t i = 0; i < extForce_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_extForce));
        memcpy( &(this->extForce[i]), &(this->st_extForce), sizeof(float));
      }
      uint32_t prox_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      prox_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      prox_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      prox_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->prox_length);
      if(prox_lengthT > prox_length)
        this->prox = (float*)realloc(this->prox, prox_lengthT * sizeof(float));
      prox_length = prox_lengthT;
      for( uint32_t i = 0; i < prox_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_prox));
        memcpy( &(this->prox[i]), &(this->st_prox), sizeof(float));
      }
      uint32_t force1_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      force1_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      force1_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      force1_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->force1_length);
      if(force1_lengthT > force1_length)
        this->force1 = (float*)realloc(this->force1, force1_lengthT * sizeof(float));
      force1_length = force1_lengthT;
      for( uint32_t i = 0; i < force1_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_force1));
        memcpy( &(this->force1[i]), &(this->st_force1), sizeof(float));
      }
      uint32_t force2_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      force2_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      force2_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      force2_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->force2_length);
      if(force2_lengthT > force2_length)
        this->force2 = (float*)realloc(this->force2, force2_lengthT * sizeof(float));
      force2_length = force2_lengthT;
      for( uint32_t i = 0; i < force2_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_force2));
        memcpy( &(this->force2[i]), &(this->st_force2), sizeof(float));
      }
      uint32_t force3_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      force3_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      force3_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      force3_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->force3_length);
      if(force3_lengthT > force3_length)
        this->force3 = (float*)realloc(this->force3, force3_lengthT * sizeof(float));
      force3_length = force3_lengthT;
      for( uint32_t i = 0; i < force3_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_force3));
        memcpy( &(this->force3[i]), &(this->st_force3), sizeof(float));
      }
      uint32_t totalForce_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      totalForce_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      totalForce_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      totalForce_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->totalForce_length);
      if(totalForce_lengthT > totalForce_length)
        this->totalForce = (float*)realloc(this->totalForce, totalForce_lengthT * sizeof(float));
      totalForce_length = totalForce_lengthT;
      for( uint32_t i = 0; i < totalForce_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_totalForce));
        memcpy( &(this->totalForce[i]), &(this->st_totalForce), sizeof(float));
      }
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->skinTau[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tau[i]));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_ur_robot_msgs/ControlEventEval"; };
    virtual const char * getMD5() override { return "c0ef0ef415a9a8810cc3bf535047673b"; };

  };

}
#endif
