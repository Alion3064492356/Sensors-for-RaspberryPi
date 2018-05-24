#include <wiringPi.h>
#include <stdio.h>

#define    IrEmissionPin    0
#define	   IrReceiverPin	16
#define	   LedPin	4

int cnt = 0;

void myISR(void)
{
	printf("Recevied infrared. cnt = %d\n", ++cnt);
	if(digitalRead(LedPin) == HIGH)
	{
		digitalWrite(LedPin, LOW);	
	}
    else
	{
		digitalWrite(LedPin, HIGH);
	}	
	delay(100);
	digitalWrite(LedPin, LOW);	
}

int main(void)
{
	if(wiringPiSetup() == -1)
	{ 
		printf("setup wiringPi failed !\n");
		return -1; 
	}
	pinMode(LedPin, OUTPUT);
	pinMode(IrEmissionPin, OUTPUT);
	pinMode(IrReceiverPin, INPUT);
	pullUpDnControl(IrReceiverPin, PUD_UP) 
	
	if(wiringPiISR(IrReceiverPin, INT_EDGE_FALLING, &myISR) == -1)
	{
		printf("setup ISR failed !");
		return -1;
	}
	while(1)
	{
		digitalWrite(IrEmissionPin, HIGH);
		printf("IrEmissionPin is set High\n");
		delay(500);
		
		digitalWrite(IrEmissionPin, LOW);
		printf("IrEmissionPin is set Low\n");
		delay(500);
	}
	
	return 0;
}
