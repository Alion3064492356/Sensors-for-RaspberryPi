#include <wiringPi.h>
#include <stdio.h>

#define    IrPin    0
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
	
	if(wiringPiISR(IrPin, INT_EDGE_FALLING, &myISR) == -1)
	{
		printf("setup ISR failed !");
		return -1;
	}
	while(1);
	
	return 0;
}
