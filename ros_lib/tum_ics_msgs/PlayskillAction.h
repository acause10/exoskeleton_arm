#ifndef _ROS_tum_ics_msgs_PlayskillAction_h
#define _ROS_tum_ics_msgs_PlayskillAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "tum_ics_msgs/PlayskillActionGoal.h"
#include "tum_ics_msgs/PlayskillActionResult.h"
#include "tum_ics_msgs/PlayskillActionFeedback.h"

namespace tum_ics_msgs
{

  class PlayskillAction : public ros::Msg
  {
    public:
      typedef tum_ics_msgs::PlayskillActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef tum_ics_msgs::PlayskillActionResult _action_result_type;
      _action_result_type action_result;
      typedef tum_ics_msgs::PlayskillActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    PlayskillAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_msgs/PlayskillAction"; };
    virtual const char * getMD5() override { return "60e3609a58fad7550a14a4800e8408a4"; };

  };

}
#endif
