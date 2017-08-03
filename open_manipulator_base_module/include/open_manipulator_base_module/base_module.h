#ifndef OPEN_MANIPULATOR_BASE_MODULE_H_
#define OPEN_MANIPULATOR_BASE_MODULE_H_

#include <map>
#include <ros/ros.h>
#include <ros/callback_queue.h>
#include <ros/package.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Float64.h>
#include <std_msgs/String.h>
#include <sensor_msgs/JointState.h>
#include <geometry_msgs/Pose.h>
#include <boost/thread.hpp>
#include <yaml-cpp/yaml.h>

#include "robotis_math/robotis_math.h"
#include "robotis_framework_common/motion_module.h"

#include "robotis_controller_msgs/JointCtrlModule.h"
#include "robotis_controller_msgs/StatusMsg.h"
#include "open_manipulator_kinematics_dynamics/open_manipulator_kinematics_dynamics.h"
//#define MAX_JOINT_ID 5

namespace open_manipulator
{



class BaseModule
    : public robotis_framework::MotionModule,
      public robotis_framework::Singleton<BaseModule>
{
public:
  BaseModule();
  virtual ~BaseModule();

  /* ROS Topic Callback Functions */
  void initPoseMsgCallback(const std_msgs::String::ConstPtr& msg);
  void jointPosMsgCallback(const sensor_msgs::JointState::ConstPtr& msg);

  void kinematicsPoseMsgCallback(const geometry_msgs::Pose::ConstPtr& msg);
  void WorkStatusMsgCallback(const std_msgs::String::ConstPtr& msg);
//  bool getJointPoseCallback(thormang3_manipulation_module_msgs::GetJointPose::Request &req,
//                            thormang3_manipulation_module_msgs::GetJointPose::Response &res);
//  bool getKinematicsPoseCallback(thormang3_manipulation_module_msgs::GetKinematicsPose::Request &req,
//                                 thormang3_manipulation_module_msgs::GetKinematicsPose::Response &res);

  /* ROS Calculation Functions */
  void initPoseTrajGenerateProc();
  void jointTrajGenerateProc();
  void taskTrajGenerateProc();
  void generationTraj();
  void goalPoseTrahGenerationProc();

  /* ROS Framework Functions */
  void initialize(const int control_cycle_msec, robotis_framework::Robot *robot);
  void process(std::map<std::string, robotis_framework::Dynamixel *> dxls, std::map<std::string, double> sensors);
  void stop();
  bool isRunning();

  void publishStatusMsg(unsigned int type, std::string msg);

  /* Parameter */
  BaseModule                   *joint_state_;
  
  KinematicsDynamics *robotis_;
//////////////////////////////////////////
  /*   Value  */
  double joint_value_;
private:
  void queueThread();

  void parseData(const std::string &path);
  void parseIniPoseData(const std::string &path);

//  bool arm_angle_display_;

  double          control_cycle_sec_;
  boost::thread   queue_thread_;
  boost::thread  *traj_generate_tread_;

  std_msgs::String movement_done_msg_;

  ros::Publisher  status_msg_pub_;
  ros::Publisher  movement_done_pub_;

  ros::Publisher  work_status_pub;
  ros::Publisher  write_msg_pub;
  ros::Publisher  write_status_pub;
  ros::Publisher  present_pos_pub;


  /* joint state */
  Eigen::VectorXd present_joint_position_;
  Eigen::VectorXd goal_joint_position_;
  Eigen::VectorXd goal2_joint_position_;
  Eigen::VectorXd goal3_joint_position_;
  Eigen::VectorXd init_joint_position_;

  /* trajectory */
  bool    is_moving_;
  double  mov_time_;
  int     cnt_;
  int     count;
  int     all_time_steps_;

  Eigen::MatrixXd goal_joint_tra_;
  Eigen::MatrixXd goal_task_tra_;

  /* msgs */
  sensor_msgs::JointState joint_pose_msg_;
//  thormang3_manipulation_module_msgs::JointPose       goal_joint_pose_msg_;
//  thormang3_manipulation_module_msgs::KinematicsPose  goal_kinematics_pose_msg_;
  geometry_msgs::Pose  goal_kinematics_pose_msg_;

  /* inverse kinematics */
  bool  ik_solving_;
  int   ik_id_start_;
  int   ik_id_end_;
  int   flag;
  int   flag2;


  Eigen::MatrixXd ik_target_position_;
  Eigen::MatrixXd ik_start_rotation_;
  Eigen::MatrixXd ik_target_rotation_;
  Eigen::MatrixXd ik_weight_;

  void setInverseKinematics(int cnt);

  std::map<std::string, int> joint_name_to_id_;
  std::string ini_pose_path;
  std_msgs::String status_msg;
};

}

#endif /* OPEN_MANIPULATOR_BASE_MODULE_H_ */
