#pragma once

#include <Wire.h>
#include "RTClib.h"
#include <MPU6050_tockn.h>
RTC_DS3231 rtc;
MPU6050 mpu6050(Wire);

struct Gyro {
  Gyro() {}

  void begin() {
    Wire.begin();
    mpu6050.begin();
    mpu6050.calcGyroOffsets(true);
//    if (! rtc.begin()) {
//    Serial.println("Couldn't find RTC");
//    while (1);
//    }
//    rtc.adjust(DateTime(__DATE__, __TIME__));
//    rtc.adjust(DateTime(2022,11,16,21,45,00));
  }

  void start(){
    mpu6050.update(); 
  }

//  String daten(){
//    DateTime now = rtc.now();
//    return String(daysOfTheWeek[now.dayOfTheWeek()]) + "," + String(now.hour(), DEC) + ":" + String(now.minute(), DEC) + ":" + String(now.second(), DEC);
//  }
//
//  String hari(){
//    DateTime now = rtc.now();
//    return String(daysOfTheWeek[now.dayOfTheWeek()]);
//  }
//
//  String jam(){
//    DateTime now = rtc.now();
//    return String(now.hour(), DEC);
//  }
//
//  String menit(){
//    DateTime now = rtc.now();
//    return String(now.minute(), DEC);
//  }
//
//  String detik(){
//    DateTime now = rtc.now();
//    return String(now.second(), DEC);
//  }

  int sudut_x(){
    return mpu6050.getAngleX();
  }

  int sudut_y(){
    return mpu6050.getAngleY();
  }

  int sudut_z(){
    return mpu6050.getAngleZ();
  }
};
