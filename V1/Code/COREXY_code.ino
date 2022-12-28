//information for the adafruit motor shield and using 2 steppers simultaneously:
// https://github.com/adafruit/Adafruit_Motor_Shield_V2_Library 
// NOTE: For my servo parked at input 89 NOT 90 (manufacturing error I didn't have time to fix). 
//       So when 89 is written to servo1 that means park

// Other Important Sources in README document

// Required libraries
#include <Servo.h>
#include <ezButton.h>
#include <AccelStepper.h>
#include <Adafruit_MotorShield.h>

// initiation of joystick properties
#define joyX_Pin A0
#define joyY_Pin A1

// initial storage variables for joystick inputs
int joyX;
int joyY;

// joystick button pin number
const int pushButtonPin = 2;

// initiaion of Jotstick Button
ezButton button(pushButtonPin);
int bValue = 0;

// variable dictating what keybinds are active
//  1 = head movement
// -1 = servo movement
int controlState = 1;


// initiation of servo
Servo servo1;
int Park = 88;
int sSpeed = Park;



// creation of motorshield object
Adafruit_MotorShield AFMS(0x60); 

// Initiation of motorshield communication with the steppers (steps per revolution, port)
// Using 17HS4023 stepper motors with 1.8 degrees per step
Adafruit_StepperMotor *ADA_Left_Step = AFMS.getStepper(200, 1); 
Adafruit_StepperMotor *ADA_Right_Step = AFMS.getStepper(200, 2);


// creation of functions that step motors forward and backward with standard Adafruit library
// AccelStepper requires these functions for initiation

// wrappers for the Left Motor
void Left_forwardstep() {
  ADA_Left_Step->onestep(FORWARD, DOUBLE);
}
void Left_backwardstep() {
  ADA_Left_Step->onestep(BACKWARD, DOUBLE);
}
// wrappers for the Right Motor
void Right_forwardstep() {
  ADA_Right_Step->onestep(FORWARD, DOUBLE);
}
void Right_backwardstep() {
  ADA_Right_Step->onestep(BACKWARD, DOUBLE);
}

// Creation of Accel Stepper objects
// These are what will actually control the stepper motors
// and will allow for simultaneous control
AccelStepper Left_Step(Left_forwardstep, Left_backwardstep);
AccelStepper Right_Step(Right_forwardstep, Right_backwardstep);

// Final Stepper Speed Variables  
int V_Left = 0;
int V_Right = 0;


void setup() {
  // put your setup code here, to run once:

  AFMS.begin(); //Begin communication with the motor shield

  // set up parameters for stepper motor movement
  Left_Step.setSpeed(100); //steps
  Left_Step.moveTo(100); // steps from initial
  Left_Step.setMaxSpeed(3000); // steps/s
  Left_Step.setAcceleration(100.0); // steps/s^2
  
  Right_Step.setSpeed(100);
  Right_Step.moveTo(100); 
  Right_Step.setMaxSpeed(3000);
  Right_Step.setAcceleration(100.0);

  // initiation of servo and Arduino Communication
  servo1.attach(10);
  Serial.begin(9600);
  servo1.write(Park); // 89 was closest to park for my servo

  // sets button delay
  button.setDebounceTime(1);

  // Set mode of Joystick Analogue Axis
  pinMode(joyX_Pin, INPUT);
  pinMode(joyY_Pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // check for button
  button.loop();
  bValue = button.getState();

  // code to switch keybinds
  // stops all motors/actuators and changes keybinds
  if(button.isReleased()) {
    Left_Step.moveTo(Left_Step.currentPosition());
    Right_Step.moveTo(Right_Step.currentPosition());
    Left_Step.setSpeed(0);
    Right_Step.setSpeed(0);
    servo1.write(89);
    
    controlState = -controlState;
    delay(1000);
  }

  // read and process joystick inputs so (0,0) is the center position
  joyX = analogRead(joyX_Pin);
  joyY = analogRead(joyY_Pin);
  joyX -= 513; 
  joyY -= 513;

  // convert joystick x:y to velocity of Left and Right stepper motors
  // equations found via linear transformation in README document
  V_Left = (2000.0/512.0)*(joyX + joyY);
  V_Right = (2000.0/512.0)*(joyX - joyY);

  // conditional statement dictating active keybinds
  
  // head movement only
  // code to move the head around the xy plane while the servo stays still
  if(controlState == 1){
    
    // set target amount of steps from current positions to move
    // magnitude and direction doesn't matter so long as the motors think they must move somewhere
    Left_Step.move(100);
    Right_Step.move(100);

    // set speed to targets
    // ratio same as x:y ratio of joystick
    // motors will be moved after the conditional at the end
    Left_Step.setSpeed((int)V_Left);
    Right_Step.setSpeed((int)V_Right);
    

    //servo stays still under these keybinds
    servo1.write(Park);
 
  }

  // servo movement only
  // code to keep the head still while the servo is moved
  else{
    
    //make the stepper motors stay still
    Left_Step.moveTo(Left_Step.currentPosition());
    Right_Step.moveTo(Right_Step.currentPosition());
    Left_Step.setSpeed(0);
    Right_Step.setSpeed(0);

    // convert X axis movement to the 180 unit range of servo speed
    sSpeed = (int)(joyX + 513)*(180.0/1024.0);

    // run servo
    servo1.write(sSpeed);
  }
  // illustrate which keybinds are active
  Serial.println(controlState);

  // runs motors at speed specified earlier in the loop under "head movement only" keybinds
  Left_Step.runSpeed();
  Right_Step.runSpeed();
}
