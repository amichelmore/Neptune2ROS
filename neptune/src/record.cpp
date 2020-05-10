#include <cstdlib>

#include "ros/ros.h"


int main(int argc, char **argv){
	ros::init(argc, argv, "record");
	ros::NodeHandle nh;

	ros::Rate loop_rate(5);

	while (ros::ok()){
		ROS_INFO("Is this thing on??");

		ros::spinOnce();
		loop_rate.sleep();
	}

}