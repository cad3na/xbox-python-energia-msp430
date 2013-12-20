xbox-python-energia-msp430
==========================

This is an attempt to control motors or LED's attached to an MSP430, through the signals from an Xbox Controller connected to a Mac.

# Dependencies.

The first thing I want to share with you is the collective of software needed to make this example work on a MacBook Air with OS X Mavericks.

## On the Python side.

### Python.

Well, that one is kind of obvious... but perhaps it's relevant to say that I'm using Python 2.7.6. There are many ways to obtain a python interpreter, the one I recommend is [conda](https://store.continuum.io/cshop/anaconda/).

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

## How they work.

All right then, let's say you have all the dependencies and you've downloaded this files, you've installed correctly the Energia IDE with the drivers for the Launchpad. Let's look at the steps for running all this code.

1. You need to open the code in the ```energia``` folder on the Energia IDE.
2. Make sure the Energia IDE knows the uC you're using (the only one that worked for me in this example is the 2553).
3. Compile the code.
4. Upload it to the Launchpad.

If you've successfully done this, take a minute to test the code is working properly with the aid of the Serial Monitor.

1. Make sure the serial port selected in the Energia IDE is the correct one (Tools -> Serial Port).
2. Fire up the Serial Monitor (Tools -> Serial Monitor).
3. Write a number from ```0``` to ```255``` and hit Return (or click Send).
4. A little ```:)``` should appear telling you that the Launchpad received the data and that it has set up the brightness accordingly.
5. You should try other values too (```0``` for completely off, something in between for dim, ```255``` for completely lit up and something higher will be taken as ```255```).

If everything went right in this stage, you're ready to move on to the Python script.

1. Open up the script with your favorite text editor/IDE (by the way I always recommend [Sublime Text](http://www.sublimetext.com)) and change the port name to the port name that appears as your Launchpad (as in the one that appears in your Energia IDE).
2. Run the Python script by either ```python controllertoserial.py``` on your terminal or from your text editor build command (what? not all of the text editors have build commands?).

If everything goes smoothly you should see that the LED goes off and it brights up depending on the displacement of the left trigger on your Xbox controller. If nothing happens perhaps pushing the RESET button on your Launchpad helps. When you're done playing around with it, you can press the central button on your controller to finish the execution of the script.

# Bugs!

This script doesn't handle well the syncronization between the Launchpad and the computer, meaning that from time this script won't work at all. Which bring me to the next section.

# Help make this better!

If you have corrections (or any comment whatsoever) make a pull request and make this example better.