/* 4 Head Infrared Transmitter Module [S180] : http://rdiot.tistory.com/163 [RDIoT Demo] */

#include "U8glib.h"
#include "IRremote.h"
 
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
int receiver = 11; // pin 1 of IR receiver to Arduino digital pin 11
 
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'
String str_hex = "";
String str_value = "";
 
void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Raw Data + Button Decode Test");
  irrecv.enableIRIn(); // Start the receiver
  pinMode(2, OUTPUT);
}
 
void loop(void) {
  
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    //Serial.println(results.value, HEX);  UN Comment to see raw values
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
 
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  //delay(500);
}
 
void draw(void) {
  u8g.setFont(u8g_font_9x15B);
  u8g.setPrintPos(0, 12); 
  u8g.println("KY-005 IR Trans");
 
  u8g.setFont(u8g_font_helvB14);
  u8g.setPrintPos(0,40);
  u8g.print("hex="+str_hex);
  
  u8g.setFont(u8g_font_helvB12);
  u8g.setPrintPos(0,60);
  u8g.print("str="+str_value);
 
}
 
/*-----( Declare User-written Functions )-----*/
void translateIR() // takes action based on IR code received
{
 
  switch(results.value)
  {
 
  case 0xE0E040BF:       
    str_hex = "0xE0E040BF";
    str_value = "power ";
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    break;
 
    default: 
    str_hex = "NONE";
    str_value = "NONE";
  }

  
  delay(200);
 
} //END translateIR
