#include <hcsr04.h>

#define TRIG_PIN 4
#define ECHO_PIN 5

const int buzz = 11;
const int led1 = 6;
const int led2 = 7;
const int led3 = 8;

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000);

double a;

void setup(){
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzz, OUTPUT);
}
void loop() {
  a = hcsr04.distanceInMillimeters()/10;

  if (a>=30) {
    digitalWrite (led3 , HIGH);
    digitalWrite (led2, LOW);
    digitalWrite (led1 , LOW);
  }
  if (a<30 and a>10) {
    digitalWrite (led2 , HIGH);
    digitalWrite (led3 , LOW);
    digitalWrite (led1 , LOW);
    tone(buzz, 880, a);
  }
  if (a<=10) {
    digitalWrite (led1 , HIGH);
    digitalWrite (led3 , LOW);
    digitalWrite (led2, LOW);
    tone(buzz, 880, a*50);
  }

  Serial.print(a);
  Serial.println("cm");
  delay(100);
}
