#!/usr/bin/env python

#
# This is a program for JoystickPS2 Module.
# This program depend on ADC0832 ADC chip.
#

import ADC0832
import RPi.GPIO as GPIO
import time

btn = 15	

def setup():
	ADC0832.setup()										# Setup ADC0832
	GPIO.setmode(GPIO.BOARD)							# Numbers GPIOs by physical location
	GPIO.setup(btn, GPIO.IN, pull_up_down=GPIO.PUD_UP)	# Setup button pin as input an pull it up
	global state
	state = ['up', 'down', 'left', 'right']	

def getResult():										#get joystick result
	if ADC0832.getResult(1) == 0:
		return 1		#up
	if ADC0832.getResult(1) == 255:
		return 2		#down

	if ADC0832.getResult(0) == 0:
		return 3		#left
	if ADC0832.getResult(0) == 255:
		return 4		#right

	if GPIO.input(btn) == 0:
		print 'Button is pressed!'						# Button pressed

def loop():
	while True:
		tmp = getResult()
		if tmp != None:
			print state[tmp - 1]
                time.sleep(0.2)

def destory():
	GPIO.cleanup()										# Release resource

if __name__ == '__main__':								# Program start from here
	setup()
	try:
		loop()
	except KeyboardInterrupt:  	
		destory()