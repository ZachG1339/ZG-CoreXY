# CoreXY

Arduino Based Core XY assembly. All 3D printed components are custom made for this assembly but are compatible with 20x20 extrusion.

The core xy method is one of many methods to move a "head" anywhere in a set MxN rectangular 2D plane. It utilizes two timing belts connected to two independent stepper motors. The belts all begin and end at the head, moving it in any direction with the combined torque of both steppers. 

 

## V1:

The quick background behind V1 is it was officially intended to be the arduino project for a C++ programming class. Using that as my excuse and hard 3 week timeline I tried to make a functional prototype that technically fit the project parameters, hence the joystick control and not automation.

Designed and coded to move a continuous servo attached to the head using the arduino joystick module. 

#### Known Defects:
- Motor overheating issue
  - likely caused by lack of ventilation in the motor mounts however load may have exceeded the motors I acquired for this prototype

