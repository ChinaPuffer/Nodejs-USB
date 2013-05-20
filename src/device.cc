// #define BUILDING_NODE_EXTENSION

#include <node.h>

#include "device_wrap.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
  Device::Init(exports);
}

NODE_MODULE(device, InitAll)
