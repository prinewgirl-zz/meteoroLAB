#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 31 23:00:01 2020

@author: Priscila
"""

import serial

class SerialControl:
    def __init__(self, serial_port = '/dev/ttyUSB0'):
        self.serial_port = serial_port
        self.ser = serial.Serial(self.serial_port,9600,timeout=1)
        
    def io(self, string):
        self.ser.write(string.encode())
        reading = self.ser.readline().decode('utf8')
        return reading
    
    
