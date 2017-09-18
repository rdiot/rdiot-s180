/* 4 Head Infrared Transmitter Module [S180] : http://rdiot.tistory.com/163 [RDIoT Demo] */

#include <IRremote.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x20 for a 16 chars and 2 line display

//* An IR LED must be connected to Arduino PWM pin 3.
IRsend irsend;
 
void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
}

int count = 0;
void loop() {
 
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  // unsigned int irSignal[] = {9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 39416, 9000, 2210, 560}; //AnalysIR Batch Export (IRremote) - RAW
  
  unsigned int  rawData[67] = {4500,4400, 600,1650, 550,1650, 650,1600, 600,550, 550,550, 550,550, 550,550, 550,550, 550,1650, 600,1650, 550,1650, 600,550, 550,550, 550,550, 550,550, 550,550, 600,500, 600,1600, 600,550, 550,550, 550,550, 550,550, 550,550, 550,550, 600,1600, 600,550, 550,1650, 600,1650, 550,1650, 600,1650, 600,1650, 550,1650, 600};  // SAMSUNG E0E040BF
  unsigned int  data = 0xE0E040BF;
 
  irsend.sendRaw(rawData, sizeof(rawData) / sizeof(rawData[0]), khz); //Note the approach used to automatically calculate the size of the array.
  
  lcd.setCursor(0,0);
  lcd.print("S180:4 Head IR Trans.");
  lcd.setCursor(0,1);
  count++;
  lcd.print("every 5sec count: "+(String)count+" ");
  lcd.setCursor(0,2);
  lcd.print("data=0xE0E040BF");
 
  delay(5000); //In this example, the signal will be repeated every 5 seconds, approximately.
}
