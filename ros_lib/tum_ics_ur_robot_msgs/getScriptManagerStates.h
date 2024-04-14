#ifndef _ROS_SERVICE_getScriptManagerStates_h
#define _ROS_SERVICE_getScriptManagerStates_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_ur_robot_msgs
{

static const char GETSCRIPTMANAGERSTATES[] = "tum_ics_ur_robot_msgs/getScriptManagerStates";

  class getScriptManagerStatesRequest : public ros::Msg
  {
    public:

    getScriptManagerStatesRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return GETSCRIPTMANAGERSTATES; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class getScriptManagerStatesResponse : public ros::Msg
  {
    public:
      uint32_t names_length;
      typedef char* _names_type;
      _names_type st_names;
      _names_type * names;
      uint32_t enabled_length;
      typedef bool _enabled_type;
      _enabled_type st_enabled;
      _enabled_type * enabled;

    getScriptManagerStatesResponse():
      names_length(0), st_names(), names(nullptr),
      enabled_length(0), st_enabled(), enabled(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->names_length);
      for( uint32_t i = 0; i < names_length; i++){
      uint32_t length_namesi = strlen(this->names[i]);
      varToArr(outbuffer + offset, length_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->names[i], length_namesi);
      offset += length_namesi;
      }
      *(outbuffer + offset + 0) = (this->enabled_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->enabled_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->enabled_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->enabled_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->enabled_length);
      for( uint32_t i = 0; i < enabled_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_enabledi;
      u_enabledi.real = this->enabled[i];
      *(outbuffer + offset + 0) = (u_enabledi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enabled[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->names_length);
      if(names_lengthT > names_length)
        this->names = (char**)realloc(this->names, names_lengthT * sizeof(char*));
      names_length = names_lengthT;
      for( uint32_t i = 0; i < names_length; i++){
      uint32_t length_st_names;
      arrToVar(length_st_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_names-1]=0;
      this->st_names = (char *)(inbuffer + offset-1);
      offset += length_st_names;
        memcpy( &(this->names[i]), &(this->st_names), sizeof(char*));
      }
      uint32_t enabled_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      enabled_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      enabled_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      enabled_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->enabled_length);
      if(enabled_lengthT > enabled_length)
        this->enabled = (bool*)realloc(this->enabled, enabled_lengthT * sizeof(bool));
      enabled_length = enabled_lengthT;
      for( uint32_t i = 0; i < enabled_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_enabled;
      u_st_enabled.base = 0;
      u_st_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_enabled = u_st_enabled.real;
      offset += sizeof(this->st_enabled);
        memcpy( &(this->enabled[i]), &(this->st_enabled), sizeof(bool));
      }
     return offset;
    }

    virtual const char * getType() override { return GETSCRIPTMANAGERSTATES; };
    virtual const char * getMD5() override { return "44bb719088af7b4a0bc3023901924bc8"; };

  };

  class getScriptManagerStates {
    public:
    typedef getScriptManagerStatesRequest Request;
    typedef getScriptManagerStatesResponse Response;
  };

}
#endif
