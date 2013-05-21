#ifndef FRUIT_WRAP_H
#define FRUIT_WRAP_H

#include <node.h>

extern "C" {

#include <libusb.h> 
 
}

using namespace v8;


  
class Device : public node::ObjectWrap {
 
 public:
  
    Device();
  ~Device();
  
  static Persistent<FunctionTemplate> device_template;
  
  static void Init(Handle<Object> exports);  
  static Handle<Value> New(const Arguments& args);  
  static Handle<Value> GetName(const Arguments& args);
  
  libusb_device *ptrDev;
     
protected:
       
};


#endif
