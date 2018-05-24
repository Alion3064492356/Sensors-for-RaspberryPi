#!/usr/bin/env python
import time
import RPi.GPIO as GPIO

LedPin = 16
SensorPin = 11

def init():
        GPIO.setmode(GPIO.BOARD)
	GPIO.setup(LedPin, GPIO.OUT)
	GPIO.setup(SensorPin, GPIO.IN)

def loop():
	while True:
		if(GPIO.input(SensorPin)):
			GPIO.output(LedPin, GPIO.LOW)
		else:
			GPIO.output(LedPin, GPIO.HIGH)
		time.sleep(0.2)	
		
if __name__ == '__main__':
	init()
	try:
		loop()
	except KeyboardInterrupt: 
		print 'The end !'
