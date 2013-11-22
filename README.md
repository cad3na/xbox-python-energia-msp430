xbox-python-energia-msp430
==========================

This is an attempt to control motors or LED's attached to an MSP430, through the signals from an Xbox Controller connected to a Mac.

# Dependencies.

The first thing I want to share with you is the collective of software needed to make this example work on a MacBook Air with OS X Mavericks.

## On the Python side.

### Python.

Well, that one is kind of obvious... but perhaps it's relevant to say that I'm using Python 2.7.5. There are many ways to obtain a python interpreter, the one I recommend is [brew](http://brew.sh).

### Pygame.

Pygame is a nice library for developing video games in Python (though I have only used the Joystick part of it, it is reference when someone asks about developing video games in Python).

There are some dependencies that I could install from [brew](http://brew.sh).

    brew install sdl
    brew install sdl_image
    brew install sdl_mixer
    brew install sdl_ttf
    brew install portmidi
    brew install mercurial

What I found is that the pip version of pygame is not working, so just go ahead and:

    pip install hg+http://bitbucket.org/pygame/pygame

### Pyserial.

Pyserial is just a simple and reliable library for communicating over serial.

    pip install pyserial

## On the Energia side.

First you need to install [Energia](http://energia.nu). When you download it, you copy the app, and install the driver for the MSP430 boards (this is the only way that I've been able to use my MSP430 Launchpad with my Mac, and that alone is a very good reason to try it out). The Energia system is a fork of the Arduino, that allows you to work with the Launchpad ecosystem with a higher level of abstraction, and reusing many examples from the Arduino community.

## On the real side.

I'm using a *Rev 1.5 Launchpad board* with an *MSP430G2553*. This is important! I struggled for hours with the serial communication before realizing that I was doing it all wrong. With Energia you'll want to use *Hardware UART*. Software UART is too slow to give you reliable readings. The instructions for enabling the Hardware UART are [here](http://www.energia.nu/Serial.html).

## Xbox 360 Controller driver.

I used [this](http://tattiebogle.net/index.php/ProjectRoot/Xbox360Controller/OsxDriver) driver to connect my Xbox 360 Controller to my Mac (there are official drivers for Windows already available from Microsoft).

This one I'm not pretty sure if it is a dependency because I installed it prior to the development of this example (who doesn't like to play old snes games?), although I'm suspecting it is.

# The scripts.

The scripts on this repo are only an example of what can be done, I don't expect them to be very useful to everyone, except for folks like me that are learning how to interface from the real world to a computer and back.

I provide a simple example of how the serial part works, how the controller part works, and finally how to put it together.

At this point, the code lacks good comments, and is not as good as it should be, but it's working for me.

## On the Energia side.

The script for Energia is marked in the repo as Arduino code, because it does work with Arduino, so if you're used to the system, you should think about getting a Launchpad too and make it work with Energia (the board is cheaper, and in the Value line you can actually detach the uC from the board and put it into a PCB).

The script is simple, it receives a signal from the serial port to set the brightness of the GREEN_LED attached to the Launchpad, and sends a signal to say it's ready for another one.

## On the Python side.

The python script is actually pretty simple too. Imports and initializes the libraries needed to get the signal from the Xbox controller and the MPS430. Then it looks for the signal from the MSP430 to tell the script that it can begin to send data. Refreshes the data from the Xbox controller and sends out the data to the MSP430 (the Xbox controller sends values between -1 and 1, so it's mapped from 0 to 255).

# Help make this better!

If you have corrections (or any comment whatsoever) make a pull request and make this example better.