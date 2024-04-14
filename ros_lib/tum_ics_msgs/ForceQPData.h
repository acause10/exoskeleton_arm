#ifndef _ROS_tum_ics_msgs_ForceQPData_h
#define _ROS_tum_ics_msgs_ForceQPData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace tum_ics_msgs
{

  class ForceQPData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _time_type;
      _time_type time;
      typedef float _QP_time_type;
      _QP_time_type QP_time;
      typedef float _skin_time_type;
      _skin_time_type skin_time;
      typedef float _total_time_type;
      _total_time_type total_time;
      typedef float _N_cells1_type;
      _N_cells1_type N_cells1;
      typedef float _N_cells2_type;
      _N_cells2_type N_cells2;
      typedef float _N_cells3_type;
      _N_cells3_type N_cells3;
      typedef float _N_cells4_type;
      _N_cells4_type N_cells4;
      typedef float _N_cells5_type;
      _N_cells5_type N_cells5;
      typedef float _N_cells6_type;
      _N_cells6_type N_cells6;
      float t_bary1[3];
      float t_bary2[3];
      float t_bary3[3];
      float t_bary4[3];
      float t_bary5[3];
      float t_bary6[3];
      float W_bary1[6];
      float W_bary2[6];
      float W_bary3[6];
      float W_bary4[6];
      float W_bary5[6];
      float W_bary6[6];
      float Xppd1[6];
      float Xppd2[6];
      float Xppd3[6];
      float Xppd4[6];
      float Xppd5[6];
      float Xppd6[6];
      float Xpp1[6];
      float Xpp2[6];
      float Xpp3[6];
      float Xpp4[6];
      float Xpp5[6];
      float Xpp6[6];
      float torques[6];

    ForceQPData():
      header(),
      time(0),
      QP_time(0),
      skin_time(0),
      total_time(0),
      N_cells1(0),
      N_cells2(0),
      N_cells3(0),
      N_cells4(0),
      N_cells5(0),
      N_cells6(0),
      t_bary1(),
      t_bary2(),
      t_bary3(),
      t_bary4(),
      t_bary5(),
      t_bary6(),
      W_bary1(),
      W_bary2(),
      W_bary3(),
      W_bary4(),
      W_bary5(),
      W_bary6(),
      Xppd1(),
      Xppd2(),
      Xppd3(),
      Xppd4(),
      Xppd5(),
      Xppd6(),
      Xpp1(),
      Xpp2(),
      Xpp3(),
      Xpp4(),
      Xpp5(),
      Xpp6(),
      torques()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->time);
      offset += serializeAvrFloat64(outbuffer + offset, this->QP_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->skin_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->total_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->N_cells1);
      offset += serializeAvrFloat64(outbuffer + offset, this->N_cells2);
      offset += serializeAvrFloat64(outbuffer + offset, this->N_cells3);
      offset += serializeAvrFloat64(outbuffer + offset, this->N_cells4);
      offset += serializeAvrFloat64(outbuffer + offset, this->N_cells5);
      offset += serializeAvrFloat64(outbuffer + offset, this->N_cells6);
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->t_bary1[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->t_bary2[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->t_bary3[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->t_bary4[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->t_bary5[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->t_bary6[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->W_bary1[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->W_bary2[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->W_bary3[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->W_bary4[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->W_bary5[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->W_bary6[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xppd1[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xppd2[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xppd3[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xppd4[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xppd5[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xppd6[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xpp1[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xpp2[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xpp3[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xpp4[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xpp5[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->Xpp6[i]);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->QP_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->skin_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->total_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->N_cells1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->N_cells2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->N_cells3));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->N_cells4));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->N_cells5));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->N_cells6));
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->t_bary1[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->t_bary2[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->t_bary3[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->t_bary4[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->t_bary5[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->t_bary6[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->W_bary1[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->W_bary2[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->W_bary3[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->W_bary4[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->W_bary5[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->W_bary6[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xppd1[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xppd2[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xppd3[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xppd4[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xppd5[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xppd6[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xpp1[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xpp2[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xpp3[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xpp4[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xpp5[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Xpp6[i]));
      }
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->torques[i]));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_msgs/ForceQPData"; };
    virtual const char * getMD5() override { return "2a3d260ea71e57afe07b65fdff5de883"; };

  };

}
#endif
