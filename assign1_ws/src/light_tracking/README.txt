Package light_tracking
-----------------------------------------------
Description: This package allows for brightness detection and tracking of bright objects.
Inputs
	/image
	Type: sensor_msgs/msg/Image
Outputs
	/bright
	Type: example_interfaces/msg/String
	/cog_object
	Type: assign1_interfaces/msg/PixelCoordinates
	
Run
In a terminal run either of the following commands once the image_tools cam2image is running:
	ros2 run light_tracking detector
	ros2 run light_tracking position
	
Parameters
	int threshold : Sets the threshold value for light detection or for binary thresholding. Values equal to the threshold are considered below the threshold. Default = 242
	double timer_period : Sets the publishing rate of the object position. Default = 1.0
	
Core components
	callbackLuminance(): Ingests webcam image and publishes whether average brightness is above or below threshold
	callbackObjPos(): Ingests webcam image and publishes centroid of bright object
