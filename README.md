# MERRY-GO-ROUND
---

This project involves controlling a DC motor using an Arduino board, a motor driver module, a potentiometer for speed control, and LEDs for status indication. The motor runs for a specified duration, and the system provides visual feedback via the LEDs. The project is designed to be simple yet effective in controlling the motor's speed and run-time, with easy-to-understand feedback for the user.

[Refer to the Components Documentation for detailed specifications and connections.](assets/ComponentConnection.md)

## Pin Configuration

- **motorPin1 (Pin 8)**: Controls the direction of the motor (via motor driver).
- **motorPin2 (Pin 9)**: Controls the direction of the motor (via motor driver).
- **enablePin (Pin 10)**: Controls the motor's speed using Pulse Width Modulation (PWM).
- **potPin (Pin A0)**: Reads the potentiometer value for speed control.
- **redLedPin (Pin 11)**: Indicates the motor is off (red LED).
- **greenLedPin (Pin 12)**: Indicates the motor is on (green LED).

---

## Key Logic Breakdown

1. **Motor Control**:
   - The motor's direction and speed are controlled via the motor driver module.
   - Speed is determined by the potentiometer value, mapped to a PWM value (0 to 255).
   - The motor runs for a predefined time (`runTime`), and after that, it stops automatically.
   
2. **LED Control**:
   - **Red LED**: Turns on when the motor is off (motor stopped).
   - **Green LED**: Turns on when the motor is running.
   - **Blinking Green LED**: Blinks in the last 10 seconds of the motor's run time.

3. **Run Time**: The motor runs for 10 seconds (`runTime`), and the system controls the LED feedback during that time. The LEDs indicate the motor's operational status.

---

## Circuit Diagram

1. **Motor Driver Connections (L298N or L293D)**:
   - **motorPin1** (Pin 8) → IN1 on the motor driver
   - **motorPin2** (Pin 9) → IN2 on the motor driver
   - **enablePin** (Pin 10) → EN pin on the motor driver (PWM control)
   - Connect the motor's terminals to the OUT1 and OUT2 pins on the motor driver.
   - Connect the motor driver's ground to the Arduino ground.
   - Connect the motor driver's VCC to an appropriate power source for the motor.

2. **Potentiometer Connections**:
   - One pin goes to **5V** on the Arduino.
   - Another pin goes to **ground**.
   - The third pin (wiper) connects to **A0** on the Arduino.

3. **LEDs**:
   - The red LED is connected to **Pin 11** with a current-limiting resistor (220 ohms).
   - The green LED is connected to **Pin 12** with a current-limiting resistor (220 ohms).

---

## Code Overview

- **setup()**: Initializes the motor, LED, and potentiometer pins. It also sets the initial LED states (Red on, Green off).
- **loop()**:
  - Reads the potentiometer value and adjusts the motor speed.
  - Controls motor run-time, stopping the motor after a set time (`runTime`).
  - Updates the LEDs based on the motor's status, with the green LED blinking near the end of the run-time.

---

## Operation Summary

1. **Motor Speed Control**: The potentiometer adjusts the motor's speed. As the user turns the potentiometer, the motor speed is modified through PWM signals.
   
2. **Motor Duration**: The motor operates for a set time (10 seconds). After this duration, the motor automatically stops.

3. **LED Indicators**:
   - **Red LED**: Indicates when the motor is off.
   - **Green LED**: Indicates when the motor is on, and it blinks during the last 10 seconds of the motor's operation.

---

## Troubleshooting

1. **Motor Not Starting**:
   - Verify motor and driver connections.
   - Check the power supply for the motor (may need a higher voltage than the Arduino provides).
   - Ensure the motor driver is receiving the correct input pins from the Arduino.

2. **LEDs Not Turning On**:
   - Confirm LED connections and ensure the correct pins are used.
   - Check that the current-limiting resistors are placed correctly to avoid excessive current.

3. **Potentiometer Not Adjusting Speed**:
   - Check the wiring to the potentiometer and ensure it's connected to the **A0** pin.
   - Ensure the `map()` function correctly adjusts the potentiometer reading to a valid PWM range (0-255).

---
