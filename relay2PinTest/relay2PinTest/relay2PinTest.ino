const int motorPin = 7; // check all pins if correct with logic without screen code
//const int heaterPin = 9; // You can change this to any digital pin
const int valvePin = 8; 
//const int SpeedPin = 5; // You can change this to any digital pin


void setup() 
{
  Serial.begin(9600);
  //pinMode(heaterPin, OUTPUT); // Set the pin as output
  pinMode(motorPin, OUTPUT); // Set the pin as output
  pinMode(valvePin, OUTPUT); // Set the pin as output
  //pinMode(SpeedPin, OUTPUT); // Set the pin as output

  digitalWrite(motorPin, HIGH); // Turn the pin OFF
  digitalWrite(valvePin, HIGH); // Turn the pin OFF
  //digitalWrite(heaterPin, HIGH); // Turn the pin OFF
  delay(2000);
}


void loop() 
{
  digitalWrite(motorPin, LOW); // Turn the pin ON
  digitalWrite(valvePin, HIGH); // Turn the pin OFF
  //digitalWrite(heaterPin, LOW); // Turn the pin ON
  Serial.println("Agetation started");
  delay(420000);  //7 minutes
  Serial.println("agetation completed");

  digitalWrite(motorPin, HIGH); // Turn the pin OFF
  digitalWrite(valvePin, LOW); // Turn the pin ON
  //digitalWrite(SpeedPin, LOW); // Turn the pin ON
  Serial.println("Drain started");
  delay(90000);  //1.5 minutes
  Serial.println("drain completed");

  //delay(1000);                // Wait for 1 second
  digitalWrite(motorPin, LOW);  // Turn the pin ON
  digitalWrite(valvePin, HIGH); // Turn the pin OFF
  //digitalWrite(heaterPin, HIGH); // Turn the pin OFF
  Serial.println("spin started");
  delay(300000);  //5 minutes.
  Serial.println("spin completed");

  digitalWrite(motorPin, HIGH); // Turn the pin OFF
  digitalWrite(valvePin, HIGH); // Turn the pin OFF
  //digitalWrite(SpeedPin, HIGH); // Turn the pin OFF
  delay(1000);                // Wait for 1 second

  while(true);
}
