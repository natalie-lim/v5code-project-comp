#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
  brain  Brain;
// A global instance of competition
competition Competition;
controller Controller1;
motor leftMotorA = motor(PORT15, ratio18_1, false);//face back of brain, a farther (farther), b closer (second)
motor leftMid = motor (PORT17, ratio18_1, false);
motor leftMotorB = motor(PORT5, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMid, leftMotorB);
motor rightMotorA = motor(PORT19, ratio18_1, true);
motor rightMid = motor (PORT7, ratio18_1, true);
motor rightMotorB = motor(PORT8, ratio18_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMid, rightMotorB);
motor ArmMotor = motor(PORT11, ratio18_1, true);
motor nemMotor = motor(PORT16, ratio18_1, true);
digital_out dig1 = digital_out(Brain.ThreeWirePort.H);
digital_out bro = digital_out(Brain.ThreeWirePort.G);

// VEXcode device constructors



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}