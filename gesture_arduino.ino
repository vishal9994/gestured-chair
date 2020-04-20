int LMT1=6,LMT2=7; // Motor Terminals M1
int RMT1=8,RMT2=9; // Motor Terminals M2
int X=A2; // X Axis is given to A2
int Y=A1; // Y Axis is given to A1
int Xvalue,Yvalue; // Variables for storing the value
#define enA 10 // Enable Pin for motor 1
#define enB 11 // Enable Pin for motor 2
void setup()
{
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(LMT1,OUTPUT); // Motors are declared as output
pinMode(LMT2,OUTPUT);
pinMode(RMT1,OUTPUT);
pinMode(RMT2,OUTPUT);
pinMode(X,INPUT); // A2 & A1 pins are declared as input
pinMode(Y,INPUT);
}
void loop()
{
Xvalue=analogRead(X); // X axis values stored in a variable
Yvalue=analogRead(Y);
Serial.print(Xvalue); // Y axis values stored in a variable
Serial.print(Yvalue);
if(Xvalue>=345 && Xvalue<=360 && Yvalue>=340 && Yvalue<=355) // The boundary values are set to stop the motors
{
Stop();
}
else if(Xvalue>=388 && Xvalue<=410) // The X axis values are used for vertical movement
{
forward();
}
else if(Xvalue>=270 && Xvalue<=305)
{
back();
}
else if(Yvalue>=280 && Yvalue<=300) // The Y axis values are used for horizontal movement
{
left();
}
else if(Yvalue>=375 && Yvalue<=410)
{
right();
}
}
void forward() // forward function is defined
{
for (int i = 0; i < 256; i+=20) //accelerating the motors
{
analogWrite(enA, i);
analogWrite(enB, i);
}
digitalWrite(LMT1,HIGH);
digitalWrite(LMT2,LOW);
digitalWrite(RMT1,HIGH);
digitalWrite(RMT2,LOW);
}
void back() // backward function is defined
{
for (int i = 0; i < 256; i+=20) //accelerating the motors
{
analogWrite(enA, i);
analogWrite(enB, i);
delay(20);
}
digitalWrite(LMT1,LOW);
digitalWrite(LMT2,HIGH);
digitalWrite(RMT1,LOW);
digitalWrite(RMT2,HIGH);
}
void left() // left function is defined
{
digitalWrite(LMT1,HIGH);
digitalWrite(LMT2,LOW);
digitalWrite(RMT1,LOW);
digitalWrite(RMT2,HIGH);
}
void right() // right function is defined
{
digitalWrite(LMT1,LOW);
digitalWrite(LMT2,HIGH);
digitalWrite(RMT1,HIGH);
7
digitalWrite(RMT2,LOW);
}
void Stop() // stop function is defined
{
for (int i = 255; i > 0; --i) //deaccelerating the motors
{
analogWrite(enA, i);
analogWrite(enB, i);
delay(20);
}
digitalWrite(LMT1,LOW);
digitalWrite(LMT2,LOW);
digitalWrite(RMT1,HIGH);
digitalWrite(RMT2,HIGH);
}
