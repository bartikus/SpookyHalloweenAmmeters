/*
 * SpookyHalloweenAmmeters.ino
 *
 * Created: 6/25/2017 2:28:01 PM
 * Author: Bartikus
 */ 


const int potPin=A0;
const int pulsePin=5;

void setup()
{
	Serial.begin(115200);
	Serial.println("//////////////////////////////////////");
	Serial.println("Arduino Ammeter Controller by Bartikus");
	Serial.println("//////////////////////////////////////");
	Serial.println();
	Serial.println("Real-time debug output: ");
	
	pinMode(potPin, INPUT);
	pinMode(pulsePin, OUTPUT);
}

void loop()
{
	unsigned int potVal = analogRead(potPin);
	unsigned int pwmVal = map(potVal,0,1023,0,255);
	Serial.print("Pot: "); Serial.print(potVal); Serial.print(" PWM: "); Serial.println(pwmVal);
	analogWrite(pulsePin,pwmVal);
	delay(350);
	analogWrite(pulsePin,0);
	delay(20);
}
