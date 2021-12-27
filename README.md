## About
This is a simple project that make a ROS service-client connection between Python and C++ modules. Either of them can be either the service or the client.


## How to run?
- in a catkin workspace, run `catkin_make`
- run `roscore` to initialize ros
- in another terminal, run `source ~/catkin_ws/devel/setup.bash`
- and then `cd catkin_ws/`
- next: `roscd ros_service_examples`
- run the service `rosrun ros_service_examples vsum_service_python.py` (in this command the python script is used. one can also use c++ as the service by running: `rosrun ros_service_examples vsum_service`.)
- again, in another terminal, run `source ~/catkin_ws/devel/setup.bash`
- `cd catkin_ws/`
- run the client `rosrun ros_service_examples vsum_client_python.py` (if you wish to run the c++ client, run `rosrun ros_service_examples vsum_client`)
