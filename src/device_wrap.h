#ifndef FRUIT_WRAP_H
#define FRUIT_WRAP_H

#include <node.h>

#include<CoreFoundation/CoreFoundation.h>


#include <IOKit/IOKitLib.h> // get rid
#include <IOKit/IOMessage.h> // get rid
#include <IOKit/IOCFPlugIn.h> // get rid


#include <IOKit/usb/IOUSBLib.h>
#include <IOKit/usb/USBSpec.h>
#include <IOKit/hid/IOHIDManager.h>

#include<node_object_wrap.h> // added to work around the emit problem


using namespace v8;
  
class Device : public node::ObjectWrap {
 
 public:
   
    Device();
  ~Device();
  
  static Persistent<FunctionTemplate> device_template;
  
  static void Init(Handle<Object> exports);  
  static Handle<Value> New(const Arguments& args);  
  static Handle<Value> InitDevice(const Arguments& args);
      
protected:
       
};


#endif
