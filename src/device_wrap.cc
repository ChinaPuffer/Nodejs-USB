
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
  
  libusb_context *ptrCtx = NULL; // context pointer

  libusb_device_handle *ptrDeviceHandle = NULL; // handle to the device
  
  libusb_device *devPtr = NULL; // used to get information about the device
  
  struct libusb_device_descriptor desc;
  
  int retVal = 0;  // used to check success of a call
    
  const char *ptrMessage;  
  
  uint16_t vendor_id  = args[0]->NumberValue();
  uint16_t product_id = args[1]->NumberValue(); 
     
  retVal = libusb_init( &ptrCtx );
  
  if ( retVal < 0 ) {
       
    ptrMessage = "Failed to initialise the library";
       
   } else {
   
    ptrMessage = "Library successfully initialised"; 
        
  }
  
  // following is a crude approach and assumes that the device exists 
 
  ptrDeviceHandle = libusb_open_device_with_vid_pid( ptrCtx, vendor_id, product_id );
  
  if (ptrDeviceHandle == NULL ) {
  
    Local<String> name = String::New("Error trying to find the device");

    return scope.Close(name);
    
  }
  

  devPtr = libusb_get_device( ptrDeviceHandle );
    
  retVal = libusb_get_device_descriptor( devPtr, &desc);
  
  if ( retVal < 0 ) {
  
     ptrMessage = "Failed to get device description";
     
  } else {
  
     ptrMessage = "Extracted device information";
  }  
  
  
  libusb_close( ptrDeviceHandle );  // close the device
      
  libusb_exit( ptrCtx );  // close the library  
  
  Local<String> name = String::New(ptrMessage);

  return scope.Close(name);
}

Persistent<FunctionTemplate> Device::device_template;



