#include <time.h>

char datamess[100] = "";
int heure = 15;
int minute = 12;
int sec = 0;
int count1 = 0;
int count2 = 0;
int coinc = 0;
int temps = 0;
int intervalle = 0;
int message = 0;

void setup() 
{
  Serial.begin(9600);

  temps = millis();
}

void loop() {
  intervalle = millis() - temps;
  
  if(intervalle >= 5000) {
    count1 = rand() % 4;
    count2 = rand() % 4;
    coinc += rand() % 3 + 1;
      
    sprintf(datamess, "DATA 2018, 05, 26, %d, %d, %d, 99, (*), 6000, -999.0, -999.0,  -999.0, 33.2, 101000, 0, %d, %d, %d", heure, minute, sec, count1, count2, coinc);
    Serial.println(datamess);
  
    sec += 5;
    if(sec == 60) {
      sec = 0;
      minute++;
    }
    if(minute == 60) {
      minute = 0;
      heure++;
    }    
  }

  while (Serial.available())  {
    message = Serial.read()-'0';  // on soustrait le caractère 0, qui vaut 48 en ASCII
    Serial.println(message);
  }
}

