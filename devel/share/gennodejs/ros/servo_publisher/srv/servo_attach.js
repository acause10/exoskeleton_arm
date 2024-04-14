// Auto-generated. Do not edit!

// (in-package servo_publisher.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class servo_attachRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.servo_attach_bool = null;
    }
    else {
      if (initObj.hasOwnProperty('servo_attach_bool')) {
        this.servo_attach_bool = initObj.servo_attach_bool
      }
      else {
        this.servo_attach_bool = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type servo_attachRequest
    // Serialize message field [servo_attach_bool]
    bufferOffset = _serializer.bool(obj.servo_attach_bool, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type servo_attachRequest
    let len;
    let data = new servo_attachRequest(null);
    // Deserialize message field [servo_attach_bool]
    data.servo_attach_bool = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'servo_publisher/servo_attachRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1780cb17a15c46ad2593be5875f4549b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool servo_attach_bool
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new servo_attachRequest(null);
    if (msg.servo_attach_bool !== undefined) {
      resolved.servo_attach_bool = msg.servo_attach_bool;
    }
    else {
      resolved.servo_attach_bool = false
    }

    return resolved;
    }
};

class servo_attachResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.done = null;
    }
    else {
      if (initObj.hasOwnProperty('done')) {
        this.done = initObj.done
      }
      else {
        this.done = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type servo_attachResponse
    // Serialize message field [done]
    bufferOffset = _serializer.string(obj.done, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type servo_attachResponse
    let len;
    let data = new servo_attachResponse(null);
    // Deserialize message field [done]
    data.done = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.done);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'servo_publisher/servo_attachResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6f6f8833c91017f802acaa131839007d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string done
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new servo_attachResponse(null);
    if (msg.done !== undefined) {
      resolved.done = msg.done;
    }
    else {
      resolved.done = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: servo_attachRequest,
  Response: servo_attachResponse,
  md5sum() { return '146def3fa9252891419a241942ae5da6'; },
  datatype() { return 'servo_publisher/servo_attach'; }
};
