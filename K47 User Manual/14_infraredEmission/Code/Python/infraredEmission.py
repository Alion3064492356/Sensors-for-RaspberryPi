#!/usr/bin/env python
import RPi.GPIO as GPIO
import time

IrPin = 11    # pin11
ledPin = 16

def setup():
	GPIO.setmode(GPIO.BOARD)       # Numbers GPIOs by physical location
	GPIO.setup(IrPin, GPIO.OUT)   # Set IrPin's mode is output
	GPIO.setup(ledPin, GPIO.OUT)

def loop():
	while True:
		print '...IrPin high'
		GPIO.output(IrPin, GPIO.HIGH)  # IrPin on
		GPIO.output(ledPin, GPIO.HIGH)
		time.sleep(0.5)
		print 'IrPin low...'
		GPIO.output(IrPin, GPIO.LOW) # IrPin off
		GPIO.output(ledPin, GPIO.LOW)
		time.sleep(0.5)

def destroy():
	GPIO.output(IrPin, GPIO.LOW)       # IrPin off
	GPIO.cleanup()                     # Release resource

if __name__ == '__main__':     # Program start from here
	setup()
	try:
		loop()
	except KeyboardInterrupt:  # When 'Ctrl+C' is pressed, the child program destroy() will be  executed.
		destroy()

