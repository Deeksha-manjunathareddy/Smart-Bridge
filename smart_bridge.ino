// C++ code
//

int moisture = 0;
#include <Servo.h>

int pos = 0;

Servo servo_6;

void setup()
{
   servo_6.attach(6, 500, 2500);
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  Serial.println("apply power to the soil moisture sensor");
  digitalWrite(A0, HIGH);
  delay(10); // Wait for 10 millisecond(s)
  moisture = analogRead(A1);
  // Turn off the sensor to reduce metal corrosion
  // over time
  digitalWrite(A0, LOW);
  Serial.println(moisture);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  if (moisture < 200) {
    digitalWrite(12, HIGH);
    //for (pos = 180; pos >=90; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_6.write(90);
    // wait 15 ms for servo to reach the position
    delay(1000); // Wait for 15 millisecond(s)
  
//}
  } else {
    if (moisture > 200 && moisture < 400) {
      digitalWrite(11, HIGH);
    } else {
      if (moisture > 400 && moisture < 600) {
        digitalWrite(10, HIGH);
      } else {
        if (moisture > 600 && moisture < 800) {
          digitalWrite(9, HIGH);
        } else {
          digitalWrite(8, HIGH);
          
  // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
  //for(int i=0;i<=1;i+=1){        
   //for (pos = 0; pos <= 90; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_6.write(180);
    // wait 15 ms for servo to reach the position
    delay(1000); // Wait for 15 millisecond(s)
  //}
    //}
  
            
        }
      }
    }
  }
  delay(100); // Wait for 100 millisecond(s)
}