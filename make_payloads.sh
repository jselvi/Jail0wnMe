#!/bin/sh

rm -f payload_reversetcp payload_writefile payload_wget

gcc -L/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.2.sdk/usr/lib -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.2.sdk/usr/include -arch armv7 -mthumb payload_wget.c -o payload_wget

gcc -L/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.2.sdk/usr/lib -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.2.sdk/usr/include -arch armv7 -mthumb payload_reversetcp.c -o payload_reversetcp

gcc -L/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.2.sdk/usr/lib -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.2.sdk/usr/include -arch armv7 -mthumb payload_writefile.c -o payload_writefile
