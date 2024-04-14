#ifndef _ROS_tum_ics_msgs_ObjectPose_h
#define _ROS_tum_ics_msgs_ObjectPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Point.h"

namespace tum_ics_msgs
{

  class ObjectPose : public ros::Msg
  {
    public:
      typedef std_msgs::String _objType_type;
      _objType_type objType;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef float _area_size_type;
      _area_size_type area_size;
      uint32_t local_positions_length;
      typedef geometry_msgs::Point _local_positions_type;
      _local_positions_type st_local_positions;
      _local_positions_type * local_positions;
      typedef geometry_msgs::Point _min_blob_position_type;
      _min_blob_position_type min_blob_position;
      typedef geometry_msgs::Point _max_blob_position_type;
      _max_blob_position_type max_blob_position;

    ObjectPose():
      objType(),
      position(),
      area_size(0),
      local_positions_length(0), st_local_positions(), local_positions(nullptr),
      min_blob_position(),
      max_blob_position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->objType.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_area_size;
      u_area_size.real = this->area_size;
      *(outbuffer + offset + 0) = (u_area_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_area_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_area_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_area_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->area_size);
      *(outbuffer + offset + 0) = (this->local_positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->local_positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->local_positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->local_positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->local_positions_length);
      for( uint32_t i = 0; i < local_positions_length; i++){
      offset += this->local_positions[i].serialize(outbuffer + offset);
      }
      offset += this->min_blob_position.serialize(outbuffer + offset);
      offset += this->max_blob_position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->objType.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_area_size;
      u_area_size.base = 0;
      u_area_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_area_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_area_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_area_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->area_size = u_area_size.real;
      offset += sizeof(this->area_size);
      uint32_t local_positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      local_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      local_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      local_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->local_positions_length);
      if(local_positions_lengthT > local_positions_length)
        this->local_positions = (geometry_msgs::Point*)realloc(this->local_positions, local_positions_lengthT * sizeof(geometry_msgs::Point));
      local_positions_length = local_positions_lengthT;
      for( uint32_t i = 0; i < local_positions_length; i++){
      offset += this->st_local_positions.deserialize(inbuffer + offset);
        memcpy( &(this->local_positions[i]), &(this->st_local_positions), sizeof(geometry_msgs::Point));
      }
      offset += this->min_blob_position.deserialize(inbuffer + offset);
      offset += this->max_blob_position.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_msgs/ObjectPose"; };
    virtual const char * getMD5() override { return "a15f852f5379b0c300d74792ceb0fedc"; };

  };

}
#endif
