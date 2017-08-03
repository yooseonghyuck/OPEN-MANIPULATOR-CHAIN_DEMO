/*******************************************************************************/


#ifndef OPNE_MANIPULATOR_SUB_H_
#define OPNE_MANIPULATOR_SUB_H_


#include <map>
#include <math.h>
#include <ros/ros.h>
#include <ros/callback_queue.h>
#include <ros/package.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Float64.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Pose.h>
#include <boost/thread.hpp>
#include <yaml-cpp/yaml.h>

#include "robotis_math/robotis_math.h"
#include "robotis_framework_common/motion_module.h"

#include "robotis_controller_msgs/JointCtrlModule.h"
#include "robotis_controller_msgs/StatusMsg.h"
#include "sensor_msgs/JointState.h"
#define MAX_JOINT_ID  5

namespace robotis_test
{

class OpenManipulatorSub
{
public:
  OpenManipulatorSub();
  ~OpenManipulatorSub();
  ros::Publisher work_status_pub;
  ros::Publisher ini_msg_pub;
  ros::Publisher point_kinematics_msg_pub;
  ros::Publisher point_write_msg_pub;
  ros::Publisher grip_joint_sub_pub_;
  ros::Subscriber grip_joint_state_sub_;
  ros::Subscriber write_msg_sub;
  ros::Subscriber write_status_sub;

  ros::Subscriber keyboard_msg_sub;

  ros::Subscriber present_pos_msg_sub;
  ros::Subscriber alp_msg_sub;
  ros::Subscriber next_msg_sub;


  void initialize();
  void process();
  void msgCallback(const std_msgs::String::ConstPtr &msg);
  void StatsuMsgCallback(const std_msgs::String::ConstPtr &msg);
  void KeyboardmsgCallback(const geometry_msgs::Pose::ConstPtr &msgg);
  void PresentPositionMsgCallback(const geometry_msgs::Pose::ConstPtr &msg);
  void alpMsgCallback(const std_msgs::String::ConstPtr &msg);
  void NextMsgCallback(const std_msgs::String::ConstPtr &msg);
  std_msgs::Float64 grip_joint_comm;
  std_msgs::String Alp_msg;

  geometry_msgs::Pose kinematics_msg;

  geometry_msgs::Pose present_position;
  int count_num;
  int count_num2;
  int cnt;
  int cnt2;
  int flag;
  int write_flag;
  int flag2;
  int flag_ver;
  int cnt_test;

  int test;
private:
   ros::NodeHandle ros_node_;

};

}
#endif // OPEN_MANPULATOR_SUB_H
