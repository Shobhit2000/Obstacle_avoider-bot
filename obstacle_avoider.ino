int trig=A2;
int echo=A1;
#define l1 9 //arduino pin 3 to input pin 1 (IN3) of motor driver (LEFT WHEEL)
#define l2 3 //arduino pin 5 to input pin 2 (IN4) of motor driver (LEFT WHEEL)
#define r1 11//arduino pin 6 to input pin 3 (IN1) of motor driver (RIGHT WHEEL)
#define r2 10//arduino pin 9 to input pin 4 (IN2) of motor driver (RIGHT WHEEL)
long duration;
long distance;
void setup() {
  Serial.begin(9600);
 pinMode(l1,OUTPUT);
 pinMode(l2,OUTPUT);
 pinMode(r1,OUTPUT);
 pinMode(r2,OUTPUT);
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration= pulseIn(echo,HIGH);
  distance=(duration*0.034)/2;
  Serial.println(distance);
  if(distance<=15)
  {
    right();
    delay(600);
  }
  else
  {
    forward();
  }
}
void forward()
{
  analogWrite(l1,175);
  analogWrite(l2,0);
  analogWrite(r1,175);
  analogWrite(r2,0);
}
void right()
{
  analogWrite(l1,0);
  analogWrite(l2,175);
  analogWrite(r1,175);
  analogWrite(r2,0);
}
