#include <wiringPi.h>
#include <stdio.h>

#define TouchPin    0
#define LedPin      4

int main(void)
{
	if(wiringPiSetup() == -1)
	{ 
		printf("setup wiringPi failed !");
		return -1; 
	}
	
	pinMode(TouchPin, INPUT);
	pinMode(LedPin,  OUTPUT);

	while(1)
	{
		if(digitalRead(TouchPin) == HIGH)
		{
			printf("touched\n");
			digitalWrite(LedPin, HIGH);     //led on
			delay(100);
			digitalWrite(LedPin, LOW);    //led off
		}	
	}

	return 0;
}
