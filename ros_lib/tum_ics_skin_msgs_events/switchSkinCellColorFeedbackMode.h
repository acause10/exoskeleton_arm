#ifndef _ROS_SERVICE_switchSkinCellColorFeedbackMode_h
#define _ROS_SERVICE_switchSkinCellColorFeedbackMode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs_events
{

static const char SWITCHSKINCELLCOLORFEEDBACKMODE[] = "tum_ics_skin_msgs_events/switchSkinCellColorFeedbackMode";

  class switchSkinCellColorFeedbackModeRequest : public ros::Msg
  {
    public:
      typedef int32_t _mode_type;
      _mode_type mode;
      uint32_t cellId_length;
      typedef int32_t _cellId_type;
      _cellId_type st_cellId;
      _cellId_type * cellId;

    switchSkinCellColorFeedbackModeRequest():
      mode(0),
      cellId_length(0), st_cellId(), cellId(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_mode;
      u_mode.real = this->mode;
      *(outbuffer + offset + 0) = (u_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mode);
      *(outbuffer + offset + 0) = (this->cellId_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cellId_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cellId_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cellId_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cellId_length);
      for( uint32_t i = 0; i < cellId_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_cellIdi;
      u_cellIdi.real = this->cellId[i];
      *(outbuffer + offset + 0) = (u_cellIdi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cellIdi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cellIdi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cellIdi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cellId[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_mode;
      u_mode.base = 0;
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mode = u_mode.real;
      offset += sizeof(this->mode);
      uint32_t cellId_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cellId_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cellId_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cellId_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cellId_length);
      if(cellId_lengthT > cellId_length)
        this->cellId = (int32_t*)realloc(this->cellId, cellId_lengthT * sizeof(int32_t));
      cellId_length = cellId_lengthT;
      for( uint32_t i = 0; i < cellId_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_cellId;
      u_st_cellId.base = 0;
      u_st_cellId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cellId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_cellId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_cellId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_cellId = u_st_cellId.real;
      offset += sizeof(this->st_cellId);
        memcpy( &(this->cellId[i]), &(this->st_cellId), sizeof(int32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return SWITCHSKINCELLCOLORFEEDBACKMODE; };
    virtual const char * getMD5() override { return "e1fbedee1f827e174a01abd32bb71849"; };

  };

  class switchSkinCellColorFeedbackModeResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    switchSkinCellColorFeedbackModeResponse():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    virtual const char * getType() override { return SWITCHSKINCELLCOLORFEEDBACKMODE; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class switchSkinCellColorFeedbackMode {
    public:
    typedef switchSkinCellColorFeedbackModeRequest Request;
    typedef switchSkinCellColorFeedbackModeResponse Response;
  };

}
#endif
