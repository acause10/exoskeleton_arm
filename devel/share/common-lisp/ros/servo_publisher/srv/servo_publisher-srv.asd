
(cl:in-package :asdf)

(defsystem "servo_publisher-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "servo_attach" :depends-on ("_package_servo_attach"))
    (:file "_package_servo_attach" :depends-on ("_package"))
  ))