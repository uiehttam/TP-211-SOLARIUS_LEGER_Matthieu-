// Coding in cpp
// TP - Solarius
// LEGER / AUGER / LE-DEVEHAT


// Nous allons appeler la fonction que nous allons utliser

#include <Servo.h>

// Ici, nous initialison le servo qui décrit l'axe horizontal

Servo horizontal;
int servoh = 90;

// Nous allons défnir les limites d'angle de notre servo afin qu'il ne puisse pas s'endommager

int servohLimitHigh = 180;
int servohLimitLow = 65;

// Ici, nous initialison le servo qui décrit l'axe horizontal

Servo vertical;
int servov = 90;

// Nous allons défnir les limites d'angle de notre servo afin qu'il ne puisse pas s'endommager

int servovLimitHigh = 120;
int servovLimitLow = 15;


// Nous allons définir les pin(s) de connections pour les photos résistances

int ldrTR = 0; // LDR haut droite
int ldrTL = 1; // LDR haut gauche
int ldrBR = 2; // LDR bas droite
int ldrBL = 3; // LDR bas gauche


void setup() {
  Serial.begin(9600);
  // Nous attachons les servos à leur pin respectif
  horizontal.attach(9);
  vertical.attach(10);
  // nous faisons bouger les servos
  horizontal.write(90);
  vertical.write(45);
  delay(50); // le délai peu être variable
}


void loop() {

// on implémente les valeurs des photosrésistances

  int tr = analogRead(ldrTR); // haut droite
  int tl = analogRead(ldrTL); // haut gauche
  int br = analogRead(ldrBR); // bas droite
  int bl = analogRead(ldrBL); // bas gauche

  int dtime = 0; // cette fonction permet de débugguer le système
  int tol = 5;

  int avt = (tl + tr) / 2; // valeur moyenne des photorésistance du haut
  int avd = (bl + br) / 2; // valeur moyenne des photorésistance du bas
  int avl = (tl + bl) / 2; // valeur moyenne des photorésistance de gauche
  int avr = (tr + br) / 2; // valeur moyenne des photorésistance de droite

  int dvert = avt - avd;  // on regarde la différence entre les valeurs du haut et du bas
  int dhoriz = avl - avr; // on regarde la différence entre les valeurs de la droite et de la gauche


  // on print l'ensemble des valeurs calculées
  
  Serial.print(tl);
  Serial.print(" ");
  Serial.print(tr);
  Serial.print(" ");
  Serial.print(bl);
  Serial.print(" ");
  Serial.print(br);
  Serial.print("  ");
  Serial.print(avt);
  Serial.print(" ");
  Serial.print(avd);
  Serial.print(" ");
  Serial.print(avl);
  Serial.print(" ");
  Serial.print(avr);
  Serial.print("  ");
  Serial.print(dtime);
  Serial.print("   ");
  Serial.print(tol);
  Serial.print("  ");
  Serial.print(servov);
  Serial.print("   ");
  Serial.print(servoh);
  Serial.println(" ");


  // on regarde la différence entre les capteurs si les angles changes avec la modification verticale
  
  if (-1 * tol > dvert || dvert > tol) {
    if (avt > avd) {
      servov = ++servov;
      if (servov > servovLimitHigh) {
        servov = servovLimitHigh;
      }
    }
    else if (avt < avd) {
      servov = --servov;
      if (servov < servovLimitLow) {
        servov = servovLimitLow;
      }
    }
    vertical.write(servov);
  }

  // on regarde la différence entre les capteurs si les angles changes avec la modification horizontale
  
  if (-1 * tol > dhoriz || dhoriz > tol) {
    if (avl > avr) {
      servoh = --servoh;
      if (servoh < servohLimitLow) {
        servoh = servohLimitLow;
      }
    }
    else if (avl < avr) {
      servoh = ++servoh;
      if (servoh > servohLimitHigh) {
        servoh = servohLimitHigh;
      }
    }
    else if (avl = avr) {
      // rien ne se passe
    }
    horizontal.write(servoh);
  }
  
  delay(dtime);
  
}
