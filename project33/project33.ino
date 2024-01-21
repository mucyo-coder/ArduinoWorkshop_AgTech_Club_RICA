// Project 33 - Addressing Areas on the Touchscreen

int x,y = 0;

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
  xr=analogRead(0); // store the value of the x-axis
  return xr;
}

int readY() // returns the value of the touchscreen's y-axis
{
  int yr=0;
  pinMode(A0, OUTPUT); // A0
  pinMode(A1, INPUT); // A1
  pinMode(A2, OUTPUT); // A2
  pinMode(A3, INPUT); // A3
  digitalWrite(14, LOW); // set A0 to GND
  digitalWrite(16, HIGH); // set A2 as 5V
  delay(5);
  yr=analogRead(1); // store the value of the y-axis
  return yr;
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print(" x = ");
  x=readX();
  Serial.print(x);
  y=readY();
  Serial.print(" y = ");
  Serial.println(y);
  delay (200);
}
