#include "ros/ros.h"
#include "iostream"
#include "ackermann_msgs/AckermannDrive.h"
#include "ackermann_msgs/AckermannDriveStamped.h"

using namespace std;

int main(int argc, char **argv){
	ros::init(argc, argv, "node");
	ros::NodeHandle nh;

	ros::Publisher pub = nh.advertise<ackermann_msgs::AckermannDriveStamped>("/ctrl_cmd",10);
	ackermann_msgs::AckermannDriveStamped ackerData_;
	ackerData_.drive.steering_angle = -28;
	ros::Rate loop_rate(10);
	
	while(ros::ok()){
		if (ackerData_.drive.steering_angle > 28){
			ackerData_.drive.steering_angle = -28;
		}
		ackerData_.drive.speed = 0;
		cout << "############" << endl;
		cout << ackerData_ << endl;
		pub.publish(ackerData_);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;

}
