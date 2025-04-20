#include <Stepper.h>
#define STEPS 32

// define stepper  motor control pins
#define IN1_1  11
#define IN2_1  10
#define IN3_1   9
#define IN4_1   8
#define IN1_2   2
#define IN2_2   3
#define IN3_2   5
#define IN4_2   6
 
// initialize stepper library
Stepper stepper1(STEPS, IN4_1, IN2_1, IN3_1, IN1_1);
Stepper stepper2(STEPS, IN4_2, IN2_2, IN3_2, IN1_2);
 
// joystick pot output is connected to Arduino A0
#define  joystickx  A0
#define  joysticky  A1
 
void setup()
{
  
}
 
void loop()
{

  //  read analog value from the potentiometer
  int valx = analogRead(joystickx);
  int valy = analogRead(joysticky);

///////////////////STEPPER1///////////////////
  
  // if the joystic is in the middle ===> stop the motor
  if(  (valx > 500)  && (valx < 523) )
  {
    digitalWrite(IN1_1, LOW);
    digitalWrite(IN2_1,  LOW);
    digitalWrite(IN3_1, LOW);
    digitalWrite(IN4_1, LOW);
  }
 
  else
  {
    // move the motor in the first direction
    while (valx  >= 523)
    {
      // map the speed between 5 and 500 rpm
      int speed_  = map(valx, 523, 1023, 5, 1000);
      // set motor speed
      stepper1.setSpeed(speed_);
  
      // move the motor (1 step)
      stepper1.step(1);
 
      valx  = analogRead(joystickx);
    }
 
    // move the motor in the other direction
    while (valx <= 500)
    {
      // map the speed between 5 and 500 rpm
      int speed_ = map(valx, 500, 0, 5, 1000);
      // set motor speed
      stepper1.setSpeed(speed_);
  
      // move the motor (1 step)
      stepper1.step(-1);
 
      valx  = analogRead(joystickx);
    }
 
  }

///////////////////STEPPER2///////////////////

  // if the joystic is in the middle ===> stop the motor
  if(  (valy > 500)  && (valy < 523) )
  {
    digitalWrite(IN1_2, LOW);
    digitalWrite(IN2_2,  LOW);
    digitalWrite(IN3_2, LOW);
    digitalWrite(IN4_2, LOW);
  }
 
  else
  {
    // move the motor in the first direction
    while (valy  >= 523)
    {
      // map the speed between 5 and 500 rpm
      int speed_  = map(valy, 523, 1023, 5, 500);
      // set motor speed
      stepper2.setSpeed(speed_);
  
      // move the motor (1 step)
      stepper2.step(1);
 
      valy  = analogRead(joysticky);
    }
 
    // move the motor in the other direction
    while (valy <= 500)
    {
      // map the speed between 5 and 500 rpm
      int speed_ = map(valy, 500, 0, 5, 500);
      // set motor speed
      stepper2.setSpeed(speed_);
  
      // move the motor (1 step)
      stepper2.step(-1);
 
      valy  = analogRead(joysticky);
    }
 
  }
 
}

