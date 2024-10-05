#Binary Counter LED Project

#Project Overview
This project demonstrates a binary counter implemented using an 8-bit sequence that is displayed on LEDs connected to an Arduino Uno board. The counter counts from 0 to 255 in binary, with each number being displayed on 8 LEDs connected to digital pins 3 to 10. The counter increments every 0.5 seconds, providing a visual representation of the binary counting sequence.

#Project Details

#Language: The project is written in the C programming language.

#Functionality:

The program controls the LEDs to show the current binary number. Each LED represents one bit of the 8-bit binary number.
The counter starts at 0 and increments by 1 every 0.5 seconds until it reaches 255 (binary: 11111111), then it rolls over and restarts at 0.
Hardware: The project uses an Arduino Uno board. The LEDs are connected to digital pins 3 to 10.

#How It Works

The program initializes the pins 3 to 10 as outputs.
A loop counts from 0 to 255 and writes each value to the output pins, lighting up the LEDs in the corresponding binary pattern.
After displaying each number, the program waits for 0.5 seconds before incrementing the counter.

#Compilation and Upload

The source code is written in C and needs to be compiled using avr-gcc or an IDE that supports AVR programming (like Atmel Studio or PlatformIO).

After compilation, the compiled hex file (Binar_Counter_LED.hex) is uploaded to the Arduino Uno board using the avrdude tool.

Uploading the Hex File Using avrdude
To upload the compiled .hex file to the Arduino Uno, use the following avrdude command:
avrdude -p m328p -c arduino -P COM3 -b 115200 -U flash:w:Binar_Counter_LED.hex:i

-p m328p: Specifies the microcontroller (ATmega328P for Arduino Uno).

-c arduino: Uses the Arduino bootloader protocol.

-P COM3: Specifies the port where the Arduino is connected (adjust COM3 if needed).

-b 115200: Baud rate for communication.

-U flash:w:Binar_Counter_LED.hex:i: Instructs avrdude to write the hex file to the flash memory of the microcontroller.

Ensure that the Arduino is properly connected to the correct COM port and that avrdude is installed on your system.

#Requirements

Arduino Uno board

8 LEDs connected to pins 3 to 10

Resistors for LEDs (optional, depending on your circuit setup)

avrdude for uploading the hex file

USB cable for programming the Arduino
