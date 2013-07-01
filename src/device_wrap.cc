
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
  
  NODE_SET_PROTOTYPE_METHOD(device_template, "initDevice", InitDevice);

  exports->Set(String::NewSymbol("Device"), device_template->GetFunction());
  
}

Handle<Value> Device::New(const Arguments& args) {
  HandleScope scope;
    
  Device *dev = new Device();
  
  dev->Wrap(args.This());
  
  return args.This();
}

Handle<Value> Device::InitDevice(const Arguments& args) {

  HandleScope scope;
      
  const char *ptrMessage;  
  
  SInt32 idVendor  = args[0]->NumberValue();
  SInt32 idProduct = args[1]->NumberValue(); 
  
   
  IOHIDManagerRef hidManager = IOHIDManagerCreate(kCFAllocatorDefault, 
                                                  kIOHIDOptionsTypeNone);
                                                  
  CFMutableDictionaryRef matchDict = CFDictionaryCreateMutable(kCFAllocatorDefault,
                                                               4,
                                                               NULL,
                                                               NULL );
                                                              
  CFDictionarySetValue(matchDict,   
                      CFSTR(kIOHIDVendorIDKey),
                      CFNumberCreate(kCFAllocatorDefault,
                      kCFNumberSInt32Type, &idVendor));
                     
  CFDictionarySetValue(matchDict, 
                       CFSTR(kIOHIDProductIDKey),
                       CFNumberCreate(kCFAllocatorDefault,
                       kCFNumberSInt32Type, &idProduct));
                          
                         
    
    // Register the Matching Dictionary to the HID Manager
  IOHIDManagerSetDeviceMatching(hidManager, matchDict); 
    
    // Search the devices
    
  CFSetRef devSet = IOHIDManagerCopyDevices(hidManager);
    
  if ( devSet ) {
    
     ptrMessage = "Device found";
      
  } else { 
    
      ptrMessage = "Device not found";    
  }
                                                         
  Local<String> name = String::New(ptrMessage);
  
  return scope.Close(name);
}

Persistent<FunctionTemplate> Device::device_template;



