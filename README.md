# Pulse Width Modulation Lab Project
## Overview
The Embedded Systems Lab Project is a comprehensive exploration of pulse width modulation (PWM) and servo motors within the realm of embedded systems. Utilizing the TM4C123GH6PM LaunchPad Board, the project delves into various tasks, including RGB LED brightness control, creating a breathing effect, and servo motor rotation.

## Table of Contents
- [Tasks](#tasks)
  - [Task 1: RGB LED Control](#task-1-rgb-led-control)
  - [Task 2: Breathing Effect](#task-2-breathing-effect)
  - [Task 3: Servo Motor Rotation](#task-3-servo-motor-rotation)
  - [Task 4: Variable Speed Servo Motor](#task-4-variable-speed-servo-motor)
- [Setup](#setup)
- [Usage](#usage)

## Tasks
### Task 1: RGB LED Control
In this school project, the TM4C123GH6PM LaunchPad Board is employed to demonstrate the control of an RGB LED's brightness using PWM. Pushbuttons on GPIO ports determine different duty cycles, resulting in varying LED brightness.

### Task 2: Breathing Effect
Task 2 introduces a breathing effect to the RGB LED by modulating the duty cycle through two for loops. This creates a smooth transition between low and high brightness, simulating a breathing pattern.

### Task 3: Servo Motor Rotation
Task 3 involves the use of a servo motor controlled by PWM to rotate from -90 to 90 degrees. Challenges were encountered and addressed during implementation, including adjusting pulse width values for proper rotation.

### Task 4: Variable Speed Servo Motor
Building on Task 3, Task 4 introduces variable speed control for the servo motor. The speed is determined by different pushbuttons, showcasing the versatility of PWM in motor control.

## Setup
### Configure GPIO Ports
- Port F (RGB LED):
  - Enable clock for PORTF.
  - Configure PF2 as an output pin for the blue LED.
  - Enable alternate function for PF2 to allow PWM control.
- Port D (Pushbuttons):
  - Enable clock for PORTD.
  - Configure PD3-PD0 as input pins for pushbuttons.
- Port B (LED Indicators):
  - Enable clock for PORTB.
  - Configure PB3-PB0 as output pins for LED indicators.

### Configure PWM
- Enable clock for PWM1.
- Configure PWM1 generator and comparator registers for desired functionality.
- Connect PWM output to appropriate GPIO pins for LED and servo control.

## Usage
- Compile and flash the code onto the TM4C123GH6PM LaunchPad Board.
- Observe the effects on the RGB LED and servo motor based on the defined tasks.
