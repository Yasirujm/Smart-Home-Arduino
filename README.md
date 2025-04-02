# Smart-Home-Arduino
This is the code for a smart home to function with various IOT devices and sensors.


Features
- Three Ultrasonic Sensors: Each sensor controls a servo to open or close a door when an object is detected within a specified range.

- Rain Sensor: Detects heavy rainfall and triggers an LED to indicate rain.

- Temperature Sensor (DHT22): Measures the temperature and turns on a motor if the temperature exceeds a set threshold.

- Light Sensor (LDR): Detects ambient light levels and controls an LED to indicate whether the room is bright or dark.

- Servo Motors: Controls three doors based on ultrasonic sensor readings.


## Devices Used

- **Ultrasonic Sensors (HC-SR04)**:
  - **Pin Connections**:  
    - **Sensor 1**: Trigger on pin 5, Echo on pin 10  
    - **Sensor 2**: Trigger on pin 7, Echo on pin 6  
    - **Sensor 3**: Trigger on pin 12, Echo on pin 11  
  - Used for detecting objects in front of the doors to control servo motors.
  
- **Servo Motors**:  
  - **Pin Connections**:  
    - Door 1 Servo on pin 9  
    - Door 2 Servo on pin 3  
    - Door 3 Servo on pin 8  
  - Controls the opening and closing of the doors based on sensor input.

- **DHT22 Temperature and Humidity Sensor**:  
  - **Pin Connection**: Pin 2  
  - Measures the temperature and humidity. If the temperature exceeds a threshold, it triggers a motor to turn on.

- **Rain Sensor**:  
  - **Pin Connection**: Analog pin A3  
  - Detects heavy rain and activates an LED to indicate the presence of rain.

- **Light Sensor (LDR)**:  
  - **Pin Connection**: Analog pin A0  
  - Detects ambient light levels and turns on/off an LED depending on the lighting conditions in the room.

- **Motor**:  
  - **Pin Connection**: Pin 1  
  - Controls the fan's operation when the temperature exceeds the defined threshold.

- **LEDs**:  
  - **Pin Connections**: Pin 4 (Rain Sensor LED), Pin 13 (Light Sensor LED)  
  - Provides visual feedback for rain and light sensor states.

## Pinout Diagram

- **Ultrasonic Sensor 1**: Trigger pin 5, Echo pin 10  
- **Ultrasonic Sensor 2**: Trigger pin 7, Echo pin 6  
- **Ultrasonic Sensor 3**: Trigger pin 12, Echo pin 11  
- **Servo 1**: Pin 9  
- **Servo 2**: Pin 3  
- **Servo 3**: Pin 8  
- **Rain Sensor LED**: Pin 4  
- **Light Sensor LED**: Pin 13  
- **Motor**: Pin 1  
- **Temperature Sensor (DHT22)**: Pin 2  
- **LDR**: Analog pin A0  
- **Rain Sensor**: Analog pin A3

## Setup Instructions

### Hardware Connections

1. **Connect the Ultrasonic Sensors**:
   - **Sensor 1**: Trigger pin to pin 5, Echo pin to pin 10
   - **Sensor 2**: Trigger pin to pin 7, Echo pin to pin 6
   - **Sensor 3**: Trigger pin to pin 12, Echo pin to pin 11

2. **Connect the Servo Motors**:
   - **Door 1 Servo**: Pin 9
   - **Door 2 Servo**: Pin 3
   - **Door 3 Servo**: Pin 8

3. **Connect the Rain Sensor**:
   - Connect the sensor to analog pin A3.

4. **Connect the Light Sensor (LDR)**:
   - Connect the LDR to analog pin A0.

5. **Connect the DHT22 Temperature Sensor**:
   - Connect the DHT22 sensor to pin 2.

6. **Connect the Motor**:
   - Connect the motor to pin 1.

7. **Connect the LEDs**:
   - **Rain LED** to pin 4
   - **Light LED** to pin 13

### Software Setup

1. Clone this repository to your local machine.
2. Open the project in the Arduino IDE.
3. Upload the provided code to your Arduino board.
4. Open the Serial Monitor (baud rate: 9600) to observe the sensor readings and status messages.

### Dependencies

- **Servo Library**: Used to control the servo motors.
- **DHT Library**: Required for the DHT22 temperature sensor.

Install the necessary libraries in the Arduino IDE:
1. Go to **Sketch > Include Library > Manage Libraries**.
2. Search for **Servo** and **DHT** and install them.

## Usage

- When an object is detected within a certain distance of the ultrasonic sensor, the corresponding door will open.
- If the rain sensor detects heavy rain, the rain LED will blink.
- If the temperature exceeds the defined threshold, the motor (fan) will turn on.
- The light sensor controls an LED based on the ambient light level.
