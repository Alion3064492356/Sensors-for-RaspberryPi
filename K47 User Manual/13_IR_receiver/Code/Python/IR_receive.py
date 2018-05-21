#!/usr/bin/env python
import RPi.GPIO as GPIO
import time

IrPin  = 11
LedPin = 16

Led_status = 1

def setup():
	GPIO.setmode(GPIO.BOARD)       # Numbers GPIOs by physical location
	GPIO.setup(LedPin, GPIO.OUT)   # Set LedPin's mode is output
	GPIO.setup(IrPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
	GPIO.output(LedPin, GPIO.LOW) # Set LedPin low to off led

def swLed(ev=None):
	global Led_status
	Led_status = not Led_status
	GPIO.output(LedPin, Led_status)  # switch led status(on-->off; off-->on)
	print("receive signal!\n")
	time.sleep(0.1)
	GPIO.output(LedPin, False)

def loop():
	GPIO.add_event_detect(IrPin, GPIO.FALLING, callback=swLed) # wait for falling
	while True:
		pass   # Don't do anything

def destroy():
	GPIO.output(LedPin, GPIO.LOW)     # led off
	GPIO.cleanup()                     # Release resource

if __name__ == '__main__':     # Program start from here
	setup()
	try:
		loop()
	except KeyboardInterrupt:  # When 'Ctrl+C' is pressed, the child program destroy() will be  executed.
                print("KeyboardInterrupt.\n")
		destroy()

