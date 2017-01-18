
// www.arduinom.org tarafından yayınlanılmıştır.
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
//#include <Time.h>
//#include <TimeAlarms.h>
// Adafruit_PCD8544 display = Adafruit_PCD8544(SCLK, DIN, DC, CS, RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(2, 3, 4, 5, 6);
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// a maximum of eight servo objects can be created

int pos = 0;    // variable to store the servo position
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;
#include <DHT.h>
#define DHTPIN 8     // what pin we're connected DHT11
#define DHTTYPE DHT22   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
int artis  ;
int kalangun=0 ;
#include <EEPROM.h>
int kalangunaddr = 2;
int saataddr = 1 ;
int gundecikar= 0 ;
#define saattolerans 1
#define guntolerans 0
int oldsaat = 0;
int oldgun = 0;
int eggposition = 90;
float eggmaxt = 37.9;
float eggmint = 37.5;
int eggmaxh = 66;
int eggminh= 60;
// this file generated by Image2GLCD
const unsigned char PROGMEM img[] = {

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0xE3, 0xB0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x3C, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x08, 0xF2,
0xC2, 0x00, 0x00, 0x00, 0x01, 0x84, 0x00, 0x00, 0x09, 0x38, 0x36, 0x00, 0x00, 0x00, 0x07, 0x0C,
0x00, 0x00, 0x0E, 0xC4, 0x0C, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x5B, 0x06, 0x7F,
0xFC, 0x00, 0x30, 0x30, 0x00, 0x00, 0x0C, 0xA1, 0x03, 0xE0, 0x07, 0xC1, 0xE0, 0x20, 0x00, 0x00,
0x34, 0xF1, 0x02, 0x00, 0x00, 0x7F, 0x00, 0x60, 0x00, 0x00, 0x66, 0x02, 0x00, 0x00, 0x00, 0x00,
0x00, 0xF8, 0x00, 0x00, 0x5E, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0x00, 0x00, 0x7E, 0x0C,
0x02, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x1C, 0x30, 0x00, 0x03, 0x83, 0xF3, 0xF8, 0x60,
0x00, 0x00, 0x38, 0x42, 0xE0, 0x08, 0x00, 0x00, 0x08, 0xC0, 0x00, 0x00, 0x78, 0x41, 0x00, 0x00,
0x00, 0x00, 0x11, 0xE0, 0x00, 0x00, 0x60, 0x40, 0x00, 0x00, 0x00, 0x00, 0x11, 0x20, 0x00, 0x00,
0x60, 0x40, 0x00, 0x00, 0x00, 0x80, 0x60, 0xC0, 0x00, 0x00, 0x20, 0x80, 0x00, 0x00, 0x00, 0x40,
0xA0, 0xC0, 0x00, 0x00, 0x33, 0x01, 0x00, 0x00, 0x04, 0x87, 0x60, 0xC0, 0x00, 0x00, 0x1C, 0x04,
0x00, 0x00, 0x04, 0x38, 0x40, 0x80, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x04, 0x40, 0x81, 0x80,
0x00, 0x00, 0x28, 0x40, 0x00, 0x00, 0x00, 0x63, 0x07, 0x00, 0x00, 0x00, 0x48, 0x22, 0x00, 0x00,

0x02, 0x24, 0x82, 0x00, 0x00, 0x00, 0x44, 0x52, 0x00, 0x00, 0x02, 0x5C, 0x83, 0x00, 0x00, 0x00,
0x74, 0x00, 0x00, 0x00, 0x04, 0x21, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x04, 0x43,
0x03, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x66, 0x0B, 0x00, 0x00, 0x00, 0xF2, 0x81,
0x00, 0x00, 0x00, 0x98, 0x03, 0xE0, 0x00, 0x06, 0x11, 0x81, 0x80, 0x04, 0x06, 0x40, 0x02, 0x3F,
0x00, 0x30, 0x18, 0x50, 0x00, 0x01, 0xFF, 0x80, 0x5E, 0x0C, 0x00, 0x60, 0x0C, 0x48, 0x00, 0x00,
0x10, 0x00, 0x94, 0x30, 0x01, 0x81, 0x06, 0x20, 0x00, 0x00, 0x00, 0x00, 0xAC, 0x3F, 0x02, 0xFC,
0x02, 0x01, 0x80, 0x00, 0x00, 0x00, 0x38, 0x9D, 0x0F, 0x1F, 0x4F, 0x81, 0xA0, 0x00, 0x00, 0x00,
0x70, 0x62, 0x08, 0x69, 0x89, 0xF0, 0x00, 0x00, 0x00, 0x6C, 0x8F, 0xF1, 0x03, 0xD6, 0x98, 0x1F,
0x00, 0x00, 0x00, 0x1F, 0x00, 0xFF, 0x0C, 0xBA, 0xA1, 0x01, 0xE1, 0xF0, 0x7F, 0xFC, 0x9F, 0x80,
0x7F, 0xE6, 0xCE, 0xD4, 0x3F, 0xBF, 0x80, 0x03, 0x3B, 0x60, 0x01, 0x18, 0xFF, 0x36, 0x08, 0x00,
0x00, 0x01, 0xFB, 0x30, 0x06, 0x64, 0xFE, 0xA4, 0x4D, 0x3E, 0x10, 0x1C, 0xC7, 0xD0, 0x14, 0x05,
0xDC, 0xCD, 0x6B, 0x21, 0x25, 0x69, 0xE4, 0xA8, 0x00, 0x01, 0x48, 0xC8, 0xF9, 0xD2, 0x8A, 0xD4,
0xBA, 0x04, 0x00, 0x02, 0x18, 0x88, 0xDD, 0xE2, 0x86, 0xCA, 0x4E, 0x05, 0x00, 0x00, 0x00, 0x80,
0x4C, 0x61, 0x42, 0x62, 0x05, 0x81, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x80, 0x20, 0x00, 0x00,
0x4F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/////////////////////

int fanpin = A1;
int humidifierpin = A2 ;
int speakerpin = 11 ;
int heater = A3;
int sagadon=1 ;
int soladon=0;

void setup () {
Serial.begin(9600);
pinMode(fanpin, OUTPUT);
pinMode(humidifierpin, OUTPUT);
pinMode(speakerpin, OUTPUT);
pinMode(heater, OUTPUT);

myservo.attach(9);  // attaches the servo on pin 9 to the servo object

dht.begin();
display.begin();
display.setContrast(50);
Wire.begin();
Wire.beginTransmission(0x68);
Wire.write(0x07); // move pointer to SQW address
Wire.write(0x10); // sends 0x10 (hex) 00010000 (binary) to control register - turns on square wave
Wire.endTransmission();

RTC.begin();
// RTC.adjust(DateTime(__DATE__, __TIME__));
// if you need set clock... just remove // from line above this
display.clearDisplay();
display.drawBitmap(0, 0, img, 80, 45, BLACK);
display.display();
delay(3000);
}
void loop(){
DateTime now = RTC.now();
float h = dht.readHumidity();
float t = dht.readTemperature();
int tround;
int hround;
tround =(int) t;
hround=(int) h;

int zs = now.second()/10;
int us = now.second() - zs*10;
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(BLACK);
display.setCursor(16, 0);
if ( now.hour() < 10)
{
display.print(" ");
display.print(now.hour(), DEC);
}
else
{
//  display.setCursor(16, 0);
display.print(now.hour(), DEC);
}
display.print(":");
if ( now.minute() < 10)
{
display.print("0");
display.print(now.minute(), DEC);
}
else
{
display.print(now.minute(), DEC);
}
display.print(":");
if ( now.second() < 10)
{
display.print("0");
display.print(now.second(), DEC);
}
else
{
display.print(now.second(), DEC);
}

display.setCursor(10, 8);
if ( now.day() < 10)
{
display.print("0");
display.print(now.day(), DEC);
}
else
{
display.print(now.day(), DEC);
}
display.print("/");
if ( now.month() < 10) {
 display.print("0"); 
display.print(now.month(), DEC);
 } else { 
display.print(now.month(), DEC);
 } 
display.print("/");
 display.print(now.year(), DEC);
 ///////////////////////// 
display.drawRect(0,16,84,32, BLACK);
 display.setTextColor(WHITE, BLACK); 
display.setTextSize(1); 
display.setCursor(5,20);
 display.print(" TEMP ");
 display.setCursor(49,20); 
display.print(" HUM ");
 display.setTextSize(2); 
display.setTextColor(BLACK);
 display.setCursor(2,30); 
display.print(tround); 
display.setCursor(32,30);
 display.print("C"); 
display.setTextSize(1);
 display.setTextColor(BLACK); 
display.setCursor(26,30);
 display.print("o");
 ////////////////hum/////////////// 
display.setCursor(50,30); 
display.setTextSize(2); 
display.print(hround); 
display.setCursor(74,30);
 display.setTextSize(1); 
display.print("%");
 ///////////////////////// 
int gun = now.day();
 int gundiff = abs(gun-oldgun);
 if ( gundiff > guntolerans )
{
oldgun=gun;
artis = artis + 1 ;
kalangun = 22 - artis ;
}

/////////////////////////////

///////////////////////////////////////////////////
///////////////////////////////////////////////////

int saat = now.hour();
int diff = abs(saat - oldsaat);
if(diff > saattolerans && kalangun > 3 && soladon == 1 ){
eggposition = 180;
for(pos = 180; pos > 1 ; pos -= 1)  // goes from 0 degrees to 180 degrees
{                                 // in steps of 1 degree
myservo.write(pos);              // tell servo to go to position in variable 'pos'
delay(100);               // waits 15ms for the servo to reach the position
soladon = 0;
sagadon = 1;
oldsaat = saat;
}}
diff = abs(saat - oldsaat);
if(diff > saattolerans && kalangun > 3 && sagadon == 1 ){
eggposition = 0 ;
for(pos = 0; pos < 180 ; pos += 1)  // goes from 0 degrees to 180 degrees
{                                 // in steps of 1 degree
myservo.write(pos);              // tell servo to go to position in variable 'pos'
delay(100);               // waits 15ms for the servo to reach the position
soladon = 1;
sagadon = 0;
oldsaat = saat;
}}

////////////////////////////////////////////////////
////////////////////////////////////////////////////

///////////////////////////////////////////////////
/////////////////CONTROL UNIT//////////////////////
if ( t < eggmaxt && h < eggminh ){
 digitalWrite (heater,HIGH); 
digitalWrite(humidifierpin,HIGH);
 }else if ( t > eggmaxt ) {
digitalWrite(heater,LOW);
digitalWrite(fanpin,HIGH);

} else if ( t < eggmaxt && h > eggmaxh ){
digitalWrite (heater,HIGH);
digitalWrite(fanpin,LOW);
digitalWrite(humidifierpin,LOW);

}
else if (h < eggminh ){ 
digitalWrite(humidifierpin,HIGH);
 }else if (h>eggmaxh){
digitalWrite( humidifierpin,LOW);

}

/////////////////////////////FINAL SCREEN///////////////////
if ( artis > 20 ){
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(BLACK);
display.setCursor(0,0);
display.print("CIVCIVLER CIKMAK UZERE");
display.print(kalangun);
display.display();
delay (1000);
display.clearDisplay();

///////////////////////ALARM FOR FINAL/////////////////////
for (int z= 0 ;  z < 10 ; z = z+1 ){
for (int i = 0; i < 3000; i = i + 1){ 
tone(11, i,20);
 } 
tone(11, 3000,200);
 for (int j = 3000; j > 0; j = j - 1){

}
}
}
///////////////////////////////////////////////////////////////

//////////////////////////////////
//////////////////////////////////
if (us > 2 )
{
display.clearDisplay();
/////////////////////////////////////////////////Clock and Remain day and Remain Day

display.setTextSize(1);
display.setCursor(2,0);
display.print("REMAIN");
display.setCursor(42,0);
display.print("DAYS");
display.setCursor(70,0);
display.setTextColor(WHITE,BLACK);
display.setTextSize(1);
display.print(kalangun);
display.setTextColor(BLACK);

/*  display.setTextSize(2);
display.setTextColor(BLACK);
display.setCursor(0, 0);

{
if ( now.hour() < 10)
{
display.print(" ");
display.print(now.hour(), DEC);
}
else
{
display.print(now.hour(), DEC);
}
display.setCursor(20, 0);
display.print(":");
display.setCursor(28, 0);
if ( now.minute() < 10)
{
display.print("0");
display.print(now.minute(), DEC);
}
else
{
display.print(now.minute(), DEC);
}

display.setCursor(48, 0);
display.print(":");
display.setCursor(57, 0);
if ( now.second() < 10)
{
display.print("0");
display.print(now.second(), DEC);
}
else
{
display.print(now.second(), DEC);
}
}
*/

display.drawRect(0,16,84,32, BLACK);
display.setTextColor( BLACK);
display.setTextSize(1);
display.setCursor(25,8);

display.print("STATUS");
display.print(" ");
//display.print(eggposition);
display.setTextSize(1);
display.setCursor(2,18);
display.print("FAN");
display.setCursor(60,18);
if( digitalRead(fanpin)==HIGH){
display.print(" ON "); }  else {
display.setCursor(59,18);
display.setTextColor(WHITE,BLACK);
display.print(" OFF"); }
display.setTextColor(BLACK);
display.setCursor(2,28);
display.print("HEATER");
display.setTextColor(WHITE, BLACK);
display.setCursor(60,28);
if( digitalRead(heater)==HIGH){
display.print(" ON "); }  else {
display.setCursor(59,28);
display.setTextColor(WHITE,BLACK);
display.print(" OFF"); }
display.setCursor(2,38);
display.setTextColor(BLACK);
display.print("HUMIDIF.");
display.setTextColor(WHITE, BLACK);
display.setCursor(60,38);
if( digitalRead(humidifierpin)==HIGH){
display.print(" ON "); }  else {
display.setCursor(59,38);
display.setTextColor(WHITE,BLACK);
display.print(" OFF"); }

display.display();
//display.setCursor(58,20);
// display.setCursor(49,20);
// display.print(" HUM ");

}

/*

display.drawRect(0,16,84,32, BLACK);
display.setTextSize(1);
display.setTextColor(BLACK);
display.setCursor(2,20);
display.print("Heater");
display.setTextColor(WHITE, BLACK);
display.setCursor(60,20);
display.print(" ON ");
display.setCursor(2,32);
display.setTextColor(BLACK);
display.print("Humidifier");
display.setTextColor(WHITE, BLACK);
display.setCursor(60,32);
display.print(" ON ");
*/
display.display();

}
