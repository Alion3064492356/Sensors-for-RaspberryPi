
#include <wiringPi.h>
#include <stdio.h>

#define RelayPin      16
#define LedPin		  4

int main(void)
{
	if(wiringPiSetup() == -1)
	{
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(RelayPin, OUTPUT);
	pinMode(LedPin, OUTPUT);
	digitalWrite(LedPin, HIGH);
	while(1)
	{
			digitalWrite(RelayPin, HIGH);
			delay(500);
			digitalWrite(RelayPin, LOW);
			delay(500);
	}

	return 0;
}
