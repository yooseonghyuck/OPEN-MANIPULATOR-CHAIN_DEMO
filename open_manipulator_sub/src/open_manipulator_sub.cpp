#include "open_manipulator_sub/open_manipulator_sub.h"

namespace robotis_test
{
OpenManipulatorSub::OpenManipulatorSub()
    : ros_node_()
{

}


OpenManipulatorSub::~OpenManipulatorSub()
{

}

void OpenManipulatorSub::initialize()
{

  point_kinematics_msg_pub = ros_node_.advertise<geometry_msgs::Pose>("/robotis/base/kinematics_pose_msg",100);

  color_write_sta_pub_ = ros_node_.advertise<std_msgs::String>("/robotis/sub/color_sta_msgs",100);
 //write_msg_pub      = ros_node_.advertise<std_msgs::String>("/robotis/base/write_msg",100);
  ini_msg_pub         = ros_node_.advertise<std_msgs::String>("/robotis/base/ini_pose_msg", 100);

  work_status_pub     = ros_node_.advertise<std_msgs::String>("robotis/base/work_status_msg",100);

  test_mode_status_pub = ros_node_.advertise<std_msgs::String>("/robotis/base/test_mode_status_pub",100);

  grip_joint_sub_pub_ = ros_node_.advertise<std_msgs::Float64>("/open_manipulator_chain/grip_joint_sub_position/command", 100);

  write_status_sub    = ros_node_.subscribe("/robotis/base/write_status_msg", 100, &OpenManipulatorSub::StatsuMsgCallback, this);

  write_msg_sub       = ros_node_.subscribe("/robotis/base/write_msg", 100, &OpenManipulatorSub::msgCallback, this);

  alp_msg_sub         = ros_node_.subscribe("open_manipulator/alp_keyboard_msg", 100, &OpenManipulatorSub::alpMsgCallback, this);
  keyboard_msg_sub    = ros_node_.subscribe("/open_manipulator/cmd_keyboard", 100, &OpenManipulatorSub::KeyboardmsgCallback, this);

  present_pos_msg_sub = ros_node_.subscribe("/robotis/base/present_pos_msg", 100, &OpenManipulatorSub::PresentPositionMsgCallback, this);

  next_msg_sub        = ros_node_.subscribe("/robotis/base/next_work_msg",100, &OpenManipulatorSub::NextMsgCallback,this);

  color_msgs_sub      = ros_node_.subscribe("/robotis/sub/color_msgs",100, &OpenManipulatorSub::ColorMsgCallback,this);

  test_msgs_sub       = ros_node_.subscribe("open_manipulator/test_msg",100, &OpenManipulatorSub::testMsgCallback,this);
  /**value**/


  cnt=0;
  cnt2=0;
  write_flag = 0;
  count_num = 0;
  flag=0;
  flag_ver=0;
  count_num2 = 0;
  test =0;
  red_cnt=0;
  blue_cnt=0;
  next_page_cnt =0;
  next_page_flag =0;
  next_cnt =0;
  test_cnt =0;
  test_flag=0;


}
///////////if you change initial position, change this funcition///////////
void OpenManipulatorSub::initial_position_set()
{
  kinematics_msg.position.x = 0.076;
  kinematics_msg.position.y = -0.05;
  kinematics_msg.position.z = 0.102;
}
void OpenManipulatorSub::testMsgCallback(const std_msgs::String::ConstPtr &msg)
{

  if(msg->data == "end")
  {
    ROS_INFO("Exit test mode");


    ROS_INFO("initial position");
    std_msgs::String ini_msg;
    ini_msg.data = "ini_pose";
    ini_msg_pub.publish(ini_msg);
    cnt = 0;
    write_flag =0;
    test = 0;
    count_num  = 0;
    count_num2 = 0;
    red_cnt=0;
    blue_cnt=0;
    cnt2;
    next_cnt=0;
    test_cnt=0;
    test_flag=0;
    watch_cnt=0;


    int count =0;
    for(int i=0; i<1000; i++)
    {
      ROS_INFO("wait");
      count++;
      if(i==100)
      {
        ROS_INFO("initial position");
        std_msgs::String ini_msg;
        ini_msg.data = "ini_pose";
        ini_msg_pub.publish(ini_msg);
        break;
      }
    }

  }
  else if(msg->data == "wtestmode")
  {

      test_cnt = test_cnt-1;
      test     = test-1;

      std_msgs::String test_mode_status_msg;
      test_mode_status_msg.data = "testing";
      test_mode_status_pub.publish(test_mode_status_msg);


  }
  else if(msg->data == "testmode")
  {



   if(test_cnt==0)
   {


     write_flag = 1;

     Alp_msg.data = "r";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {

         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "r";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;
      test_cnt++;
      test_flag=1;
    }
   else if(test_cnt==1)
   {
     write_flag = 1;

     Alp_msg.data = "o";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {
         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "o";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;
      test_cnt++;
      test_flag=1;
   }

   else if(test_cnt==2)
   {
     write_flag = 1;

     Alp_msg.data = "b";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {
         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "b";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;
      test_cnt++;
      test_flag=1;
   }
   else if(test_cnt==3)
   {
     write_flag = 1;


     Alp_msg.data = "o";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {
         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "o";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;
      test_cnt++;
      test_flag=1;
   }
   else if(test_cnt==4)
   {
     write_flag = 1;

     Alp_msg.data = "t";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {
         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "t";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;
      test_cnt++;
      test_flag=1;
   }
   else if(test_cnt==5)
   {
     write_flag = 1;

     Alp_msg.data = "i";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {
         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "i";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;
      test_cnt++;
      test_flag=1;
   }
   else if(test_cnt==6)
   {
     write_flag = 1;

     Alp_msg.data = "s";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {
         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "s";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;

      test_flag=1;

   }

 }
}

void OpenManipulatorSub::ColorMsgCallback(const std_msgs::String::ConstPtr &msg)
{
  if(msg->data == "red")
  {

    ROS_INFO("1");
   if(red_cnt==0)
   {
     write_flag = 1;
     ROS_INFO("1");
     Alp_msg.data = "r";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {

         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "r";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;
      red_cnt++;
    }
   else if(red_cnt==1)
   {
     write_flag = 1;
     ROS_INFO("1");
     Alp_msg.data = "e";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {
         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "e";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;
      red_cnt++;
   }
   else if(red_cnt==2)
   {
     write_flag = 1;
     ROS_INFO("1");
     Alp_msg.data = "d";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {
         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "d";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;
      red_cnt==0;

   }


 }
  if(msg->data == "blue")
  {

    ROS_INFO("1");
   if(blue_cnt==0)
   {
     write_flag = 1;
     ROS_INFO("1");
     Alp_msg.data = "b";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {
         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "b";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;
      blue_cnt++;
    }
   else if(blue_cnt==1)
   {
     write_flag = 1;
     ROS_INFO("1");
     Alp_msg.data = "l";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {
         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "l";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;
      blue_cnt++;
   }
   else if(blue_cnt==2)
   {

     write_flag = 1;
     ROS_INFO("1");
     Alp_msg.data = "u";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {
         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "u";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;
      blue_cnt==0;

   }
   else if(blue_cnt==3)
   {
     write_flag = 1;
     ROS_INFO("1");
     Alp_msg.data = "e";

     if(cnt==0 && flag ==0)
     {
       if(test==0)
       {
         OpenManipulatorSub::initial_position_set();
         point_kinematics_msg_pub.publish(kinematics_msg);
       }

      std_msgs::String work_msg;
      work_msg.data = "e";
      if(flag==0)
      {
      work_status_pub.publish(work_msg);
      }
      ROS_INFO("send");
      cnt++;
      write_flag = 0;

      }
      test ++;
      blue_cnt==0;

   }


 }

}

void OpenManipulatorSub::NextMsgCallback(const std_msgs::String::ConstPtr &msg)
{
  if(msg->data =="a")
   write_flag =1;
  else if(msg->data =="b")
   write_flag =1;
  else if(msg->data =="c")
   write_flag =1;
  else if(msg->data =="d")
   write_flag =1;
  else if(msg->data =="e")
   write_flag =1;
  else if(msg->data =="f")
   write_flag =1;
  else if(msg->data =="g")
   write_flag =1;
  else if(msg->data =="h")
   write_flag =1;
  else if(msg->data =="i")
   write_flag =1;
  else if(msg->data =="j")
   write_flag =1;
  else if(msg->data =="k")
   write_flag =1;
  else if(msg->data =="l")
   write_flag =1;
  else if(msg->data =="m")
   write_flag =1;
  else if(msg->data =="n")
   write_flag =1;
  else if(msg->data =="o")
   write_flag =1;
  else if(msg->data =="p")
   write_flag =1;
  else if(msg->data =="q")
   write_flag =1;
  else if(msg->data =="r")
   write_flag =1;
  else if(msg->data =="s")
   write_flag =1;
  else if(msg->data =="t")
   write_flag =1;
  else if(msg->data =="u")
   write_flag =1;
  else if(msg->data =="v")
   write_flag =1;
  else if(msg->data =="w")
   write_flag =1;
  else if(msg->data =="x")
   write_flag =1;
  else if(msg->data =="y")
   write_flag =1;
  else if(msg->data =="z")
   write_flag =1;
  else if(msg->data =="test")
   write_flag =1;

}
////////////////////if you change initial position, change this funciton/////////////////////////
void OpenManipulatorSub::alpMsgCallback(const std_msgs::String::ConstPtr &msg)
{

  if(msg->data == "a")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "a";

   if(cnt==0 && flag ==0)
   {
     if(test==0)
     {
       OpenManipulatorSub::initial_position_set();
       point_kinematics_msg_pub.publish(kinematics_msg);
     }

    std_msgs::String work_msg;
    work_msg.data = "a";
    if(flag==0)
    {
    work_status_pub.publish(work_msg);
    }
    ROS_INFO("send");
    cnt++;
    write_flag = 0;

    }
    test ++;
  }
  else if(msg->data == "b")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "b";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }

     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "b";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;

     }
     test ++;
  }
  else if(msg->data == "c")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "c";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "c";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "d")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "d";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "d";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "e")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "e";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "f")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "f";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "g")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "g";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "g";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "h")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "h";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "h";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "i")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "i";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "i";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "j")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "j";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "j";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "k")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "k";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "k";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "l")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "l";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "l";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "m")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "m";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "m";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "n")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "n";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "n";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "o")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "o";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "o";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "p")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "p";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "p";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "q")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "q";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "r")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "r";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "r";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "s")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "s";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "s";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "t")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "t";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "t";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "u")
  {

    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "u";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "u";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "v")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "v";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "v";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "w")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "w";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "w";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "x")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "x";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "x";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "y")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "y";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "y";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }
  else if(msg->data == "z")
  {
    write_flag = 1;
    ROS_INFO("1");
    Alp_msg.data = "z";

    if(cnt==0 && flag ==0)
    {
      if(test==0)
      {
        OpenManipulatorSub::initial_position_set();
        point_kinematics_msg_pub.publish(kinematics_msg);
      }
     ROS_INFO("2");
     std_msgs::String work_msg;
     work_msg.data = "z";
     work_status_pub.publish(work_msg);
     cnt++;
     write_flag = 0;
     }
    test ++;
  }




}

void OpenManipulatorSub::PresentPositionMsgCallback(const geometry_msgs::Pose::ConstPtr &msg)
{
  present_position.position.x = msg->position.x;
  present_position.position.y = msg->position.y;
  present_position.position.z = msg->position.z;

}

void OpenManipulatorSub::KeyboardmsgCallback(const geometry_msgs::Pose::ConstPtr &msg)
{
   geometry_msgs::Pose kine;
   kine.position.x = msg->position.x;
   kine.position.y = msg->position.y;
   kine.position.z = msg->position.z;

   double pos_x;
   double pos_y;
   double pos_z;
   double pre_pos_z;

   pos_x = kine.position.x;
   pos_y = kine.position.y;
   pos_z = kine.position.z;


   if(pos_x == 0.0 && pos_y == 1.0 && pos_z == 0.0 && flag == 0)
   {

        int pre_count_num = count_num;

        count_num++;

        ROS_INFO("RIGHT");
        ROS_INFO("%d",count_num);



            if( flag_ver == 1)
            {
              kinematics_msg.position.x = present_position.position.x + 0.001;
            }
            else if( flag_ver == 0)
            {
              kinematics_msg.position.x = present_position.position.x - 0.001;
            }

            kinematics_msg.position.y = present_position.position.y + 0.01;

            if(count_num >0)
            {
               if(abs(pre_count_num) < abs(count_num))
               {
                  kinematics_msg.position.z =present_position.position.z  - 0.001;
               }
               else
               {
                  kinematics_msg.position.z =present_position.position.z  + 0.001;
               }
            }
             else if(count_num <0)
             {
                if(abs(pre_count_num) > abs(count_num))
                {
                   kinematics_msg.position.z =present_position.position.z  - 0.001;
                }
                else
                {
                   kinematics_msg.position.z =present_position.position.z  + 0.001;
                }
              }
             else
            {
          //    kinematics_msg.position.z = 0.039;
            }

            pre_pos_z = kinematics_msg.position.z;
            point_kinematics_msg_pub.publish(kinematics_msg);


            flag_ver = 1;



    }
   else if(pos_x == 0.0 && pos_y == -1.0 && pos_z == 0.0 && flag == 0)
   {
           int pre_count_num = count_num;

           pre_count_num = abs(pre_count_num);
           count_num--;

           ROS_INFO("LEFT");
           ROS_INFO("%d",count_num);



             if( flag_ver == 1)
             {
               kinematics_msg.position.x = present_position.position.x - 0.001;
             }
             else if( flag_ver == 0)
             {
               kinematics_msg.position.x = present_position.position.x + 0.001;
             }

             kinematics_msg.position.y = present_position.position.y - 0.01;

             if(count_num > 0)
             {
                if(abs(pre_count_num) < abs(count_num))
                {
                   kinematics_msg.position.z =present_position.position.z  - 0.001;
                }
                else
                {
                   kinematics_msg.position.z =present_position.position.z  + 0.001;
                }
             }
            else if(count_num < 0)
             {
                 if(abs(pre_count_num) > abs(count_num))
                 {
                    kinematics_msg.position.z =present_position.position.z  + 0.001;
                 }
                 else
                 {
                    kinematics_msg.position.z =present_position.position.z  - 0.001;
                 }
              }
             else
             {
        //       kinematics_msg.position.z = 0.039;
             }

             point_kinematics_msg_pub.publish(kinematics_msg);



           flag_ver = 0;

   }
   else if(pos_x == -1.0 && pos_y == 0.0 && pos_z == 0.0 && flag == 0)
   {
           int pre_count_num = count_num2;


           count_num2++;

           ROS_INFO("UP");
           ROS_INFO("%d",count_num2);

           kinematics_msg.position.x = present_position.position.x + 0.01;

           if(count_num2 >0)
           {
               if(abs(pre_count_num) < abs(count_num))
               {
                kinematics_msg.position.z =present_position.position.z  + 0.001;
               }
               else
               {
                 kinematics_msg.position.z =present_position.position.z  - 0.0010;
               }
           }
           else if(count_num2 <0)
           {
               if(abs(pre_count_num) > abs(count_num))
               {
                kinematics_msg.position.z =present_position.position.z  + 0.001;
               }
               else
               {
                 kinematics_msg.position.z =present_position.position.z  - 0.0010;
               }
           }
           else
           {
        //     kinematics_msg.position.z = 0.039;
           }

           if(count_num>0)
           {
              kinematics_msg.position.y =present_position.position.y  + 0.001;
           }
           point_kinematics_msg_pub.publish(kinematics_msg);



   }
   else if(pos_x == 1.0 && pos_y == 0.0 && pos_z == 0.0 && flag == 0)
   {
          int pre_count_num = count_num2;

           count_num2--;

           ROS_INFO("DOWN");
           ROS_INFO("%d",count_num2);
           kinematics_msg.position.x = present_position.position.x - 0.01;

           if(count_num2 >0)
           {
               if(abs(pre_count_num) < abs(count_num))
               {
                kinematics_msg.position.z =present_position.position.z  - 0.001;
               }
               else
               {
                 kinematics_msg.position.z =present_position.position.z  + 0.0010;
               }
           }
           else if(count_num2 <0)
           {
               if(abs(pre_count_num) > abs(count_num))
               {
                kinematics_msg.position.z =present_position.position.z  - 0.001;
               }
               else
               {
                 kinematics_msg.position.z =present_position.position.z  + 0.0010;
               }
           }
           else
           {
           //  kinematics_msg.position.z = 0.039;
           }

           point_kinematics_msg_pub.publish(kinematics_msg);
   }
   else if(pos_x == -1.0 && pos_z == 1.0 && flag ==0)
   {

     ROS_INFO("RIGHT UP");



     kinematics_msg.position.x =present_position.position.x  + 0.01;
     kinematics_msg.position.y =present_position.position.y  + 0.01;

     if(count_num >0 || abs(count_num2)>0)
     {
        kinematics_msg.position.z =present_position.position.z  - 0.001;
     }
     else if(count_num <0 || abs(count_num2)>0)
     {
        kinematics_msg.position.z =present_position.position.z  + 0.001;
     }
     else if(count_num == 0 && abs(count_num2)==0)
     {
       kinematics_msg.position.z =present_position.position.z  - 0.001;
     }

     count_num ++;
     count_num2++;

     point_kinematics_msg_pub.publish(kinematics_msg);
   }
   else if(pos_x == 1.0 && pos_z == -1.0 && flag ==0)
   {



     ROS_INFO("RIGHT DOWN");
     kinematics_msg.position.x =present_position.position.x  - 0.01;
     kinematics_msg.position.y =present_position.position.y  + 0.01;
     if(count_num >0 || abs(count_num2)>0)
     {
        kinematics_msg.position.z =present_position.position.z  + 0.001;
     }
     else if(count_num <0 || abs(count_num2)>0)
     {
        kinematics_msg.position.z =present_position.position.z  + 0.001;
     }
     else if(count_num == 0 && abs(count_num2)==0)
     {
       kinematics_msg.position.z =present_position.position.z  + 0.001;
     }

     count_num ++;
     count_num2--;
     point_kinematics_msg_pub.publish(kinematics_msg);
   }
   else if(pos_x == 1.0 && pos_z == 1.0 && flag ==0)
   {
     ROS_INFO("LEFT UP");
     kinematics_msg.position.x =present_position.position.x  + 0.01;
     kinematics_msg.position.y =present_position.position.y  - 0.01;

     if(count_num >0 || abs(count_num2)>0)
     {
        kinematics_msg.position.z =present_position.position.z  - 0.001;
     }
     else if(count_num <0 || abs(count_num2)>0)
     {
        kinematics_msg.position.z =present_position.position.z  + 0.001;
     }
     else if(count_num == 0 && abs(count_num2)==0)
     {
       kinematics_msg.position.z =present_position.position.z  - 0.001;
     }
     count_num --;
     count_num2++;
     point_kinematics_msg_pub.publish(kinematics_msg);
   }
   else if(pos_x == -1.0 && pos_z == -1.0)
   {
     ROS_INFO("LEFT DOWN");
     kinematics_msg.position.x =present_position.position.x  - 0.01;
     kinematics_msg.position.y =present_position.position.y  - 0.01;

     if(count_num >0 || abs(count_num2)>0)
     {
        kinematics_msg.position.z =present_position.position.z  + 0.001;
     }
     else if(count_num <0 || abs(count_num2)>0)
     {
        kinematics_msg.position.z =present_position.position.z  + 0.001;
     }
     else if(count_num == 0 && abs(count_num2)==0)
     {
       kinematics_msg.position.z =present_position.position.z  +0.001;
     }
     count_num --;
     count_num2--;
     point_kinematics_msg_pub.publish(kinematics_msg);
   }
   else if(pos_x ==1.0 && pos_y == 1.0 && pos_z == 0.0 && flag == 0)
   {
     if(cnt2==0)
     {
     ROS_INFO("initial position");
     std_msgs::String ini_msg;
     ini_msg.data = "ini_pose";
     ini_msg_pub.publish(ini_msg);
     cnt = 0;
     write_flag =0;
     test = 0;
     count_num  = 0;
     count_num2 = 0;
     red_cnt=0;
     blue_cnt=0;
     cnt2;
     next_cnt=0;
     }
     else if(cnt2==1)
     {
       ROS_INFO("ready to write");
       kinematics_msg.position.x = 0.066;
       kinematics_msg.position.y = 0.0;
       kinematics_msg.position.z = 0.043;
       point_kinematics_msg_pub.publish(kinematics_msg);
       count_num  = 0;
       count_num2 = 0;
       cnt2 = 0;
     }
   }
   else if(pos_x == 0.0 && pos_y == 0.0 && pos_z == 1.0 && flag == 0)
   {
       ROS_INFO("z position up");
       kinematics_msg.position.x =present_position.position.x;
       kinematics_msg.position.y =present_position.position.y;
       kinematics_msg.position.z =present_position.position.z  + 0.001;
       point_kinematics_msg_pub.publish(kinematics_msg);
   }
   else if(pos_x == 0.0 && pos_y == 1.0 && pos_z == 1.0 && flag == 0)
   {
       ROS_INFO("z position down");
       kinematics_msg.position.x =present_position.position.x;
       kinematics_msg.position.y =present_position.position.y;
       kinematics_msg.position.z =present_position.position.z  - 0.001;
       point_kinematics_msg_pub.publish(kinematics_msg);
    }


}

void OpenManipulatorSub::StatsuMsgCallback(const std_msgs::String::ConstPtr &msg)
{
  if(msg->data == "Start")
  {
    flag = 1;
    flag2 = 1;
  }
  else if(msg->data == "Finsh")
  {
    flag = 0;

  }

}

void OpenManipulatorSub::msgCallback(const std_msgs::String::ConstPtr &msg)
{
///////////////////init pose//////////////


  if(msg->data == "write")
  {
      count_num  = 0;
      count_num2 = 0;
      write_flag = 1;

ROS_INFO("%d",write_flag);

  if(cnt==0 && flag ==0)
  {
    kinematics_msg.position.x = 0.066;
    kinematics_msg.position.y = 0.0;
    kinematics_msg.position.z = 0.102;

    point_kinematics_msg_pub.publish(kinematics_msg);
    ROS_INFO("2");
    std_msgs::String work_msg;
    work_msg.data = "next";
    work_status_pub.publish(work_msg);
    cnt++;
    write_flag = 0;

   }






  } // cnt++;






}

void OpenManipulatorSub::next_page_touch_function()
{



  if(next_page_flag ==1 && next_cnt==0 && write_flag ==1 && flag ==0)
  {

       ROS_INFO("next1");


       for(int i; i<3000; i++)
       {
         \
         if(i==1000)
         {
           std_msgs::String work_msg;
           work_msg.data = alp.data;
           ROS_INFO("send");
           work_status_pub.publish(work_msg);
           write_flag =0;
           next_cnt++;
         }
       }


   }
  else if(next_page_flag ==1 && next_cnt==1 && write_flag ==1 && flag ==0)
  {

       ROS_INFO("next2");
       kinematics_msg.position.x = present_position.position.x;
       kinematics_msg.position.y = present_position.position.y;
       kinematics_msg.position.z = present_position.position.z +0.009;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = alp.data;
       work_status_pub.publish(work_msg);
       write_flag =0;
       next_cnt++;
   }
  else if(next_page_flag ==1 && next_cnt==2 && write_flag ==1 && flag ==0)
  {

       ROS_INFO("next3");
       kinematics_msg.position.x = present_position.position.x;
       kinematics_msg.position.y = present_position.position.y;
       kinematics_msg.position.z = present_position.position.z +0.009;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = alp.data;
       work_status_pub.publish(work_msg);
       write_flag =0;
       next_cnt++;
   }
  else if(next_page_flag ==1 && next_cnt==3 && write_flag ==1 && flag ==0)
  {
       ROS_INFO("next4");
       kinematics_msg.position.x = 0.160;
       kinematics_msg.position.y = 0.020;
       kinematics_msg.position.z = 0.065;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = alp.data;
       work_status_pub.publish(work_msg);
       write_flag =0;
       next_cnt++;
   }
  else if(next_page_flag ==1 && next_cnt==4 && write_flag ==1 && flag ==0)
  {
       ROS_INFO("next5");
       kinematics_msg.position.x = 0.160;
       kinematics_msg.position.y = 0.020;
       kinematics_msg.position.z = 0.065;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = alp.data;
       work_status_pub.publish(work_msg);
       write_flag =0;
       next_cnt++;
   }
  else if(next_page_flag ==1 && next_cnt==5 && write_flag ==1 && flag ==0)
  {
       ROS_INFO("next6");
       kinematics_msg.position.x = 0.160;
       kinematics_msg.position.y = 0.0192;
       kinematics_msg.position.z = 0.035;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = alp.data;
       work_status_pub.publish(work_msg);
       write_flag =0;
       next_cnt++;
   }
  else if(next_page_flag ==1 && next_cnt==6 && write_flag ==1 && flag ==0)
  {
       ROS_INFO("next7");
       kinematics_msg.position.x = 0.160;
       kinematics_msg.position.y = 0.0192;
       kinematics_msg.position.z = 0.035;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = alp.data;
       work_status_pub.publish(work_msg);
       write_flag =0;
       next_cnt++;
   }
  else if(next_page_flag ==1 && next_cnt==7 && write_flag ==1 && flag ==0)
  {
       ROS_INFO("next8");

       kinematics_msg.position.x = 0.160;
       kinematics_msg.position.y = 0.020;
       kinematics_msg.position.z = 0.045;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = alp.data;
       work_status_pub.publish(work_msg);
       write_flag =0;
       next_cnt++;

   }
  else if(next_page_flag ==1 && next_cnt==8 && write_flag ==1 && flag ==0)
  {
       ROS_INFO("next9");

       kinematics_msg.position.x = 0.160;
       kinematics_msg.position.y = 0.020;
       kinematics_msg.position.z = 0.045;

       point_kinematics_msg_pub.publish(kinematics_msg);


       for(int i; i<2000; i++)
       {
         ROS_INFO("wait");
         if(i==1000)
         {
           std_msgs::String work_msg;
           work_msg.data = alp.data;
           work_status_pub.publish(work_msg);
           write_flag =0;
           next_page_flag=0;
           next_cnt =0;
           cnt++;
         }
       }


   }
}
void OpenManipulatorSub::next_position_set()
{
  if(test <4)
  {
    if(test==1)
    {
      kinematics_msg.position.x =  0.070 - (test-1)*0.00075;
    }
    else if(test ==2)
    {
      kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
    }
    else
    {
      kinematics_msg.position.x =  0.066 - (test-1)*0.00065;
    }
  }
  else if(test == 4)
  {
    kinematics_msg.position.x =  0.063 + (test-1)*0.0013;
  }
  else if(test == 5)
  {
    kinematics_msg.position.x =  0.064 + (test-1)*0.0012;
  }
  else if(test ==6)
  {
    kinematics_msg.position.x =  0.065 - (test-1)*0.00075;
  }
  else
  {
    kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
  }



  if(test == 1)
  {
     kinematics_msg.position.y =  present_position.position.y + (test*0.0135);

  }
  else if(test ==2)
  {
     kinematics_msg.position.y =  present_position.position.y + (test*0.0075);
  }
  else if(test ==3)
  {
     kinematics_msg.position.y =  present_position.position.y + (test*0.0055);
  }
  else if(test ==4)
  {
     kinematics_msg.position.y =  present_position.position.y + (test*0.0037);
  }
  else if(test ==5)
  {
     kinematics_msg.position.y =  present_position.position.y + (test*0.00275);
  }
  else if(test == 6)
  {
     kinematics_msg.position.y =  present_position.position.y + (test*0.0025);
  }
  else
  {

      kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
  }
  kinematics_msg.position.z = 0.060;


}

void OpenManipulatorSub::process()
{


  ////////////////////////// write a //////////////////////////////////////////////

  if(Alp_msg.data == "a")
  {
    if(cnt==1 && write_flag ==1 && flag ==0)
    {
       ROS_INFO("3");
       if(test==1)
       {
         kinematics_msg.position.x =  present_position.position.x +0.005;
       }
       else if(test ==2)
       {
         kinematics_msg.position.x =  present_position.position.x +0.008;
       }
       else if(test ==7)
       {
         kinematics_msg.position.x =  present_position.position.x +0.0185;
       }
       else
       {
         kinematics_msg.position.x =  present_position.position.x +0.0095;
       }

       if(test>1)
       {
         kinematics_msg.position.y =  present_position.position.y +0.0015;
       }
       else if(test ==2)
       {
         kinematics_msg.position.y =  present_position.position.y +0.0011;
       }
       else
       {
         kinematics_msg.position.y =  present_position.position.y +0.009;
       }


       if(test==2)
       {
         kinematics_msg.position.z = 0.0465 - test*0.0009 ;
       }
       else
       {
         kinematics_msg.position.z = 0.046 - test*0.0007;
       }
       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "a";
       work_status_pub.publish(work_msg);
       write_flag = 0;
     //  write_flag =0;
     //  cnt =0;
        cnt++;
    }
  else if(cnt==2 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("4");

    kinematics_msg.position.x = present_position.position.x +0.0025;
    kinematics_msg.position.y = present_position.position.y -0.0025;
    kinematics_msg.position.z = present_position.position.z -0.001;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "a";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==3 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("5");
    kinematics_msg.position.x = present_position.position.x +0.004;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z -0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "a";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==4 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("6");
    kinematics_msg.position.x = present_position.position.x +0.0025;
    kinematics_msg.position.y = present_position.position.y +0.0020;
    kinematics_msg.position.z = present_position.position.z -0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "a";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==5 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("7");
    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y +0.002;
    kinematics_msg.position.z = present_position.position.z -0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "a";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==6 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("8");
    kinematics_msg.position.x = present_position.position.x -0.0025;
    kinematics_msg.position.y = present_position.position.y +0.0020;
    kinematics_msg.position.z = present_position.position.z +0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "a";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==7 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("9");
    kinematics_msg.position.x = present_position.position.x -0.004;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z +0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "a";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==8 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("10");
    kinematics_msg.position.x = present_position.position.x -0.0025;
    kinematics_msg.position.y = present_position.position.y -0.0020;
    kinematics_msg.position.z = present_position.position.z +0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "a";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==9 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("11");
    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y -0.002;
    kinematics_msg.position.z = present_position.position.z +0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "a";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==10 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("12");
    kinematics_msg.position.x = present_position.position.x;
    if(test<2)
    {
      kinematics_msg.position.y = present_position.position.y + 0.0031;
    }
    else if(test==2||test==3)
    {
      kinematics_msg.position.y = present_position.position.y + 0.00323;
    }
    else if(test>3)
    {
      kinematics_msg.position.y = present_position.position.y + (test*0.0004);
    }
    kinematics_msg.position.z = present_position.position.z -0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "a";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }

  else if(cnt==11 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("13");
    kinematics_msg.position.x = present_position.position.x +0.011;
    kinematics_msg.position.y = present_position.position.y +0.0020 + 0.0003*test;
    kinematics_msg.position.z = present_position.position.z -0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "a";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;


   }
    else if(cnt==12 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("14");

      kinematics_msg.position.x = present_position.position.x;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z +0.009;
      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "a";
      alp.data = work_msg.data;
      work_status_pub.publish(work_msg);
      write_flag =0;


      if(test>6)
      {
        ROS_INFO("start!!!");
        next_page_flag=1;
        write_flag =1;
        OpenManipulatorSub::next_page_touch_function();
      }
      else
      {

        cnt++;
      }
    }

  else if(cnt==13 && write_flag ==1 && flag ==0)
  {
   // ROS_INFO("13");
    ROS_INFO("15");
   //   kinematics_msg.position.x = present_position.position.x;
    OpenManipulatorSub::next_position_set();

    if(test<7)
    {
      std_msgs::String work_msg;
      work_msg.data = "a";
      work_status_pub.publish(work_msg);
      point_kinematics_msg_pub.publish(kinematics_msg);
      write_flag =0;
      cnt =0;
    }
    else if(test>6  && flag==0)
    {

      ROS_INFO("initial position");
      std_msgs::String ini_msg;
      ini_msg.data = "ini_pose";
      ini_msg_pub.publish(ini_msg);
      cnt = 0;
      write_flag =0;
      test = 0;
      count_num  = 0;
      count_num2 = 0;
      red_cnt=0;
      blue_cnt=0;
      cnt2;
      next_cnt=0;

      int count =0;
      for(int i=0; i<1000; i++)
      {
        ROS_INFO("wait");
        count++;
        if(i==100)
        {
          ROS_INFO("initial position");
          std_msgs::String ini_msg;
          ini_msg.data = "ini_pose";
          ini_msg_pub.publish(ini_msg);
          break;
        }
      }
    }
  }

}

/////////////////////////////////////////////////////////////////////////////////////////
    if(Alp_msg.data == "b")
    {

      if(cnt==1 && write_flag ==1 && flag ==0)
      {
         ROS_INFO("3");
         if(test==1)
         {
           kinematics_msg.position.x =  present_position.position.x +0.005;
         }
         else if(test ==2)
         {
           kinematics_msg.position.x =  present_position.position.x +0.008;
         }
         else if(test ==7)
         {
           kinematics_msg.position.x =  present_position.position.x +0.0185;
         }
         else
         {
           kinematics_msg.position.x =  present_position.position.x +0.0095;
         }

         if(test==1)
         {
           kinematics_msg.position.y =  present_position.position.y +0.0009;
         }
         else if(test ==2)
         {
           kinematics_msg.position.y =  present_position.position.y +0.0015;
         }
         else
         {
           kinematics_msg.position.y =  present_position.position.y +0.0015;
         }


         if(test ==1)
         {
           kinematics_msg.position.z = 0.042 - test*0.0004;
         }
         else if(test==2)
         {
           kinematics_msg.position.z = 0.0465 - test*0.0009 ;
         }
         else if(test==3)
         {
           kinematics_msg.position.z = 0.045 - test*0.0004;
         }
         else
         {
           kinematics_msg.position.z = 0.044 - test*0.0004;
         }
         point_kinematics_msg_pub.publish(kinematics_msg);

         std_msgs::String work_msg;
         work_msg.data = "b";
         work_status_pub.publish(work_msg);
         write_flag = 0;
       //  write_flag =0;
       //  cnt =0;
          cnt++;
      }
  else if(cnt==2 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("4");

    kinematics_msg.position.x = present_position.position.x +0.009;
    kinematics_msg.position.y = present_position.position.y -0.001;
    kinematics_msg.position.z = present_position.position.z -0.002;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "b";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==3 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("5");

    kinematics_msg.position.x = present_position.position.x +0.0035;
    kinematics_msg.position.y = present_position.position.y +0.00125;
    kinematics_msg.position.z = present_position.position.z -0.0005;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "b";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==4 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("6");

    kinematics_msg.position.x = present_position.position.x -0.0005;
    kinematics_msg.position.y = present_position.position.y +0.003;
    kinematics_msg.position.z = present_position.position.z -0.001;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "b";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==5 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("7");

    kinematics_msg.position.x = present_position.position.x -0.0035;
    kinematics_msg.position.y = present_position.position.y +0.0015;
    kinematics_msg.position.z = present_position.position.z +0.0005;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "b";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==6 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("8");

    kinematics_msg.position.x = present_position.position.x -0.0035;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z -0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "b";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==7 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("9");

    kinematics_msg.position.x = present_position.position.x -0.0025;
    kinematics_msg.position.y = present_position.position.y -0.0010;
    kinematics_msg.position.z = present_position.position.z -0.0005;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "b";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==8 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("10");

    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y -0.005;
    kinematics_msg.position.z = present_position.position.z +0.001;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "b";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==9 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("11");

    kinematics_msg.position.x = present_position.position.x +0.0065;
    kinematics_msg.position.y = present_position.position.y -0.0015;
    kinematics_msg.position.z = present_position.position.z +0.001;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "b";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==10 && write_flag ==1 && flag ==0)
  {
        ROS_INFO("12");

        kinematics_msg.position.x = present_position.position.x +0.005;
        kinematics_msg.position.y = present_position.position.y;
        kinematics_msg.position.z = present_position.position.z +0.015;

        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "b";
        alp.data = work_msg.data;
        work_status_pub.publish(work_msg);
        write_flag =0;


        if(test>6)
        {
          ROS_INFO("start!!!");
          next_page_flag=1;
          write_flag =1;
          OpenManipulatorSub::next_page_touch_function();
        }
        else
        {

          cnt++;
        }

  }
  else if(cnt==11 && write_flag ==1 && flag ==0)
  {
   // ROS_INFO("13");
    ROS_INFO("13");
   //   kinematics_msg.position.x = present_position.position.x;
    OpenManipulatorSub::next_position_set();

    if(blue_cnt>0)
    {
      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "b";
      work_status_pub.publish(work_msg);

      std_msgs::String color_write_sta_msg;
      color_write_sta_msg.data ="finish_blue";
      color_write_sta_pub_.publish(color_write_sta_msg);
      write_flag =0;
      cnt =0;
    } 
    else if(test_cnt==3 && test_flag==1)
    {
      std_msgs::String work_msg;
      work_msg.data = "b";
      work_status_pub.publish(work_msg);

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String test_mode_status_msg;
      test_mode_status_msg.data = "testing";
      test_mode_status_pub.publish(test_mode_status_msg);

      write_flag =0;
      cnt =0;
      test_flag=0;

    }
    else if(test<7 && test_cnt==0)
    {
      std_msgs::String work_msg;
      work_msg.data = "b";
      work_status_pub.publish(work_msg);
      point_kinematics_msg_pub.publish(kinematics_msg);
      write_flag =0;
      cnt =0;
    }
    else if(test>6 && flag==0)
    {

      ROS_INFO("initial position");
      std_msgs::String ini_msg;
      ini_msg.data = "ini_pose";
      ini_msg_pub.publish(ini_msg);
      cnt = 0;
      write_flag =0;
      test = 0;
      count_num  = 0;
      count_num2 = 0;
      red_cnt=0;
      blue_cnt=0;
      cnt2;
      next_cnt=0;

      int count =0;
      for(int i=0; i<1000; i++)
      {
        ROS_INFO("wait");
        count++;
        if(i==100)
        {
          ROS_INFO("initial position");
          std_msgs::String ini_msg;
          ini_msg.data = "ini_pose";
          ini_msg_pub.publish(ini_msg);
          break;
        }
      }
    }
  }

 }
 else if(Alp_msg.data == "c")////////////////////////////////////////////////////////////
 {

      if(cnt==1 && write_flag ==1 && flag ==0)
      {
         ROS_INFO("3");
         if(test==1)
         {
           kinematics_msg.position.x =  present_position.position.x +0.005;
         }
         else if(test ==2)
         {
           kinematics_msg.position.x =  present_position.position.x +0.008;
         }
         else if(test ==7)
         {
           kinematics_msg.position.x =  present_position.position.x +0.0185;
         }
         else
         {
           kinematics_msg.position.x =  present_position.position.x +0.0095;
         }

         if(test>1)
         {
           kinematics_msg.position.y =  present_position.position.y +0.0015;
         }
         else if(test ==2)
         {
           kinematics_msg.position.y =  present_position.position.y +0.0011;
         }
         else
         {
           kinematics_msg.position.y =  present_position.position.y +0.009;
         }


         if(test==1)
         {
           kinematics_msg.position.z = 0.0455 - test*0.0009 ;
         }
         else if(test<5)
         {
           if(test==2)
           {
             kinematics_msg.position.z = 0.0464 - test*0.0002 ;
           }

           kinematics_msg.position.z = 0.0473 - test*0.0002 ;
         }
         else
         {
           kinematics_msg.position.z = 0.0483 - test*0.0001;
         }
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "c";
     work_status_pub.publish(work_msg);
     write_flag = 0;
   //  write_flag =0;
   //  cnt =0;
      cnt++;
    }
   else if(cnt==2 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("4");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "c";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==3 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("5");

     kinematics_msg.position.x = present_position.position.x -0.001;
     kinematics_msg.position.y = present_position.position.y -0.0002;
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "c";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==4 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("6");

     kinematics_msg.position.x = present_position.position.x; // +? -?
     kinematics_msg.position.y = present_position.position.y -0.004;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "c";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");

     kinematics_msg.position.x = present_position.position.x +0.0025;
     kinematics_msg.position.y = present_position.position.y -0.0025;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "c";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x +0.005;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "c";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==7 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("9");

     kinematics_msg.position.x = present_position.position.x +0.0025;
     kinematics_msg.position.y = present_position.position.y +0.0015;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "c";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");

     kinematics_msg.position.x = present_position.position.x; // +? -?
     kinematics_msg.position.y = present_position.position.y +0.0055;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "c";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("11");

     kinematics_msg.position.x = present_position.position.x -0.001;
     kinematics_msg.position.y = present_position.position.y +0.0005;
     kinematics_msg.position.z = present_position.position.z +0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "c";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;


    }
    else if(cnt==10 && write_flag ==1 && flag ==0)
    {
        ROS_INFO("12");

        kinematics_msg.position.x = present_position.position.x;
        kinematics_msg.position.y = present_position.position.y;
        kinematics_msg.position.z = present_position.position.z +0.007;

        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "c";
        alp.data = work_msg.data;
        work_status_pub.publish(work_msg);
        write_flag =0;


        if(test>6)
        {
          ROS_INFO("start!!!");
          next_page_flag=1;
          write_flag =1;
          OpenManipulatorSub::next_page_touch_function();
        }
        else
        {

          cnt++;
        }
    }
   else if(cnt==11 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("15");
    //   kinematics_msg.position.x = present_position.position.x;
     OpenManipulatorSub::next_position_set();

     if(test<7)
     {
       std_msgs::String work_msg;
       work_msg.data = "c";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test>6 && flag==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }

   }


 }
 else if(Alp_msg.data == "d")////////////////////////////////////////////////////////////
 {

      if(cnt==1 && write_flag ==1 && flag ==0)
      {
         ROS_INFO("3");
         if(test==1)
         {
           kinematics_msg.position.x =  present_position.position.x +0.005;
         }
         else if(test ==2)
         {
           kinematics_msg.position.x =  present_position.position.x +0.008;
         }
         else if(test ==7)
         {
           kinematics_msg.position.x =  present_position.position.x +0.0185;
         }
         else
         {
           kinematics_msg.position.x =  present_position.position.x +0.0095;
         }

         if(test>1)
         {
           kinematics_msg.position.y =  present_position.position.y +0.0015;
         }
         else if(test ==2)
         {
           kinematics_msg.position.y =  present_position.position.y +0.0011;
         }
         else
         {
           kinematics_msg.position.y =  present_position.position.y +0.009;
         }


         if(test==2)
         {
           kinematics_msg.position.z = 0.0475 - test*0.0009 ;
         }
         else
         {
           kinematics_msg.position.z = 0.048 - test*0.0008;
         }
           point_kinematics_msg_pub.publish(kinematics_msg);

           std_msgs::String work_msg;
           work_msg.data = "d";
           work_status_pub.publish(work_msg);
           write_flag = 0;


         //  write_flag =0;
         //  cnt =0;
            cnt++;
        }
   else if(cnt==2 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("4");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z + 0.007;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "d";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==3 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("5");

     kinematics_msg.position.x = present_position.position.x  - 0.0016 - test*0.001;
     if(test>2)
     {
      kinematics_msg.position.y = present_position.position.y + 0.0040;
     }
     else
     {
      kinematics_msg.position.y = present_position.position.y + 0.0055;
     }
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "d";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==4 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("6");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z- 0.01;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "d";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");

     kinematics_msg.position.x = present_position.position.x +0.01;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.002;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "d";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x +0.002;
     kinematics_msg.position.y = present_position.position.y -0.0005;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "d";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }

   else if(cnt==7 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("9");

     kinematics_msg.position.x = present_position.position.x; // +? -?
     kinematics_msg.position.y = present_position.position.y -0.004;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "d";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }

   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");


     kinematics_msg.position.x = present_position.position.x -0.0045;

     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "d";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("11");

     kinematics_msg.position.x = present_position.position.x -0.001;
     kinematics_msg.position.y = present_position.position.y +0.0025;
     kinematics_msg.position.z = present_position.position.z +0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "d";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==10 && write_flag ==1 && flag ==0)
      {
        ROS_INFO("12");

        kinematics_msg.position.x = present_position.position.x -0.0015;
        kinematics_msg.position.y = present_position.position.y +0.002;
        kinematics_msg.position.z = present_position.position.z +0.001;
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "d";
        work_status_pub.publish(work_msg);
        write_flag =0;
        cnt++;
      }
   else if(cnt==11 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("13");

     kinematics_msg.position.x = present_position.position.x + 0.001;
     kinematics_msg.position.y = present_position.position.y +0.00025 + 0.0004*test;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "d";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }

   else if(cnt==12 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("14");

     kinematics_msg.position.x = present_position.position.x +0.0065;
     kinematics_msg.position.y = present_position.position.y +0.0008;
     kinematics_msg.position.z = present_position.position.z -0.002;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "d";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==13 && write_flag ==1 && flag ==0)
   {
        ROS_INFO("15");

        kinematics_msg.position.x = present_position.position.x;
        kinematics_msg.position.y = present_position.position.y;
        kinematics_msg.position.z = present_position.position.z +0.01;

        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "d";
        alp.data = work_msg.data;
        work_status_pub.publish(work_msg);
        write_flag =0;


        if(test>6)
        {
          ROS_INFO("start!!!");
          next_page_flag=1;
          write_flag =1;
          OpenManipulatorSub::next_page_touch_function();
        }
        else
        {

          cnt++;
        }
    }
   else if(cnt==14 && write_flag ==1 && flag ==0)
    {
     // ROS_INFO("13");
      ROS_INFO("15");
     //   kinematics_msg.position.x = present_position.position.x;


     OpenManipulatorSub::next_position_set();

     if(red_cnt>0 && flag==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }
    else if(test<7)
     {
       std_msgs::String work_msg;
       work_msg.data = "d";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test>6 && flag==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }
   }
 }
 else if(Alp_msg.data == "e")////////////////////////////////////////////////////////////
 {

      if(cnt==1 && write_flag ==1 && flag ==0)
      {
         ROS_INFO("3");
         if(test==1)
         {
           kinematics_msg.position.x =  present_position.position.x +0.0033;
         }
         else if(test ==2)
         {
           kinematics_msg.position.x =  present_position.position.x +0.008;
         }
         else if(test ==7)
         {
           kinematics_msg.position.x =  present_position.position.x +0.0185;
         }
         else
         {
           kinematics_msg.position.x =  present_position.position.x +0.0095;
         }

         if(test>1)
         {
           kinematics_msg.position.y =  present_position.position.y +0.0015;
         }
         else if(test ==2)
         {
           kinematics_msg.position.y =  present_position.position.y +0.0011;
         }
         else
         {
           kinematics_msg.position.y =  present_position.position.y +0.009;
         }


         if(test==2)
         {
           kinematics_msg.position.z = 0.047 - test*0.0009 ;
         }
         else
         {
           kinematics_msg.position.z = 0.047 - test*0.0004;
         }
             point_kinematics_msg_pub.publish(kinematics_msg);

             std_msgs::String work_msg;
             work_msg.data = "e";
             work_status_pub.publish(work_msg);
             write_flag = 0;
           //  write_flag =0;
           //  cnt =0;
              cnt++;
          }
   else if(cnt==2 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("4");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z + 0.007;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==3 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("5");

     if(test==1 || test ==5)
     {
       kinematics_msg.position.x = present_position.position.x +0.037 + test*0.0004;
     }
     else
     {
       kinematics_msg.position.x = present_position.position.x +0.011 - test*0.0022;
     }
     kinematics_msg.position.y = present_position.position.y +0.005 - test*0.00065;
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==4 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("6");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     if(test<3)
     {
        kinematics_msg.position.z = present_position.position.z- 0.012;
     }
     else
     {
      kinematics_msg.position.z = present_position.position.z- 0.0103;
     }
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");

     kinematics_msg.position.x = present_position.position.x +0.001;
     kinematics_msg.position.y = present_position.position.y -0.001;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x; // +? -?
     if(test>1)
     {
       kinematics_msg.position.y = present_position.position.y -0.005;
     }
     else
     {
       kinematics_msg.position.y = present_position.position.y -0.0025;
     }
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==7 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("9");

     if(test<2)
     {
        kinematics_msg.position.x = present_position.position.x -0.0013;
     }
     else if(test==2)
     {
       kinematics_msg.position.x = present_position.position.x -0.0012;
     }
     else
     {
        kinematics_msg.position.x = present_position.position.x -0.0025;
     }
     kinematics_msg.position.y = present_position.position.y -0.001;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");

     if(test<2)
     {
        kinematics_msg.position.x = present_position.position.x -0.003;
     }
     else
     {
       kinematics_msg.position.x = present_position.position.x -0.002;
     }
     kinematics_msg.position.y = present_position.position.y +0.0005*test;
     kinematics_msg.position.z = present_position.position.z +0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("11");

     if(test >2)
     {
        kinematics_msg.position.x = present_position.position.x -0.005 +0.0007*test;
     }
     else
     {
       kinematics_msg.position.x = present_position.position.x -0.001;
     }

     kinematics_msg.position.y = present_position.position.y +0.001 -test*0.0005;


     kinematics_msg.position.z = present_position.position.z +0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);



     write_flag =0;
     cnt++;
   }
   else if(cnt==10 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("12");

     kinematics_msg.position.x = present_position.position.x -0.0025;
     kinematics_msg.position.y = present_position.position.y +0.0025;
     kinematics_msg.position.z = present_position.position.z +0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==11 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("13");

     kinematics_msg.position.x = present_position.position.x; // +? -?
     if(test <3)
     {
        kinematics_msg.position.y = present_position.position.y +0.0035 -0.0003*test;
     }
     else
     {
        kinematics_msg.position.y = present_position.position.y +0.0035 +0.0001*test;
     }
     kinematics_msg.position.z = present_position.position.z -0.0002;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==12 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("14");

     kinematics_msg.position.x = present_position.position.x +0.0040 +0.0003*test;
     kinematics_msg.position.y = present_position.position.y +0.001 +0.0003*test;
     kinematics_msg.position.z = present_position.position.z -0.0005;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==13 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("15");

     kinematics_msg.position.x = present_position.position.x +0.001 +0.0008; // +? -?
     kinematics_msg.position.y = present_position.position.y -0.011 +0.0003*test;
     kinematics_msg.position.z = present_position.position.z +0.001 +test*0.0003;

     point_kinematics_msg_pub.publish(kinematics_msg);


     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==14 && write_flag ==1 && flag ==0)
   {
           ROS_INFO("15");

           kinematics_msg.position.x = present_position.position.x;
           kinematics_msg.position.y = present_position.position.y;
           kinematics_msg.position.z = present_position.position.z +0.01;

           point_kinematics_msg_pub.publish(kinematics_msg);

           std_msgs::String work_msg;
           work_msg.data = "e";
           alp.data = work_msg.data;
           work_status_pub.publish(work_msg);
           write_flag =0;


           if(test>6)
           {
             ROS_INFO("start!!!");
             next_page_flag=1;
             write_flag =1;
             OpenManipulatorSub::next_page_touch_function();
           }
           else
           {

             cnt++;
           }
     }
   else if(cnt==15 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("17");
    //   kinematics_msg.position.x = present_position.position.x;
     OpenManipulatorSub::next_position_set();



      if(blue_cnt==0 && red_cnt>0)
      {
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String color_write_sta_msg;
        color_write_sta_msg.data ="finish_red";
        color_write_sta_pub_.publish(color_write_sta_msg);

        write_flag =0;
        cnt =0;

      }
      else if(blue_cnt>0 && flag==0)
      {

        ROS_INFO("initial position");
        std_msgs::String ini_msg;
        ini_msg.data = "ini_pose";
        ini_msg_pub.publish(ini_msg);
        cnt = 0;
        write_flag =0;
        test = 0;
        count_num  = 0;
        count_num2 = 0;
        red_cnt=0;
        blue_cnt=0;
        cnt2;
        next_cnt=0;
      }
      else if(test<7)
      {
        std_msgs::String work_msg;
        work_msg.data = "e";
        work_status_pub.publish(work_msg);
        point_kinematics_msg_pub.publish(kinematics_msg);
        write_flag =0;
        cnt =0;
      }
      else if(test>6  && flag==0)
      {

        ROS_INFO("initial position");
        std_msgs::String ini_msg;
        ini_msg.data = "ini_pose";
        ini_msg_pub.publish(ini_msg);
        cnt = 0;
        write_flag =0;
        test = 0;
        count_num  = 0;
        count_num2 = 0;
        red_cnt=0;
        blue_cnt=0;
        cnt2;

        int count =0;
        for(int i=0; i<1000; i++)
        {
          ROS_INFO("wait");
          count++;
          if(i==100)
          {
            ROS_INFO("initial position");
            std_msgs::String ini_msg;
            ini_msg.data = "ini_pose";
            ini_msg_pub.publish(ini_msg);
            break;
          }
        }
      }
    }


 }
 else if(Alp_msg.data == "f")////////////////////////////////////////////////////////////
 {

      if(cnt==1 && write_flag ==1 && flag ==0)
      {
         ROS_INFO("3");
         if(test==1)
         {
           kinematics_msg.position.x =  present_position.position.x +0.005;
         }
         else if(test ==2)
         {
           kinematics_msg.position.x =  present_position.position.x +0.008;
         }
         else if(test ==7)
         {
           kinematics_msg.position.x =  present_position.position.x +0.0185;
         }
         else
         {
           kinematics_msg.position.x =  present_position.position.x +0.0095;
         }

         if(test>1)
         {
           kinematics_msg.position.y =  present_position.position.y +0.0015;
         }
         else if(test ==2)
         {
           kinematics_msg.position.y =  present_position.position.y +0.0011;
         }
         else
         {
           kinematics_msg.position.y =  present_position.position.y +0.009;
         }


         if(test==2)
         {
           kinematics_msg.position.z = 0.0475 - test*0.0009 ;
         }
         else
         {
           kinematics_msg.position.z = 0.047 - test*0.0006;
         }
               point_kinematics_msg_pub.publish(kinematics_msg);

               std_msgs::String work_msg;
               work_msg.data = "f";
               work_status_pub.publish(work_msg);
               write_flag = 0;
             //  write_flag =0;
             //  cnt =0;
                cnt++;
            }
   else if(cnt==2 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("4");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z + 0.01;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==3 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("5");

     kinematics_msg.position.x = present_position.position.x+0.002;
     kinematics_msg.position.y = present_position.position.y+0.0015;
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==4 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("6");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z- 0.014;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");
     kinematics_msg.position.x = present_position.position.x -0.002;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");
     kinematics_msg.position.x = present_position.position.x -0.0020;
     kinematics_msg.position.y = present_position.position.y -0.0010;
     kinematics_msg.position.z = present_position.position.z +0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==7 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("9");
     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y -0.0015;
     kinematics_msg.position.z = present_position.position.z +0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");

     kinematics_msg.position.x = present_position.position.x +0.0020;
     kinematics_msg.position.y = present_position.position.y -0.001;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("11");
     kinematics_msg.position.x = present_position.position.x +0.012;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.002;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==10 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("12");
     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.007;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==11 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("13");
     kinematics_msg.position.x = present_position.position.x -0.008;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==12 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("15");
     kinematics_msg.position.x = present_position.position.x +0.0003;
     kinematics_msg.position.y = present_position.position.y -0.0015;
     kinematics_msg.position.z = present_position.position.z -0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==13 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("14");
     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.0065;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==14 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("16");
     kinematics_msg.position.x = present_position.position.x -0.0005;
     kinematics_msg.position.y = present_position.position.y +0.0055;
     kinematics_msg.position.z = present_position.position.z +0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;



     }
      else if(cnt==15 && write_flag ==1 && flag ==0)
      {
        ROS_INFO("17");
        kinematics_msg.position.x = present_position.position.x +0.0003;
        kinematics_msg.position.y = present_position.position.y;
        kinematics_msg.position.z = present_position.position.z +0.008;
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "f";
        alp.data = work_msg.data;
        work_status_pub.publish(work_msg);
        write_flag =0;



        if(test>6)
        {
          ROS_INFO("start!!!");
          next_page_flag=1;
          write_flag =1;
          OpenManipulatorSub::next_page_touch_function();
        }
        else
        {

          cnt++;
        }
   }
   else if(cnt==16 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("18");
    //   kinematics_msg.position.x = present_position.position.x;
     OpenManipulatorSub::next_position_set();

     if(test<7)
     {
       std_msgs::String work_msg;
       work_msg.data = "f";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test>6  && flag==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }
   }
 }
 if(Alp_msg.data == "g")
 {

   if(cnt==1 && write_flag ==1 && flag ==0)
   {
      ROS_INFO("3");
      if(test==1)
      {
        kinematics_msg.position.x =  present_position.position.x +0.005;
      }
      else if(test ==2)
      {
        kinematics_msg.position.x =  present_position.position.x +0.008;
      }
      else if(test ==7)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0185;
      }
      else
      {
        kinematics_msg.position.x =  present_position.position.x +0.0095;
      }

      if(test>1)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0015;
      }
      else if(test ==2)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0011;
      }
      else
      {
        kinematics_msg.position.y =  present_position.position.y +0.009;
      }


      if(test==2)
      {
        kinematics_msg.position.z = 0.0465 - test*0.0009 ;
      }
      else if(test >5)
      {
       kinematics_msg.position.z = 0.046 - test*0.0007;
      }
      else
      {
        kinematics_msg.position.z = 0.046 - test*0.0003;
      }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "g";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
  else if(cnt==2 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("4");

    kinematics_msg.position.x = present_position.position.x +0.0025;
    kinematics_msg.position.y = present_position.position.y -0.0025;
    kinematics_msg.position.z = present_position.position.z -0.001;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "g";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==3 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("5");
    kinematics_msg.position.x = present_position.position.x +0.001;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z -0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "g";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==4 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("6");
    kinematics_msg.position.x = present_position.position.x +0.0025;
    kinematics_msg.position.y = present_position.position.y +0.0020;
    kinematics_msg.position.z = present_position.position.z -0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "g";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==5 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("7");
    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y +0.001 +(0.0005*test);
    kinematics_msg.position.z = present_position.position.z -0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "g";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==6 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("8");
    kinematics_msg.position.x = present_position.position.x -0.0025;
    kinematics_msg.position.y = present_position.position.y +0.0020;
    kinematics_msg.position.z = present_position.position.z +0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "g";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==7 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("9");
    kinematics_msg.position.x = present_position.position.x -0.001;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z +0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "g";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==8 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("10");
    kinematics_msg.position.x = present_position.position.x -0.0025;
    kinematics_msg.position.y = present_position.position.y -0.0020;
    kinematics_msg.position.z = present_position.position.z +0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "g";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==9 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("11");
    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y -0.001 -(0.00037*test);
    kinematics_msg.position.z = present_position.position.z +0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "g";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==10 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("12");
    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y +0.002 +(0.00032*test);
    kinematics_msg.position.z = present_position.position.z -0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "g";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }

  else if(cnt==11 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("13");
    kinematics_msg.position.x = present_position.position.x +0.0055;
    kinematics_msg.position.y = present_position.position.y +0.0005;
    kinematics_msg.position.z = present_position.position.z -0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "g";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
   else if(cnt==12 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("14");
     kinematics_msg.position.x = present_position.position.x +0.0075;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "g";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==13 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("15");
     kinematics_msg.position.x = present_position.position.x +0.0025;
     kinematics_msg.position.y = present_position.position.y -0.0020;
     kinematics_msg.position.z = present_position.position.z -0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "g";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==14 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("16");
     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y -0.002;
     kinematics_msg.position.z = present_position.position.z -0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "g";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==15 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("17");
     kinematics_msg.position.x = present_position.position.x -0.0025;
     kinematics_msg.position.y = present_position.position.y -0.0010;
     kinematics_msg.position.z = present_position.position.z +0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "g";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==16 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("18");
     kinematics_msg.position.x = present_position.position.x -0.0085;
     kinematics_msg.position.y = present_position.position.y +0.0075;
     kinematics_msg.position.z = present_position.position.z +0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "g";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==17 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("19");
     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.007;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "g";
     alp.data = work_msg.data;
     work_status_pub.publish(work_msg);
     write_flag =0;



     if(test>6)
     {
       ROS_INFO("start!!!");
       next_page_flag=1;
       write_flag =1;
       OpenManipulatorSub::next_page_touch_function();
     }
     else
     {

       cnt++;
     }
   }
   else if(cnt==18 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("20");
    //   kinematics_msg.position.x = present_position.position.x;
     OpenManipulatorSub::next_position_set();


     if(test<7)
     {
       std_msgs::String work_msg;
       work_msg.data = "g";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test>6 && flag==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }


   }

 }
   if(Alp_msg.data == "h")
   {
     if(cnt==1 && write_flag ==1 && flag ==0)
     {
        ROS_INFO("3");
        if(test==1)
        {
          kinematics_msg.position.x =  present_position.position.x +0.005;
        }
        else if(test ==2)
        {
          kinematics_msg.position.x =  present_position.position.x +0.008;
        }
        else if(test ==7)
        {
          kinematics_msg.position.x =  present_position.position.x +0.0185;
        }
        else
        {
          kinematics_msg.position.x =  present_position.position.x +0.0095;
        }

        if(test>1)
        {
          kinematics_msg.position.y =  present_position.position.y +0.0015;
        }
        else if(test ==2)
        {
          kinematics_msg.position.y =  present_position.position.y +0.0011;
        }
        else
        {
          kinematics_msg.position.y =  present_position.position.y +0.009;
        }

        if(test ==1)
        {
          kinematics_msg.position.z = 0.0445 - test*0.0009 ;
        }
       else if(test==2)
        {
          kinematics_msg.position.z = 0.0465 - test*0.0009 ;
        }
        else
        {
          kinematics_msg.position.z = 0.0456 - test*0.0005;
        }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "h";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
  else if(cnt==2 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("4");

    kinematics_msg.position.x = present_position.position.x +0.012;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z -0.003;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "h";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==3 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("5");

    kinematics_msg.position.x = present_position.position.x -0.0085;
    kinematics_msg.position.y = present_position.position.y +0.0015;
    kinematics_msg.position.z = present_position.position.z -0.0005;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "h";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==4 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("6");

    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y +0.002;
    kinematics_msg.position.z = present_position.position.z +0.001;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "h";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==5 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("7");

    kinematics_msg.position.x = present_position.position.x +0.0045;
    kinematics_msg.position.y = present_position.position.y +0.0015;
    kinematics_msg.position.z = present_position.position.z -0.0005;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "h";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==6 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("8");

    kinematics_msg.position.x = present_position.position.x +0.004;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z -0.001;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "h";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==7 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("9");

    if(test<4)
    {
      kinematics_msg.position.x = present_position.position.x + test*0.0002;
    }
    else
    {
      kinematics_msg.position.x = present_position.position.x;
    }

    if(test<4)
    {
      kinematics_msg.position.y = present_position.position.y -test*0.0007;
    }
    else
    {
      kinematics_msg.position.y = present_position.position.y;
    }
    kinematics_msg.position.z = present_position.position.z +0.011;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "h";
    alp.data = work_msg.data;
    work_status_pub.publish(work_msg);
    write_flag =0;


    if(test>6)
    {
      ROS_INFO("start!!!");
      next_page_flag=1;
      write_flag =1;
      OpenManipulatorSub::next_page_touch_function();
    }
    else
    {

      cnt++;
    }
 }
  else if(cnt==8 && write_flag ==1 && flag ==0)
  {
   // ROS_INFO("13");
    ROS_INFO("10");
   //   kinematics_msg.position.x = present_position.position.x;
    OpenManipulatorSub::next_position_set();

    if(test<7)
    {
      std_msgs::String work_msg;
      work_msg.data = "h";
      work_status_pub.publish(work_msg);
      point_kinematics_msg_pub.publish(kinematics_msg);
      write_flag =0;
      cnt =0;
    }
    else if(test>6 && flag==0)
    {

      ROS_INFO("initial position");
      std_msgs::String ini_msg;
      ini_msg.data = "ini_pose";
      ini_msg_pub.publish(ini_msg);
      cnt = 0;
      write_flag =0;
      test = 0;
      count_num  = 0;
      count_num2 = 0;
      red_cnt=0;
      blue_cnt=0;
      cnt2;
      next_cnt=0;

      int count =0;
      for(int i=0; i<1000; i++)
      {
        ROS_INFO("wait");
        count++;
        if(i==100)
        {
          ROS_INFO("initial position");
          std_msgs::String ini_msg;
          ini_msg.data = "ini_pose";
          ini_msg_pub.publish(ini_msg);
          break;
        }
      }
    }
   }

 }
   if(Alp_msg.data == "i")
   {
     if(cnt==1 && write_flag ==1 && flag ==0)
     {
        ROS_INFO("3");
        if(test==1)
        {
          kinematics_msg.position.x =  present_position.position.x +0.005;
        }
        else if(test ==2)
        {
          kinematics_msg.position.x =  present_position.position.x +0.008;
        }
        else if(test ==7)
        {
          kinematics_msg.position.x =  present_position.position.x +0.0185;
        }
        else
        {
          kinematics_msg.position.x =  present_position.position.x +0.0095;
        }

        if(test>1)
        {
          kinematics_msg.position.y =  present_position.position.y +0.0015;
        }
        else if(test ==2)
        {
          kinematics_msg.position.y =  present_position.position.y +0.0011;
        }
        else
        {
          kinematics_msg.position.y =  present_position.position.y +0.009;
        }


        if(test==1)
        {
         kinematics_msg.position.z = 0.045 - test*0.0004;
        }
        else if(test==2)
        {
          kinematics_msg.position.z = 0.0475 - test*0.0009 ;
        }
        else
        {
          kinematics_msg.position.z = 0.047 - test*0.0005;
        }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "i";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
   else if(cnt==2 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("4");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z - 0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "i";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==3 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("5");

     if(test>1 && test<5)
     {
       kinematics_msg.position.x = present_position.position.x +0.00025 - test*0.0000;
     }
     else
     {
        kinematics_msg.position.x = present_position.position.x +0.0007 + test*0.0001;
     }
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "i";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==4 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("6");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.007;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "i";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");

     kinematics_msg.position.x = present_position.position.x +0.003;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "i";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z-0.007;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "i";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==7 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("9");

     kinematics_msg.position.x = present_position.position.x +0.008;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "i";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;



}
     else if(cnt==8 && write_flag ==1 && flag ==0)
     {
       ROS_INFO("10");

       kinematics_msg.position.x = present_position.position.x;
       kinematics_msg.position.y = present_position.position.y;
       kinematics_msg.position.z = present_position.position.z +0.008;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "i";
       alp.data = work_msg.data;
       work_status_pub.publish(work_msg);
       write_flag =0;



       if(test>6)
       {
         ROS_INFO("start!!!");
         next_page_flag=1;
         write_flag =1;
         OpenManipulatorSub::next_page_touch_function();
       }
       else
       {

         cnt++;
       }
   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("10");
    //   kinematics_msg.position.x = present_position.position.x;
     OpenManipulatorSub::next_position_set();

     if(test<7 && test_cnt==0)
     {
       std_msgs::String work_msg;
       work_msg.data = "i";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test_cnt==6 && test_flag==1)
     {
       std_msgs::String work_msg;
       work_msg.data = "i";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String test_mode_status_msg;
       test_mode_status_msg.data = "testing";
       test_mode_status_pub.publish(test_mode_status_msg);

       write_flag =0;
       cnt =0;

     }
     else if(test>6 && flag==0 && test_cnt==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }
    }


 }
 if(Alp_msg.data == "j")
 {

   if(cnt==1 && write_flag ==1 && flag ==0)
   {
      ROS_INFO("3");
      if(test==1)
      {
        kinematics_msg.position.x =  present_position.position.x +0.005;
      }
      else if(test ==2)
      {
        kinematics_msg.position.x =  present_position.position.x +0.008;
      }
      else if(test ==7)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0185;
      }
      else
      {
        kinematics_msg.position.x =  present_position.position.x +0.0095;
      }

      if(test>1)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0015;
      }
      else if(test ==2)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0011;
      }
      else
      {
        kinematics_msg.position.y =  present_position.position.y +0.009;
      }


      if(test==2)
      {
        kinematics_msg.position.z = 0.0465 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.046 - test*0.0004;
      }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "j";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
   else if(cnt==2 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("4");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z - 0.002;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "j";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==3 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("5");

     if(test>1 && test<5)
     {
       kinematics_msg.position.x = present_position.position.x +0.00025 - test*0.00007;
     }
     else
     {
        kinematics_msg.position.x = present_position.position.x +0.0007 + test*0.0001;
     }
     kinematics_msg.position.y = present_position.position.y -0.0003;
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "j";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==4 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("6");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.012;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "j";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");

     kinematics_msg.position.x = present_position.position.x +0.003;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "j";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z-0.0125;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "j";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==7 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("9");

     kinematics_msg.position.x = present_position.position.x +0.008;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "j";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");
     kinematics_msg.position.x = present_position.position.x +0.0025;
     kinematics_msg.position.y = present_position.position.y -0.0020;
     kinematics_msg.position.z = present_position.position.z -0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "j";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("11");
     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y -0.002;
     kinematics_msg.position.z = present_position.position.z -0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "j";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==10 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("12");
     kinematics_msg.position.x = present_position.position.x -0.0025;
     kinematics_msg.position.y = present_position.position.y -0.0010;
     kinematics_msg.position.z = present_position.position.z +0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "j";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;


   }
   else if(cnt==11 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("13");
     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.008;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "j";
     alp.data = work_msg.data;
     work_status_pub.publish(work_msg);
     write_flag =0;



     if(test>6)
     {
       ROS_INFO("start!!!");
       next_page_flag=1;
       write_flag =1;
       OpenManipulatorSub::next_page_touch_function();
     }
     else
     {

       cnt++;
     }
  }
   else if(cnt==12 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("13");
    //   kinematics_msg.position.x = present_position.position.x;
     OpenManipulatorSub::next_position_set();

     if(test<7)
     {
       std_msgs::String work_msg;
       work_msg.data = "j";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test>6 && flag==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }
    }
  }
 if(Alp_msg.data == "k")
 {

   if(cnt==1 && write_flag ==1 && flag ==0)
   {
      ROS_INFO("3");
      if(test==1)
      {
        kinematics_msg.position.x =  present_position.position.x +0.005;
      }
      else if(test ==2)
      {
        kinematics_msg.position.x =  present_position.position.x +0.008;
      }
      else if(test ==7)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0185;
      }
      else
      {
        kinematics_msg.position.x =  present_position.position.x +0.0095;
      }

      if(test>1)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0015;
      }
      else if(test ==2)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0011;
      }
      else
      {
        kinematics_msg.position.y =  present_position.position.y +0.009;
      }


      if(test==1)
      {
         kinematics_msg.position.z = 0.045 - test*0.0008;
      }
      else if(test==2)
      {
        kinematics_msg.position.z = 0.0465 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.0455 - test*0.0008;
      }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "k";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
  else if(cnt==2 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("4");

    kinematics_msg.position.x = present_position.position.x +0.012;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z -0.002;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "k";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==3 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("5");

    kinematics_msg.position.x = present_position.position.x -0.016;
    kinematics_msg.position.y = present_position.position.y +0.005;
    kinematics_msg.position.z = present_position.position.z -0.001;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "k";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }

  else if(cnt==4 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("6");

    kinematics_msg.position.x = present_position.position.x +0.0066;
    if(test<3)
    {

      kinematics_msg.position.y = present_position.position.y -0.0028 -test*0.0004;
    }
    else
    {
      kinematics_msg.position.y = present_position.position.y -0.00527 +test*0.00005;
    }

    kinematics_msg.position.z = present_position.position.z -0.001;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "k";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==5 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("7");

    kinematics_msg.position.x = present_position.position.x +0.006 + (test-1)*0.001;

    kinematics_msg.position.y = present_position.position.y +0.0022 + (test-1)*0.0005;


    kinematics_msg.position.z = present_position.position.z +0.001;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "k";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;



}
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.008;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "k";
     alp.data = work_msg.data;
     work_status_pub.publish(work_msg);
     write_flag =0;



     if(test>6)
     {
       ROS_INFO("start!!!");
       next_page_flag=1;
       write_flag =1;
       OpenManipulatorSub::next_page_touch_function();
     }
     else
     {

       cnt++;
     }
 }
  else if(cnt==7 && write_flag ==1 && flag ==0)
  {
   // ROS_INFO("13");
    ROS_INFO("8");
   //   kinematics_msg.position.x = present_position.position.x;
    OpenManipulatorSub::next_position_set();

    if(test<7)
    {
      std_msgs::String work_msg;
      work_msg.data = "k";
      work_status_pub.publish(work_msg);
      point_kinematics_msg_pub.publish(kinematics_msg);
      write_flag =0;
      cnt =0;
    }
    else if(test>6 && flag==0)
    {

      ROS_INFO("initial position");
      std_msgs::String ini_msg;
      ini_msg.data = "ini_pose";
      ini_msg_pub.publish(ini_msg);
      cnt = 0;
      write_flag =0;
      test = 0;
      count_num  = 0;
      count_num2 = 0;
      red_cnt=0;
      blue_cnt=0;
      cnt2;
      next_cnt=0;

      int count =0;
      for(int i=0; i<1000; i++)
      {
        ROS_INFO("wait");
        count++;
        if(i==100)
        {
          ROS_INFO("initial position");
          std_msgs::String ini_msg;
          ini_msg.data = "ini_pose";
          ini_msg_pub.publish(ini_msg);
          break;
        }
      }
    }
   }
 }
 if(Alp_msg.data == "l")
 {

   if(cnt==1 && write_flag ==1 && flag ==0)
   {
      ROS_INFO("3");
      if(test==1)
      {
        kinematics_msg.position.x =  present_position.position.x +0.005;
      }
      else if(test ==2)
      {
        kinematics_msg.position.x =  present_position.position.x +0.013;
      }
      else if(test ==7)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0185;
      }
      else
      {
        kinematics_msg.position.x =  present_position.position.x +0.0095;
      }

      if(test==1)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0017;
      }
      else if(test ==2)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0019;
      }
      else
      {
        kinematics_msg.position.y =  present_position.position.y +0.0014;
      }

      if(test==2)
      {
        kinematics_msg.position.z = 0.0475 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.046 - test*0.0004;
      }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "l";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }

   else if(cnt==2 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("4");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z + 0.007;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "l";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==3 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("5");

     kinematics_msg.position.x = present_position.position.x  - 0.0011 - test*0.0002;
     if(test>2)
     {
      kinematics_msg.position.y = present_position.position.y + 0.0040;
     }
     else
     {
      kinematics_msg.position.y = present_position.position.y + 0.0055;
     }
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "l";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==4 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("6");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z- 0.0085;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "l";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z - 0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "l";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x +0.012;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.0015;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "l";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==7 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("9");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.011;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "l";
     alp.data = work_msg.data;
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;

     if(test>6)
     {
       ROS_INFO("start!!!");
       next_page_flag=1;
       write_flag =1;
       OpenManipulatorSub::next_page_touch_function();
     }
     else
     {

       cnt++;
     }
   }

   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("10");
    //   kinematics_msg.position.x = present_position.position.x;

     OpenManipulatorSub::next_position_set();



     if(blue_cnt>0)
     {
       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "l";
       work_status_pub.publish(work_msg);

       std_msgs::String color_write_sta_msg;
       color_write_sta_msg.data ="finish_blue";
       color_write_sta_pub_.publish(color_write_sta_msg);

       write_flag =0;
       cnt =0;
     }
     if(test<7)
     {
       std_msgs::String work_msg;
       work_msg.data = "l";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test>6)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }

    }
 }
   if(Alp_msg.data == "m")
   {
     if(cnt==1 && write_flag ==1 && flag ==0)
     {
        ROS_INFO("3");
        if(test==1)
        {
          kinematics_msg.position.x =  present_position.position.x +0.005;
        }
        else if(test ==2)
        {
          kinematics_msg.position.x =  present_position.position.x +0.008;
        }
        else if(test ==7)
        {
          kinematics_msg.position.x =  present_position.position.x +0.0185;
        }
        else
        {
          kinematics_msg.position.x =  present_position.position.x +0.0095;
        }

        if(test>1)
        {
          kinematics_msg.position.y =  present_position.position.y +0.0015;
        }
        else if(test ==2)
        {
          kinematics_msg.position.y =  present_position.position.y +0.0011;
        }
        else
        {
          kinematics_msg.position.y =  present_position.position.y +0.009;
        }


        if(test==2)
        {
          kinematics_msg.position.z = 0.047 - test*0.0009 ;
        }
        else if(test==3)
        {
         kinematics_msg.position.z = 0.048 - test*0.0006;
        }
        else
        {
          kinematics_msg.position.z = 0.0465 - test*0.0006;
        }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "m";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
    else if(cnt==2 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("4");

      kinematics_msg.position.x = present_position.position.x;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z+0.005;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "m";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==3 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("5");

      kinematics_msg.position.x = present_position.position.x+0.005;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "m";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==4 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("6");

      kinematics_msg.position.x = present_position.position.x;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z-0.006;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "m";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==5 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("7");

      if(test==2)
      {
        kinematics_msg.position.x = present_position.position.x +0.007;
      }
      else
      {
        kinematics_msg.position.x = present_position.position.x +0.006;
      }

      if(test==1)
      {
       kinematics_msg.position.y = present_position.position.y+0.0035;
      }
      else if(test==2)
      {
       kinematics_msg.position.y = present_position.position.y+0.002;
      }
      else
      {
       kinematics_msg.position.y = present_position.position.y;
      }
      kinematics_msg.position.z = present_position.position.z -0.002;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "m";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==6 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("8");

      kinematics_msg.position.x = present_position.position.x -0.009;
      if(test==1)
      {
       kinematics_msg.position.y = present_position.position.y+0.0035;
      }
      else if(test==2)
      {
       kinematics_msg.position.y = present_position.position.y+0.002;
      }
      else
      {
       kinematics_msg.position.y = present_position.position.y;
      }
      kinematics_msg.position.z = present_position.position.z -0.002;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "m";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==7 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("9");

      kinematics_msg.position.x = present_position.position.x;
      kinematics_msg.position.y = present_position.position.y +0.0018 +test*0.0002;
      kinematics_msg.position.z = present_position.position.z +0.001;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "m";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==8 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("10");

      kinematics_msg.position.x = present_position.position.x +0.0037;
      kinematics_msg.position.y = present_position.position.y +0.0004;
      kinematics_msg.position.z = present_position.position.z -0.0005;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "m";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==9 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("11");

      kinematics_msg.position.x = present_position.position.x +0.0038;
      kinematics_msg.position.y = present_position.position.y -0.0008;
      kinematics_msg.position.z = present_position.position.z -0.002;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "m";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==10 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("12");

      kinematics_msg.position.x = present_position.position.x -0.0095+test*0.0005;
      kinematics_msg.position.y = present_position.position.y +0.0015;
      kinematics_msg.position.z = present_position.position.z -0.0005;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "m";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==11 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("13");

      kinematics_msg.position.x = present_position.position.x;
      kinematics_msg.position.y = present_position.position.y +0.0015 +test*0.0002;
      kinematics_msg.position.z = present_position.position.z +0.001;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "m";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==12 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("14");

      kinematics_msg.position.x = present_position.position.x +0.0034;
      kinematics_msg.position.y = present_position.position.y +0.0008;
      kinematics_msg.position.z = present_position.position.z -0.0005;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "m";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==13 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("15");

      kinematics_msg.position.x = present_position.position.x +0.0048;
      if(test<4)
      {
        kinematics_msg.position.y = present_position.position.y -0.0018;
      }
      else
      {
        kinematics_msg.position.y = present_position.position.y -0.0012;
      }
      kinematics_msg.position.z = present_position.position.z +0.001;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "m";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
     else if(cnt==14 && write_flag ==1 && flag ==0)
     {
       ROS_INFO("16");

       kinematics_msg.position.x = present_position.position.x;
       kinematics_msg.position.y = present_position.position.y;
       kinematics_msg.position.z = present_position.position.z +0.012;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "m";
       alp.data = work_msg.data;
       work_status_pub.publish(work_msg);
       write_flag =0;

       if(test>6)
       {
         ROS_INFO("start!!!");
         next_page_flag=1;
         write_flag =1;
         OpenManipulatorSub::next_page_touch_function();
       }
       else
       {

         cnt++;
       }
     }
    else if(cnt==15 && write_flag ==1 && flag ==0)
    {
     // ROS_INFO("13");
      ROS_INFO("17");
     //   kinematics_msg.position.x = present_position.position.x;

      OpenManipulatorSub::next_position_set();

      if(test<7)
      {
        std_msgs::String work_msg;
        work_msg.data = "m";
        work_status_pub.publish(work_msg);
        point_kinematics_msg_pub.publish(kinematics_msg);
        write_flag =0;
        cnt =0;
      }
      else if(test>6 && flag==0)
      {

        ROS_INFO("initial position");
        std_msgs::String ini_msg;
        ini_msg.data = "ini_pose";
        ini_msg_pub.publish(ini_msg);
        cnt = 0;
        write_flag =0;
        test = 0;
        count_num  = 0;
        count_num2 = 0;
        red_cnt=0;
        blue_cnt=0;
        cnt2;
        next_cnt=0;

        int count =0;
        for(int i=0; i<1000; i++)
        {
          ROS_INFO("wait");
          count++;
          if(i==100)
          {
            ROS_INFO("initial position");
            std_msgs::String ini_msg;
            ini_msg.data = "ini_pose";
            ini_msg_pub.publish(ini_msg);
            break;
          }
        }
      }
     }

 }
   if(Alp_msg.data == "n")
   {

     if(cnt==1 && write_flag ==1 && flag ==0)
     {
        ROS_INFO("3");
        if(test==1)
        {
          kinematics_msg.position.x =  present_position.position.x +0.005;
        }
        else if(test ==2)
        {
          kinematics_msg.position.x =  present_position.position.x +0.008;
        }
        else if(test ==7)
        {
          kinematics_msg.position.x =  present_position.position.x +0.0185;
        }
        else
        {
          kinematics_msg.position.x =  present_position.position.x +0.0095;
        }

        if(test>1)
        {
          kinematics_msg.position.y =  present_position.position.y +0.0015;
        }
        else if(test ==2)
        {
          kinematics_msg.position.y =  present_position.position.y +0.0011;
        }
        else
        {
          kinematics_msg.position.y =  present_position.position.y +0.009;
        }


        if(test==2)
        {
          kinematics_msg.position.z = 0.047 - test*0.0009 ;
        }
        else
        {
          kinematics_msg.position.z = 0.0465 - test*0.0006;
        }
          point_kinematics_msg_pub.publish(kinematics_msg);

          std_msgs::String work_msg;
          work_msg.data = "n";
          work_status_pub.publish(work_msg);
          write_flag = 0;
        //  write_flag =0;
        //  cnt =0;
           cnt++;
       }
    else if(cnt==2 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("4");

      kinematics_msg.position.x = present_position.position.x;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z+0.005;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "n";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==3 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("5");

      kinematics_msg.position.x = present_position.position.x+0.005;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "n";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==4 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("6");

      kinematics_msg.position.x = present_position.position.x;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z-0.007;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "n";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==5 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("7");

      kinematics_msg.position.x = present_position.position.x +0.006;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z -0.002;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "n";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==6 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("8");

      kinematics_msg.position.x = present_position.position.x -0.0075;
      kinematics_msg.position.y = present_position.position.y +0.0020;
      kinematics_msg.position.z = present_position.position.z -0.0005;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "n";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==7 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("9");

      kinematics_msg.position.x = present_position.position.x;
      kinematics_msg.position.y = present_position.position.y +0.004;
      kinematics_msg.position.z = present_position.position.z +0.001;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "n";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==8 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("10");

      kinematics_msg.position.x = present_position.position.x +0.0050;
      kinematics_msg.position.y = present_position.position.y +0.0007;
      kinematics_msg.position.z = present_position.position.z -0.0005;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "n";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==9 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("11");

      kinematics_msg.position.x = present_position.position.x +0.0027;
      kinematics_msg.position.y = present_position.position.y -0.0013;
      kinematics_msg.position.z = present_position.position.z -0.0012;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "n";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
     else if(cnt==10 && write_flag ==1 && flag ==0)
     {
       ROS_INFO("12");

       kinematics_msg.position.x = present_position.position.x;
       kinematics_msg.position.y = present_position.position.y;
       kinematics_msg.position.z = present_position.position.z +0.012;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "n";
       alp.data = work_msg.data;
       work_status_pub.publish(work_msg);
       write_flag =0;

       if(test>6)
       {
         ROS_INFO("start!!!");
         next_page_flag=1;
         write_flag =1;
         OpenManipulatorSub::next_page_touch_function();
       }
       else
       {

         cnt++;
       }
     }
    else if(cnt==11 && write_flag ==1 && flag ==0)
    {
     // ROS_INFO("13");
      ROS_INFO("13");

      OpenManipulatorSub::next_position_set();


      if(test<7)
      {
        std_msgs::String work_msg;
        work_msg.data = "n";
        work_status_pub.publish(work_msg);
        point_kinematics_msg_pub.publish(kinematics_msg);
        write_flag =0;
        cnt =0;
      }
      else if(test>6 && flag==0)
      {

        ROS_INFO("initial position");
        std_msgs::String ini_msg;
        ini_msg.data = "ini_pose";
        ini_msg_pub.publish(ini_msg);
        cnt = 0;
        write_flag =0;
        test = 0;
        count_num  = 0;
        count_num2 = 0;
        red_cnt=0;
        blue_cnt=0;
        cnt2;
        next_cnt=0;

        int count =0;
        for(int i=0; i<1000; i++)
        {
          ROS_INFO("wait");
          count++;
          if(i==100)
          {
            ROS_INFO("initial position");
            std_msgs::String ini_msg;
            ini_msg.data = "ini_pose";
            ini_msg_pub.publish(ini_msg);
            break;
          }
        }
      }
     }
   }
   if(Alp_msg.data == "o")
   {
     if(cnt==1 && write_flag ==1 && flag ==0)
     {
        ROS_INFO("3");
        if(test==1)
        {
          kinematics_msg.position.x =  present_position.position.x +0.01;
        }
        else if(test ==2)
        {
          kinematics_msg.position.x =  present_position.position.x +0.013;
        }
        else if(test ==7)
        {
          kinematics_msg.position.x =  present_position.position.x +0.0285;
        }
        else
        {
          kinematics_msg.position.x =  present_position.position.x +0.0135;
        }

        if(test>1)
        {
          kinematics_msg.position.y =  present_position.position.y +0.0015;
        }
        else if(test ==2)
        {
          kinematics_msg.position.y =  present_position.position.y +0.0009;
        }
        else
        {
          kinematics_msg.position.y =  present_position.position.y +0.009;
        }


        if(test<3)
        {
          if(test==1)
          {
            kinematics_msg.position.z = 0.0455 - test*0.0004;
          }
          else if(test==2)
          {
            kinematics_msg.position.z = 0.0472 - test*0.0004;
          }
          else
          {
            kinematics_msg.position.z = 0.0473 - test*0.0004;
          }
        }
        else
        {
          kinematics_msg.position.z = 0.0481 - test*0.00053;
        }

        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "o";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
     else if(cnt==2 && write_flag ==1 && flag ==0)
     {
       ROS_INFO("4");

       kinematics_msg.position.x = present_position.position.x +0.0020;
       kinematics_msg.position.y = present_position.position.y -0.0035;
       kinematics_msg.position.z = present_position.position.z -0.001;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "o";
       work_status_pub.publish(work_msg);
       write_flag =0;
       cnt++;
     }
     else if(cnt==3 && write_flag ==1 && flag ==0)
     {
       ROS_INFO("o");
       kinematics_msg.position.x = present_position.position.x +0.004;
       kinematics_msg.position.y = present_position.position.y;
       kinematics_msg.position.z = present_position.position.z -0.001;
       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "o";
       work_status_pub.publish(work_msg);
       write_flag =0;
       cnt++;
     }
     else if(cnt==4 && write_flag ==1 && flag ==0)
     {
       ROS_INFO("6");
       kinematics_msg.position.x = present_position.position.x +0.0025;
       kinematics_msg.position.y = present_position.position.y +0.0020;
       kinematics_msg.position.z = present_position.position.z -0.001;
       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "o";
       work_status_pub.publish(work_msg);
       write_flag =0;
       cnt++;
     }
     else if(cnt==5 && write_flag ==1 && flag ==0)
     {
       ROS_INFO("7");
       kinematics_msg.position.x = present_position.position.x;
       kinematics_msg.position.y = present_position.position.y +0.002;
       kinematics_msg.position.z = present_position.position.z -0.001;
       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "o";
       work_status_pub.publish(work_msg);
       write_flag =0;
       cnt++;
     }
     else if(cnt==6 && write_flag ==1 && flag ==0)
     {
       ROS_INFO("8");
       kinematics_msg.position.x = present_position.position.x -0.0025;
       kinematics_msg.position.y = present_position.position.y +0.0020;
       kinematics_msg.position.z = present_position.position.z +0.001;
       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "o";
       work_status_pub.publish(work_msg);
       write_flag =0;
       cnt++;
     }
     else if(cnt==7 && write_flag ==1 && flag ==0)
     {
       ROS_INFO("9");
       kinematics_msg.position.x = present_position.position.x -0.004;
       kinematics_msg.position.y = present_position.position.y;
       kinematics_msg.position.z = present_position.position.z +0.001;
       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "o";
       work_status_pub.publish(work_msg);
       write_flag =0;
       cnt++;
     }
     else if(cnt==8 && write_flag ==1 && flag ==0)
     {
       ROS_INFO("10");
       kinematics_msg.position.x = present_position.position.x -0.0025;
       kinematics_msg.position.y = present_position.position.y -0.0020;
       kinematics_msg.position.z = present_position.position.z +0.001;
       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "o";
       work_status_pub.publish(work_msg);
       write_flag =0;
       cnt++;
     }
     else if(cnt==9 && write_flag ==1 && flag ==0)
     {
       ROS_INFO("11");
       kinematics_msg.position.x = present_position.position.x;
       kinematics_msg.position.y = present_position.position.y -0.002;
       kinematics_msg.position.z = present_position.position.z +0.001;
       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "o";
       alp.data = work_msg.data;
       work_status_pub.publish(work_msg);
       write_flag =0;

       if(test>6)
       {
         ROS_INFO("start!!!");
         next_page_flag=1;
         write_flag =1;
         OpenManipulatorSub::next_page_touch_function();
       }
       else
       {

         cnt++;
       }

     }
     else if(cnt==10 && write_flag ==1 && flag ==0)
     {
       ROS_INFO("12");

       OpenManipulatorSub::next_position_set();


       if(test_cnt>0 && test_flag==1)
       {
         std_msgs::String work_msg;
         work_msg.data = "o";
         work_status_pub.publish(work_msg);
         point_kinematics_msg_pub.publish(kinematics_msg);

         std_msgs::String test_mode_status_msg;
         test_mode_status_msg.data = "testing";
         test_mode_status_pub.publish(test_mode_status_msg);

         write_flag =0;
         test_flag=0;
         cnt =0;

       }
       else if(test<7 && test_cnt==0)
       {
         std_msgs::String work_msg;
         work_msg.data = "o";
         work_status_pub.publish(work_msg);
         point_kinematics_msg_pub.publish(kinematics_msg);
         write_flag =0;
         cnt =0;
       }
       else if(test>6 && flag==0)
       {

         ROS_INFO("initial position");
         std_msgs::String ini_msg;
         ini_msg.data = "ini_pose";
         ini_msg_pub.publish(ini_msg);
         cnt = 0;
         write_flag =0;
         test = 0;
         count_num  = 0;
         count_num2 = 0;
         red_cnt=0;
         blue_cnt=0;
         cnt2;
         next_cnt=0;

         int count =0;
         for(int i=0; i<1000; i++)
         {
           ROS_INFO("wait");
           count++;
           if(i==100)
           {
             ROS_INFO("initial position");
             std_msgs::String ini_msg;
             ini_msg.data = "ini_pose";
             ini_msg_pub.publish(ini_msg);
             break;
           }
         }
       }
      }
   }
 if(Alp_msg.data == "p")
 {

   if(cnt==1 && write_flag ==1 && flag ==0)
   {
      ROS_INFO("3");
      if(test==1)
      {
        kinematics_msg.position.x =  present_position.position.x +0.005;
      }
      else if(test ==2)
      {
        kinematics_msg.position.x =  present_position.position.x +0.008;
      }
      else if(test ==7)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0185;
      }
      else
      {
        kinematics_msg.position.x =  present_position.position.x +0.0095;
      }

      if(test>1)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0015;
      }
      else if(test ==2)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0011;
      }
      else
      {
        kinematics_msg.position.y =  present_position.position.y +0.009;
      }


      if(test==2)
      {
        kinematics_msg.position.z = 0.0465 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.046 - test*0.0005;
      }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "p";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
   if(cnt==2 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("4");

     kinematics_msg.position.x = present_position.position.x +0.0015;
     kinematics_msg.position.y = present_position.position.y +0.00125;
     kinematics_msg.position.z = present_position.position.z -0.0005;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "p";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==3 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("5");


     kinematics_msg.position.x = present_position.position.x -0.0005;
     kinematics_msg.position.y = present_position.position.y +0.0017;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "p";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==4 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("6");

     kinematics_msg.position.x = present_position.position.x -0.0025;
     kinematics_msg.position.y = present_position.position.y +0.0015;
     kinematics_msg.position.z = present_position.position.z +0.0005;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "p";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");

     kinematics_msg.position.x = present_position.position.x -0.0020;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "p";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x -0.0025;
     kinematics_msg.position.y = present_position.position.y -0.0010;
     kinematics_msg.position.z = present_position.position.z -0.0005;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "p";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==7 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("9");

     kinematics_msg.position.x = present_position.position.x;
     if(test<3)
     {
       kinematics_msg.position.y = present_position.position.y -0.0030 - (test*0.0003);
     }
     else
     {
       kinematics_msg.position.y = present_position.position.y -0.0040;
     }

     kinematics_msg.position.z = present_position.position.z +0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "p";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");

     kinematics_msg.position.x = present_position.position.x +0.015;
     kinematics_msg.position.y = present_position.position.y + 0.0004 *test;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "p";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;


   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("11");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.013;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "p";
     alp.data = work_msg.data;
     work_status_pub.publish(work_msg);
     write_flag =0;

     if(test>6)
     {
       ROS_INFO("start!!!");
       next_page_flag=1;
       write_flag =1;
       OpenManipulatorSub::next_page_touch_function();
     }
     else
     {

       cnt++;
     }
   }
   else if(cnt==10 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("12");
    //   kinematics_msg.position.x = present_position.position.x;
     OpenManipulatorSub::next_position_set();

     if(test<7)
     {
       std_msgs::String work_msg;
       work_msg.data = "p";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test>6 && flag==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }
    }
 }
 else if(Alp_msg.data == "q")////////////////////////////////////////////////////////////
 {

   if(cnt==1 && write_flag ==1 && flag ==0)
   {
      ROS_INFO("3");
      if(test==1)
      {
        kinematics_msg.position.x =  present_position.position.x +0.005;
      }
      else if(test ==2)
      {
        kinematics_msg.position.x =  present_position.position.x +0.008;
      }
      else if(test ==7)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0185;
      }
      else
      {
        kinematics_msg.position.x =  present_position.position.x +0.0095;
      }

      if(test>1)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0015;
      }
      else if(test ==2)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0011;
      }
      else
      {
        kinematics_msg.position.y =  present_position.position.y +0.009;
      }


      if(test==2)
      {
        kinematics_msg.position.z = 0.0475 - test*0.0009 ;
      }
      else if(test==3)
      {
        kinematics_msg.position.z = 0.048 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.046 - test*0.00055;
      }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "q";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
   else if(cnt==2 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("4");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z + 0.007;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==3 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("5");

     kinematics_msg.position.x = present_position.position.x ;
     if(test>2)
     {
      kinematics_msg.position.y = present_position.position.y + 0.0040;
     }
     else
     {
      kinematics_msg.position.y = present_position.position.y + 0.0055;
     }
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==4 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("6");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z- 0.008;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");

     kinematics_msg.position.x = present_position.position.x +0.002;
     kinematics_msg.position.y = present_position.position.y -0.0005;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }

   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x; // +? -?
     kinematics_msg.position.y = present_position.position.y -0.003;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==7 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("9");

     kinematics_msg.position.x = present_position.position.x -0.003;
     kinematics_msg.position.y = present_position.position.y -0.002;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");


     kinematics_msg.position.x = present_position.position.x -0.002;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("11");

     if(test<3)
     {
      kinematics_msg.position.x = present_position.position.x -0.0027;
      kinematics_msg.position.y = present_position.position.y +0.0017;
     }
     else if(test ==3)
     {
       kinematics_msg.position.x = present_position.position.x -0.0035;
       kinematics_msg.position.y = present_position.position.y +0.0025;
     }
     else
     {
       kinematics_msg.position.x = present_position.position.x -0.0027;
       kinematics_msg.position.y = present_position.position.y +0.0017;
     }
     kinematics_msg.position.z = present_position.position.z +0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==10 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("12");

     kinematics_msg.position.x = present_position.position.x;
     if(test<3)
     {
      kinematics_msg.position.y = present_position.position.y +0.0045;
     }
     else
     {
      kinematics_msg.position.y = present_position.position.y +0.003 -test*0.0002;
     }
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==11 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("13");

     kinematics_msg.position.x = present_position.position.x +0.0007;
     kinematics_msg.position.y = present_position.position.y +0.0006;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==12 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("14");

     kinematics_msg.position.x = present_position.position.x +0.0007;
     if(test<3)
     {
      kinematics_msg.position.y = present_position.position.y +0.001;
     }
     else
     {
      kinematics_msg.position.y = present_position.position.y +0.0006;
     }
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }

   else if(cnt==13 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("15");

     kinematics_msg.position.x = present_position.position.x +0.013;
     kinematics_msg.position.y = present_position.position.y -0.0008;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     alp.data = work_msg.data;
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;


   }
   else if(cnt==14 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("16");

     kinematics_msg.position.x = present_position.position.x-0.0005;
     if(test<4)
     {
        kinematics_msg.position.y = present_position.position.y +0.001 + test*0.0005;
     }
     else if(test==4)
     {
       kinematics_msg.position.y = present_position.position.y +0.005 + test*0.0005;
     }
     else
     {
        kinematics_msg.position.y = present_position.position.y +0.0015 + test*0.0009;
     }
     kinematics_msg.position.z = present_position.position.z +0.009;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     alp.data = work_msg.data;
     work_status_pub.publish(work_msg);
     write_flag =0;

     if(test>6)
     {
       ROS_INFO("start!!!");
       next_page_flag=1;
       write_flag =1;
       OpenManipulatorSub::next_page_touch_function();
     }
     else
     {

       cnt++;
     }
   }
   else if(cnt==15 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("17");
    //   kinematics_msg.position.x = present_position.position.x;
     OpenManipulatorSub::next_position_set();

     if(test<7)
     {
       std_msgs::String work_msg;
       work_msg.data = "q";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test>6 && flag==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }
    }
 }
   if(Alp_msg.data == "r")
   {
     if(cnt==1 && write_flag ==1 && flag ==0)
     {
        ROS_INFO("3");
        if(test==1)
        {
          kinematics_msg.position.x =  present_position.position.x +0.009;
        }
        else if(test ==2)
        {
          kinematics_msg.position.x =  present_position.position.x +0.008;
        }
        else if(test ==7)
        {
          kinematics_msg.position.x =  present_position.position.x +0.0185;
        }
        else
        {
          kinematics_msg.position.x =  present_position.position.x +0.0095;
        }

        if(test>1)
        {
          kinematics_msg.position.y =  present_position.position.y +0.0015;
        }
        else if(test ==2)
        {
          kinematics_msg.position.y =  present_position.position.y +0.0011;
        }
        else
        {
          kinematics_msg.position.y =  present_position.position.y +0.009;
        }


        if(test==2)
        {
          kinematics_msg.position.z = 0.0465 - test*0.0009 ;
        }
        else
        {
          kinematics_msg.position.z = 0.046 - test*0.0004;
        }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "r";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
    else if(cnt==2 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("4");

      kinematics_msg.position.x = present_position.position.x;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z+0.004;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "r";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==3 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("5");

      kinematics_msg.position.x = present_position.position.x+0.0012;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "r";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==4 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("6");

      kinematics_msg.position.x = present_position.position.x;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z-0.0057;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "r";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==5 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("7");

      kinematics_msg.position.x = present_position.position.x +0.006;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z -0.002;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "r";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==6 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("8");

      kinematics_msg.position.x = present_position.position.x -0.0085 -test*0.0005;
      kinematics_msg.position.y = present_position.position.y +0.0020;
      kinematics_msg.position.z = present_position.position.z +0.001;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "r";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==7 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("9");

      kinematics_msg.position.x = present_position.position.x +0.0006;
      kinematics_msg.position.y = present_position.position.y +0.0043;
      kinematics_msg.position.z = present_position.position.z +0.002;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "r";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;

   }
    else if(cnt==8 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("10");

      kinematics_msg.position.x = present_position.position.x +0.006;
      kinematics_msg.position.y = present_position.position.y -0.004;
      kinematics_msg.position.z = present_position.position.z +0.01;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "r";
      alp.data = work_msg.data;
      work_status_pub.publish(work_msg);
      write_flag =0;

      if(test>6)
      {
        ROS_INFO("start!!!");
        next_page_flag=1;
        write_flag =1;
        OpenManipulatorSub::next_page_touch_function();
      }
      else
      {

        cnt++;
      }
    }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("11");
    //   kinematics_msg.position.x = present_position.position.x;
     OpenManipulatorSub::next_position_set();



     if(blue_cnt==0 && red_cnt>0)
     {
       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String color_write_sta_msg;
       color_write_sta_msg.data ="finish_red";
       color_write_sta_pub_.publish(color_write_sta_msg);

       write_flag =0;
       cnt =0;

     }
     else if(test_cnt==1 && test_flag==1)
     {
       std_msgs::String work_msg;
       work_msg.data = "r";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String test_mode_status_msg;
       test_mode_status_msg.data = "testing";
       test_mode_status_pub.publish(test_mode_status_msg);

       write_flag =0;
       test_flag=0;
       cnt =0;

     }
     else if(test<7 && test_cnt==0)
     {
       std_msgs::String work_msg;
       work_msg.data = "r";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test>6  && flag==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;
       ini_msg_pub.publish(ini_msg);

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }
    }
  }
  if(Alp_msg.data == "s")
  {

    if(cnt==1 && write_flag ==1 && flag ==0)
    {
       ROS_INFO("3");
       if(test==1)
       {
         kinematics_msg.position.x =  present_position.position.x +0.005;
       }
       else if(test ==2)
       {
         kinematics_msg.position.x =  present_position.position.x +0.008;
       }
       else if(test ==7)
       {
         kinematics_msg.position.x =  present_position.position.x +0.0185;
       }
       else
       {
         kinematics_msg.position.x =  present_position.position.x +0.0095;
       }

       if(test>1)
       {
         kinematics_msg.position.y =  present_position.position.y +0.0015;
       }
       else if(test ==2)
       {
         kinematics_msg.position.y =  present_position.position.y +0.0011;
       }
       else
       {
         kinematics_msg.position.y =  present_position.position.y +0.009;
       }


       if(test==2)
       {
         kinematics_msg.position.z = 0.0465 - test*0.0009 ;
       }
       if(test ==4)
       {
         kinematics_msg.position.z = 0.046 - test*0.00015;
       }
       else
       {
         kinematics_msg.position.z = 0.0485 - test*0.0005;
       }
         point_kinematics_msg_pub.publish(kinematics_msg);

         std_msgs::String work_msg;
         work_msg.data = "s";
         work_status_pub.publish(work_msg);
         write_flag = 0;
       //  write_flag =0;
       //  cnt =0;
          cnt++;
      }
    else if(cnt==2 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("4");

      kinematics_msg.position.x = present_position.position.x;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z + 0.007;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==3 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("5");

      kinematics_msg.position.x = present_position.position.x + 0.0003*test;
      if(test>2)
      {
        if(test==7)
        {
          kinematics_msg.position.y = present_position.position.y + 0.0037 + test*0.0007;
        }
        else
        {
          kinematics_msg.position.y = present_position.position.y + 0.0040 + test*0.001;
        }
      }
      else
      {
       kinematics_msg.position.y = present_position.position.y + 0.0055;
      }
      kinematics_msg.position.z = present_position.position.z;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==4 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("6");

      kinematics_msg.position.x = present_position.position.x;
      kinematics_msg.position.y = present_position.position.y;
      if(test==7)
      {
        kinematics_msg.position.z = present_position.position.z- 0.0095 -test*0.0003;
      }
      else
      {
        kinematics_msg.position.z = present_position.position.z- 0.0105 -test*0.0003;
      }
      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==5 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("7");

      kinematics_msg.position.x = present_position.position.x -0.005;
      kinematics_msg.position.y = present_position.position.y - 0.0035-0.00032*test;
      kinematics_msg.position.z = present_position.position.z -0.001;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==6 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("8");

      kinematics_msg.position.x = present_position.position.x + 0.0025;
      kinematics_msg.position.y = present_position.position.y - 0.0030;
      kinematics_msg.position.z = present_position.position.z -0.001;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==7 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("9");

      kinematics_msg.position.x = present_position.position.x + 0.0022 + 0.00021*test;
      kinematics_msg.position.y = present_position.position.y +0.0005;
      kinematics_msg.position.z = present_position.position.z+0.0005;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==8 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("10");

      kinematics_msg.position.x = present_position.position.x + 0.0025;
      kinematics_msg.position.y = present_position.position.y + 0.0005;
      kinematics_msg.position.z = present_position.position.z-0.001;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==9 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("11");

      kinematics_msg.position.x = present_position.position.x -0.0016;
      kinematics_msg.position.y = present_position.position.y + 0.0045 +0.00035*test;
      kinematics_msg.position.z = present_position.position.z+0.001;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==10 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("12");

      kinematics_msg.position.x = present_position.position.x + 0.0025;
      kinematics_msg.position.y = present_position.position.y + 0.0025;
      kinematics_msg.position.z = present_position.position.z-0.001;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==11 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("13");

      kinematics_msg.position.x = present_position.position.x + 0.0015;
      kinematics_msg.position.y = present_position.position.y - 0.0025;
      kinematics_msg.position.z = present_position.position.z-0.001;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==12 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("14");

      if(test==7)
      {
       kinematics_msg.position.x = present_position.position.x + 0.0013+ test*0.0005;
      }
      else
      {
        kinematics_msg.position.x = present_position.position.x + 0.0015+ test*0.0005;
      }
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z-0.001;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==13 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("15");

      kinematics_msg.position.x = present_position.position.x + 0.002 -test*0.0001;
      kinematics_msg.position.y = present_position.position.y - 0.008;
      kinematics_msg.position.z = present_position.position.z +0.009;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==14 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("16");

      kinematics_msg.position.x = present_position.position.x+0.01;
      kinematics_msg.position.y = present_position.position.y;
      kinematics_msg.position.z = present_position.position.z+0.015;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      alp.data = work_msg.data;
      work_status_pub.publish(work_msg);
      write_flag =0;

      if(test>6)
      {
        ROS_INFO("start!!!");
        next_page_flag=1;
        write_flag =1;
        OpenManipulatorSub::next_page_touch_function();
      }
      else
      {

        cnt++;
      }
    }
    else if(cnt==15 && write_flag ==1 && flag ==0)
    {
     // ROS_INFO("13");
      ROS_INFO("17");
     //   kinematics_msg.position.x = present_position.position.x;
      OpenManipulatorSub::next_position_set();



      if(test<7 && test_cnt==0)
      {
        std_msgs::String work_msg;
        work_msg.data = "s";
        work_status_pub.publish(work_msg);
        point_kinematics_msg_pub.publish(kinematics_msg);
        write_flag =0;
        cnt =0;
      }
      else if(test>6 && flag==0)
      {


        ROS_INFO("initial position!");
        std_msgs::String ini_msg;
        ini_msg.data = "ini_pose";
        ini_msg_pub.publish(ini_msg);
        cnt = 0;
        write_flag =0;
        test = 0;
        count_num  = 0;
        count_num2 = 0;
        red_cnt=0;
        blue_cnt=0;
        cnt2;
        next_cnt=0;
        test_cnt=0;



      }
      else if(test_cnt==7 && test_flag==1)
      {

/*
        for(int i; i<2000;i++)
        {
          if(i==1000)
          {

            std_msgs::String test_mode_status_msg;
            test_mode_status_msg.data = "testing";
            test_mode_status_pub.publish(test_mode_status_msg);
            break;
          }
        }


*/


        write_flag =0;
        cnt =0;
        test=0;



      }


      }


  }
 if(Alp_msg.data == "t")
 {

   if(cnt==1 && write_flag ==1 && flag ==0)
   {
      ROS_INFO("3");
      if(test==1)
      {
        kinematics_msg.position.x =  present_position.position.x +0.005;
      }
      else if(test ==2)
      {
        kinematics_msg.position.x =  present_position.position.x +0.008;
      }
      else if(test ==7)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0185;
      }
      else
      {
        kinematics_msg.position.x =  present_position.position.x +0.0095;
      }

      if(test>1)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0015;
      }
      else if(test ==2)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0011;
      }
      else
      {
        kinematics_msg.position.y =  present_position.position.y +0.009;
      }

      if (test==1)\
      {
        kinematics_msg.position.z = 0.045 - test*0.0009;
      }
      else if(test==2)
      {
        kinematics_msg.position.z = 0.0465 - test*0.0009;
      }
      else
      {
        kinematics_msg.position.z = 0.046 - test*0.00073;
      }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "t";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
  else if(cnt==2 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("4");
    if(test==5)
    {
      kinematics_msg.position.x = present_position.position.x +0.014;
    }
    else
    {
      kinematics_msg.position.x = present_position.position.x +0.012;
    }
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z -0.002;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "t";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==3 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("5");
    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z +0.007;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "t";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==4 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("6");
    kinematics_msg.position.x = present_position.position.x -0.011 -test*0.0002;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z +0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "t";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==5 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("7");

    kinematics_msg.position.x = present_position.position.x +0.0004;
    kinematics_msg.position.y = present_position.position.y -0.0015;
    kinematics_msg.position.z = present_position.position.z -0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "t";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==6 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("8");
    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z -0.0045 -test*0.00015;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "t";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==7 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("9");
    kinematics_msg.position.x = present_position.position.x +0.0006;
    kinematics_msg.position.y = present_position.position.y +0.0050;
    kinematics_msg.position.z = present_position.position.z +0.001;
    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "t";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
   }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");
     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.011;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "t";
     work_status_pub.publish(work_msg);
     alp.data = work_msg.data;
     write_flag =0;

     if(test>6)
     {
       ROS_INFO("start!!!");
       next_page_flag=1;
       write_flag =1;
       OpenManipulatorSub::next_page_touch_function();
     }
     else
     {

       cnt++;
     }
   }
  else if(cnt==9 && write_flag ==1 && flag ==0)
  {

    ROS_INFO("11");

    OpenManipulatorSub::next_position_set();

    if(test_cnt==5 && test_flag==1)
    {
      std_msgs::String work_msg;
      work_msg.data = "t";
      work_status_pub.publish(work_msg);
      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String test_mode_status_msg;
      test_mode_status_msg.data = "testing";
      test_mode_status_pub.publish(test_mode_status_msg);

      write_flag =0;
      test_flag=0;
      cnt =0;

    }
    else if(test<7 && test_cnt==0)
    {
      std_msgs::String work_msg;
      work_msg.data = "t";
      work_status_pub.publish(work_msg);
      point_kinematics_msg_pub.publish(kinematics_msg);
      write_flag =0;
      cnt =0;
    }

    else if(test>6 && flag==0)
    {

      ROS_INFO("initial position");
      std_msgs::String ini_msg;
      ini_msg.data = "ini_pose";
      ini_msg_pub.publish(ini_msg);
      cnt = 0;
      write_flag =0;
      test = 0;
      count_num  = 0;
      count_num2 = 0;
      red_cnt=0;
      blue_cnt=0;
      cnt2;
      next_cnt=0;

      int count =0;
      for(int i=0; i<1000; i++)
      {
        ROS_INFO("wait");
        count++;
        if(i==100)
        {
          ROS_INFO("initial position");
          std_msgs::String ini_msg;
          ini_msg.data = "ini_pose";
          ini_msg_pub.publish(ini_msg);
          break;
        }
      }

    }
    }
  }
 if(Alp_msg.data == "u")
 {
   if(cnt==1 && write_flag ==1 && flag ==0)
   {
      ROS_INFO("3");
      if(test==1)
      {
        kinematics_msg.position.x =  present_position.position.x +0.005;
      }
      else if(test ==2)
      {
        kinematics_msg.position.x =  present_position.position.x +0.008;
      }
      else if(test ==7)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0185;
      }
      else
      {
        kinematics_msg.position.x =  present_position.position.x +0.0095;
      }

      if(test>1)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0015;
      }
      else if(test ==2)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0011;
      }
      else
      {
        kinematics_msg.position.y =  present_position.position.y +0.009;
      }


      if(test==2)
      {
        kinematics_msg.position.z = 0.0465 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.046 - test*0.0007;
      }
      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "u";
      work_status_pub.publish(work_msg);
      write_flag = 0;
    //  write_flag =0;
    //  cnt =0;
       cnt++;
   }
 else if(cnt==2 && write_flag ==1 && flag ==0)
 {
   ROS_INFO("4");
   kinematics_msg.position.x = present_position.position.x +0.004;
   kinematics_msg.position.y = present_position.position.y;
   kinematics_msg.position.z = present_position.position.z -0.001;
   point_kinematics_msg_pub.publish(kinematics_msg);

   std_msgs::String work_msg;
   work_msg.data = "u";
   work_status_pub.publish(work_msg);
   write_flag =0;
   cnt++;
 }
 else if(cnt==3 && write_flag ==1 && flag ==0)
 {
   ROS_INFO("5");
   kinematics_msg.position.x = present_position.position.x +0.0025;
   kinematics_msg.position.y = present_position.position.y +0.0020;
   kinematics_msg.position.z = present_position.position.z -0.001;
   point_kinematics_msg_pub.publish(kinematics_msg);

   std_msgs::String work_msg;
   work_msg.data = "u";
   work_status_pub.publish(work_msg);
   write_flag =0;
   cnt++;
 }
 else if(cnt==4 && write_flag ==1 && flag ==0)
 {
   ROS_INFO("6");
   kinematics_msg.position.x = present_position.position.x;
   kinematics_msg.position.y = present_position.position.y +0.002;
   kinematics_msg.position.z = present_position.position.z -0.001;
   point_kinematics_msg_pub.publish(kinematics_msg);

   std_msgs::String work_msg;
   work_msg.data = "u";
   work_status_pub.publish(work_msg);
   write_flag =0;
   cnt++;
 }
 else if(cnt==5 && write_flag ==1 && flag ==0)
 {
   ROS_INFO("7");
   kinematics_msg.position.x = present_position.position.x -0.0025;
   kinematics_msg.position.y = present_position.position.y +0.0020;
   kinematics_msg.position.z = present_position.position.z +0.001;
   point_kinematics_msg_pub.publish(kinematics_msg);

   std_msgs::String work_msg;
   work_msg.data = "u";
   work_status_pub.publish(work_msg);
   write_flag =0;
   cnt++;
 }
 else if(cnt==6 && write_flag ==1 && flag ==0)
 {
   ROS_INFO("8");
   kinematics_msg.position.x = present_position.position.x -0.0065;
   kinematics_msg.position.y = present_position.position.y;
   kinematics_msg.position.z = present_position.position.z +0.001;
   point_kinematics_msg_pub.publish(kinematics_msg);

   std_msgs::String work_msg;
   work_msg.data = "u";
   work_status_pub.publish(work_msg);
   write_flag =0;
   cnt++;
 }
   else if(cnt==7 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("9");
     kinematics_msg.position.x = present_position.position.x +0.011;
     kinematics_msg.position.y = present_position.position.y +0.0016 + 0.0003*test;
     kinematics_msg.position.z = present_position.position.z -0.001;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "a";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;


    }


   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.009;
     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "u";
     alp.data = work_msg.data;
     work_status_pub.publish(work_msg);
     write_flag =0;


     if(test>6)
     {
       ROS_INFO("start!!!");
       next_page_flag=1;
       write_flag =1;
       OpenManipulatorSub::next_page_touch_function();
     }
     else
     {

       cnt++;
     }
   }

 else if(cnt==9 && write_flag ==1 && flag ==0)
 {
  // ROS_INFO("13");
   ROS_INFO("11");
  //   kinematics_msg.position.x = present_position.position.x;
   OpenManipulatorSub::next_position_set();

   if(test<7)
   {
     std_msgs::String work_msg;
     work_msg.data = "u";
     work_status_pub.publish(work_msg);
     point_kinematics_msg_pub.publish(kinematics_msg);
     write_flag =0;
     cnt =0;
   }
   else if(test>6  && flag==0)
   {

     ROS_INFO("initial position");
     std_msgs::String ini_msg;
     ini_msg.data = "ini_pose";
     ini_msg_pub.publish(ini_msg);
     cnt = 0;
     write_flag =0;
     test = 0;
     count_num  = 0;
     count_num2 = 0;
     red_cnt=0;
     blue_cnt=0;
     cnt2;
     next_cnt=0;

     int count =0;
     for(int i=0; i<1000; i++)
     {
       ROS_INFO("wait");
       count++;
       if(i==100)
       {
         ROS_INFO("initial position");
         std_msgs::String ini_msg;
         ini_msg.data = "ini_pose";
         ini_msg_pub.publish(ini_msg);
         break;
       }
     }
   }
 }

}

 if(Alp_msg.data == "v")
 {

   if(cnt==1 && write_flag ==1 && flag ==0)
   {
      ROS_INFO("3");
      if(test==1)
      {
        kinematics_msg.position.x =  present_position.position.x +0.005;
      }
      else if(test ==2)
      {
        kinematics_msg.position.x =  present_position.position.x +0.008;
      }
      else if(test ==7)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0185;
      }
      else
      {
        kinematics_msg.position.x =  present_position.position.x +0.0095;
      }

      if(test>1)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0015;
      }
      else if(test ==2)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0011;
      }
      else
      {
        kinematics_msg.position.y =  present_position.position.y +0.009;
      }


      if(test==1)
      {
         kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else if(test==2)
      {
        kinematics_msg.position.z = 0.0465 - test*0.0009 ;
      }
      else if(test ==4)
      {
        kinematics_msg.position.z = 0.0465 - test*0.0009;
      }
      else
      {
        kinematics_msg.position.z = 0.0467 - test*0.0004;
      }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "v";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
  else if(cnt==2 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("4");

    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z+0.005;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "v";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==3 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("5");

    kinematics_msg.position.x = present_position.position.x+0.0025;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "v";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==4 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("6");

    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z-0.0055;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "v";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");

     kinematics_msg.position.x = present_position.position.x +0.0075 -test*0.0005;
     kinematics_msg.position.y = present_position.position.y +0.0033 +test*0.0003;
     kinematics_msg.position.z = present_position.position.z -0.0005;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "v";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x -0.0095 -test*0.0005;
     kinematics_msg.position.y = present_position.position.y +0.0033 +test*0.00015;
     kinematics_msg.position.z = present_position.position.z -0.0005;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "v";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==7 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("9");

     kinematics_msg.position.x = present_position.position.x +0.0045;
     kinematics_msg.position.y = present_position.position.y -0.0023+test*0.00015;
     kinematics_msg.position.z = present_position.position.z +0.006;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "v";
     alp.data=work_msg.data;
     work_status_pub.publish(work_msg);
     write_flag =0;

     if(test>6)
     {
       ROS_INFO("start!!!");
       next_page_flag=1;
       write_flag =1;
       OpenManipulatorSub::next_page_touch_function();
     }
     else
     {

       cnt++;
     }
   }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("10");
    //   kinematics_msg.position.x = present_position.position.x;
     OpenManipulatorSub::next_position_set();

     if(test<7)
     {
       std_msgs::String work_msg;
       work_msg.data = "u";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test>6  && flag==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }
    }
  }
 if(Alp_msg.data == "w")
 {

   if(cnt==1 && write_flag ==1 && flag ==0)
   {
      ROS_INFO("3");
      if(test==1)
      {
        kinematics_msg.position.x =  present_position.position.x -0.003;
      }
      else if(test ==2)
      {
        kinematics_msg.position.x =  present_position.position.x +0.008;
      }
      else if(test ==7)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0185;
      }
      else
      {
        kinematics_msg.position.x =  present_position.position.x +0.0095;
      }

      if(test>1)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0015;
      }
      else if(test ==2)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0011;
      }
      else
      {
        kinematics_msg.position.y =  present_position.position.y +0.009;
      }


      if(test ==1)
      {
       kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else if(test==2)
      {
        kinematics_msg.position.z = 0.0475 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.0480 - test*0.0012;
      }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "w";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
  else if(cnt==2 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("4");

    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z+0.005;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "w";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==3 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("5");

    kinematics_msg.position.x = present_position.position.x+0.0025;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "w";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==4 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("6");

    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z-0.0055;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "w";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");

     kinematics_msg.position.x = present_position.position.x +0.0075 +test*0.0005;
     kinematics_msg.position.y = present_position.position.y +0.0023 +test*0.0003;
     kinematics_msg.position.z = present_position.position.z -0.0005;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "w";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x -0.0095 -test*0.0005;
     kinematics_msg.position.y = present_position.position.y +0.0023 +test*0.00005;
     kinematics_msg.position.z = present_position.position.z -0.0005;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "w";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
    else if(cnt==7 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("9");

      kinematics_msg.position.x = present_position.position.x +0.0095 +test*0.0005;
      kinematics_msg.position.y = present_position.position.y +0.0023 +test*0.0005;
      kinematics_msg.position.z = present_position.position.z -0.0005;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "w";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==8 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("10");

      kinematics_msg.position.x = present_position.position.x -0.0085 -test*0.0009;
      kinematics_msg.position.y = present_position.position.y +0.0023 +test*0.00005;
      kinematics_msg.position.z = present_position.position.z -0.0005;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "w";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("11");

     kinematics_msg.position.x = present_position.position.x +0.0055;
     kinematics_msg.position.y = present_position.position.y -0.0013+test*0.00055;
     kinematics_msg.position.z = present_position.position.z +0.006;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "w";
     alp.data=work_msg.data;
     work_status_pub.publish(work_msg);
     write_flag =0;

     if(test>6)
     {
       ROS_INFO("start!!!");
       next_page_flag=1;
       write_flag =1;
       OpenManipulatorSub::next_page_touch_function();
     }
     else
     {

       cnt++;
     }
   }
   else if(cnt==10 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("12");
    //   kinematics_msg.position.x = present_position.position.x;
    OpenManipulatorSub::next_position_set();

    if(test<7)
    {
      std_msgs::String work_msg;
      work_msg.data = "u";
      work_status_pub.publish(work_msg);
      point_kinematics_msg_pub.publish(kinematics_msg);
      write_flag =0;
      cnt =0;
    }
    else if(test>6  && flag==0)
    {

      ROS_INFO("initial position");
      std_msgs::String ini_msg;
      ini_msg.data = "ini_pose";
      ini_msg_pub.publish(ini_msg);
      cnt = 0;
      write_flag =0;
      test = 0;
      count_num  = 0;
      count_num2 = 0;
      red_cnt=0;
      blue_cnt=0;
      cnt2;
      next_cnt=0;

      int count =0;
      for(int i=0; i<1000; i++)
      {
        ROS_INFO("wait");
        count++;
        if(i==100)
        {
          ROS_INFO("initial position");
          std_msgs::String ini_msg;
          ini_msg.data = "ini_pose";
          ini_msg_pub.publish(ini_msg);
          break;
        }
      }
    }
    }
  }
 if(Alp_msg.data == "x")
 {

   if(cnt==1 && write_flag ==1 && flag ==0)
   {
      ROS_INFO("3");
      if(test==1)
      {
        kinematics_msg.position.x =  present_position.position.x +0.005;
      }
      else if(test ==2)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0105;
      }
      else if(test ==7)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0185;
      }
      else
      {
        kinematics_msg.position.x =  present_position.position.x +0.0095;
      }

      if(test>1)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0015;
      }
      else if(test ==2)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0011;
      }
      else
      {
        kinematics_msg.position.y =  present_position.position.y +0.009;
      }


      if(test==1)
      {
        kinematics_msg.position.z = 0.045 - test*0.0009 ;
      }
      else if(test==2)
      {
        kinematics_msg.position.z = 0.047 - test*0.0009 ;
      }
      else if(test==3)
      {
        kinematics_msg.position.z = 0.0478 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.0468 - test*0.0006;
      }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "x";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
  else if(cnt==2 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("4");

    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z+0.006;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "x";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==3 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("5");

    kinematics_msg.position.x = present_position.position.x+0.0015;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "x";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==4 && write_flag ==1 && flag ==0)
  {
    ROS_INFO("6");

    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z-0.0065;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "x";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");

     kinematics_msg.position.x = present_position.position.x +0.0075;
     kinematics_msg.position.y = present_position.position.y +0.0035 +test*0.0002;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "x";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.006;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "x";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==7 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("9");

     kinematics_msg.position.x = present_position.position.x -0.0085 +0.0002*test;
     kinematics_msg.position.y = present_position.position.y +0.001  -0.0003*test;
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "x";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.0065;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "x";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("11");

     kinematics_msg.position.x = present_position.position.x +0.0075;
     kinematics_msg.position.y = present_position.position.y -0.0045 -test*0.0002;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "x";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==10 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("12");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.009;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "x";
     alp.data=work_msg.data;
     work_status_pub.publish(work_msg);
     write_flag =0;

     if(test>6)
     {
       ROS_INFO("start!!!");
       next_page_flag=1;
       write_flag =1;
       OpenManipulatorSub::next_page_touch_function();
     }
     else
     {

       cnt++;
     }
   }
   else if(cnt==11 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("13");
    //   kinematics_msg.position.x = present_position.position.x;
     OpenManipulatorSub::next_position_set();

     if(test<7)
     {
       std_msgs::String work_msg;
       work_msg.data = "x";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test>6  && flag==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }
    }
  }
 if(Alp_msg.data == "y")
 {

   if(cnt==1 && write_flag ==1 && flag ==0)
   {
      ROS_INFO("3");
      if(test==1)
      {
        kinematics_msg.position.x =  present_position.position.x -0.002;
      }
      else if(test ==2)
      {
        kinematics_msg.position.x =  present_position.position.x +0.008;
      }
      else if(test ==7)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0185;
      }
      else
      {
        kinematics_msg.position.x =  present_position.position.x +0.0095;
      }

      if(test>1)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0015;
      }
      else if(test ==2)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0011;
      }
      else
      {
        kinematics_msg.position.y =  present_position.position.y +0.009;
      }


      if(test==1)
      {
        kinematics_msg.position.z = 0.045 - test*0.0009;
      }
      else if(test==2)
      {
        kinematics_msg.position.z = 0.0473 - test*0.0009;
      }
      else
      {
        kinematics_msg.position.z = 0.047 - test*0.0006;
      }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "y";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
   else if(cnt==2 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("4");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z+0.005;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "y";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==3 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("5");

     kinematics_msg.position.x = present_position.position.x+0.0015;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "y";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==4 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("6");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z-0.0068;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "y";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");

     kinematics_msg.position.x = present_position.position.x +0.0045 +test*0.0005;
     kinematics_msg.position.y = present_position.position.y +0.002;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "y";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.006;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "y";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==7 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("9");

     kinematics_msg.position.x = present_position.position.x -0.005 -0.0003*test;
     kinematics_msg.position.y = present_position.position.y +0.002  -0.0003*test;
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "y";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.0065;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "y";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("11");

     kinematics_msg.position.x = present_position.position.x +0.0085;
     kinematics_msg.position.y = present_position.position.y -0.0045 +test*0.0005;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "y";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==10 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("12");

     kinematics_msg.position.x = present_position.position.x -0.0025;
     kinematics_msg.position.y = present_position.position.y -0.0015 -test*0.0002;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "y";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==11 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("13");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z +0.009;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "y";
     alp.data=work_msg.data;
     work_status_pub.publish(work_msg);
     write_flag =0;

     if(test>6)
     {
       ROS_INFO("start!!!");
       next_page_flag=1;
       write_flag =1;
       OpenManipulatorSub::next_page_touch_function();
     }
     else
     {

       cnt++;
     }
   }

   else if(cnt==12 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("14");
    //   kinematics_msg.position.x = present_position.position.x;
     OpenManipulatorSub::next_position_set();


     if(test<7)
     {
       std_msgs::String work_msg;
       work_msg.data = "x";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test>6  && flag==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }
    }
  }
 if(Alp_msg.data == "z")
 {

   if(cnt==1 && write_flag ==1 && flag ==0)
   {
      ROS_INFO("3");
      if(test==1)
      {
        kinematics_msg.position.x =  present_position.position.x +0.002;
      }
      else if(test ==2)
      {
        kinematics_msg.position.x =  present_position.position.x +0.008;
      }
      else if(test ==7)
      {
        kinematics_msg.position.x =  present_position.position.x +0.0185;
      }
      else
      {
        kinematics_msg.position.x =  present_position.position.x +0.0095;
      }

      if(test>1)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0015;
      }
      else if(test ==2)
      {
        kinematics_msg.position.y =  present_position.position.y +0.0011;
      }
      else
      {
        kinematics_msg.position.y =  present_position.position.y +0.009;
      }


      if(test==1)
      {
        kinematics_msg.position.z = 0.046 - test*0.0009;
      }
      else if(test==2)
      {
        kinematics_msg.position.z = 0.0475 - test*0.0009;
      }
      else
      {
        kinematics_msg.position.z = 0.047 - test*0.0004;
      }
        point_kinematics_msg_pub.publish(kinematics_msg);

        std_msgs::String work_msg;
        work_msg.data = "z";
        work_status_pub.publish(work_msg);
        write_flag = 0;
      //  write_flag =0;
      //  cnt =0;
         cnt++;
     }
   else if(cnt==2 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("4");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z+0.005;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "z";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==3 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("5");

     kinematics_msg.position.x = present_position.position.x+0.004;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "z";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==4 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("6");

     kinematics_msg.position.x = present_position.position.x;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z-0.0065;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "z";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==5 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("7");

     kinematics_msg.position.x = present_position.position.x -0.0002*test;
     kinematics_msg.position.y = present_position.position.y + 0.008;
     kinematics_msg.position.z = present_position.position.z;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "z";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==6 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("8");

     kinematics_msg.position.x = present_position.position.x +0.0060;
     kinematics_msg.position.y = present_position.position.y -0.01;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "z";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
     else if(cnt==7 && write_flag ==1 && flag ==0)
     {
       ROS_INFO("9");

       kinematics_msg.position.x = present_position.position.x -0.0002*test;
       kinematics_msg.position.y = present_position.position.y + 0.010;
       kinematics_msg.position.z = present_position.position.z;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "z";
       work_status_pub.publish(work_msg);
       write_flag =0;
       cnt++;
     }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");

     kinematics_msg.position.x = present_position.position.x -0.0002*test;
     kinematics_msg.position.y = present_position.position.y - 0.006;
     kinematics_msg.position.z = present_position.position.z +0.006;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "z";
     alp.data=work_msg.data;
     work_status_pub.publish(work_msg);
     write_flag =0;

     if(test>6)
     {
       ROS_INFO("start!!!");
       next_page_flag=1;
       write_flag =1;
       OpenManipulatorSub::next_page_touch_function();
     }
     else
     {

       cnt++;
     }
   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("11");
    //   kinematics_msg.position.x = present_position.position.x;
     OpenManipulatorSub::next_position_set();

     if(test<7)
     {
       std_msgs::String work_msg;
       work_msg.data = "z";
       work_status_pub.publish(work_msg);
       point_kinematics_msg_pub.publish(kinematics_msg);
       write_flag =0;
       cnt =0;
     }
     else if(test>6  && flag==0)
     {

       ROS_INFO("initial position");
       std_msgs::String ini_msg;
       ini_msg.data = "ini_pose";
       ini_msg_pub.publish(ini_msg);
       cnt = 0;
       write_flag =0;
       test = 0;
       count_num  = 0;
       count_num2 = 0;
       red_cnt=0;
       blue_cnt=0;
       cnt2;
       next_cnt=0;

       int count =0;
       for(int i=0; i<1000; i++)
       {
         ROS_INFO("wait");
         count++;
         if(i==100)
         {
           ROS_INFO("initial position");
           std_msgs::String ini_msg;
           ini_msg.data = "ini_pose";
           ini_msg_pub.publish(ini_msg);
           break;
         }
       }
     }
    }
  }
 }
}




