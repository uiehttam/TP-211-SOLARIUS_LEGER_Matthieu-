// C++ code
//
/*

*/

#include <Servo.h>

int pos = 0;

Servo servo_9;
Servo servo_10;

void setup()
{
  servo_9.attach(9, 500, 2500);
  servo_10.attach(10, 500, 2500);

}

void loop()
{
  // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    servo_10.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    servo_10.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
}


// 
const int sensorPin_0 = A0;    // pin that the sensor is attached to
const int sensorPin_1 = A1;
const int sensorPin_2 = A2; 
const int sensorPin_3= A3; 


void setup() { 
  Serial.begin(9600);
  servo_9.attach(9, 500, 2500);
  servo_10.attach(10, 500, 2500);
  } 
void loop() {
// Un entier pour contenir une valeur variant de 0 à 1023 
  int val_0 = analogRead(A0); // capteur du haut
  int val_1 = analogRead(A1); // capteur de la droite
  int val_2 = analogRead(A2); // capteur du bas
  int val_3 = analogRead(A3); // capteur de la gauche
  Serial.println(val_0);
  Serial.println(val_1);
  Serial.println(val_2);
  Serial.println(val_3);
  delay(1); 
  }

// ici on va créer un interval de valeur 


void loop()
{
  if val_0 < 500
  // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
    for (pos = 0; pos <= 180; pos += 1) {
    // tell servo to go to position in variable 'pos'
      servo_9.write(pos);

    // wait 15 ms for servo to reach the position
      delay(15); // Wait for 15 millisecond(s)
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_10.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
  if val_0 > 550

}
