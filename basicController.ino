/*
 * Very simple pump switch using pin 3 with a miliseconds delay in the loop
 * 
 * 1  minute  =   60000 miliseconds
 * 5  minutes =  300000 miliseconds
 * 15 minutes =  900000 miliseconds
 * 30 minutes = 1800000 miliseconds
 * 60 minutes = 3600000 miliseconds
 *
 */

int ledPin = 13;
int pumpPin = 3;

void setup()
{   
  pinMode(ledPin, OUTPUT);   
  pinMode(pumpPin, OUTPUT);   
	
  Serial.begin(9600);
  Serial.println("Lets start this pump");
  delay(2000);
}

void loop()
{   
  digitalWrite(ledPin, HIGH);    // Turn the led on
  digitalWrite(pumpPin, HIGH);   // Turn the pump on
  Serial.println("Pump on");
  
  delay(60000);                 // wait for 1 minute
  
  digitalWrite(ledPin, LOW);    // Turn the led off
  digitalWrite(pumpPin, LOW);   // Turn the pump off
  Serial.println("Pump off");
  
  delay(1800000);               // wait for half an hour
}
