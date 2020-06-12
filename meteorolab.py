#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Fri Jun 12 09:39:18 2020

@author: Priscila Gutierres <priscila.gutierres@gmail.com>
"""

import sys
from lib import SerialIO
from time import sleep
import datetime
from os import path

try:
    serialinst = SerialIO.SerialControl()
except:
    print("An error on Arduino has ocurred. Exiting...")
    exit()
    
if path.exists(sys.argv[1]):
    f = open(sys.argv[1],"w+")
    f.write("date,hour,dht11_temperature,dht11_humidity,b180_temperature," +
        "b180_altitude,b180_pressure,b180_seapressure \n")
else:
    f = open(sys.argv[1],"a+")

serialinst.io('t')
serialinst.io('h')
serialinst.io('w')
serialinst.io('a')
serialinst.io('p')
serialinst.io('s')
id = 0

while True:
    sleep(60)
    print("bla")
    try:
        date = str(datetime.date.today())
        time = str(datetime.datetime.now().time())
        f.write(date + ",")
        f.write(time + ",")
        f.write(str(serialinst.io('t')) + ",")
        f.write(str(serialinst.io('h')) + ",")
        f.write(str(serialinst.io('w')) + ",")
        f.write(str(serialinst.io('a')) + ",")
        f.write(str(serialinst.io('p')) + ",")
        f.write(str(serialinst.io('s')))
        f.write("\n")
        id = +1
    except KeyboardInterrupt:
        f.close()
        sys.exit()
