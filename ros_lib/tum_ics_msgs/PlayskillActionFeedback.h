#ifndef _ROS_tum_ics_msgs_PlayskillActionFeedback_h
#define _ROS_tum_ics_msgs_PlayskillActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "tum_ics_msgs/PlayskillFeedback.h"

namespace tum_ics_msgs
{

  class PlayskillActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef tum_ics_msgs::PlayskillFeedback _feedback_type;
      _feedback_type feedback;

    PlayskillActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_msgs/PlayskillActionFeedback"; };
    virtual const char * getMD5() override { return "03cd2ed538a6093c26f058e7b3fb85c9"; };

  };

}
#endif
