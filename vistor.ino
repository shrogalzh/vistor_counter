#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27,16,2);
int in=3;
int out=5;
int in_val;
int out_val;
int led=11;
int count=0;
void setup() {
// put your setup code here, to run once:
pinMode(in,INPUT);
pinMode(out,INPUT);
pinMode(led,OUTPUT);
lcd.init();
lcd.backlight();
lcd.print("welcom to store");

}
void loop() {
// put your main code here, to run repeatedly:
in_val=digitalRead(in);
out_val=digitalRead(out);


if(in_val==HIGH) {
count++;
lcd.setCursor(0,0);
delay(500);
lcd.clear();
lcd.print("welcom to store");
lcd.setCursor(0,1);
lcd.print(count);
digitalWrite(led, LOW);     // turn off LED3
  delay(300);
}
else if(out_val==HIGH) {
count--;
lcd.setCursor(0,0);
delay(500);
lcd.clear();
lcd.print("welcom to store");
lcd.setCursor(0,1);
lcd.print(count);
if(count<=0){
lcd.clear();
lcd.print("welcom to store");
}
digitalWrite(led, LOW);     // turn off LED3
  delay(300);
}
else if(count>=5) {
  lcd.clear();
lcd.setCursor(0,0);
delay(100);
lcd.print("PLZ wait");
   
  digitalWrite(led, HIGH);    // turn on LED3 
  delay(200);                  // wait for 200ms

  digitalWrite(led, LOW);     // turn off LED3
  delay(300);                  // wait for 300ms before running program all over again
}
}
