#include <wiringPi.h>
#include <stdio.h>

#define IrPin    0
#define ledPin	  4

int main(void)
{
	if(wiringPiSetup() == -1)
	{ 
		printf("setup wiringPi failed !\n");
		return -1; 
	}

	pinMode(IrPin, OUTPUT);

	while(1)
	{
		digitalWrite(IrPin, HIGH);
		digitalWrite(ledPin, HIGH);
		printf("IrPin is set High\n");
		delay(1000);
		
		digitalWrite(IrPin, LOW);
		digitalWrite(ledPin, LOW);
		printf("IrPin is set Low\n");
		delay(1000);
	}
	return 0;
}
