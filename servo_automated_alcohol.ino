#include <Servo.h>
#define trigPin 7
#define echoPin 6

Servo servo1;
Servo servo2;

void setup()
{
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
servo1.attach(8);
servo2.attach(9);
}

void loop()

{
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 10)
{
Serial.println("the distance is less than 5");
servo1.write(90);
servo2.write(90);
}
else
{
servo1.write(0);
servo2.write(180);
}
if (distance > 60 || distance <= 0)
{
Serial.println("The distance is more than 60");
}
else
{
Serial.print(distance);
Serial.println(" cm");
}
delay(100);
}
