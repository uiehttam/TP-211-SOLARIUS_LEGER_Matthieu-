#include <Servo.h> //On commence par inclure la bibliothèque de commande des servos
#define PIN_POT1  A0
#define PIN_POT2  A1

const int potentiometre = 0; // Initialisation du potentiomètre
Servo Servo1;    // Initialisation du servo-moteur n°1
Servo Servo2;   // Initialisation du servo-moteur n°2

void setup()
{
    Servo1.attach(9); // on va commander l'angle du servo-moteur avec la pin 9
    Servo1.write(0);  // on place le servo à 0 degré au démarrage
    Servo2.attach(10);  // on va commander l'angle du servo-moteur avec la pin 10
    Servo2.write(0);  // on place le servo à 0 degré au démarrage
    
}
 
void loop()
{   
  int val_1 = analogRead(PIN_POT1);      
  int pos_1 = map(val_1, 0, 1023, 0, 180); 
  Servo1.write(pos_1);  // tell servo to go to position in variable 'pos' 
  int val_2 = analogRead(PIN_POT2);      
  int pos_2 = map(val_2, 0, 1023, 0, 180);
  Servo2.write(pos_2);
  Serial.println(pos_1); 
  Serial.println(pos_2);
  delay(100);

}
