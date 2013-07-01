# Node [Addon](http://nodejs.org/api/addons.html) Module to Access a USB


Exploring the technology used to develop a C++ wrapped [Addon](http://nodejs.org/api/addons.html) Module for [Node js](http://nodejs.org/) 
that can access an USB Port.

# Technology Stack

## Software

 
* Operating System : Mac OS 10.8 ( Mountain Lion )
* Node Version : v0.10.0 
* Node Package Manager ( NPM ) : v1.2.14 
* Node-GYP : v0.9.5
* V8 : v3.17.15
* [HID Manager](http://developer.apple.com/library/mac/#technotes/tn2187/_index.html)
* HTML5, Javascript, CSS

## Hardware


* MacBook Pro 15-inch 
* Logitech USB Mouse

# Current Status

Initially ran into a problem trying to use [libusb](http://www.libusb.org/) where access was denied
because the kernel had taken access before the routine could run ( see [Stack Overflow](http://stackoverflow.com/questions/15102168/libusb-claim-interface-fails-on-mac-os-x-mountain-lion)
for more detail ). [Work arounds](http://stackoverflow.com/questions/3368008/reading-and-writing-to-usb-hid-interrupt-endpoints-on-mac) were suggested however decided 
use [HID Manager](http://developer.apple.com/library/mac/#technotes/tn2187/_index.html). 

A further problem was trying to manage [CFRunLoop](https://developer.apple.com/library/mac/#documentation/CoreFoundation/Reference/CFRunLoopRef/Reference/reference.html). Further searching 
found [node-hid](https://github.com/hanshuebner/node-hid) which is uses [hidapi](https://github.com/signal11/hidapi) to manage the threads required to manage access to the 
USB device. 

[node-hid](https://github.com/hanshuebner/node-hid) achieved what I set out as my initial objective and therefore 
due to time constraints work halted at the moment. 
 
# Thanks

Many people to thank, however special mention for the [Programmers Notebook](http://oroboro.com/usb-serial-number-osx/) which gives a step-by-step 
description of developing the software and some useful links to further documentation to accessing USB ports. 
Also, [Dragons & Bytecode](http://dragonsandbytecode.wordpress.com/2012/02/26/game-developers-diary-3-getting-in-control/) for 
a step-by-step guide on accessing the data from a USB device. Finally [Apple's Sample Software](https://developer.apple.com/library/mac/#samplecode/USBPrivateDataSample/Listings/USBPrivateDataSample_c.html#//apple_ref/doc/uid/DTS10000456-USBPrivateDataSample_c-DontLinkElementID_4)
and, of course, [Hans Hübner](https://github.com/hanshuebner) for [node-hid](https://github.com/hanshuebner/node-hid), 
and [Alan Ott](https://github.com/signal11) for [hidapi](https://github.com/signal11/hidapi) that gave me great insight into the
underlying software required to read a USB via Nodejs.

# Licence

[See Licence](https://github.com/dtinblack/Nodejs-USB/blob/master/LICENSE)


		    
    
    
 
 
 
 
 
 
 
    







    
    
    










