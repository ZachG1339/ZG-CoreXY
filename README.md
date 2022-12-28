# CoreXY

Arduino Based Core XY assembly. All 3D printed components are custom made for this assembly but are compatible with 20x20 extrusion.

The core xy method is one of many methods to move a "head" anywhere in a set MxN rectangular 2D plane. It utilizes two timing belts connected to two independent stepper motors. The belts all begin and end at the head, moving it in any direction with the combined torque of both steppers. 

 

### Required Materials:
(N and M are arbitrary constants)
- ~500g of PLA and 3D printer access
#### Frame:
- 20x20mm extrusion:
  - 2 (N + 1.57)" for width
  - 2 M" for length -> required only for structural stability
  - 4 2" as vertical supports
  - 1 (M - 1.6)" as the X axis
#### Linear Motion:
- [GT2 6mm timing belt](https://www.amazon.ca/gp/product/B08PKPK4D8/ref=ppx_yo_dt_b_asin_title_o00_s01?ie=UTF8&psc=1) -> length depends on extrusion length -> approximately 2M + 2N 
- [8 bearing idlers](https://www.amazon.ca/gp/product/B07P9M6BRC/ref=ppx_yo_dt_b_asin_title_o00_s01?ie=UTF8&psc=1) (5mm bore, 12mm inner diameter, 18mm outer diameter)
- [2 GT2 pulleys](https://www.amazon.ca/gp/product/B08PKPK4D8/ref=ppx_yo_dt_b_asin_title_o00_s01?ie=UTF8&psc=1)
- [9 Bearing wheels](https://www.amazon.ca/gp/product/B07Q5WN3GK/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)
- 11 M5 40mm bolts
- 18 M5 nuts or 9 M5 lock nuts
- 4 13mm segements of smooth 5mm diameter shaft

(note: M5 items can be comfortably replaced with 3/16" equivalents)
#### Electrical:
- 2 identical NEMA 17 stepper motors
- Arduino Uno R3 or Mega R3
- DC Power Supply -> compatible with motors and drivers
- Generous supply of F-M and M-M DuPont (jumper) wires -> at least 6 and 10 respectively



## V1:

The quick background behind V1 is it was officially intended to be the arduino project for a C++ programming class. Using that as my excuse and hard 3 week timeline I tried to make a functional prototype that technically fit the project parameters, hence the joystick control and not automation.

Designed and coded to move a continuous servo attached to the head using the arduino joystick module. 
### Additional Materials:
- Adafruit Motor Shield V2 -> max per motor current 1.2 A
  - [Adafruit Documentation](https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino)
- 1 [SG90 servo motor](https://www.amazon.ca/Micro-Servos-Helicopter-Airplane-Controls/dp/B07MLR1498/ref=sr_1_5?crid=3LEQ2GAQYVWLO&keywords=sg90+continuous&qid=1672194251&sprefix=sg90+continuous%2Caps%2C99&sr=8-5)
- 5 F-M jumper wires
- 1 Arduino joystick module


#### Known Defects:
- Motor overheating issue
  - likely caused by lack of ventilation in the motor mounts however load may have exceeded the motors I acquired for this prototype

