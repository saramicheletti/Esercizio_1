#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <cstring>
#include <string>

int comando;


void filteredPubblica(const std_msgs::String::ConstPtr& msg){

	if( comando !='0' ){

 	 char * cstr = new char [msg->data.length()+1];
  	 std::strcpy (cstr, msg->data.c_str());

		switch ( comando ){
		
			case 'a': 
				std::cout << cstr << '\n';
			break;
	
			case 'n': 
				{char * p = std::strtok(cstr," "); //p punta alla prima sottostringa del messaggio 
				std::cout << p << '\n';
    				}
			break;
	
			case 'e': 
				{char * p = std::strtok(cstr," ");
				p = std::strtok(NULL," "); //p punta alla seconda sottostringa 
				std::cout << p << '\n';
				}
			break;
	
			case 'c': 
				{char * p = std::strtok(cstr," ");
				p = std::strtok(NULL," "); //p punta alla seconda sottostringa 
				p = std::strtok(NULL," "); //p punta alla terza sottostringa
				std::cout << p << '\n';
				}
			break;
		}


  	delete[] cstr;
	}
  
}


void chatterComando(const std_msgs::String::ConstPtr& msg){

	ROS_INFO("I heard: [%s]", msg->data.c_str());
	
	comando=msg->data[0];
}




int main(int argc, char **argv) {

  ros::init(argc, argv, "nodo3");

 
  ros::NodeHandle n;

  
  ros::Subscriber sub = n.subscribe("filtered", 1000, filteredPubblica);


  ros::Subscriber s = n.subscribe("chatter", 1000, chatterComando);


  ros::spin();


}

