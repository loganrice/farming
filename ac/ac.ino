#include <Time.h>
#include <TimeLib.h>


int HOUR = 1;
int MINUTE = 12;
int SECOND = 00;
int DAY = 22;
int MONTH = 7;
int YEAR = 2019;


unsigned long startMillis;
unsigned long currentMillis;

// runPeriod must be greater than offPeriod
const unsigned long runPeriod = 1200000;  //the value is a number of milliseconds, is 20 minutes
const unsigned long offPeriod = 600000;  //the value is a number of milliseconds, is 10 minutes

int pinOut = 7;

boolean isOn = false; 
boolean isWaiting = false; // used to toggle between on mode and rest mode

void setup() {
  setTime(HOUR, MINUTE, SECOND, DAY, MONTH, YEAR);
  startMillis = millis();
  Serial.begin(9600);  
  Serial.println("--- Start Serial Monitor SEND_RCVE ---");

  pinMode(pinOut, OUTPUT);

}

void loop() {
  currentMillis = millis();
  time_t t = now();
  int h = hour(t);

  if(h >= 8 && h <= 21) { 
 
    if (currentMillis - startMillis >= runPeriod) {
      startMillis = currentMillis;
      powerOff();
    } else {
      if (isWaiting) {
        if (currentMillis - startMillis >= offPeriod) {
          isWaiting = false;
          startMillis = currentMillis;
        }
      } else {
        powerOn();
      }
    }
  }
}

void powerOn() {
  if (isOn == false) {
    Serial.println("HGH");
    digitalWrite(pinOut, HIGH);
    isOn = true;
    isWaiting = false;
    printStatus();
  }
}

void powerOff() {
  if (isOn == true) {
    Serial.println("Low");
    digitalWrite(pinOut, LOW);
    isOn = false;
    isWaiting = true;
    printStatus();
  }
}

void printStatus() {
  Serial.print("--- isOn ");
  Serial.print(isOn);
  Serial.print("--- isWaiting ");
  Serial.print(isWaiting);
  Serial.print(" runtime millis ");
  Serial.print(currentMillis );
  Serial.println(" ");
}
