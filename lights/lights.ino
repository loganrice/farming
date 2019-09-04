#include <Time.h>
#include <TimeLib.h>

#include <Time.h>
#include <TimeLib.h>


int HOUR = 20;
int MINUTE = 20;
int SECOND = 0;
int DAY = 3;
int MONTH = 9;
int YEAR = 2019;
int startHour = 5;
int endHour = 23;
//int startHour = 13;
//int endHour = 14;

int pinOut = 10;

boolean isOn = false;

void setup() {
  setTime(HOUR, MINUTE, SECOND, DAY, MONTH, YEAR);
  Serial.begin(9600);  
  Serial.println("--- Start Serial Monitor SEND_RCVE ---");

  pinMode(pinOut, OUTPUT);

}

void loop() {
  time_t t = now();
  int h = hour(t);
  Serial.println(h);

  if(h >= startHour && h < endHour) { 
    if (isOn == false) {
      digitalWrite(pinOut, HIGH);
    }
    isOn = true;
    Serial.println("Lights On");
  } else {
    if (isOn == true) {
      digitalWrite(pinOut, LOW);
      Serial.println("Lights Off");
    }
    isOn = false;
     
  }
  
  delay(10000);
}
