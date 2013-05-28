#ifndef FRUIT_WRAP_H
#define FRUIT_WRAP_H

#include <node.h>

#include<CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/IOMessage.h>
#include <IOKit/IOCFPlugIn.h>
#include <IOKit/usb/IOUSBLib.h>

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
