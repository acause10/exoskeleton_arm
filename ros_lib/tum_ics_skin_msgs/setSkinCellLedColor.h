#ifndef _ROS_SERVICE_setSkinCellLedColor_h
#define _ROS_SERVICE_setSkinCellLedColor_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs/SkinCellLedColor.h"

namespace tum_ics_skin_msgs
{

static const char SETSKINCELLLEDCOLOR[] = "tum_ics_skin_msgs/setSkinCellLedColor";

  class setSkinCellLedColorRequest : public ros::Msg
  {
    public:
      uint32_t color_length;
      typedef tum_ics_skin_msgs::SkinCellLedColor _color_type;
      _color_type st_color;
      _color_type * color;

    setSkinCellLedColorRequest():
      color_length(0), st_color(), color(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->color_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->color_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->color_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->color_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->color_length);
      for( uint32_t i = 0; i < color_length; i++){
      offset += this->color[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t color_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      color_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      color_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      color_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->color_length);
      if(color_lengthT > color_length)
        this->color = (tum_ics_skin_msgs::SkinCellLedColor*)realloc(this->color, color_lengthT * sizeof(tum_ics_skin_msgs::SkinCellLedColor));
      color_length = color_lengthT;
      for( uint32_t i = 0; i < color_length; i++){
      offset += this->st_color.deserialize(inbuffer + offset);
        memcpy( &(this->color[i]), &(this->st_color), sizeof(tum_ics_skin_msgs::SkinCellLedColor));
      }
     return offset;
    }

    virtual const char * getType() override { return SETSKINCELLLEDCOLOR; };
    virtual const char * getMD5() override { return "9133a9967c34e8689fc188bfd2235151"; };

  };

  class setSkinCellLedColorResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    setSkinCellLedColorResponse():
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

    virtual const char * getType() override { return SETSKINCELLLEDCOLOR; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class setSkinCellLedColor {
    public:
    typedef setSkinCellLedColorRequest Request;
    typedef setSkinCellLedColorResponse Response;
  };

}
#endif
