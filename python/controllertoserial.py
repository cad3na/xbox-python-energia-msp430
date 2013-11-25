# Import all the needed libraries
import pygame
import serial

# Declares a variable to hold the name of my Launchpad serial port
# You should change the port name here
port = "/dev/tty.uart-0AFF4676258A174C"

# Initializes the pygame module
pygame.init()

# Declares an object of type Joystick (with the first controller found)
xcon = pygame.joystick.Joystick(0)
xcon.init()

# Declares an object of type Serial opening the port my Launchpad is in
msp = serial.Serial(port)

# Main loop for reading the serial and sending data
while True:
	if msp.readable():
		if msp.read(4) == ":)\r\n":
			pygame.event.pump()
			if xcon.get_button(10) == 1:
				break
			axis = xcon.get_axis(4)
			axis = (axis + 1)*128
			axis_str = str(int(axis))
			msp.write(axis_str)

# Closes pygame and the serial port
pygame.quit()
msp.close()