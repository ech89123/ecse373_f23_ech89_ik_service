#include "ros/ros.h"
#include "ik_service/PoseIK.h"
#include "ur_kinematics/ur_kin.h"


bool pose_ik(ik_service::PoseIK::Request &req, ik_service::PoseIK::Response &res) {
  ROS_INFO("pose_ik service has been called");
  
  double T[4][4] = {{0.0, -1.0, 0.0, req.part_pose.position.x}, \
                    {0.0, 0.0, 1.0, req.part_pose.position.y}, \
                    {-1.0, 0.0, 0.0 , req.part_pose.position.z}, \
                    {0.0, 0.0, 0.0, 1.0}};
     
  // Allocate space for up to eight solutions of six joint angles
  float q_sols[8][6];         
  // Variable to receive the number of solutions returned
  int num_sol;

  // Inverse kinematic solution(s)
  num_sol = ur_kinematics::inverse(&T[0][0], (double *) &q_sols[0][0], 0.0);
  res.num_sols = num_sol;
  
  //Useing the num_sol and q_sols variables to fill out the ik_service::PoseIK::Response res
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 6; j++){
      res.joint_solutions[i].joint_angles[j] = q_sols[i][j];
    }
  }
  
  //for testing purposes
  //res.num_sols = -1;
  
  return true;
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "ik_service");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("pose_ik", pose_ik);
  
  ros::spin();
  
  return 0;
}



