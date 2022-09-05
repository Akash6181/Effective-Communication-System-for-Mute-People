
#include<LiquidCrystal.h>


LiquidCrystal lcd(8,9,10,11,12,13);// rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;

#define flexPin_1 A0      // Pin connected to voltage divider output
#define flexPin_2 A1      // Pin connected to voltage divider output
#define flexPin_3 A2      // Pin connected to voltage divider output
#define flexPin_4 A3      // Pin connected to voltage divider output
// Change these constants according to your project's design
const float VCC = 5;      // voltage at Ardunio 5V line
const float R_DIV_1 = 100000.0;  // resistor used to create a voltage divider
const float flatResistance_1 = 50000.0; // resistance when flat
const float bendResistance_1 = 170000.0;  // resistance at 180 deg //
const float R_DIV_2 = 220000.0;  // resistor used to create a voltage divider
const float flatResistance_2 = 160000.0; // resistance when flat
const float bendResistance_2 = 320000.0;  // resistance at 180 deg //
int M0=4;
int M1=5;
int M2=6;
int M3=7;
int M4=2;
int M5=3;
int M6=A4;
int M7=A5;
String str1;  
int a=0;
int b=0;
void setup()
{
   Serial.begin(9600);                                  // begin serial port with baud rate 9600bps
    //defining Flux sensors as inputs
  pinMode(flexPin_1, INPUT);
  pinMode(flexPin_2, INPUT);
  pinMode(flexPin_3, INPUT);
  pinMode(flexPin_4, INPUT);
  lcd.begin(16,2);
   pinMode(M0,OUTPUT);
   pinMode(M1,OUTPUT);
   pinMode(M2,OUTPUT); 
   pinMode(M3,OUTPUT);
   pinMode(M4,OUTPUT);
   pinMode(M5,OUTPUT);
   pinMode(M6,OUTPUT); 
   pinMode(M7,OUTPUT);
   digitalWrite(M0,HIGH);
   digitalWrite(M1,HIGH);
   digitalWrite(M2,HIGH);
   digitalWrite(M3,HIGH);
    digitalWrite(M4,HIGH);
   digitalWrite(M5,HIGH);
   digitalWrite(M6,HIGH);
   digitalWrite(M7,HIGH);
   lcd.clear();
lcd.setCursor(0,0);
lcd.print("SPEAKING SYS");
lcd.setCursor(0,1);
lcd.print("FOR MUTE");
delay(2000);

}

void loop()
{

   // Read the ADC, and calculate voltage and resistance from it
  int ADCflex_1 = analogRead(flexPin_1);
  int ADCflex_2 = analogRead(flexPin_2);
   int ADCflex_3 = analogRead(flexPin_3);
  int ADCflex_4 = analogRead(flexPin_4);
   lcd.clear();
   lcd.setCursor(0,0);
lcd.print("fx1:");
lcd.setCursor(4,0);
lcd.print(ADCflex_1);
lcd.setCursor(8,0);
lcd.print("fx2:");
lcd.setCursor(12,0);
lcd.print(ADCflex_2);
 lcd.setCursor(0,1);
lcd.print("fx3:");
lcd.setCursor(4,1);
lcd.print(ADCflex_3);
lcd.setCursor(8,1);
lcd.print("fx4:");
lcd.setCursor(12,1);
lcd.print(ADCflex_4);
  delay(2000); 
 /* Serial.println(ADCflex_1);
    delay(1000); 
   Serial.println(ADCflex_2);
    delay(1000); 
    Serial.println(ADCflex_3);
    delay(1000); 
   Serial.println(ADCflex_4);*/
    delay(3000);
    if(a==0)
    { 
  if(ADCflex_1>=630&&ADCflex_1<=650)
  
   {
    
         lcd.clear();
   lcd.setCursor(0,0);
lcd.print("WAY TO GROCERY");
    digitalWrite(M0,LOW);
        delay(2000);
         digitalWrite(M0,HIGH);
   delay(3000); 
  // str1 =String(ADCflex_1);
    Serial.println("111");
               
   }
    }
   if(ADCflex_1>680)
   {
    
         lcd.clear();
   lcd.setCursor(0,0);
lcd.print("WAY TO RAILSTATION");
    digitalWrite(M5,LOW);
        delay(2000);
         digitalWrite(M5,HIGH);
   delay(3000); 
  // str1 =String(ADCflex_1);
    Serial.println("555");
    a=1;
    if(ADCflex_1<620)
    {
      a=0;
    }
               
   }
   
  /* if(ADCflex_1<40)
   {
    
         lcd.clear();
   lcd.setCursor(0,0);
lcd.print("WAY TO BANK");
    digitalWrite(M5,LOW);
        delay(2000);
         digitalWrite(M5,HIGH);
   delay(3000); 
  // str1 =String(ADCflex_1);
    //Serial.println("111");
               
   }
   if(ADCflex_1>=370)
   {
    
         lcd.clear();
   lcd.setCursor(0,0);
lcd.print("WAY TO BANK");
    digitalWrite(M5,LOW);
        delay(2000);
         digitalWrite(M5,HIGH);
   delay(3000); 
  // str1 =String(ADCflex_1);
   // Serial.println("111");
               
   }*/
    if(ADCflex_2<1024)
   { 
    lcd.clear();
   lcd.setCursor(0,0);
lcd.print("REST ROOM");
    digitalWrite(M1,LOW);
        delay(2000);
         digitalWrite(M1,HIGH);
         delay(3000);
         // str1 =String(ADCflex_2);
    Serial.println("222");
   }
   if(b==0)
   {
   if(ADCflex_3>=800&&ADCflex_3<840) //OR 1001
   {
    lcd.clear();
   lcd.setCursor(0,0);
lcd.print("HOSPITAL");
    digitalWrite(M2,LOW);
        delay(2000);
         digitalWrite(M2,HIGH);
         delay(3000);
         // str1 =String(ADCflex_3);
    Serial.println("666");
   }

   }
    if(ADCflex_3>=840) //OR 1001
   {
    lcd.clear();
   lcd.setCursor(0,0);
lcd.print("PHARMACY");
    digitalWrite(M6,LOW);
        delay(2000);
         digitalWrite(M6,HIGH);
         delay(3000);
         // str1 =String(ADCflex_3);
   Serial.println("333");
   b=1;
   if(ADCflex_3<800)
   {
    b=0;
   }
   
   }
   if(ADCflex_4<1024
   )
   {
    lcd.clear();
   lcd.setCursor(0,0);
lcd.print("BUS STOP");
    digitalWrite(M3,LOW);
        delay(2000);
         digitalWrite(M3,HIGH);
         delay(3000);
         // str1 =String(ADCflex_4);
    Serial.println("444");
   }
   else
   {
     lcd.clear();
   lcd.setCursor(0,0);
lcd.print("NORMAL");
     delay(500);
   }
      
 
 }

 
