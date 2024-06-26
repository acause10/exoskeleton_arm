// Generated by gencpp from file servo_publisher/servo_attach.msg
// DO NOT EDIT!


#ifndef SERVO_PUBLISHER_MESSAGE_SERVO_ATTACH_H
#define SERVO_PUBLISHER_MESSAGE_SERVO_ATTACH_H

#include <ros/service_traits.h>


#include <servo_publisher/servo_attachRequest.h>
#include <servo_publisher/servo_attachResponse.h>


namespace servo_publisher
{

struct servo_attach
{

typedef servo_attachRequest Request;
typedef servo_attachResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct servo_attach
} // namespace servo_publisher


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::servo_publisher::servo_attach > {
  static const char* value()
  {
    return "146def3fa9252891419a241942ae5da6";
  }

  static const char* value(const ::servo_publisher::servo_attach&) { return value(); }
};

template<>
struct DataType< ::servo_publisher::servo_attach > {
  static const char* value()
  {
    return "servo_publisher/servo_attach";
  }

  static const char* value(const ::servo_publisher::servo_attach&) { return value(); }
};


// service_traits::MD5Sum< ::servo_publisher::servo_attachRequest> should match
// service_traits::MD5Sum< ::servo_publisher::servo_attach >
template<>
struct MD5Sum< ::servo_publisher::servo_attachRequest>
{
  static const char* value()
  {
    return MD5Sum< ::servo_publisher::servo_attach >::value();
  }
  static const char* value(const ::servo_publisher::servo_attachRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::servo_publisher::servo_attachRequest> should match
// service_traits::DataType< ::servo_publisher::servo_attach >
template<>
struct DataType< ::servo_publisher::servo_attachRequest>
{
  static const char* value()
  {
    return DataType< ::servo_publisher::servo_attach >::value();
  }
  static const char* value(const ::servo_publisher::servo_attachRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::servo_publisher::servo_attachResponse> should match
// service_traits::MD5Sum< ::servo_publisher::servo_attach >
template<>
struct MD5Sum< ::servo_publisher::servo_attachResponse>
{
  static const char* value()
  {
    return MD5Sum< ::servo_publisher::servo_attach >::value();
  }
  static const char* value(const ::servo_publisher::servo_attachResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::servo_publisher::servo_attachResponse> should match
// service_traits::DataType< ::servo_publisher::servo_attach >
template<>
struct DataType< ::servo_publisher::servo_attachResponse>
{
  static const char* value()
  {
    return DataType< ::servo_publisher::servo_attach >::value();
  }
  static const char* value(const ::servo_publisher::servo_attachResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SERVO_PUBLISHER_MESSAGE_SERVO_ATTACH_H
