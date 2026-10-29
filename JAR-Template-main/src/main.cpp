#include "vex.h"

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
ZERO_TRACKER_NO_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(),

//Right Motors:
motor_group(),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT1,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.6,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 0;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

void pre_auton() {
  
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  Optical1.setLight(ledState::on);
  Optical1.setLightPower(100, percent);

  while(!auto_started){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    Brain.Screen.printAt(5, 40, "Battery Percentage:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 120, "Selected Auton:");
    switch(current_auton_selection){
      case 0:
        Brain.Screen.printAt(5, 140, "Auton 1");
        break;
      case 1:
        Brain.Screen.printAt(5, 140, "Auton 2");
        break;
      case 2:
        Brain.Screen.printAt(5, 140, "Auton 3");
        break;
      case 3:
        Brain.Screen.printAt(5, 140, "Auton 4");
        break;
      case 4:
        Brain.Screen.printAt(5, 140, "Auton 5");
        break;
      case 5:
        Brain.Screen.printAt(5, 140, "Auton 6");
        break;
      case 6:
        Brain.Screen.printAt(5, 140, "Auton 7");
        break;
      case 7:
        Brain.Screen.printAt(5, 140, "Auton 8");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){ 
    case 0:
      drive_test();
      break;
    case 1:         
      drive_test();
      break;
    case 2:
      turn_test();
      break;
    case 3:
      swing_test();
      break;
    case 4:
      full_test();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
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
int eventPressed() {
  Controller1.rumble("-");
}

void usercontrol(void) {

  // User control code here, inside the loop
  while (1) {
    if (Controller1.ButtonUp.pressing()) {
      RightDrive.spin(forward);
      LeftDrive.spin(forward);
    }
    if (Controller1.ButtonDown.pressing()) {
      RightDrive.spin(reverse);
      LeftDrive.spin(reverse);
    } else if (Controller1.ButtonLeft.pressing()) {
      RightDrive.spin(reverse);
      LeftDrive.spin(forward);
    } else if (Controller1.ButtonRight.pressing()) {
      RightDrive.spin(forward);
      LeftDrive.spin(reverse);
    } else {
      RightDrive.stop();
      LeftDrive.stop();
    }
    if (Controller1.ButtonR1.pressing()) {
      lift.spin(forward);
    } else if (Controller1.ButtonR2.pressing()) {
      lift.spin(reverse);
    } else {
      lift.stop();
    }
    if (Controller1.ButtonL1.pressing()) {
      pneumaticClaw.set(true);
    } else if (Controller1.ButtonL2.pressing()) {
      pneumaticClaw.set(false);
    }
    rotation1.position();
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "Rotation Sensor Position: %f", rotation1.position(rotationUnits::deg));
    Brain.Screen.printAt(5, 40, "Chassis Heading Reading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 60, "Battery Percentage: %d", Brain.Battery.capacity());

 

  // Run BumperPressed when the value of the Bumper Switch is pressed.
 
    Brain.Screen.printAt(5, 80, "Bumper A Pressed: %d", BumperA.pressing());
    Brain.Screen.printAt(5, 100, "Is near object?: %d", Optical1.isNearObject());
    Brain.Screen.printAt(5, 120, "Optical Sensor color detected:", Optical1.color());

    BumperA.released(eventPressed);



  // Get the current angle of the Potentiometer V2 in the
// range 0 to 330 degrees.
double angle = PotentiometerV2A.angle(degrees);

// Create an inertial instance for the V5 Inertial Sensor
inertial myInertial = inertial(
    PORT1,      // Smart Port 1
    right);     // dir



void inertialTask() {
  while (true) {
    // Get the current heading of the Inertial Sensor in the
    // range 0 to 360 degrees.
    double heading = myInertial.heading(degrees);


    // Print the current heading of the Inertial Sensor to the
    // brain screen.
    Brain.Screen.printAt(5, 140, "Inertial Sensor Heading: %f", heading);

    

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

void potentiometerTask() {
  while (true) {
    // Get the current angle of the Potentiometer V2 in the
    // range 0 to 330 degrees.
    double angle = PotentiometerV2A.angle(degrees);

// Print the current angle of the Potentiometer to the
// brain screen.
Brain.Screen.printAt(5, 120, "Potentiometer V2 Angle: %f", angle);

}

void opticalTask() {
  while (true) {
    // Get the current color detected by the Optical Sensor.
    vex::color detectedColor = Optical1.color();

    // Print the current color detected by the Optical Sensor to the
    // brain screen.
    Brain.Screen.printAt(5, 160, "Optical Sensor Color Detected: %s", detectedColor.toString().c_str());

}

void bumperTask() {
  while (true) {
    // Check if the Bumper Switch is pressed.
    bool isPressed = BumperA.pressing();

    // Print the current status of the Bumper Switch to the
    // brain screen.
    Brain.Screen.printAt(5, 180, "Bumper A Pressed: %d", isPressed);
  }
}

void chassisTask() {
  while (true) {
    // Get the current heading of the chassis.
    double heading = chassis.get_absolute_heading();

    // Print the current heading of the chassis to the
    // brain screen.
    Brain.Screen.printAt(5, 200, "Chassis Heading Reading: %f", heading);
  }
}
void batteryTask() {
  while (true) {
    // Get the current battery percentage.
    int batteryPercentage = Brain.Battery.capacity();

    // Print the current battery percentage to the
    // brain screen.
    Brain.Screen.printAt(5, 220, "Battery Percentage: %d", batteryPercentage);
  }

void rotationSensorTask() {
  while (true) {
    // Get the current position of the Rotation Sensor in degrees.
    double position = Rotation1.position(rotationUnits::deg);

    // Print the current position of the Rotation Sensor to the
    // brain screen.
    Brain.Screen.printAt(5, 240, "Rotation Sensor Position: %f", position);
  }

void triportTask() {
  while (true) {
    // Get the current value of the Triport.
    int32_t triportValue = Expander1.value();

    // Print the current value of the Triport to the
    // brain screen.
    Brain.Screen.printAt(5, 260, "Triport Value: %d", triportValue);
  }

void pneumaticsTask() {
  while (true) {
    // Get the current state of the Pneumatics Claw.
    bool isClawOpen = PneumaticsClaw.isOpen();

    // Print the current state of the Pneumatics Claw to the
    // brain screen.
    Brain.Screen.printAt(5, 280, "Pneumatics Claw Open: %d", isClawOpen);
  }

void opticalProximityTask() {
  while (true) {
    // Check if the Optical Sensor detects a nearby object.
    bool isNearObject = Optical1.isNearObject();

    // Print the current proximity status to the
    // brain screen.
    Brain.Screen.printAt(5, 300, "Is Near Object?: %d", isNearObject);
  }

void opticalColorTask() {
  while (true) {
    // Get the current color detected by the Optical Sensor.
    vex::color detectedColor = Optical1.color();

    // Print the current color detected by the Optical Sensor to the
    // brain screen.
    Brain.Screen.printAt(5, 320, "Optical Sensor Color Detected: %s", detectedColor.toString().c_str());
  }

void potentiometerV2Task() {
  while (true) {
    // Get the current angle of the Potentiometer V2 in the
    // range 0 to 330 degrees.
    double angle = PotentiometerV2B.angle(degrees);

    // Print the current angle of the Potentiometer V2 to the
    // brain screen.
    Brain.Screen.printAt(5, 340, "Potentiometer V2B Angle: %f", angle);
  }
  

}

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {

  task inertialTaskInstance(inertialTask);
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    PotentiometerV2A.angle(degrees);
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "Potentiometer V2 Angle: %f", PotentiometerV2A.angle(degrees));

    wait(100, msec);
  }
}
