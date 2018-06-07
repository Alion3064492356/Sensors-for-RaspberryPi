#include <wiringPi.h>
#include <stdio.h>

typedef unsigned char uchar;
typedef unsigned int  uint;

#define     ADC_CS    0
#define     ADC_CLK   1
#define     ADC_DIO   2
#define     LedPin      4
#define	    Threshold	100

uchar get_ADC_Result(void)
{
	
	uchar i;
	uchar dat1=0, dat2=0;

	digitalWrite(ADC_CS, 0);

	digitalWrite(ADC_CLK,0);
	digitalWrite(ADC_DIO,1);	delayMicroseconds(2);
	digitalWrite(ADC_CLK,1);	delayMicroseconds(2);
	digitalWrite(ADC_CLK,0);

	digitalWrite(ADC_DIO,1);    delayMicroseconds(2); 
	digitalWrite(ADC_CLK,1);	delayMicroseconds(2);
	digitalWrite(ADC_CLK,0);

	digitalWrite(ADC_DIO,0);	delayMicroseconds(2); 
	
	digitalWrite(ADC_CLK,1);	
	digitalWrite(ADC_DIO,1);    delayMicroseconds(2);
	digitalWrite(ADC_CLK,0);	
	digitalWrite(ADC_DIO,1);    delayMicroseconds(2);
	
	for(i=0;i<8;i++)
	{
		digitalWrite(ADC_CLK,1);	delayMicroseconds(2);
		digitalWrite(ADC_CLK,0);    delayMicroseconds(2);

		pinMode(ADC_DIO, INPUT);
		dat1=dat1<<1 | digitalRead(ADC_DIO);
	}
	
	for(i=0;i<8;i++)
	{
		dat2 = dat2 | ((uchar)(digitalRead(ADC_DIO))<<i);
		digitalWrite(ADC_CLK,1); 	delayMicroseconds(2);
		digitalWrite(ADC_CLK,0);    delayMicroseconds(2);
	}

	digitalWrite(ADC_CS,1);

	pinMode(ADC_DIO, OUTPUT);
	
	return(dat1==dat2) ? dat1 : 0;
}

int main(void)
{
	uchar tmp;

	if(wiringPiSetup() == -1)
	{
		printf("setup wiringPi failed !");
		return -1; 
	}

	pinMode(ADC_CS,  OUTPUT);
	pinMode(ADC_CLK, OUTPUT);
	pinMode(LedPin,  OUTPUT);

	while(1)
	{
		pinMode(ADC_DIO, OUTPUT);
		tmp = get_ADC_Result();
		printf("%d\n",tmp);

		if(tmp > Threshold)
		{
			digitalWrite(LedPin, LOW);
			delay(1000);
			digitalWrite(LedPin, HIGH);
			printf("\n***********	\
				\n  Danger!    \
				\n***********  \
				\n");
			delay(1000);
		}
		else
		{
			digitalWrite(LedPin, LOW);
		}
		delay(100);
	}

	return 0;
}
