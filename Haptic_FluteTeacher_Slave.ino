// I2C Slave

#include <Wire.h>

//Motor Left Hand
const int Lpointer  = 11;  // Pin 2 of L293
const int Lmiddle  = 10; // Pin 7 of L293
const int Lring  = 9;  // Pin 10 of L293
const int Lpinky = 6; // Pin 15 of L293
const int Lthumb = 5;// Pin 2 of L293

int x = 0;


void setup() {
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  Serial.begin(9600);
  Serial.println("Begin");
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
   
  pinMode(Lthumb, OUTPUT);
  pinMode(Lpointer, OUTPUT);
  pinMode(Lmiddle, OUTPUT);
  pinMode(Lring, OUTPUT);
  pinMode(Lpinky, OUTPUT);
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}

void loop() {
  Serial.println(x);
  if (x == 1) { //NOTE C
    analogWrite(Lpointer, 75);
    delay(2000);
    Serial.println("note C");
    digitalWrite(Lpointer, LOW);
  }
  else if (x == 2) {//NOTE D
      analogWrite(Lring, 75);
      analogWrite(Lmiddle, 75);
      analogWrite(Lthumb, 75);
      delay(2000);
      
      digitalWrite(Lring, LOW);
      digitalWrite(Lmiddle, LOW);
      digitalWrite(Lthumb, LOW);
  }
  else if (x == 3 || x == 4 || x == 5) {//NOTE E or F or G
      analogWrite(Lring, 75);
      analogWrite(Lmiddle, 75);
      analogWrite(Lthumb, 75);
      analogWrite(Lpointer, 75);
      delay(2000);
      
      digitalWrite(Lring, LOW);
      digitalWrite(Lmiddle, LOW);
      digitalWrite(Lthumb, LOW);
      digitalWrite(Lpointer, LOW);
  }
  else if (x == 6){
      analogWrite(Lmiddle, 75);
      analogWrite(Lthumb, 75);
      analogWrite(Lpointer, 75);
      delay(2000);
      
      digitalWrite(Lmiddle, LOW);
      digitalWrite(Lthumb, LOW);
      digitalWrite(Lpointer, LOW);
  }
  else if (x== 7){
      analogWrite(Lthumb, 75);
      analogWrite(Lpointer, 75);
      delay(2000);
      
      digitalWrite(Lthumb, LOW);
      digitalWrite(Lpointer, LOW);
  }
  else if (x==8){
      analogWrite(Lring, 75);
      analogWrite(Lmiddle, 75);
      analogWrite(Lthumb, 75);
      analogWrite(Lpointer, 75);
      analogWrite(Lpinky, 75);
      delay(2000);
      
      digitalWrite(Lring, LOW);
      digitalWrite(Lmiddle, LOW);
      digitalWrite(Lthumb, LOW);
      digitalWrite(Lpointer, LOW);
      analogWrite(Lpinky, 75);
  }
  x=0;
}


