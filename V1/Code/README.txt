/*
// mathematical inputs to set motor speed (check phone for math)

Linear Algebra:
[a b] [joyX]   [ V_Left]
[c d] [joyY] = [V_Right]
                       [1]
Left Positive vector = [1]
                        [ 1]
Right Positive Vector = [-1]

[1  1] [joyX]   [ V_Left]    with scaling  [1000/512  1000/512] [joyX]   [ V_Left]
[1 -1] [joyY] = [V_Right]   -------------> [1000/512 -1000/512] [joyY] = [V_Right]

V_Left = (1000.0/512.0)(joyX + joyY)
V_Right = (1000.0/512.0)(joyX - joyY)

*/

// Important sources
//    Stepper Motors - https://abra-electronics.com/electromechanical/motors/stepper-motors/nema-17/mot-17hs4023-17hs4023-nema-17-43mm-1.8a-dual-phase-stepper-motor-1.8.html
//    Adafruit Motor Shield V2 - https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino
//    AccelStepper Library - http://www.airspayce.com/mikem/arduino/AccelStepper/index.html
