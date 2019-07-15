#include <Time.h>
#include <TimeLib.h>


int HOUR = 16;
int MINUTE = 45;
int SECOND = 00;
int DAY = 31;
int MONTH = 5;
int YEAR = 2019;

int pinOut = 7;

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

  if(h >= 6 && h <= 19) { 
    if (isOn == false) {
      digitalWrite(pinOut, HIGH);
    }
    isOn = true;
    Serial.println("Lights On");
  } else {
    if (isOn == true) {
      digitalWrite(pinOut, LOW);
    }
    isOn = false;
    Serial.println("Lights Off"); 
  }
  
  delay(10000);
}
