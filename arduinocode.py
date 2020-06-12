#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 31 23:00:01 2020

@author: priscila
"""

import serial
import time



class SerialControl:
    def __init__(self, serial_port): 
        ser = serial.Serial(self.serial_port,9600)
        
    def send_serial(string):
        ser.open()
        ser.write(string)
        ser.close()
        
    def read_serial(bytes):
        ser.open()
        ser.read(bytes)
        ser.close()
        
    
