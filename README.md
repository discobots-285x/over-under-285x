# 285X Over Under Code

This is team 285X's code for the 2023-24 VRC game, Over Under.
Here's a brief explanation of the most important files you'll *probably* edit for usage.

## Accessing the code

First things first, you gotta access the code! Using your local command line, *git clone* the link for this repository, transferring this code to your local system. Now, to access and edit the code, you'll have to download the VEXcode Pro V5 editor from the VEX website (there is a VScode extension for VEXcode V5, and I think that's actually the preferred way to do it, but idk how to LMAO). Once in VEXcode, go to File > Open > (whatever folder you saved the project in) > over-under-285x.v5code.

# Breakdown of the code

## /src/robot-config.cpp

This file contains the code that configures the motors and sensors hooked up to the brain of the bot. I would reccomend using the built-in VEXCode Device Configuration tool to configure your motors and sensors, but do NOT use it to configure your user control code (it puts all the controller code into a separate task which fucks with autons). Instead, write your user control in main.cpp in the cleverly-named function *user_control()*. You do NOT need to code in drivetrain controls, the drivetrain initialization in main.cpp takes care of that.

## /src/main.cpp

This file contains the initialization code for the drivetrain, odometry/position tracking system, autonomous code selection, and user control code. For the drivetrain and odometry configuration, follow the instructions in the comments of the code. For autonomous code selection, go to the two functions *pre_auton()* and *autonomous()*. Basically, the *pre_auton()* values are what will be printed on the screen of the brain during auton selection and the corresponding *autonomous()* selection is what code will actually run. Finally, for user control code, make sure to put the drivetrain control function into in while loop (so usually that will be *chassis.control_arcade()*) and then program the controller code. The way VEXCode functions work, the controller code is a constant switch (meaning you have to constantly press a button for a motor to move), but I have a latch-toggle system coded right now so that the buttons act as a toggle.

## /src/autons.cpp

Pretty straightforward - it literally holds the code for your different autons. Code whatever you need and put it here. Note: make sure that when you make new autons here, you reflect those changes in *main.cpp* in the auton selection code and in *autons.h*, otherwise you won't be able to actually use that code in match, which is not ideal!

## /src/JAR-Template

There is almost no scenario in which you change anything in here - this is all the boilerplate code and setup for the odometry position tracking systems and the functions to help you with autonomous coding. Check these files if you want to get a better understanding of odometry code or if you need to see the inner workings of the drive functions for autonomous coding!


That's pretty much it, this code is super easy to get set up and running - you only really need to change the configuration of the motors and drive and then get straight into coding autons! If you ever need any help with coding, this code is based on the JAR-Template created by team 2775V. They have their own documentation [here](https://jacksonarearobotics.github.io/JAR-Template/). Additionally, if you ever need help or have any questions, reach out to me on insta (@notzayan.n)! Happy coding!