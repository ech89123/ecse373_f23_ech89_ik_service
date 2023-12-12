# ECSE 373 Laboratory #6 (Fall 2023)
The ik_service package runs on the ARIAC 2019 environment using ROS Noetic. More about ARIAC 2019 can be read here: [Link]( https://bitbucket.org/osrf/ariac/wiki/2019/Home)
## Preparing the Lab
To prepare the lab, the ARIAC workspace for the simulation environment and the ARIAC node are required. To install those, follow the instructions in the “Preparing the Lab” section from lab 5 listed here: [link](https://github.com/ech89123/ecse373_f23_ech89_ariac_entry).
More information about the two workspaces can be found here:  
[Simulation Environment Workspace](https://github.com/cwru-eecs-373/cwru_ariac_2019.git)
[ARIAC Node](https://github.com/cwru-eecs-373/ecse_373_ariac.git)
After that go to the workspace that the ik_service package is contained in and run the following commands to add it to the workspace to the ros environment and make the client and service executable:
```
source devel/setup.bash
catkin_make ik_client
catkin_make ik_service
```
## Launching the Lab
To launch the lab, use the roslaunch command first to launch the service and then use rosrun after to run the client while the service is running:
```
roslaunch ik_service ik_service.launch &
rosrun ik_service ik_client
```
## How to Confirm the Package is Running Properly 
After the `rosrun ik_service ik_client` has been run, an info print statement will be sent saying that a “pose_ik service” has been called. Along with that, the number of solutions that were sent will be returned. Finally one of the joint angles will be printed.
