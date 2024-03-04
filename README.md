# 285X Over Under Code

This is team 285X's code for the 2023-24 VRC game, Over Under.
Here's a brief explanation of the most important files you'll *probably* edit for usage.

## Accessing the code

First things first, you gotta access the code! Do the usual - create a folder and git clone the link for this repository, transferring this code to your local system. Now, to access and edit the code, you'll have to download the VEXcode Pro V5 editor from the VEX website (there is a VScode extension for VEXcode V5, and I think that's actually the preferred way to do it, but idk how to LMAO). Once in VEXcode, go to File > Open > (whatever folder you saved the project in) > over-under-285x.v5code.

## Breakdown of the code

### /src/main.cpp

Despite the name of the file being "main", this is probably the file you'll change the least. This file contains the code to setup and initialize the drivetrain and odometry system as well as the autonomous selection code.

### /src/robot-config.cpp

This file contains the code that configures the motors and sensors hooked up to the brain of the bot as well as the control scheme for the different motors and subsystems. I would suggest deleting the code above the function vexcodeInit(), and then using the built in device configuration tool in VEXcode to set up motors and sensors, and then hand-code the controller functions for your individual subsystems. You do NOT need to code in drivetrain controls, the drivetrain initialization in main.cpp takes care of that.

### /src/autons.cpp

Pretty straightforward - it literally holds the code for your different autons. Code whatever you need and put it here. Note: make sure that when you make new autons here, you reflect those changes in main.cpp in the auton selection code, otherwise you won't be able to actually use that code in match, which is not ideal!

### /src/drive

There is almost no scenario in which you change anything in here - this is all the boilerplate code and setup for the odometry position tracking systems and the functions to help you with autonomous coding. Check these files if you want to get a better understanding of odometry code or if you need to see the inner workings of the drive functions for autonomous coding!


That's pretty much it, this code is super easy to get set up and running - you only really need to change the configuration of the motors and drive and then get straight into coding autons! If you ever need any help with coding, this code is based on the JAR-Template created by team 2775V. They have their own documentation [here](https://jacksonarearobotics.github.io/JAR-Template/). Happy coding!