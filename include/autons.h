#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

void default_constants();
void odom_constants();

void safe_auton();
void far_side();
void near_side();
void near_side_elims();
void far_side_elims();

void skills_auton();

void drive_test();
void turn_test();
void swing_test();
void full_test();
void odom_test();
void tank_odom_test();