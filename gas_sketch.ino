#include <LCD5110_Basic.h>
LCD5110 LCD(8,9,10,11,12);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];


void setup() {
   LCD.InitLCD();

  Serial.begin(9600);
  pinMode(3, OUTPUT);

}

void loop() {
    LCD.setFont(SmallFont);
     LCD.print("Concentration:", 0, 0);
      long inokia = analogRead(A0);
     LCD.setFont(SmallFont);
      LCD.printNumI(inokia, 0, 16, 2, '0');
      if (analogRead(A0) > 250) {
      tone(3,1000,200);
       delay(200);
      tone(3,3000,200);
       delay(200);
    } else {
      tone(3,0,10);
       delay(10);
    }

} 
