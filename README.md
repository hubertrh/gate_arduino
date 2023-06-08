# RFID Based Gate Control System

This project represents a basic implementation of an RFID based gate control system using Arduino. The system uses an RFID reader to scan RFID tags, and upon verification of the correct tag, the gate is triggered to open.

## Files

The project consists of two main Arduino sketch files:

1. `card_read.ino`: This file contains the necessary logic for reading the UID of a presented RFID card or tag.
2. `gate_open.ino`: This file contains the logic to compare the read UID with a predefined UID. If the UIDs match, the gate opens for a specific period of time, otherwise, the gate remains closed.

## Dependencies

The project uses the following libraries which need to be installed:

- SPI.h: A library that allows the Arduino to communicate with the RFID reader using the Serial Peripheral Interface (SPI).
- MFRC522.h and MFRC522Extended.h: Libraries that allow the Arduino to communicate with the MFRC522 RFID reader and handle different RFID operations.

## Hardware setup

The project requires the following hardware components:

- An Arduino board (this code is generally compatible with all Arduino boards)
- An MFRC522 RFID reader module
- RFID cards or tags
- Cables for connecting the RFID reader to the Arduino
- A gate mechanism controlled by a digital signal (connected to pin 2 of the Arduino in this case)

## Pin Configuration

The project uses the following pin configurations:

- The SS_PIN (slave select) is connected to digital pin 10 on the Arduino.
- The RST_PIN (reset) is connected to digital pin 9 on the Arduino.
- The gate mechanism is controlled by digital pin 2 on the Arduino.

## Usage

1. Upload the `card_read.ino` sketch to your Arduino. This will allow you to read the UIDs of any RFID cards or tags you present to the reader. The UIDs are printed in the Serial Monitor.
2. Replace the `UID1` array in the `gate_open.ino` sketch with the UID of the card or tag you want to grant access to the gate.
3. Upload the `gate_open.ino` sketch to your Arduino. Now, when you present the authorized card or tag to the reader, the gate will open for the duration specified by `time_open` (in milliseconds).
4. If an unauthorized card or tag is presented, the gate will remain closed.

## Customization

- To add more authorized cards or tags, simply create more UID arrays (`UID2`, `UID3`, etc.) and add additional comparison logic in the `if` statement in the `loop` function.
- The `time_open` constant can be adjusted to control how long the gate remains open when the correct RFID card or tag is presented.
