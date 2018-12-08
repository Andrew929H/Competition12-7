#include "main.h"
#include "globals.h"

inline int auton;


int count = 0;


void refreshScreen(){
	switch(auton){
		case 0:
			pros::lcd::set_text(3,"Red Flags");
			break;
		case 1:
			pros::lcd::set_text(3,"Blue Flags");
			break;
		case 2:
			pros::lcd::set_text(3,"Red Parking");
			break;
		case 3:
			pros::lcd::set_text(3,"Blue Parking");
			break;
		case 4:
			pros::lcd::set_text(3,"Skills Auton");
			break;
	}
}


void on_left_button(){
	if(auton != 0){
		auton--;
	}
	else
		auton = 4;
		refreshScreen();
}

void on_right_button(){
	if(auton != 4)
		auton++;
	else
		auton = 0;
	refreshScreen();
}



void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(0, "Team 929H Auton Selector!");

	auton = 0;
	pros::lcd::register_btn0_cb(on_left_button);
	pros::lcd::register_btn2_cb(on_left_button);
	refreshScreen();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
