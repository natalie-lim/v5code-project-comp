/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Natalie Lim, Sophia Zhang, Valeria Ruelas                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


//gyro TurnGyroSmart = gyro(Brain.ThreeWirePort.D);

//smartdrive Drivetrain= smartdrive(LeftDriveSmart, RightDriveSmart, TurnGyroSmart, 319.19, 320, 165, mm, 1);

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  vexcodeInit();

int armSpeedPCT = 50;

int upDownSpeedPCT = 25;



 

bool down = true;

bool nemDown = true;

bool down1 = true;

bool nemDown1 = true;
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
      leftMotorA.spin (directionType ::fwd, 7.0, voltageUnits::volt);
      if (Controller1.Axis2.position()> 0) {
        RightDriveSmart.spin(directionType::fwd, armSpeedPCT,velocityUnits::pct);
      }
      else if (Controller1.Axis2.position() < 0)
      {
        RightDriveSmart.spin(directionType::rev, armSpeedPCT,velocityUnits::pct);
      }
      else
      {
        RightDriveSmart.spin(directionType::rev, 0,velocityUnits::pct);
        RightDriveSmart.stop (brakeType::brake);
      }


      if (Controller1.Axis3.position() > 0)
      {
        LeftDriveSmart.spin(directionType::fwd, armSpeedPCT,velocityUnits::pct);
      }
      else if (Controller1.Axis3.position() < 0)
      {
        LeftDriveSmart.spin(directionType::rev, armSpeedPCT,velocityUnits::pct);
      }
      else
      {
        LeftDriveSmart.stop(brakeType::brake);
      }


      //arm
      if (Controller1.ButtonR1.pressing () && down == true) {
        ArmMotor.spin
        (directionType::rev, armSpeedPCT,
        velocityUnits::pct);
        down = false;
      }
      if (Controller1.ButtonR1.pressing () && down == false) {
        ArmMotor.spin
        (directionType::fwd, armSpeedPCT,
        velocityUnits::pct);
        down = true;
      }

      //front pneumatics
      if (Controller1.ButtonR2.pressing() && nemDown == true)
      {
        dig1.set(true); //down
        nemDown = false;
      }
      if (Controller1.ButtonR2.pressing() && nemDown == false)
      {
        dig1.set (false);
        nemDown = true;
      }

      //back lift
      if (Controller1.ButtonL1.pressing() && down1 == true)
      {
        nemMotor.spin (directionType::fwd, upDownSpeedPCT, velocityUnits::pct);
        down1 = false;
      }
      if (Controller1.ButtonL1.pressing() && down1 == false)
      {
        nemMotor.spin (directionType::rev, upDownSpeedPCT, velocityUnits::pct);
        down1 = true;
      }

      //backNem nem
      if (Controller1.ButtonL2.pressing() && nemDown1 == true)
      {
        bro.set(true); //down
        nemDown1 = false;
      }
      if (Controller1.ButtonL2.pressing() && nemDown1 == false)
      {
        bro.set (false);
        nemDown1 = true;
      }
      wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
