Welcome to the Readme.txt.
This package is for the control of the robot, recieveng an input from the camera indicating the position of the center of gravity
of a briht object.
If it doesnt get a value of the center of gravity, it will set the target of the moving robot from an automatic position. 
If it recieves an input and then stops recieving it, it will set the last position as target and stay there untill a new target is provided.

DISCLAIMER: Assumed instalation of openCV for C++

Assignment 1.2.1
-----------------------------------------
Run: ros2 run rel_controller controller

you can publish on the /cog_object topic a position to be added to a vector of 10 max targets. The robot will reach these targets sequentially.

Assignment 1.2.2

Run: ros2 launch rel_controller launch.xml.

This will get the light position, if not:
you can publish on the /cog_object topic a position to be added to a vector of 10 max targets. The robot will reach these targets sequentially.
