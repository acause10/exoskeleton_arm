#ifndef _ROS_SERVICE_setSkinCellColorFeedbackSettings_h
#define _ROS_SERVICE_setSkinCellColorFeedbackSettings_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_skin_msgs_events/SkinCellColorFeedbackSettings.h"

namespace tum_ics_skin_msgs_events
{

static const char SETSKINCELLCOLORFEEDBACKSETTINGS[] = "tum_ics_skin_msgs_events/setSkinCellColorFeedbackSettings";

  class setSkinCellColorFeedbackSettingsRequest : public ros::Msg
  {
    public:
      uint32_t settings_length;
      typedef tum_ics_skin_msgs_events::SkinCellColorFeedbackSettings _settings_type;
      _settings_type st_settings;
      _settings_type * settings;

    setSkinCellColorFeedbackSettingsRequest():
      settings_length(0), st_settings(), settings(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->settings_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->settings_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->settings_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->settings_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->settings_length);
      for( uint32_t i = 0; i < settings_length; i++){
      offset += this->settings[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t settings_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      settings_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      settings_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      settings_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->settings_length);
      if(settings_lengthT > settings_length)
        this->settings = (tum_ics_skin_msgs_events::SkinCellColorFeedbackSettings*)realloc(this->settings, settings_lengthT * sizeof(tum_ics_skin_msgs_events::SkinCellColorFeedbackSettings));
      settings_length = settings_lengthT;
      for( uint32_t i = 0; i < settings_length; i++){
      offset += this->st_settings.deserialize(inbuffer + offset);
        memcpy( &(this->settings[i]), &(this->st_settings), sizeof(tum_ics_skin_msgs_events::SkinCellColorFeedbackSettings));
      }
     return offset;
    }

    virtual const char * getType() override { return SETSKINCELLCOLORFEEDBACKSETTINGS; };
    virtual const char * getMD5() override { return "49065f52e34cf82b338d899de1f37f62"; };

  };

  class setSkinCellColorFeedbackSettingsResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    setSkinCellColorFeedbackSettingsResponse():
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

    virtual const char * getType() override { return SETSKINCELLCOLORFEEDBACKSETTINGS; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class setSkinCellColorFeedbackSettings {
    public:
    typedef setSkinCellColorFeedbackSettingsRequest Request;
    typedef setSkinCellColorFeedbackSettingsResponse Response;
  };

}
#endif
