int pumpPin= 2;
int moistureSensor= A0;
int moisture_sensor_read;
int moisturelevel;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(pumpPin,OUTPUT);
}

void loop() {
  
moisture_sensor_read=analogRead(moistureSensor);

moisturelevel=map(moisture_sensor_read,0,1023,0,100);

Serial.println(moisture_sensor_read);

if(moisturelevel >=30)
{
  digitalWrite(pumpPin,HIGH);
  }

  else
{
  digitalWrite(pumpPin,LOW);
}
}
