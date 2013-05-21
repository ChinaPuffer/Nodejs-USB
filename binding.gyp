{
  "targets": [
    {
      "target_name": "device",
      "sources" : [ "src/device.cc", "src/device_wrap.cc" ],
      'include_dirs': [
       '/usr/local/include/libusb-1.0'
      ],
      'libraries': [
           '-lusb-1.0'
           ]
       }    
   ]
}

