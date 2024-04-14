; Auto-generated. Do not edit!


(cl:in-package servo_publisher-srv)


;//! \htmlinclude servo_attach-request.msg.html

(cl:defclass <servo_attach-request> (roslisp-msg-protocol:ros-message)
  ((servo_attach_bool
    :reader servo_attach_bool
    :initarg :servo_attach_bool
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass servo_attach-request (<servo_attach-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <servo_attach-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'servo_attach-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name servo_publisher-srv:<servo_attach-request> is deprecated: use servo_publisher-srv:servo_attach-request instead.")))

(cl:ensure-generic-function 'servo_attach_bool-val :lambda-list '(m))
(cl:defmethod servo_attach_bool-val ((m <servo_attach-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader servo_publisher-srv:servo_attach_bool-val is deprecated.  Use servo_publisher-srv:servo_attach_bool instead.")
  (servo_attach_bool m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <servo_attach-request>) ostream)
  "Serializes a message object of type '<servo_attach-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'servo_attach_bool) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <servo_attach-request>) istream)
  "Deserializes a message object of type '<servo_attach-request>"
    (cl:setf (cl:slot-value msg 'servo_attach_bool) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<servo_attach-request>)))
  "Returns string type for a service object of type '<servo_attach-request>"
  "servo_publisher/servo_attachRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servo_attach-request)))
  "Returns string type for a service object of type 'servo_attach-request"
  "servo_publisher/servo_attachRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<servo_attach-request>)))
  "Returns md5sum for a message object of type '<servo_attach-request>"
  "146def3fa9252891419a241942ae5da6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'servo_attach-request)))
  "Returns md5sum for a message object of type 'servo_attach-request"
  "146def3fa9252891419a241942ae5da6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<servo_attach-request>)))
  "Returns full string definition for message of type '<servo_attach-request>"
  (cl:format cl:nil "bool servo_attach_bool~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'servo_attach-request)))
  "Returns full string definition for message of type 'servo_attach-request"
  (cl:format cl:nil "bool servo_attach_bool~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <servo_attach-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <servo_attach-request>))
  "Converts a ROS message object to a list"
  (cl:list 'servo_attach-request
    (cl:cons ':servo_attach_bool (servo_attach_bool msg))
))
;//! \htmlinclude servo_attach-response.msg.html

(cl:defclass <servo_attach-response> (roslisp-msg-protocol:ros-message)
  ((done
    :reader done
    :initarg :done
    :type cl:string
    :initform ""))
)

(cl:defclass servo_attach-response (<servo_attach-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <servo_attach-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'servo_attach-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name servo_publisher-srv:<servo_attach-response> is deprecated: use servo_publisher-srv:servo_attach-response instead.")))

(cl:ensure-generic-function 'done-val :lambda-list '(m))
(cl:defmethod done-val ((m <servo_attach-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader servo_publisher-srv:done-val is deprecated.  Use servo_publisher-srv:done instead.")
  (done m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <servo_attach-response>) ostream)
  "Serializes a message object of type '<servo_attach-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'done))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'done))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <servo_attach-response>) istream)
  "Deserializes a message object of type '<servo_attach-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'done) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'done) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<servo_attach-response>)))
  "Returns string type for a service object of type '<servo_attach-response>"
  "servo_publisher/servo_attachResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servo_attach-response)))
  "Returns string type for a service object of type 'servo_attach-response"
  "servo_publisher/servo_attachResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<servo_attach-response>)))
  "Returns md5sum for a message object of type '<servo_attach-response>"
  "146def3fa9252891419a241942ae5da6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'servo_attach-response)))
  "Returns md5sum for a message object of type 'servo_attach-response"
  "146def3fa9252891419a241942ae5da6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<servo_attach-response>)))
  "Returns full string definition for message of type '<servo_attach-response>"
  (cl:format cl:nil "string done~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'servo_attach-response)))
  "Returns full string definition for message of type 'servo_attach-response"
  (cl:format cl:nil "string done~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <servo_attach-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'done))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <servo_attach-response>))
  "Converts a ROS message object to a list"
  (cl:list 'servo_attach-response
    (cl:cons ':done (done msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'servo_attach)))
  'servo_attach-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'servo_attach)))
  'servo_attach-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servo_attach)))
  "Returns string type for a service object of type '<servo_attach>"
  "servo_publisher/servo_attach")