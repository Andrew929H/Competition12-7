#include "main.h"

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor Left_Front_Mtr(1);
	pros::Motor Left_Rear_Mtr(2);
	pros::Motor Right_Front_Mtr(20, true);
	pros::Motor Right_Rear_Mtr(19, true);
	pros::Motor intake(3, true);
	pros::Motor index(5, true);
	pros::Motor flywheel(9, true);
	pros::Motor descore(11);

	//Main While Loop
	while (true) {
		//pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		  //               (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		    //             (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

		//Chassis Control - Store Joystick Value in Vaiable and Set Value equal to motors
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);
		Left_Front_Mtr = left;
		Left_Rear_Mtr = left;
		Right_Rear_Mtr = right;
		Right_Front_Mtr = right;


		//Intake system control
		if(master.get_digital(DIGITAL_R1)){
				intake.move_velocity(200);
		}
		else if(master.get_digital(DIGITAL_L1)){
				intake.move_velocity(200);
				index.move_velocity(200);
		}
		else if(master.get_digital(DIGITAL_UP)){
				intake.move_velocity(-200);
				index.move_velocity(-200);
		}
		else{
			intake.move_velocity(0);
			index.move_velocity(0);
		}


		descore.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		//Descore Control
		if(master.get_digital(DIGITAL_R2)){
				descore.move_velocity(200);
		}
		else if(master.get_digital(DIGITAL_L2)){
				descore.move_velocity(-200);
		}
		else{
			descore.move_velocity(0);
		}

		if(master.get_digital(DIGITAL_A)){
			flywheel.move_velocity(200);
		}
		if(master.get_digital(DIGITAL_B)){
			flywheel.move_velocity(0);
		}


		//Delay to prevent CPU from Starving
		pros::delay(20);
	}
}
