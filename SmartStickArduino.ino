#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);


const int trigPin = 5;
const int echoPin = 6;

void setup() {
  // initialize serial communication:

//lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(3,OUTPUT);
digitalWrite(3,LOW);
 pinMode(2,OUTPUT);
digitalWrite(2,LOW);
 
  // Print a message to the LCD.
   
lcd.setCursor(0 ,0);  
lcd.print("Advance fuel  ");
lcd.setCursor(0 ,1);    
lcd.print("Tank Monitoring ");
delay(2000);
//lcd.clear();




}

void loop()
{

  int temp1 = analogRead(A0);

int a= temp1*0.49;
Serial.println(a);
if (a>40.00){
  digitalWrite(2,HIGH);
  delay(500);
}
if (a<40.00){
  digitalWrite(2,LOW);
}

  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  
if (cm<25&&cm>20)
{
  digitalWrite(3,HIGH);
  delay(500);
  digitalWrite(3,LOW);
  delay(500);
}
if(cm<20&&cm>15){
  digitalWrite(3,HIGH);
  delay(400);
  digitalWrite(3,LOW);
  delay(400);
}
if(cm<15&&cm>10){
  digitalWrite(3,HIGH);
  delay(300);
  digitalWrite(3,LOW);
  delay(300);
}
if(cm<10&&cm>5){
  digitalWrite(3,HIGH);
  delay(200);
  digitalWrite(3,LOW);
  delay(200);
}
if(cm<5){
  digitalWrite(3,HIGH);
  delay(100);
  digitalWrite(3,LOW);
  delay(100);
}
  
 //delay(500);
}



long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
