The Cdm324 radar sensor operates at 24 GHz and is commonly used for motion and speed detection. It can provide a simpler and more straightforward solution for neighborhood speeders when combined with an ESP32.

Here's how you can proceed with the Cdm324 radar sensor:

1. Hardware Connection:
Connect the Cdm324 radar sensor according to its datasheet. It typically has pins for VCC, GND, and output. The output pin provides a digital signal that corresponds to detected motion.

2. Interface with ESP32:
Connect the output pin of the Cdm324 to a digital input pin on the ESP32.

3. Measure Speed:
You can measure speed by calculating the frequency of the digital pulses. This could be done using interrupts to measure the time between rising or falling edges.

4. Check Speed Threshold and Control Lights:
If the calculated speed exceeds the threshold, flash the lights or take other actions as needed.

You will need to calibrate the relationship between the frequency of the radar sensor's output and the actual speed. The calibration might require experimentation or consultation of additional documentation related to the Cdm324 sensor.



Remember to ensure that your NeoPixels are properly powered. They can draw a considerable amount of current, especially when all LEDs are on, so make sure to use an appropriate power supply and follow the connection guidelines for your specific NeoPixel rings.

You will need to make an amp/filter for the cdm324 if you want reliable results.

Arduino btw