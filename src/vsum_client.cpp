#include <iostream>
#include <ros/ros.h>
#include <vector>
#include <ros_service_examples/VectorSummationService.h>


int main(int argc, char **argv) {
    ros::init(argc, argv, "vector_summation_client");

    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<ros_service_examples::VectorSummationService>(
            "vector_summation_interaction");

    ros_service_examples::VectorSummationService srv;

    std::vector<double> context{1.0, 2.0, 3.0};
    srv.request.context = context;
    std::vector<double> belief{4.0, 5.0, 6.0};
    srv.request.belief = belief;

    if (client.call(srv)) {
        ROS_INFO("OK, sent. Here is the answer:");
        std::vector<double> is_weights = srv.response.weights;
        std::cout << " - Response vector[0]: " << is_weights[0] << std::endl;
        std::cout << " - Response vector[1]: " << is_weights[1] << std::endl;
        std::cout << " - Response vector[2]: " << is_weights[2] << std::endl;
    }

    return EXIT_SUCCESS;
}
