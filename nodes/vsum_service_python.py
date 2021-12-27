#!/usr/bin/env python
import time
from ros_service_examples.srv import *
from ros_service_examples.srv import VectorSummationService, VectorSummationServiceResponse
import rospy


def handle_summation(req):
    weight = [req.belief[i] + req.context[i] for i in range(min(len(req.context), len(req.belief)))]
    print("Returning:", (req.belief, req.context, weight))
    return VectorSummationServiceResponse(weight)


def vsummation_node():
    rospy.init_node('vector_summation_node')
    s = rospy.Service('vector_summation_interaction', VectorSummationService, handle_summation)
    rospy.spin()


if __name__ == "__main__":
    vsummation_node()
