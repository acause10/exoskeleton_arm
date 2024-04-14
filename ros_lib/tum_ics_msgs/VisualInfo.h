#ifndef _ROS_tum_ics_msgs_VisualInfo_h
#define _ROS_tum_ics_msgs_VisualInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "tum_ics_msgs/ObjectPose.h"

namespace tum_ics_msgs
{

  class VisualInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t objData_length;
      typedef tum_ics_msgs::ObjectPose _objData_type;
      _objData_type st_objData;
      _objData_type * objData;

    VisualInfo():
      header(),
      objData_length(0), st_objData(), objData(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->objData_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->objData_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->objData_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->objData_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->objData_length);
      for( uint32_t i = 0; i < objData_length; i++){
      offset += this->objData[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t objData_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      objData_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      objData_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      objData_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->objData_length);
      if(objData_lengthT > objData_length)
        this->objData = (tum_ics_msgs::ObjectPose*)realloc(this->objData, objData_lengthT * sizeof(tum_ics_msgs::ObjectPose));
      objData_length = objData_lengthT;
      for( uint32_t i = 0; i < objData_length; i++){
      offset += this->st_objData.deserialize(inbuffer + offset);
        memcpy( &(this->objData[i]), &(this->st_objData), sizeof(tum_ics_msgs::ObjectPose));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_msgs/VisualInfo"; };
    virtual const char * getMD5() override { return "aceed99db95768bf5cd6cc5e9e18b926"; };

  };

}
#endif
