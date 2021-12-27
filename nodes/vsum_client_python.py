#!/usr/bin/env python
import roslib

roslib.load_manifest('ros_service_examples')
import sys
from ros_service_examples.srv import *
import rospy


def vsum_client(c, b):
    rospy.wait_for_service('vector_summation_interaction')
    try:
        vsum_srv = rospy.ServiceProxy('vector_summation_interaction', VectorSummationService)
        resp = vsum_srv(c, b)
        return resp.weights
    except rospy.ServiceException, e:
        print "Service call failed: %s" % e


if __name__ == "__main__":
    context = [1.0, 2.0, 3.0]
    belief = [4.0, 5.0, 6.0]
    print(context, belief, vsum_client(context, belief))
