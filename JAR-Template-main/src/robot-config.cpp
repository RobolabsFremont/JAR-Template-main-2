#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;
motor LeftDrive1 = motor(PORT1, gearSetting::ratio6_1, false);
motor LeftDrive2 = motor(PORT2, gearSetting::ratio6_1, false);
motor LeftDrive3 = motor(PORT3, gearSetting::ratio6_1, false);
motor_group LeftDrive = motor_group(LeftDrive1, LeftDrive2, LeftDrive3);

motor RightDrive1 = motor(PORT13, gearSetting::ratio6_1, true);
motor RightDrive2 = motor(PORT14, gearSetting::ratio6_1, true);
motor RightDrive3 = motor(PORT15, gearSetting::ratio6_1, true);
motor_group RightDrive = motor_group(RightDrive1, RightDrive2, RightDrive3);

drivetrain chassis = drivetrain(LeftDrive, RightDrive, 320, 320, 130, distanceUnits::mm, 1.0);
controller Controller1 = controller(primary);


motor ArmMotor = motor(PORT7, gearSetting::ratio36_1, false);
motor ClawMotor = motor(PORT4, gearSetting::ratio18_1, false);
motor LiftMotor1 = motor(PORT5, gearSetting::ratio36_1, false);
motor LiftMotor2 = motor(PORT6, gearSetting::ratio36_1, true);
motor_group LiftGroup = motor_group(LiftMotor1, LiftMotor2);
// Create a pot instance in Port A
pot PotentiometerA = pot(Brain.ThreeWirePort.A);


// Create a Rotation Sensor instance in Port 7
rotation Rotation1 = rotation(PORT7);

// Create a bumper instance in Port A
bumper BumperA = bumper(Brain.ThreeWirePort.A);
// Create an optical instance in Port 9
optical Optical9 = optical(PORT9);
// Create an inertial instance for the V5 Inertial Sensor connected to Port 8.
inertial Inertial8 = inertial(PORT8);
// Create a Potentiometer V2 on 3-Wire Port B
potV2 PotentiometerV2B = potV2(Brain.ThreeWirePort.B);

// Create a triport instance in Port 1.
triport Expander1 = triport(PORT16);


rotation(
    int32_t index,
    bool    reverse = false );

brain Brain;

pneumatics PneumaticsClaw;
// Create a line instance in Port A
line LineTrackerLeft = line(Brain.ThreeWirePort.A);
// Create a line instance in Port A
line LineTrackerRight = line(Brain.ThreeWirePort.B);


//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:


void vexcodeInit( void ) {
  // nothing to initialize

}