#include <Arduino.h>

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define LED_PIN            13

bool Xendstop=0;
bool Yendstop=0;
bool Zendstop=0;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);
  
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  pinMode(Y_MIN_PIN, INPUT_PULLUP);
  
  pinMode(Z_STEP_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  
  
   digitalWrite(X_ENABLE_PIN,HIGH);
   digitalWrite(Y_ENABLE_PIN,HIGH);
   digitalWrite(Z_ENABLE_PIN,HIGH);

   Xendstop = digitalRead(X_MIN_PIN);
   Yendstop = digitalRead(Y_MIN_PIN);
   Zendstop = digitalRead(Z_MIN_PIN);

   go_home();
   
   move_centre();

   draw_square();

   go_home();

   move_centre();

   draw_triangle();

   go_home();

   move_centre();


}

void go_home(){

    // send all axis to home

      // move X axis to home
 while (Xendstop==LOW){
     Xendstop = digitalRead(X_MIN_PIN);
     digitalWrite(X_ENABLE_PIN,LOW); // enable y axis to move
     digitalWrite(X_DIR_PIN,HIGH); // set direction
     digitalWrite(X_STEP_PIN,HIGH); 
     delayMicroseconds(500);
     digitalWrite(X_STEP_PIN,LOW); // step X axis 1 step
     delayMicroseconds(500);
 }
 
 // move Y axis to home
 while (Yendstop==LOW){
     Yendstop = digitalRead(Y_MIN_PIN);
     digitalWrite(Y_ENABLE_PIN,LOW); // enable y axis to move
     digitalWrite(Y_DIR_PIN,LOW); // set direction
     digitalWrite(Y_STEP_PIN,HIGH); 
     delayMicroseconds(500);
     digitalWrite(Y_STEP_PIN,LOW); // step y axis 1 step
     delayMicroseconds(500);
 }

  // move Z axis to home
 while (Zendstop==LOW){
     Zendstop = digitalRead(Z_MIN_PIN);
     digitalWrite(Z_ENABLE_PIN,LOW); // enable Z axis to move
     digitalWrite(Z_DIR_PIN,LOW); // set direction
     digitalWrite(Z_STEP_PIN,HIGH); 
     delayMicroseconds(500);
     digitalWrite(Z_STEP_PIN,LOW); // step Z axis 1 step
     delayMicroseconds(500);
 }
 // disable axis 
 digitalWrite(X_ENABLE_PIN,HIGH);
 digitalWrite(Y_ENABLE_PIN,HIGH);
 digitalWrite(Z_ENABLE_PIN,HIGH);
}

void move_centre(){

    // move to centre of paper

    // Z axis down
    
  for (long i=0; i<50; i++){
    digitalWrite(Z_ENABLE_PIN,LOW);
    digitalWrite(Z_DIR_PIN,HIGH); // set direction
    digitalWrite(Z_STEP_PIN,HIGH); 
    delayMicroseconds(500);
    digitalWrite(Z_STEP_PIN,LOW); // step Z axis 1 step
    delayMicroseconds(500);
  }


  for (long i=0; i<50; i++){
    digitalWrite(Y_ENABLE_PIN,LOW);
    digitalWrite(Y_DIR_PIN,HIGH); // set direction
    digitalWrite(Y_STEP_PIN,HIGH); 
    delayMicroseconds(500);
    digitalWrite(Y_STEP_PIN,LOW); // step Y axis 1 step
    delayMicroseconds(500);
  }

    
  for (long i=0; i<50; i++){
    digitalWrite(X_ENABLE_PIN,LOW);
    digitalWrite(X_DIR_PIN,LOW); // set direction
    digitalWrite(X_STEP_PIN,HIGH); 
    delayMicroseconds(500);
    digitalWrite(X_STEP_PIN,LOW); // step X axis 1 step
    delayMicroseconds(500);
  }
  
}

void draw_square(){
    
    // bring z axis to pen

  for (long i=0; i<50; i++){
    digitalWrite(Z_ENABLE_PIN,LOW);
    digitalWrite(Z_DIR_PIN,LOW); // set direction
    digitalWrite(Z_STEP_PIN,HIGH); 
    delayMicroseconds(500);
    digitalWrite(Z_STEP_PIN,LOW); // step Z axis 1 step
    delayMicroseconds(500);
  }

  digitalWrite(Z_ENABLE_PIN,HIGH);

  // draw straight line in x axis forward

  for (long i=0; i<50; i++){
    digitalWrite(X_ENABLE_PIN,LOW);
    digitalWrite(X_DIR_PIN,LOW); // set direction
    digitalWrite(X_STEP_PIN,HIGH); 
    delayMicroseconds(500);
    digitalWrite(X_STEP_PIN,LOW); // step X axis 1 step
    delayMicroseconds(500);
  }


  // draw straight line in y axis forward

  for (long i=0; i<50; i++){
    digitalWrite(Y_ENABLE_PIN,LOW);
    digitalWrite(Y_DIR_PIN,HIGH); // set direction
    digitalWrite(Y_STEP_PIN,HIGH); 
    delayMicroseconds(500);
    digitalWrite(Y_STEP_PIN,LOW); // step Y axis 1 step
    delayMicroseconds(500);
  }


  // draw straight line in x axis back

  for (long i=0; i<50; i++){
    digitalWrite(X_ENABLE_PIN,LOW);
    digitalWrite(X_DIR_PIN,HIGH); // set direction
    digitalWrite(X_STEP_PIN,HIGH); 
    delayMicroseconds(500);
    digitalWrite(X_STEP_PIN,LOW); // step X axis 1 step
    delayMicroseconds(500);
  }


  // draw straight line in y axis back

  for (long i=0; i<50; i++){
    digitalWrite(Y_ENABLE_PIN,LOW);
    digitalWrite(Y_DIR_PIN,LOW); // set direction
    digitalWrite(Y_STEP_PIN,HIGH); 
    delayMicroseconds(500);
    digitalWrite(Y_STEP_PIN,LOW); // step Y axis 1 step
    delayMicroseconds(500);
  }

}

void draw_triangle(){

    // move z axis to pen

    
  for (long i=0; i<50; i++){
    digitalWrite(Z_ENABLE_PIN,LOW);
    digitalWrite(Z_DIR_PIN,LOW); // set direction
    digitalWrite(Z_STEP_PIN,HIGH); 
    delayMicroseconds(500);
    digitalWrite(Z_STEP_PIN,LOW); // step Z axis 1 step
    delayMicroseconds(500);
  }

}


void loop () {

 // Blink LED

  if (millis() %1000 <500) 
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
    
}