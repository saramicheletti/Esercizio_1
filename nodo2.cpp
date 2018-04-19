#include "ros/ros.h"

#include "std_msgs/String.h"


#include <sstream>


int main( int argc, char **argv ) {
 
  ros::init(argc, argv, "nodo2");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("filtered", 1000);

  ros::Rate loop_rate(1);


  while (ros::ok())
  {

    std_msgs::String message;

    std::stringstream ss;
    ss << "Sara" << "21" << "Bioinformatica";


    message.data = ss.str();


    ROS_INFO("%s", message.data.c_str());

    
    chatter_pub.publish(message);

    ros::spinOnce();

    loop_rate.sleep();

  }

}

