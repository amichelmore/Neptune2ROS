#include <vector>
#include <string>
#include <cstdlib>

#include "ros/ros.h"
#include "mavros/mavros.h"
#include "mavros_msgs/State.h"
// No more rosspawn includes??
#include "rosspawn/NodeAction.h"

//MAVLINK_VERSION string
#include "mavlink/config.h"
#include "mavconn/mavlink_dialect.h"

bool record = false;

void chatterCallback(const mavros_msgs::State::ConstPtr& state){
	if(state->mode == "NEPTUNED" && record == false){
		ROS_INFO("You are now in mode: [%s]", state->mode.c_str());
		record = true;

	} else if(state->mode != "NEPTUNED" && record == true){
		ROS_INFO("You are no longer in mode: [%s]", state->mode.c_str());
		record = false;
	}
}

int main(int argc, char **argv){

	// Initialize ROS node
	ros::init(argc, argv, "mode");
	ros::NodeHandle nh;

	// Subscriber object
	ros::Subscriber sub = nh.subscribe("mavros/state", 1000, &chatterCallback);

	ros::ServiceClient start_client = nh.serviceClient<rosspawn::start_node>("start_node");
	ros::ServiceClient stop_client = nh.serviceClient<rosspawn::stop_node>("stop_node");

	rosspawn::NodeAction srv;
	srv.request = "/src/neptune/src/record.cpp"

	bool recording = false;
	ros::Rate loop_rate(10);

	while(ros::ok())
	{
		if(record == true && recording == false){

		} else if(record == false && recording == true){

		}
		ros::spinOnce();
		loop_rate.sleep();
	}
}