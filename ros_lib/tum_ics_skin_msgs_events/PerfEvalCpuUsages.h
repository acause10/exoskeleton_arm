#ifndef _ROS_tum_ics_skin_msgs_events_PerfEvalCpuUsages_h
#define _ROS_tum_ics_skin_msgs_events_PerfEvalCpuUsages_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tum_ics_skin_msgs_events
{

  class PerfEvalCpuUsages : public ros::Msg
  {
    public:
      typedef float _skinAppManager_type;
      _skinAppManager_type skinAppManager;
      typedef float _eventManager_type;
      _eventManager_type eventManager;
      typedef float _rosUpdate_type;
      _rosUpdate_type rosUpdate;
      typedef float _rosSkin_type;
      _rosSkin_type rosSkin;
      typedef float _eventPktsToDataConverter_type;
      _eventPktsToDataConverter_type eventPktsToDataConverter;
      typedef float _eventPktUnpacker_type;
      _eventPktUnpacker_type eventPktUnpacker;
      typedef float _eventsToDataConverter_type;
      _eventsToDataConverter_type eventsToDataConverter;
      typedef float _singleIntfTsuV2_type;
      _singleIntfTsuV2_type singleIntfTsuV2;
      typedef float _eventsEvaluation_type;
      _eventsEvaluation_type eventsEvaluation;
      typedef float _eventEvalPub_type;
      _eventEvalPub_type eventEvalPub;
      typedef float _dataEvalPub_type;
      _dataEvalPub_type dataEvalPub;
      typedef float _processTotal_type;
      _processTotal_type processTotal;
      typedef float _threadsTotal_type;
      _threadsTotal_type threadsTotal;
      typedef float _threadsRest_type;
      _threadsRest_type threadsRest;
      typedef float _threadsRos_type;
      _threadsRos_type threadsRos;
      typedef float _threadsSigProc_type;
      _threadsSigProc_type threadsSigProc;
      typedef float _threadsEval_type;
      _threadsEval_type threadsEval;
      uint32_t thread_length;
      typedef float _thread_type;
      _thread_type st_thread;
      _thread_type * thread;
      uint32_t threadName_length;
      typedef char* _threadName_type;
      _threadName_type st_threadName;
      _threadName_type * threadName;

    PerfEvalCpuUsages():
      skinAppManager(0),
      eventManager(0),
      rosUpdate(0),
      rosSkin(0),
      eventPktsToDataConverter(0),
      eventPktUnpacker(0),
      eventsToDataConverter(0),
      singleIntfTsuV2(0),
      eventsEvaluation(0),
      eventEvalPub(0),
      dataEvalPub(0),
      processTotal(0),
      threadsTotal(0),
      threadsRest(0),
      threadsRos(0),
      threadsSigProc(0),
      threadsEval(0),
      thread_length(0), st_thread(), thread(nullptr),
      threadName_length(0), st_threadName(), threadName(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->skinAppManager);
      offset += serializeAvrFloat64(outbuffer + offset, this->eventManager);
      offset += serializeAvrFloat64(outbuffer + offset, this->rosUpdate);
      offset += serializeAvrFloat64(outbuffer + offset, this->rosSkin);
      offset += serializeAvrFloat64(outbuffer + offset, this->eventPktsToDataConverter);
      offset += serializeAvrFloat64(outbuffer + offset, this->eventPktUnpacker);
      offset += serializeAvrFloat64(outbuffer + offset, this->eventsToDataConverter);
      offset += serializeAvrFloat64(outbuffer + offset, this->singleIntfTsuV2);
      offset += serializeAvrFloat64(outbuffer + offset, this->eventsEvaluation);
      offset += serializeAvrFloat64(outbuffer + offset, this->eventEvalPub);
      offset += serializeAvrFloat64(outbuffer + offset, this->dataEvalPub);
      offset += serializeAvrFloat64(outbuffer + offset, this->processTotal);
      offset += serializeAvrFloat64(outbuffer + offset, this->threadsTotal);
      offset += serializeAvrFloat64(outbuffer + offset, this->threadsRest);
      offset += serializeAvrFloat64(outbuffer + offset, this->threadsRos);
      offset += serializeAvrFloat64(outbuffer + offset, this->threadsSigProc);
      offset += serializeAvrFloat64(outbuffer + offset, this->threadsEval);
      *(outbuffer + offset + 0) = (this->thread_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->thread_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->thread_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->thread_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->thread_length);
      for( uint32_t i = 0; i < thread_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->thread[i]);
      }
      *(outbuffer + offset + 0) = (this->threadName_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->threadName_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->threadName_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->threadName_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->threadName_length);
      for( uint32_t i = 0; i < threadName_length; i++){
      uint32_t length_threadNamei = strlen(this->threadName[i]);
      varToArr(outbuffer + offset, length_threadNamei);
      offset += 4;
      memcpy(outbuffer + offset, this->threadName[i], length_threadNamei);
      offset += length_threadNamei;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->skinAppManager));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eventManager));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rosUpdate));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rosSkin));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eventPktsToDataConverter));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eventPktUnpacker));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eventsToDataConverter));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->singleIntfTsuV2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eventsEvaluation));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eventEvalPub));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dataEvalPub));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->processTotal));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->threadsTotal));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->threadsRest));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->threadsRos));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->threadsSigProc));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->threadsEval));
      uint32_t thread_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      thread_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      thread_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      thread_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->thread_length);
      if(thread_lengthT > thread_length)
        this->thread = (float*)realloc(this->thread, thread_lengthT * sizeof(float));
      thread_length = thread_lengthT;
      for( uint32_t i = 0; i < thread_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_thread));
        memcpy( &(this->thread[i]), &(this->st_thread), sizeof(float));
      }
      uint32_t threadName_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      threadName_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      threadName_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      threadName_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->threadName_length);
      if(threadName_lengthT > threadName_length)
        this->threadName = (char**)realloc(this->threadName, threadName_lengthT * sizeof(char*));
      threadName_length = threadName_lengthT;
      for( uint32_t i = 0; i < threadName_length; i++){
      uint32_t length_st_threadName;
      arrToVar(length_st_threadName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_threadName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_threadName-1]=0;
      this->st_threadName = (char *)(inbuffer + offset-1);
      offset += length_st_threadName;
        memcpy( &(this->threadName[i]), &(this->st_threadName), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "tum_ics_skin_msgs_events/PerfEvalCpuUsages"; };
    virtual const char * getMD5() override { return "6f1a997898a106545ec5d432760832d4"; };

  };

}
#endif
