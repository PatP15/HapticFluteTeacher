//I2C Master
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#include <Wire.h>
#include <LiquidCrystal.h>

//Motor Right Hand
const int Rpointer  = 3;  // Pin 2 of L293
const int Rmiddle  = 10; // Pin 7 of L293
const int Rring  = 9;  // Pin 10 of L293
const int Rpinky = 6; // Pin 15 of L293
const int noteButton = 2;
const int startButton = 4;
//const int speakerpin = A2;
//const int SrNbutton = A1;//scale (and some simple music) or note button 
//no thumb key on your right hand  
int x = 0; 
int whichNote = 0;
int noteButtonState = 0;
int startButtonState = 0;
int SrNbuttonState = 0;
//int val = 0;
const int rs = 7, en = 11, d4 = 5, d5 = 8, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup(){
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Choose Note:");
    lcd.blink();
    lcd.setCursor(0,1);
    delay(1000);
    // Start the I2C Bus as Master
    Serial.begin(9600);
    Serial.println("Begin");
    //Set pins as outputs
    pinMode(Rpointer, OUTPUT);
    pinMode(Rmiddle, OUTPUT);
    pinMode(Rring, OUTPUT);
    pinMode(Rpinky, OUTPUT);
    pinMode(noteButton,  INPUT);
    pinMode(startButton, INPUT);
//    pinMode(SrNbutton, INPUT); 
    digitalWrite(Rmiddle, LOW);
    digitalWrite(Rpinky, LOW);
    digitalWrite(Rpointer, LOW);
    digitalWrite(Rring, LOW);
    Wire.begin(); 
}
void loop(){
   //val = analogRead(noteSpeed)*10;
   noteButtonState = digitalRead(noteButton);
   startButtonState = digitalRead(startButton);
//   SrNbuttonState = digitalRead(SrNbutton);
   
   if (SrNbuttonState == HIGH) {
    whichNote = whichNote + 4;
   }
   
   if (whichNote>27){
      whichNote = 0;
    }
   if (noteButtonState == HIGH){
      whichNote++;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Choose Note:");
      lcd.setCursor(0,1);
      switch (whichNote){
        case 1:
          lcd.print("Note C3 ");
          Serial.println("C3");
          break;
        case 2:
          lcd.print("Note C3s");
          Serial.println("C3s");
          break;
        case 3:
          lcd.print("Note D3 ");
          break;
        case 4:
          lcd.print("Note E3f");
          break;
        case 5:
          lcd.print("Note E3 ");
          break;
        case 6:
          lcd.print("Note F3 ");
          break;
        case 7:
          lcd.print("Note F3s ");
          break;
        case 8:
          lcd.print("Note G3 ");
          break;
        case 9:
          lcd.print("Note A4f");
          break;
        case 10:
          lcd.print("Note A4 ");
          break;
        case 11:
          lcd.print("Note B4f");
          break;
        case 12:
          lcd.print("Note B4 ");
          break;
        case 13:
          lcd.print("Note C4 ");
          break;
        case 14:
          lcd.print("Note C4s");
          break;
        case 15:
          lcd.print("Note D4 ");
          break;
        case 16:
          lcd.print("Note E4f");
          break;
        case 17:
          lcd.print("Note E4 ");
          break;
        case 18:
          lcd.print("Note F4 ");
          break;
        case 19:
          lcd.print("Note F4s ");
          break;
        case 20:
          lcd.print("Note G4 ");
          break;
        case 21:
          lcd.print("Note A5f");
          break;
        case 22:
          lcd.print("Note A5 ");
          break;
        case 23:
          lcd.print("Note B5f");
          break;
        case 24:
          lcd.print("Note B5 ");
          break;
        case 25:
          lcd.print("Note C5 ");
          break;
        case 26:
          lcd.print("Note C5s");
          break;
        case 27:
          lcd.print("Chromatic Scale");
          break;
      }
      delay(500);
    }
    if (startButtonState == HIGH && whichNote > 0) {
      switch (whichNote){
        case 1:
          noteC3();
          break;
        case 2:
          noteC3s();
          break;
        case 3:
          noteD3();
          break;
        case 4:
          noteE3f();
          break;
        case 5:
          noteE3();
          break;
        case 6:
          noteF3();
          break;
        case 7:
          noteF3s();
          break;
        case 8:
          noteG3();
          break;
        case 9:
          noteA4f();
          break;
        case 10:
          noteA4();
          break;
        case 11:
          noteB4f();
          break;
        case 12:
          noteB4();
          break;
        case 13:
          noteC4();
          break;
        case 14:
          noteC4s();
          break;
        case 15:
          noteD4();
          break;
        case 16:
          noteE4f();
          break;
        case 17:
          noteE4();
          break;
        case 18:
          noteF4();
          break;
        case 19:
          noteF4s();
          break;
        case 20:
          noteG4();
          break;
        case 21:
          noteA5f();
          break;
        case 22:
          noteA5();
          break;
        case 23:
          noteB5f();
          break;
        case 24:
          noteB5();
          break;
        case 25:
          noteC5();
          break;
        case 26:
          noteC5s();
          break;
        case 27:
          noteC3();
          noteC3s();
          noteD3();
          noteE3f();
          noteE3();
          noteF3();
          noteF3s();
          noteG3();
          noteA4f();
          noteA4();
          noteB4f();
          noteB4();
          noteC4();
          noteC4s();
          noteD4();
          noteE4f();
          noteE4();
          noteF4();
          noteF4s();
          noteG4();
          noteA5f();
          noteA5();
          noteB5f();
          noteB5();
          noteC5();
          noteC5s();
          break;
      }
    }
  }
//----------------------------------//
void noteC3(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(3);              // sends x 
  Wire.endTransmission();
  Serial.println("C3");
  // stop transmitting
  analogWrite(Rpointer, 75);
  analogWrite(Rpinky, 75);
  analogWrite(Rmiddle, 75);
  analogWrite(Rring, 75);
  
  //tone(speakerpin, NOTE_C3);
  delay(2000);
  
  //noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  digitalWrite(Rmiddle, LOW);
  digitalWrite(Rring, LOW);
  digitalWrite(Rpointer, LOW);
  delay(2000);
}
void noteC3s(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(3);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
  analogWrite(Rmiddle, 75);
  analogWrite(Rring, 75);
  analogWrite(Rpointer, 75);
  //tone(speakerpin, NOTE_CS3);
  delay(2000);
  
  //noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  digitalWrite(Rmiddle, LOW);
  digitalWrite(Rring, LOW);
  digitalWrite(Rpointer, LOW);
  delay(2000);
}
void noteD3(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(3);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rmiddle, 75);
  analogWrite(Rring, 75);
  analogWrite(Rpointer, 75);
  //tone(speakerpin, NOTE_D3);
  delay(2000);
  
  //noTone(speakerpin);
  digitalWrite(Rmiddle, LOW);
  digitalWrite(Rring, LOW);
  digitalWrite(Rpointer, LOW);
  delay(2000);
}
void noteE3f(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(3);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
  analogWrite(Rmiddle, 75);
  analogWrite(Rring, 75);
  analogWrite(Rpointer, 75);
  //tone(speakerpin, NOTE_DS3);
  delay(2000);
  
  //noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  digitalWrite(Rmiddle, LOW);
  digitalWrite(Rring, LOW);
  digitalWrite(Rpointer, LOW);
  delay(2000);
}
void noteE3(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(3);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
  analogWrite(Rmiddle, 75);
  analogWrite(Rpointer, 75);
//  tone(speakerpin, NOTE_E3);
  delay(2000);
  
////  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  digitalWrite(Rmiddle, LOW);
  digitalWrite(Rpointer, LOW);
  delay(2000);
}
void noteF3(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(3);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
  analogWrite(Rpointer, 75);
///  tone(speakerpin, NOTE_F3);
  delay(2000);
  
//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  digitalWrite(Rpointer, LOW);
  delay(2000);
}
void noteF3s(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(3);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
  analogWrite(Rring, 75);
  analogWrite(Rpointer, 75);
//  tone(speakerpin, NOTE_FS3);
  delay(2000);
  
//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  digitalWrite(Rring, LOW);
  digitalWrite(Rpointer, LOW);
  delay(2000);
}
void noteG3(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(3);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
//  tone(speakerpin, NOTE_G3);
  delay(2000);
  
//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  delay(2000);
}
void noteA4f(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(8);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
//  tone(speakerpin, NOTE_GS3);
  delay(2000);
  
//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  delay(2000);
}
void noteA4(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(6);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
//  tone(speakerpin, NOTE_A4);
  delay(2000);
  
///  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  delay(2000);
}
void noteB4f(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(7);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
  analogWrite(Rpointer, 75);
//  tone(speakerpin, NOTE_AS4);
  delay(2000);
  
///  noTone(speakerpin);
  digitalWrite(Rpointer, LOW);
  digitalWrite(Rpinky, LOW);
  delay(2000);
}
void noteB4(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(7);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
//  tone(speakerpin, NOTE_B4);
  delay(2000);
  
//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  delay(2000);
}
void noteC4(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(1);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
//  tone(speakerpin, NOTE_C4);
  delay(2000);
  
//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  delay(2000);
}
void noteC4s(){
  analogWrite(Rpinky, 75);
///  tone(speakerpin, NOTE_CS4);
  delay(2000);
  
//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  delay(2000);
}
void noteD4(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(2);              // sends x 
  Wire.endTransmission();    // stop transmitting
  
  analogWrite(Rmiddle, 75);
  analogWrite(Rring, 75);
  analogWrite(Rpointer, 75);
//  tone(speakerpin, NOTE_D4);
  delay(2000);    

////  noTone(speakerpin);
  digitalWrite(Rmiddle, LOW);
  digitalWrite(Rring, LOW);
  digitalWrite(Rpointer, LOW);
  delay(2000); 
}
void noteE4f(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(2);              // sends x 
  Wire.endTransmission();    // stop transmitting
  
  analogWrite(Rmiddle, 75);
  analogWrite(Rring, 75);
  analogWrite(Rpointer, 75);
  analogWrite(Rpinky, 75);
//  tone(speakerpin, NOTE_DS4);
  delay(2000);    

//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  digitalWrite(Rmiddle, LOW);
  digitalWrite(Rring, LOW);
  digitalWrite(Rpointer, LOW);
  delay(2000); 
}
void noteE4(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(3);              // sends x 
  Wire.endTransmission();    // stop transmitting
  
  analogWrite(Rmiddle, 75);
  analogWrite(Rpinky, 75);
  analogWrite(Rpointer, 75);
//  tone(speakerpin, NOTE_E4);
  delay(2000);    

//  noTone(speakerpin);
  digitalWrite(Rmiddle, LOW);
  digitalWrite(Rpinky, LOW);
  digitalWrite(Rpointer, LOW);
  delay(2000); 
}
void noteF4(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(4);              // sends x 
  Wire.endTransmission();    // stop transmitting
  
  analogWrite(Rpointer, 75);
  analogWrite(Rpinky, 75);
///  tone(speakerpin, NOTE_F4);
  delay(2000);

//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  digitalWrite(Rpointer, LOW);
  delay(2000);  
}
void noteF4s(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(3);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
  analogWrite(Rring, 75);
  analogWrite(Rpointer, 75);
//  tone(speakerpin, NOTE_FS4);
  delay(2000);
  
//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  digitalWrite(Rring, LOW);
  digitalWrite(Rpointer, LOW);
  delay(2000);
}
void noteG4(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(5);              // sends x 
  Wire.endTransmission();    // stop transmitting

  analogWrite(Rpinky, 75);
//  tone(speakerpin, NOTE_G4);
  delay(2000);

  //noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  delay(2000);
}
void noteA5f(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(8);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
//  tone(speakerpin, NOTE_GS4);
  delay(2000);
  
//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  delay(2000);
}
void noteA5(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(6);              // sends x 
  Wire.endTransmission();    // stop transmitting

  analogWrite(Rpinky, 75);
//  tone(speakerpin, NOTE_A5);
  delay(2000);

//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  delay(2000);   
}
void noteB5f(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(7);              // sends x 
  Wire.endTransmission();
  // stop transmitting
  analogWrite(Rpinky, 75);
  analogWrite(Rpointer, 75);
//  tone(speakerpin, NOTE_AS5);
  delay(2000);
  
//  noTone(speakerpin);
  digitalWrite(Rpointer, LOW);
  digitalWrite(Rpinky, LOW);
  delay(2000);
}
void noteB5(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(7);              // sends x 
  Wire.endTransmission();    // stop transmitting
  
//  tone(speakerpin, NOTE_B5);
  analogWrite(Rpinky, 75);
  delay(2000);
  
///  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  delay(2000); 
}
void noteC5(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(1);              // sends x 
  Wire.endTransmission();    // stop transmitting
  Serial.println("noteC5");
  
  analogWrite(Rpinky, 75);
//  tone(speakerpin, NOTE_C5);
  delay(2000);

//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  delay(2000);
}
void noteC5s(){
  analogWrite(Rpinky, 75);
//  tone(speakerpin, NOTE_CS5);
  delay(2000);
  
//  noTone(speakerpin);
  digitalWrite(Rpinky, LOW);
  delay(2000);
}


