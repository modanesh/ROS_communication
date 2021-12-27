#include <iostream>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <ros/ros.h>
#include <ros/package.h>
#include <ros_service_examples/VectorSummationService.h>


bool vector_summation_interaction(ros_service_examples::VectorSummationService::Request &req,
                                  ros_service_examples::VectorSummationService::Response &res) {
    std::vector<double> b = req.belief;
    std::vector<double> c = req.context;
    for (auto i = 0; i < 3; i++) {
        res.weights.push_back(b[i] + c[i]);
    }
    return true;
}


int main(int argc, char **argv) {
    ros::init(argc, argv, "vector_summation_node");
    ros::NodeHandle nh;
    ros::ServiceServer service = nh.advertiseService("vector_summation_interaction", vector_summation_interaction);
    ROS_INFO("Service up and running.");
    ros::spin();
    return EXIT_SUCCESS;
}
