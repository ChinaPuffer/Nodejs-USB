
#include <node.h>
#include <string>

#include "device_wrap.h"


using namespace v8;

Device::Device() {
    
};

Device::~Device() {};

void Device::Init(Handle<Object> exports) {

  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  
  device_template = Persistent<FunctionTemplate>::New(tpl);
  
  device_template->InstanceTemplate()->SetInternalFieldCount(1);  
  device_template->SetClassName(String::NewSymbol("Device"));
  
  NODE_SET_PROTOTYPE_METHOD(device_template, "getName", GetName);

  exports->Set(String::NewSymbol("Device"), device_template->GetFunction());
  
}

Handle<Value> Device::New(const Arguments& args) {
  HandleScope scope;
  
  Device *dev = new Device();
  
  dev->Wrap(args.This());
  
  return args.This();
}

Handle<Value> Device::GetName(const Arguments& args) {
  HandleScope scope;

  Local<String> name = String::New("Message From Device: Hello World !");

  return scope.Close(name);
}

Persistent<FunctionTemplate> Device::device_template;



