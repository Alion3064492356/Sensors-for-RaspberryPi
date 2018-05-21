#!/usr/bin/env python
import RPi.GPIO as GPIO
import ADC0832
import time

Reed_DO_PIN = 15
LedPin = 16
thresholdVal = 100

def init():
	GPIO.setmode(GPIO.BOARD)	
	GPIO.setup(Reed_DO_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
	GPIO.setup(LedPin, GPIO.OUT)
	ADC0832.setup()
	
def loop():	
    while True:
        global digitalVal, analogVal
        digitalVal = GPIO.input(Reed_DO_PIN)
        if(digitalVal == 1):
            print 'DO is %d' % digitalVal
	    analogVal = ADC0832.getResult(0)
	    print 'Current analog value is %d'% analogVal 
	    if(analogVal < thresholdVal):
		GPIO.output(LedPin, GPIO.HIGH)
		time.sleep(0.2)
        else:
            GPIO.output(LedPin, GPIO.LOW)

if __name__ == '__main__':
	init()
	try:
		loop()
	except KeyboardInterrupt: 
		ADC0832.destroy()
		print 'The end !'
