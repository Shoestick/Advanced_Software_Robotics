Assignment 1.1.2
-----------------------------------------------
1. Open four new terminals, in the first run
	ros2 run image_tools cam2image
   In the second run
	ros2 run image_tools showimage
   In the third run
	ros2 run light_tracking detector
   In the fourth run
	ros2 topic echo /bright

Location in code: callbackImage() function in light_detector.cpp

Assignment 1.1.3
-----------------------------------------------
1. Without closing the previous terminals, open an new one and run
	ros2 param set /detector threshold 200
	
Location in code: callbackImage() function in light_detector.cpp

2. Close all terminals and open four new ones, in the first run
	ros2 run image_tools cam2image
   In the second run
        ros2 run image_tools showimage
   In the third run
        ros2 run light_tracking detector --ros-args -p threshold:=180
   In the fourth run
        ros2 topic echo /bright
        
Location in code: callbackImage() function in light_detector.cpp

Assignment 1.1.4
-----------------------------------------------
1. Open three new terminals, in the first, run
	ros2 run light_tracking position
   In the second run
	ros2 run image_tools cam2image
   Source the third to setup.bash(because it uses a custom message), then run
	ros2 topic echo /cog_object
	
Location in code: 
	

