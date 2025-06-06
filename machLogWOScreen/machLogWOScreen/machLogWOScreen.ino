#include <Arduino.h>
//#include <OneWire.h>
//#include <Dalla HIGHerature.h>

// Pins
const uint8_t motorPwmPin = 7;           // PWM signal to VFD or ESC (motor control)
const uint8_t drainRelayPin = 8;         // Relay for drain valve/pump
const uint8_t heaterRelayPin = 9;        // Relay to control heater
const uint8_t motorDirectionPin = 5;  //input to motor to change direction CW  HIGH) CCW LOW)
const uint8_t temperatureSensePin = A0;  //input to mcu to read temperature value.
/*
  const uint8_t waterLevelPin = 2;         // Water level sensor  LOW when full) not needed yet
  const uint8_t HIGHSensorPin = 6;         // 1-Wire HIGH sensor (DS18B20)
*/

/*
  //Interrupt variables for the temperature monitoring pin.
  volatile uint8_t temperatureValue = analogRead(A0);
  addInterrupt(pinToInterrupt(temperatureSensePin), temperatureControlISR(), RISING);
*/

/* 
  //Temperature measurement protocol (one wire)
  OneWire oneWire HIGHSensorPin);
  Dalla HIGHerature sensors(&oneWire);
*/

/*
  //Constants
  const float targe HIGH = 100.0;       // Target HIGHerature in Celsius
  const uint16_t agitationSpeed = 180;       // PWM value for 360 RPM (scale to your VFD)
  const uint16_t spinSpeed = 90;             // PWM for 180 RPM (adjust as needed)
*/ 


void setup() 
{
  //inMode(waterLevelPin, INPUT);
  pinMode(motorPwmPin, OUTPUT);
  pinMode(heaterRelayPin, OUTPUT);
  pinMode(drainRelayPin, OUTPUT);
  
  Serial.begin(9600);
  //sensors.begin();

  // Turn everything off initially
  //digitalWrite(heaterRelayPin, HIGH);
  digitalWrite(heaterRelayPin, HIGH);
  digitalWrite(drainRelayPin, HIGH);
  digitalWrite(motorPwmPin, HIGH);  //analogWrite(motorPwmPin, 0);
  //******change to analogWrite for motorpwmpin when done.
  delay(2000);
}


void loop() 
{
  //fillWaterUntilLevel();
  //heatWaterT HIGHerature(targe HIGH);
  //runHeatingCycle(5 * 60 * 1000);   //heat for 5 minutes in milliseconds.
  runHeatingCycle();   //heat for 5 minutes in milliseconds.
  runAgitationCycle(600000);  //agitate for 10 minutes in milliseconds.
  drainWater(60000);   //drain for 1 minute in milliseconds.
  runSpinCycle(300000);        //spin for 5 minutes in milliseconds.

  digitalWrite(heaterRelayPin, HIGH);
  digitalWrite(drainRelayPin, HIGH);
  digitalWrite(motorPwmPin, HIGH);
  
  while (true);  // Stop program
}



// --- Function Definitions ---
//void runHeatingCycle(unsigned long duration) 
void runHeatingCycle() 
{
  Serial.println("Heating started...");
  uint8_t t = 0;
  while(t < 100)
  {
    digitalWrite(heaterRelayPin, LOW);
    t += 5;
    Serial.println("temp is: ");
    Serial.println(t);
    Serial.println("oC.");
    delay(2000);
  }

  digitalWrite(heaterRelayPin, HIGH);
  Serial.println("100 degrees reached, heating complete");

  // unsigned long heatingStartTime = millis();
  // //digitalWrite(heaterRelayPin, LOW);

  // while ((millis() - heatingStartTime) < duration) 
  // {
  //   digitalWrite(heaterRelayPin, LOW);
  //   //delay(1000);
  // }

  // digitalWrite(heaterRelayPin, HIGH);
  // Serial.println("Heating complete.");
  // //delay(20);
}



void runAgitationCycle(unsigned long durationA) 
{
  Serial.println("Starting agitation...");
  unsigned long agitationStartTime = millis();
  //analogWrite(motorPwmPin, agitationSpeed);  //******chang back to this!! when done
  digitalWrite(motorPwmPin, LOW);

  while ((millis() - agitationStartTime) < durationA) 
  {
    // You can toggle direction here if needed with another pin
    digitalWrite(motorDirectionPin, 0);   //CW
    Serial.println("rotating Clockwise...");
    Serial.println(digitalRead(motorDirectionPin));
    delay(5000);  // Maintain speed and direction
    digitalWrite(motorDirectionPin, 1);   //CCW
    Serial.println("rotating Counterclockwise...");
    Serial.println(digitalRead(motorDirectionPin));
    delay(5000);  // Maintain speed and direction
  }

  digitalWrite(motorPwmPin, HIGH);
  //analogWrite(motorPwmPin, 0);
  Serial.println("Agitation complete.");
}


void drainWater(unsigned long durationD) 
{
  Serial.println("Draining water...");
  unsigned long drainStartTime = millis();
  digitalWrite(drainRelayPin, LOW);
  //analogWrite(motorPwmPin, spinSpeed); change to this when done!!

  while ((millis() - drainStartTime) < durationD) 
  {
    delay(1000);  // Maintain spin
  }

  digitalWrite(drainRelayPin, HIGH);
  Serial.println("Drain complete.");
}


void runSpinCycle(unsigned long durationS) 
{
  Serial.println("Spinning...");
  unsigned long spinStartTime = millis();
  digitalWrite(motorPwmPin, LOW);
  //analogWrite(motorPwmPin, spinSpeed); change to this when done!!

  while ((millis() - spinStartTime) < durationS) 
  {
    delay(1000);  // Maintain spin
  }

  digitalWrite(motorPwmPin, HIGH);
  //analogWrite(motorPwmPin, 0);   change to this when done.
  Serial.println("Spin complete.");
}



// void fillWaterUntilLevel() 
//{
//   Serial.println("Filling water...");
//   while (digitalRead(waterLevelPin) == HIGH) {
//     // Wait until water level sensor goes LOW
//     delay(500);
//   }
//   Serial.println("Water filled.");
//}


// void heatWaterT HIGHerature(float target) 
//{
//   Serial.println("Heating water...");
//   digitalWrite(heaterRelayPin, LOW);
//   while (true) 
//   {
//     sensors.requestHIGHTemperatures();
//     float HIGHC = sensors.getHIGHCByIndex(0);
//     Serial.print("HIGH: ");
//     Serial.println(HIGHC);

//     if  HIGHC >= target) 
//     {
//       digitalWrite(heaterRelayPin, HIGH);
//       Serial.println("Water heated to 100°C.");
//       break;
//     }
//     delay(1000);
//   }
//}


// void temperatureControlISR()   //temperature control service routine during the entire cycle.
// {
//   volatile uint8_t temperatureValue = map(analogRead(A0), 1, 1023, 0, 200);   //temp val celcius.

//   if(temperatureValue != 100)
//   {
//     if(temperatureValue < 100)
//     {
//       digitalWrite(heaterRelayPin, LOW);
//     }
//     if(temperatureValue > 100)
//     {
//       digitalWrite(heaterRelayPin, HIGH);
//     }
//   }
// }