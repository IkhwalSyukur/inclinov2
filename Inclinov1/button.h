// input using switch : dip switch & push button
#pragma once

byte dip_switch[4] = { 23, 18, 33, 32 };
byte read_switch[4];
String show_dip;

struct Switch {
  Switch() {}

  void begin() {
    Serial.println(F("\n\ninitializing input pins"));
    for (byte i = 0; i < 5; i++) {
      pinMode(dip_switch[i], INPUT_PULLUP);
    }
  }

  void read_dip() {
    for (byte i = 0; i < 5; i++) {
      read_switch[i] = digitalRead(dip_switch[i]);
    }

//    read_switch[0] = digitalRead(dip_switch[0]);
//    Serial.println(read_switch[0]);

    show_dip = String(read_switch[0]) + String(read_switch[1]) + String(read_switch[2]) + String(read_switch[3]);
//    Serial.print(show_dip);
  }

  int set_degree() {
    if (show_dip == "0111") {
//      Serial.println(F(" setpoint set to 15 degree"));
      return 15;
    } else if (show_dip == "1011") {
//      Serial.println(F(" setpoint set to 20 degree"));
      return 20;
    } else if (show_dip == "1101") {
//      Serial.println(F(" setpoint set to 45 degree"));
      return 45;
    } else if (show_dip == "1110") {
//      Serial.println(F(" setpoint set to 60 degree"));
      return 60;
    } else {
//      Serial.println(F(" setpoint not ready"));
      return 0;
    }
  }
};
