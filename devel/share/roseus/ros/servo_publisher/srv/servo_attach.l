;; Auto-generated. Do not edit!


(when (boundp 'servo_publisher::servo_attach)
  (if (not (find-package "SERVO_PUBLISHER"))
    (make-package "SERVO_PUBLISHER"))
  (shadow 'servo_attach (find-package "SERVO_PUBLISHER")))
(unless (find-package "SERVO_PUBLISHER::SERVO_ATTACH")
  (make-package "SERVO_PUBLISHER::SERVO_ATTACH"))
(unless (find-package "SERVO_PUBLISHER::SERVO_ATTACHREQUEST")
  (make-package "SERVO_PUBLISHER::SERVO_ATTACHREQUEST"))
(unless (find-package "SERVO_PUBLISHER::SERVO_ATTACHRESPONSE")
  (make-package "SERVO_PUBLISHER::SERVO_ATTACHRESPONSE"))

(in-package "ROS")





(defclass servo_publisher::servo_attachRequest
  :super ros::object
  :slots (_servo_attach_bool ))

(defmethod servo_publisher::servo_attachRequest
  (:init
   (&key
    ((:servo_attach_bool __servo_attach_bool) nil)
    )
   (send-super :init)
   (setq _servo_attach_bool __servo_attach_bool)
   self)
  (:servo_attach_bool
   (&optional (__servo_attach_bool :null))
   (if (not (eq __servo_attach_bool :null)) (setq _servo_attach_bool __servo_attach_bool)) _servo_attach_bool)
  (:serialization-length
   ()
   (+
    ;; bool _servo_attach_bool
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _servo_attach_bool
       (if _servo_attach_bool (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _servo_attach_bool
     (setq _servo_attach_bool (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass servo_publisher::servo_attachResponse
  :super ros::object
  :slots (_done ))

(defmethod servo_publisher::servo_attachResponse
  (:init
   (&key
    ((:done __done) "")
    )
   (send-super :init)
   (setq _done (string __done))
   self)
  (:done
   (&optional __done)
   (if __done (setq _done __done)) _done)
  (:serialization-length
   ()
   (+
    ;; string _done
    4 (length _done)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _done
       (write-long (length _done) s) (princ _done s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _done
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _done (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass servo_publisher::servo_attach
  :super ros::object
  :slots ())

(setf (get servo_publisher::servo_attach :md5sum-) "146def3fa9252891419a241942ae5da6")
(setf (get servo_publisher::servo_attach :datatype-) "servo_publisher/servo_attach")
(setf (get servo_publisher::servo_attach :request) servo_publisher::servo_attachRequest)
(setf (get servo_publisher::servo_attach :response) servo_publisher::servo_attachResponse)

(defmethod servo_publisher::servo_attachRequest
  (:response () (instance servo_publisher::servo_attachResponse :init)))

(setf (get servo_publisher::servo_attachRequest :md5sum-) "146def3fa9252891419a241942ae5da6")
(setf (get servo_publisher::servo_attachRequest :datatype-) "servo_publisher/servo_attachRequest")
(setf (get servo_publisher::servo_attachRequest :definition-)
      "bool servo_attach_bool
---
string done
")

(setf (get servo_publisher::servo_attachResponse :md5sum-) "146def3fa9252891419a241942ae5da6")
(setf (get servo_publisher::servo_attachResponse :datatype-) "servo_publisher/servo_attachResponse")
(setf (get servo_publisher::servo_attachResponse :definition-)
      "bool servo_attach_bool
---
string done
")



(provide :servo_publisher/servo_attach "146def3fa9252891419a241942ae5da6")


