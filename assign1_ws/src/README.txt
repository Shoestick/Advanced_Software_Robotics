Assignment 1.1.2
-----------------------------------------------
1. Open four new terminals, in the first run
	ros2 run image_tools cam2image
   In the second run
	ros2 run image_tools showimage
   In the third run
	ros2 run light_tracking detector --ros-args -p threshold:=100
   In the fourth run
	ros2 topic echo /bright

Location in code: callbackLuminance() function in light_detector.cpp

Assignment 1.1.3
-----------------------------------------------
1. Without closing the previous terminals, open an new one and run
	ros2 param set /detector threshold 150
	
Location in code: callbackLuminance() function in light_detector.cpp

2. Close all terminals and open four new ones, in the first run
	ros2 run image_tools cam2image
   In the second run
        ros2 run image_tools showimage
   In the third run
        ros2 run light_tracking detector --ros-args -p threshold:=180
   In the fourth run
        ros2 topic echo /bright
        
Location in code: callbackLuminance() function in light_detector.cpp

DISCLAIMER: For the following subassignments it is assumed openCV is installed for C++

Assignment 1.1.4
-----------------------------------------------
1. Open three new terminals, in the first, run
	ros2 run light_tracking position
   In the second run
	ros2 run image_tools cam2image
   Source the third to setup.bash(because it uses a custom message), then run
	ros2 topic echo /cog_object
	
Location in code: callbackObjPos function in object_position.cpp
		  publishCog 	 function in object_position.cpp

Assignment 1.2.1
-----------------------------------------
Run: ros2 run rel_controller controller

you can publish on the /cog_object topic a position to be added to a vector of 10 max targets. The robot will reach these targets sequentially.

Assignment 1.2.2

Run: ros2 launch rel_controller launch.xml.

This will get the light position, if not:
you can publish on the /cog_object topic a position to be added to a vector of 10 max targets. The robot will reach these targets sequentially.
	

