#ifndef _ROS_tum_ics_msgs_PlayskillActionResult_h
#define _ROS_tum_ics_msgs_PlayskillActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "tum_ics_msgs/PlayskillResult.h"

namespace tum_ics_msgs
{

  class PlayskillActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef tum_ics_msgs::PlayskillResult _result_type;
      _result_type result;

    PlayskillActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_msgs/PlayskillActionResult"; };
    virtual const char * getMD5() override { return "3107d7b53a2ecbb5e47fc228e0d9895e"; };

  };

}
#endif
