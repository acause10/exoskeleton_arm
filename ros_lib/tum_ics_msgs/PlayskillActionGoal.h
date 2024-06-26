#ifndef _ROS_tum_ics_msgs_PlayskillActionGoal_h
#define _ROS_tum_ics_msgs_PlayskillActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "tum_ics_msgs/PlayskillGoal.h"

namespace tum_ics_msgs
{

  class PlayskillActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef tum_ics_msgs::PlayskillGoal _goal_type;
      _goal_type goal;

    PlayskillActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_msgs/PlayskillActionGoal"; };
    virtual const char * getMD5() override { return "a34d8a7713f9d12d05e2e240140c235f"; };

  };

}
#endif
