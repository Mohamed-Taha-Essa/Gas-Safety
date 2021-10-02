# Gas-Safety 
Embedded system:
Component:
•	Microcontroller PIC18F4620.
•	GSM gprs A6 module.
•	Solenoid valve.
•	Gas sensor MQ2.
•	Heat sensor lm35.
•	Lm298 module.
what it do :
read tow value from MQ2 and LM35
if the MQ2 sensig natural gas the microcontroller take three action
     1-close solenoid valve
     2-open motor to pull air from kitchen
     3-send the value of natural gas to server using GSM gprs A6 module
