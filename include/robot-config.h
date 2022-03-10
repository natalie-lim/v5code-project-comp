using namespace vex;

extern brain Brain;
extern competition Competition;
extern controller Controller1;
extern motor leftMotorA;
extern motor leftMid;
extern motor leftMotorB;
extern motor_group LeftDriveSmart;
extern motor rightMotorA;
extern motor rightMid;
extern motor rightMotorB;
extern motor_group RightDriveSmart;
extern motor ArmMotor;
extern motor nemMotor;
extern digital_out dig1;
extern digital_out bro;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
