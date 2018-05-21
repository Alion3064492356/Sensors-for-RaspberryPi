
#!/usr/bin/env python
import RPi.GPIO as GPIO
import time

ReedPin = 11
LedPin  = 16

def setup():
	GPIO.setmode(GPIO.BOARD)       # Numbers GPIOs by physical location
	GPIO.setup(LedPin, GPIO.OUT)   # Set LedPin's mode is output
	GPIO.setup(ReedPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
	GPIO.output(LedPin, GPIO.LOW) # Set LedPin low to off led


def loop():
	while True:
	    if(GPIO.input(ReedPin) == 0):
	        print "Magnet detected - LED on!"
		GPIO.output(LedPin,GPIO.HIGH)
	    else:
	        print "No magnet detected - LED off!"
                GPIO.output(LedPin, GPIO.LOW)
            time.sleep(0.2)	

def destroy():
	GPIO.output(LedPin, GPIO.LOW)     # led off
	GPIO.cleanup()                     # Release resource

if __name__ == '__main__':     # Program start from here
	setup()
	try:
		loop()
	except KeyboardInterrupt:  # When 'Ctrl+C' is pressed, the child program destroy() will be  executed.
		destroy()


