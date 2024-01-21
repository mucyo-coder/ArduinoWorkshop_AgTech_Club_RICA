// Listing 6-3

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));  
}
int array[5];    // define our array of five integer elements
void loop()
{
  int i;
  Serial.println();
  for ( i = 0 ; i < 5 ; i++ )   // write to the array
  {
    array[i] = random(10);      // random numbers from 0 to 9
  }
  for ( i = 0 ; i < 5 ; i++ )   // display the contents of the array
  {
    Serial.print("array[");
    Serial.print(i);
    Serial.print("] contains ");
    Serial.println(array[i]); 
  }
  delay(5000);
}
