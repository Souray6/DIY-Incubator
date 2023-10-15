#include <Servo.h>

int sensorInput=0;
float temperature=0.0;
Servo servo_3;
Servo servo_11;

void setup()
{

    pinMode(A0,INPUT);
    pinMode(13,OUTPUT);
    pinMode(7,OUTPUT);
    servo_3.attach(3,544,2400);
    servo_11.attach(11,544,2400);
    Serial.begin(9600);
    servo_3.write(60);
    servo_11.write(60);
}

void loop()
{
    sensorInput=analogRead(A0);
    temperature=(((sensorInput+1)*205.0)/(1024.0))-55.0;
    Serial.print("T=");
    Serial.print(temperature);
    Serial.println("degree C.");

    if (temperature>=36.5 && temperature<=37.2)
    {
        digitalWrite(7,LOW);
        digitalWrite(13,LOW);
        servo_3.write(60);
        servo_11.write(60);
    }

    else if (temperature>37.2)
    {
        servo_3.write(120);
        servo_11.write(60);
    }

    else if (temperature<36.5)
    {
        servo_3.write(60);
        servo_11.write(120);
    }
    if (temperature>38)
    {

        Serial.println("Temperature too high!!");
        tone(7,100,500);
        tone(7,150,500);
        tone(7,200,1500);
        tone(7,250,1500);
        delay(500);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(500);
    }

    else if (temperature<25)
    {
        Serial.println("Temperature too low!!");
        tone(7,250,1500);
        tone(7,200,1500);
        tone(7,150,500);
        tone(7,100,500);

        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(500);
    }
    else
    {
        digitalWrite(7,LOW);
        digitalWrite(13,LOW);
    }
}
