// Project 35 - Creating a Three-Zone Touch Switch
int x,y = 0;
void setup()
{
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}
void switchOn()
{
  digitalWrite(3, HIGH);
  delay(200);
}
void switchOff()
{
  digitalWrite(3, LOW);
  delay(200);
}
void setBrightness()
{
 int PWMvalue;
 PWMvalue=map(x, 80, 950, 0, 255);
 analogWrite(3, PWMvalue);
}
int readX() // returns the value of the touchscreen's x-axis
{
  int xr=0;
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  digitalWrite(A1, LOW); // set A1 to GND
  digitalWrite(A3, HIGH); // set A3 as 5V
  delay(5);
  xr=analogRead(0);
  return xr;
}
int readY() // returns the value of the touchscreen's y-axis
{
  int yr=0;
  pinMode(A0, OUTPUT); // A0
  pinMode(A1, INPUT); // A1
  pinMode(A2, OUTPUT); // A2
  pinMode(A3, INPUT); // A3
  digitalWrite(A0, LOW); // set A0 to GND
  digitalWrite(A2, HIGH); // set A2 as 5V
  delay(5);
  yr=analogRead(1);
  return yr;
}
void loop()
{
  x=readX();
  y=readY();
  // test for ON
  if (x<=950 && x>=515 && y>= 500 && y>900)
  {
    switchOn();
  }
  // test for OFF
  if (x>80 && x<515 && y>= 500 && y>900)
  {
    switchOff();
  }
  // test for brightness
 if (y>=100 && y<=500)
  {
    setBrightness();
  }
  Serial.println(x);
}
