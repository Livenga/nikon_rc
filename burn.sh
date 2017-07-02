#!/bin/bash

picprog --erase --burn --input bin/nikon_rc.hex -d pic16f648a -p /dev/ttyUSB0
