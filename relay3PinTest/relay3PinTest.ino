const int motorPin = 7; // check all pins if correct with logic without screen code
const int valvePin = 8; 
const int heaterPin = 9; // You can change this to any digital pin
//const int SpeedPin = 5; // You can change this to any digital pin


void setup() 
{
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT); // Set the pin as output
  pinMode(valvePin, OUTPUT); // Set the pin as output
  pinMode(heaterPin, OUTPUT); // Set the pin as output
  //pinMode(SpeedPin, OUTPUT); // Set the pin as output

  digitalWrite(motorPin, HIGH); // Turn the pin OFF
  digitalWrite(valvePin, HIGH); // Turn the pin OFF
  digitalWrite(heaterPin, HIGH); //turn off.
  delay(2000);
}


void loop() 
{
  heat();
  agitate();
  drain();
  spin();
  reset();
}


void heat()
{
  digitalWrite(heaterPin, LOW); // Turn the pin On
  digitalWrite(motorPin, HIGH); // Turn the pin Off
  digitalWrite(valvePin, HIGH); // Turn the pin OFF
  
  Serial.println("heating started");
  delay(10000);
  Serial.println("heating complete");
}


void agitate()
{
  digitalWrite(motorPin, LOW); // Turn the pin ON
  digitalWrite(valvePin, HIGH); // Turn the pin OFF
  digitalWrite(heaterPin, HIGH); // Turn the pin Off
  Serial.println("Agetation started");
  delay(30000);
  Serial.println("Agetation complete");
  delay(500);
}


void drain()
{
  digitalWrite(motorPin, HIGH); // Turn the pin OFF
  digitalWrite(valvePin, LOW); // Turn the pin ON
  digitalWrite(heaterPin, HIGH); // Turn the pin Off
  Serial.println("Drain started");
  delay(10000);
  Serial.println("drain complete");
  delay(500);
  //delay(1000);                // Wait for 1 second
}


void spin()
{
  digitalWrite(motorPin, LOW);  // Turn the pin ON
  digitalWrite(valvePin, HIGH); // Turn the pin OFF
  digitalWrite(heaterPin, HIGH); // Turn the pin OFF
  Serial.println("spin started");
  delay(15000);
  Serial.println("Spin complete");
  delay(500);
}


void reset()
{
  digitalWrite(motorPin, HIGH); // Turn the pin OFF
  digitalWrite(valvePin, HIGH); // Turn the pin OFF
  digitalWrite(heaterPin, HIGH); // Turn the pin OFF
  Serial.println("Cycle complete");
  delay(500);                // Wait for 1 second

  while(true);
}