#include "main.h"
#include "globals.h"
#include <cmath>
#include "okapi/api.hpp"

using namespace okapi;

inline int auton = 0;

pros::Motor intake(3, true);
pros::Motor indexRoller(5, true);
pros::Motor flywheel(9, true);
pros::Motor descore(11);
pros::Motor rightFront(19, true);
pros::Motor rightRear(20, true);
pros::Motor leftFront(1);
pros::Motor leftRear(2);

Rate rate;
auto chassis = ChassisControllerFactory::create({1,2}, {-19, -20}, AbstractMotor::gearset::green, {4_in, 12.5_in});


void forwardsTime(double speed, QTime time){
  leftRear.move_velocity(speed);
  leftFront.move_velocity(speed);
  rightFront.move_velocity(speed);
  rightRear.move_velocity(speed);
  rate.delayUntil(time);
  leftRear.move_velocity(0);
  leftFront.move_velocity(0);
  rightFront.move_velocity(0);
  rightRear.move_velocity(0);
}

void autonomous() {
  switch(auton){
    //RED FLAGS AUTON
    case 0:
    //set chassis speed
    chassis.setMaxVelocity(100);
    //run intake
    intake.move_velocity(200);
    //move chassis forwards
    chassis.moveDistance(43_in);
    //wait then reverse slightly
    intake.move_velocity(0);
    flywheel.move_velocity(200);
    chassis.moveDistance(-38_in);
    chassis.turnAngle(-90.0_deg);
    pros::delay(750);
    indexRoller.move_velocity(200);
    pros::delay(500);
    indexRoller.move_velocity(0);
    chassis.moveDistance(31_in);
    pros::delay(500);
    intake.move_velocity(200);
    indexRoller.move_velocity(200);
    pros::delay(1000);
    chassis.turnAngle(-8_deg);
    chassis.setMaxVelocity(200);
    chassis.moveDistance(18);
    flywheel.move_velocity(0);
      break;
    //BLUE FLAGS AUTON
    case 1:
    //set chassis speed
    chassis.setMaxVelocity(100);
    //run intake
    intake.move_velocity(200);
    //move chassis forwards
    chassis.moveDistance(43_in);
    //wait then reverse slightly
    intake.move_velocity(0);
    flywheel.move_velocity(200);
    chassis.moveDistance(-38_in);
    chassis.turnAngle(90.0_deg);
    pros::delay(750);
    indexRoller.move_velocity(200);
    pros::delay(500);
    indexRoller.move_velocity(0);
    chassis.moveDistance(31_in);
    pros::delay(500);
    intake.move_velocity(200);
    indexRoller.move_velocity(200);
    pros::delay(1000);
    chassis.turnAngle(8_deg);
    chassis.setMaxVelocity(200);
    chassis.moveDistance(18);
    flywheel.move_velocity(0);
      break;
    //RED PARKING AUTON
    case 2:
      //set chassis speed
      chassis.setMaxVelocity(100);
      //run intake
      intake.move_velocity(200);
      //move chassis forwards
      chassis.moveDistance(43_in);
      //wait then reverse slightly
      rate.delayUntil(750_ms);
      intake.move_velocity(0);
      chassis.moveDistance(-5_in);
      rate.delayUntil(750_ms);
      chassis.turnAngle(90.0_deg);
      rate.delayUntil(750_ms);
      chassis.moveDistance(-30_in);
      break;
    //BLUE PARK AUTON
    case 3:
      //set chassis speed
      chassis.setMaxVelocity(100);
      //run intake
      intake.move_velocity(200);
      //move chassis forwards
      chassis.moveDistance(43_in);
      //wait then reverse slightly
      rate.delayUntil(750_ms);
      intake.move_velocity(0);
      chassis.moveDistance(-5_in);
      rate.delayUntil(750_ms);
      chassis.turnAngle(-90.0_deg);
      rate.delayUntil(750_ms);
      chassis.moveDistance(-30_in);
      break;
    //SKILLS AUTON
    case 4:
      //Move forwards to get ball and come back
      chassis.setMaxVelocity(110);
      intake.move_velocity(200);
      flywheel.move_velocity(200);
      chassis.moveDistance(48.5_in);
      intake.move_velocity(0);
      chassis.moveDistance(-38_in);

      //Line up with wall and turn
      forwardsTime(-50,2000_ms);
      chassis.moveDistance(8);
      rate.delayUntil(750_ms);
      chassis.turnAngle(-90.0_deg);
      rate.delayUntil(750_ms);
      break;
  }
}
