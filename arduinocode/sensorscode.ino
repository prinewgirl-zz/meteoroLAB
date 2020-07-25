/* Copyright (c) 2020 Priscila Gutierres <priscila.gutierres@usp.br>

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE. */


/* 
 *  
 *  This code is intended to be used as a serial interface to BMP 180 and DHT11
 *  sensors
 *  Input: char 't': DHT11 temperature
 *         char 'h': DHT11 humidity
 *         char 'w': BMP 180 temperature
 *         char 'a': BMP 180 altitude
 *         char 'p': BMP 180 pressure
 *         char 's': BMP 180 Sea level pressure
 *  Output: serial reading of temperature, humidity and pressure
 *  If an error is caught, it returns the char 'e'.
 *  
 */


/*
 * Basic configurations
 */
 
// DHT 11 headers
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
//BMP 180 headers
#include <Wire.h>
#include <Adafruit_BMP085.h>


#define DHTPIN 2     // Digital pin connected to the DHT sensor 
#define DHTTYPE    DHT11     // DHT 11
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

// BMP 180 instance
Adafruit_BMP085 bmp;

char userInput;

void setup() {
  Serial.begin(9600);
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);

  dht.humidity().getSensor(&sensor);

}

void loop() {

  if(Serial.available() > 0) {

//DHT11 serial code
    
  userInput = Serial.read();
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature) or isnan(event.relative_humidity) or !bmp.begin()) {
    Serial.print("e");
  }
  else {
    {
    if (userInput == 't') {
    Serial.print(event.temperature);
  }
  
 if (userInput == 'h') { // Get humidity event and print its value.
  dht.humidity().getEvent(&event);

    Serial.print(event.relative_humidity);
   
      }
    }
    
 //BMP 180 serial code    
 {
 if (userInput == 'w') {
  Serial.print(bmp.readTemperature());
          }
 if (userInput == 'p') {
Serial.print(bmp.readPressure());
          }
if (userInput == 'a') {
Serial.print(bmp.readAltitude());
          }
if (userInput == 's') {
 Serial.print(bmp.readSealevelPressure());
            }                    
                      
        }
      }
  }   
  }
