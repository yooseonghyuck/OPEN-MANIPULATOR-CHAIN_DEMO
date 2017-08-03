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

 //write_msg_pub      = ros_node_.advertise<std_msgs::String>("/robotis/base/write_msg",100);
  ini_msg_pub         = ros_node_.advertise<std_msgs::String>("/robotis/base/ini_pose_msg", 100);

  work_status_pub     = ros_node_.advertise<std_msgs::String>("robotis/base/work_status_msg",100);

  grip_joint_sub_pub_ = ros_node_.advertise<std_msgs::Float64>("/open_manipulator_chain/grip_joint_sub_position/command", 100);

  write_status_sub    = ros_node_.subscribe("/robotis/base/write_status_msg", 100, &OpenManipulatorSub::StatsuMsgCallback, this);

  write_msg_sub       = ros_node_.subscribe("/robotis/base/write_msg", 100, &OpenManipulatorSub::msgCallback, this);

  alp_msg_sub         = ros_node_.subscribe("open_manipulator/alp_keyboard_msg", 100, &OpenManipulatorSub::alpMsgCallback, this);
  keyboard_msg_sub    = ros_node_.subscribe("/open_manipulator/cmd_keyboard", 100, &OpenManipulatorSub::KeyboardmsgCallback, this);

  present_pos_msg_sub = ros_node_.subscribe("/robotis/base/present_pos_msg", 100, &OpenManipulatorSub::PresentPositionMsgCallback, this);

  next_msg_sub        = ros_node_.subscribe("/robotis/base/next_work_msg",100, &OpenManipulatorSub::NextMsgCallback,this);
  /**value**/


  cnt=0;
  cnt2=0;
  write_flag = 0;
  count_num = 0;
  flag=0;
  flag_ver=0;
  count_num2 = 0;
  test =0;

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

}

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
       kinematics_msg.position.x = 0.076;
       kinematics_msg.position.y = -0.05;
       kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;
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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;
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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
        kinematics_msg.position.x = 0.076;
        kinematics_msg.position.y = -0.05;
        kinematics_msg.position.z = 0.102;

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
     cnt2;
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
         kinematics_msg.position.z = 0.0445 - test*0.0009 ;
       }
       else
       {
         kinematics_msg.position.z = 0.043 - test*0.0004;
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
   // ROS_INFO("13");
    ROS_INFO("14");
   //   kinematics_msg.position.x = present_position.position.x;
    if(test <4)
    {
      if(test ==2)
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
      kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
    }
    else if(test == 5)
    {
      kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
    }
    else if(test ==6)
    {
      kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
    }
    else
    {
      kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
    }



    if(test == 1)
    {
       kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
       kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
    }
    else if(test >6)
    {


      kinematics_msg.position.y =  0.0;

      test = 0;
    }
    else
    {

        kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
    }
    kinematics_msg.position.z = 0.060;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "a";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt =0;
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


         if(test==2)
         {
           kinematics_msg.position.z = 0.0445 - test*0.0009 ;
         }
         else
         {
           kinematics_msg.position.z = 0.043 - test*0.0004;
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

    kinematics_msg.position.x = present_position.position.x +0.008;
    kinematics_msg.position.y = present_position.position.y;
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

    kinematics_msg.position.x = present_position.position.x +0.0075;
    kinematics_msg.position.y = present_position.position.y -0.0020;
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
   // ROS_INFO("13");
    ROS_INFO("13");
   //   kinematics_msg.position.x = present_position.position.x;
    if(test <4)
    {
      if(test ==2)
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
      kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
    }
    else if(test == 5)
    {
      kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
    }
    else if(test ==6)
    {
      kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
    }
    else
    {
      kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
    }



    if(test == 1)
    {
       kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
       kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
    }
    else if(test >6)
    {


      kinematics_msg.position.y =  0.0;

      test = 0;
    }
    else
    {

        kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
    }
    kinematics_msg.position.z = 0.060;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "b";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt =0;
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


         if(test==2)
         {
           kinematics_msg.position.z = 0.0445 - test*0.0009 ;
         }
         else
         {
           kinematics_msg.position.z = 0.043 - test*0.0004;
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

     kinematics_msg.position.x = present_position.position.x +0.0015;
     kinematics_msg.position.y = present_position.position.y +0.0008;
     kinematics_msg.position.z = present_position.position.z -0.0001;

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

     kinematics_msg.position.x = present_position.position.x -0.004;
     kinematics_msg.position.y = present_position.position.y -0.001;
     kinematics_msg.position.z = present_position.position.z -0.0001;

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
     kinematics_msg.position.z = present_position.position.z +0.001;

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

     kinematics_msg.position.x = present_position.position.x +0.001;
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
    // ROS_INFO("13");
     ROS_INFO("13");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "c";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt =0;
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
           kinematics_msg.position.z = 0.0445 - test*0.0009 ;
         }
         else
         {
           kinematics_msg.position.z = 0.043 - test*0.0004;
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
     kinematics_msg.position.z = present_position.position.z- 0.007;

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

     kinematics_msg.position.x = present_position.position.x +0.008;
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


     kinematics_msg.position.x = present_position.position.x -0.0065;

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

     kinematics_msg.position.x = present_position.position.x +0.003;
     kinematics_msg.position.y = present_position.position.y +0.004;
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
     ROS_INFO("13");

     kinematics_msg.position.x = present_position.position.x + 0.001;
     kinematics_msg.position.y = present_position.position.y +0.0014 + 0.0005*test;
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
     ROS_INFO("14");

     kinematics_msg.position.x = present_position.position.x +0.0065;
     kinematics_msg.position.y = present_position.position.y +0.0012;
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
     // ROS_INFO("13");
      ROS_INFO("15");
     //   kinematics_msg.position.x = present_position.position.x;
      if(test <4)
      {
        if(test ==2)
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
        kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
      }
      else if(test == 5)
      {
        kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
      }
      else if(test ==6)
      {
        kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
      }
      else
      {
        kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
      }



      if(test == 1)
      {
         kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
         kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
      }
      else if(test >6)
      {


        kinematics_msg.position.y =  0.0;

        test = 0;
      }
      else
      {

          kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
      }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "d";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt =0;
   }
 }
 else if(Alp_msg.data == "e")////////////////////////////////////////////////////////////
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
           kinematics_msg.position.z = 0.0445 - test*0.0009 ;
         }
         else
         {
           kinematics_msg.position.z = 0.043 - test*0.0004;
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

     kinematics_msg.position.x = present_position.position.x +0.014 - test*0.0012;
     kinematics_msg.position.y = present_position.position.y +0.005;
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
     kinematics_msg.position.z = present_position.position.z- 0.007;

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
        kinematics_msg.position.x = present_position.position.x -0.0015;
     }
     else if(test==2)
     {
       kinematics_msg.position.x = present_position.position.x -0.0012;
     }
     else
     {
        kinematics_msg.position.x = present_position.position.x -0.0045;
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
        kinematics_msg.position.x = present_position.position.x -0.006;
     }
     else
     {
       kinematics_msg.position.x = present_position.position.x -0.008;
     }
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.001;

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
        kinematics_msg.position.x = present_position.position.x -0.0010;
     }
     else
     {
       kinematics_msg.position.x = present_position.position.x -0.0015;
     }

     kinematics_msg.position.y = present_position.position.y +0.0005;


     kinematics_msg.position.z = present_position.position.z -0.001;

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
     if(test>2)
     {
        kinematics_msg.position.x = present_position.position.x -0.004;
     }
     else
     {
       kinematics_msg.position.x = present_position.position.x -0.008;
     }

      kinematics_msg.position.y = present_position.position.y;

     kinematics_msg.position.z = present_position.position.z -0.001;

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

     kinematics_msg.position.x = present_position.position.x -0.0025;
     kinematics_msg.position.y = present_position.position.y +0.0025;
     kinematics_msg.position.z = present_position.position.z -0.001;

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

     kinematics_msg.position.x = present_position.position.x; // +? -?
     kinematics_msg.position.y = present_position.position.y +0.003 +0.0005*test;
     kinematics_msg.position.z = present_position.position.z -0.001;

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

     kinematics_msg.position.x = present_position.position.x +0.0085;
     kinematics_msg.position.y = present_position.position.y +0.0015 +0.0005*test;
     kinematics_msg.position.z = present_position.position.z -0.001;

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

     kinematics_msg.position.x = present_position.position.x +0.0045;
     kinematics_msg.position.y = present_position.position.y +0.0005;
     kinematics_msg.position.z = present_position.position.z +0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;

   }
   else if(cnt==14 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("16");

     kinematics_msg.position.x = present_position.position.x +0.009; // +? -?
     kinematics_msg.position.y = present_position.position.y -0.008 -0.0005*test;
     kinematics_msg.position.z = present_position.position.z +0.004;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }

   else if(cnt==15 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("17");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "e";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
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
           kinematics_msg.position.z = 0.0445 - test*0.0009 ;
         }
         else
         {
           kinematics_msg.position.z = 0.043 - test*0.0004;
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
     kinematics_msg.position.z = present_position.position.z- 0.011;

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
    // ROS_INFO("13");
     ROS_INFO("17");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "f";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
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
        kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.043 - test*0.0004;
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
    kinematics_msg.position.x = present_position.position.x +0.001 +(0.0003*test);
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
    kinematics_msg.position.x = present_position.position.x -0.001-(0.00037*test);
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
    // ROS_INFO("13");
     ROS_INFO("19");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "g";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
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


        if(test==2)
        {
          kinematics_msg.position.z = 0.0445 - test*0.0009 ;
        }
        else
        {
          kinematics_msg.position.z = 0.043 - test*0.0004;
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
    kinematics_msg.position.z = present_position.position.z -0.002;

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

    kinematics_msg.position.x = present_position.position.x -0.004;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z +0.006;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "h";
    work_status_pub.publish(work_msg);
    write_flag =0;
    cnt++;
  }
  else if(cnt==8 && write_flag ==1 && flag ==0)
  {
   // ROS_INFO("13");
    ROS_INFO("10");
   //   kinematics_msg.position.x = present_position.position.x;
    if(test <4)
    {
      if(test ==2)
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
      kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
    }
    else if(test == 5)
    {
      kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
    }
    else if(test ==6)
    {
      kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
    }
    else
    {
      kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
    }



    if(test == 1)
    {
       kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
       kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
    }
    else if(test >6)
    {


      kinematics_msg.position.y =  0.0;

      test = 0;
    }
    else
    {

        kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
    }
    kinematics_msg.position.z = 0.060;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "h";
    work_status_pub.publish(work_msg);

    write_flag =0;
    cnt =0;
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


        if(test==2)
        {
          kinematics_msg.position.z = 0.0445 - test*0.0009 ;
        }
        else
        {
          kinematics_msg.position.z = 0.043 - test*0.0004;
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

     kinematics_msg.position.x = present_position.position.x +0.0007 + 0.0001*(test);
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
    // ROS_INFO("13");
     ROS_INFO("10");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "i";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
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
        kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.043 - test*0.0004;
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

     kinematics_msg.position.x = present_position.position.x +0.0003;
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
     kinematics_msg.position.z = present_position.position.z-0.009;

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
    // ROS_INFO("13");
     ROS_INFO("13");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "j";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
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


      if(test==2)
      {
        kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.043 - test*0.0004;
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
    kinematics_msg.position.y = present_position.position.y -0.00527;
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
    kinematics_msg.position.y = present_position.position.y +0.004 + (test-1)*0.001;
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
   // ROS_INFO("13");
    ROS_INFO("8");
   //   kinematics_msg.position.x = present_position.position.x;
    if(test <4)
    {
      if(test ==2)
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
      kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
    }
    else if(test == 5)
    {
      kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
    }
    else if(test ==6)
    {
      kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
    }
    else
    {
      kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
    }



    if(test == 1)
    {
       kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
       kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
    }
    else if(test >6)
    {


      kinematics_msg.position.y =  0.0;

      test = 0;
    }
    else
    {

        kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
    }
    kinematics_msg.position.z = 0.060;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "k";
    work_status_pub.publish(work_msg);

    write_flag =0;
    cnt =0;
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
        kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.043 - test*0.0004;
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
     kinematics_msg.position.z = present_position.position.z - 0.001;

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

     kinematics_msg.position.x = present_position.position.x +0.012;
     kinematics_msg.position.y = present_position.position.y;
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
    // ROS_INFO("13");
     ROS_INFO("6");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "l";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
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
          kinematics_msg.position.z = 0.0445 - test*0.0009 ;
        }
        else
        {
          kinematics_msg.position.z = 0.043 - test*0.0004;
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
      kinematics_msg.position.z = present_position.position.z-0.005;

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

      kinematics_msg.position.x = present_position.position.x +0.006;
      kinematics_msg.position.y = present_position.position.y;
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

      kinematics_msg.position.x = present_position.position.x -0.0075;
      kinematics_msg.position.y = present_position.position.y +0.0015;
      kinematics_msg.position.z = present_position.position.z -0.0005;

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

      kinematics_msg.position.x = present_position.position.x +0.0045 ;
      kinematics_msg.position.y = present_position.position.y +0.0010;
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
      kinematics_msg.position.y = present_position.position.y +0.0025;
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
      kinematics_msg.position.y = present_position.position.y +0.002 +test*0.0002;
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

      kinematics_msg.position.x = present_position.position.x +0.0045;
      kinematics_msg.position.y = present_position.position.y +0.0010;
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

      kinematics_msg.position.x = present_position.position.x +0.0055;
      kinematics_msg.position.y = present_position.position.y -0.0009;
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

       kinematics_msg.position.x = present_position.position.x -0.0055;
       kinematics_msg.position.y = present_position.position.y +0.0009;
       kinematics_msg.position.z = present_position.position.z +0.005;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "m";
       work_status_pub.publish(work_msg);
       write_flag =0;
       cnt++;
     }
    else if(cnt==15 && write_flag ==1 && flag ==0)
    {
     // ROS_INFO("13");
      ROS_INFO("17");
     //   kinematics_msg.position.x = present_position.position.x;
      if(test <4)
      {
        if(test ==2)
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
        kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
      }
      else if(test == 5)
      {
        kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
      }
      else if(test ==6)
      {
        kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
      }
      else
      {
        kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
      }



      if(test == 1)
      {
         kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
         kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
      }
      else if(test >6)
      {


        kinematics_msg.position.y =  0.0;

        test = 0;
      }
      else
      {

          kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
      }
      kinematics_msg.position.z = 0.060;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "m";
      work_status_pub.publish(work_msg);

      write_flag =0;
      cnt =0;
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
          kinematics_msg.position.z = 0.0445 - test*0.0009 ;
        }
        else
        {
          kinematics_msg.position.z = 0.043 - test*0.0004;
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
      kinematics_msg.position.z = present_position.position.z-0.005;

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

       kinematics_msg.position.x = present_position.position.x +0.004;
       kinematics_msg.position.y = present_position.position.y +0.0013;
       kinematics_msg.position.z = present_position.position.z +0.005;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "n";
       work_status_pub.publish(work_msg);
       write_flag =0;
       cnt++;
     }
    else if(cnt==11 && write_flag ==1 && flag ==0)
    {
     // ROS_INFO("13");
      ROS_INFO("13");
     //   kinematics_msg.position.x = present_position.position.x;
      if(test <4)
      {
        if(test ==2)
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
        kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
      }
      else if(test == 5)
      {
        kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
      }
      else if(test ==6)
      {
        kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
      }
      else
      {
        kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
      }



      if(test == 1)
      {
         kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
         kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
      }
      else if(test >6)
      {


        kinematics_msg.position.y =  0.0;

        test = 0;
      }
      else
      {

          kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
      }
      kinematics_msg.position.z = 0.060;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "n";
      work_status_pub.publish(work_msg);

      write_flag =0;
      cnt =0;
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


        if(test==2)
        {
          kinematics_msg.position.z = 0.0445 - test*0.0009 ;
        }
        else
        {
          kinematics_msg.position.z = 0.0445 - test*0.0004;
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
       work_status_pub.publish(work_msg);
       write_flag =0;
       cnt++;
     }
     else if(cnt==10 && write_flag ==1 && flag ==0)
     {
      // ROS_INFO("13");
       ROS_INFO("12");
      //   kinematics_msg.position.x = present_position.position.x;
       if(test <4)
       {
         if(test ==2)
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
         kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
       }
       else if(test == 5)
       {
         kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
       }
       else if(test ==6)
       {
         kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
       }
       else
       {
         kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
       }



       if(test == 1)
       {
          kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
          kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
       }
       else if(test >6)
       {


         kinematics_msg.position.y =  0.0;

         test = 0;
       }
       else
       {

           kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
       }
       kinematics_msg.position.z = 0.060;

       point_kinematics_msg_pub.publish(kinematics_msg);

       std_msgs::String work_msg;
       work_msg.data = "o";
       work_status_pub.publish(work_msg);

       write_flag =0;
       cnt =0;
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
        kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.043 - test*0.0004;
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
     kinematics_msg.position.y = present_position.position.y +0.0017 + (test*0.0003);
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
     kinematics_msg.position.y = present_position.position.y -0.0050 - (test*0.0003);
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

     kinematics_msg.position.x = present_position.position.x +0.012;
     kinematics_msg.position.y = present_position.position.y;
     kinematics_msg.position.z = present_position.position.z -0.0008;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "p";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("11");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "p";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
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
        kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.043 - test*0.0004;
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
     kinematics_msg.position.z = present_position.position.z- 0.01;

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

     kinematics_msg.position.x = present_position.position.x -0.004;
     kinematics_msg.position.y = present_position.position.y +0.003;
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
     kinematics_msg.position.y = present_position.position.y +0.0045;
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
     kinematics_msg.position.z = present_position.position.z +0.0015;

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
     kinematics_msg.position.y = present_position.position.y +0.001;
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

     kinematics_msg.position.x = present_position.position.x +0.006;
     kinematics_msg.position.y = present_position.position.y -0.0025;
     kinematics_msg.position.z = present_position.position.z +0.0015;

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

     kinematics_msg.position.x = present_position.position.x +0.009;
     kinematics_msg.position.y = present_position.position.y -0.0008;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==14 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("16");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "q";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
    }
 }
   if(Alp_msg.data == "r")
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
          kinematics_msg.position.z = 0.0445 - test*0.0009 ;
        }
        else
        {
          kinematics_msg.position.z = 0.043 - test*0.0004;
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
      kinematics_msg.position.z = present_position.position.z-0.007;

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

      kinematics_msg.position.x = present_position.position.x -0.0085;
      kinematics_msg.position.y = present_position.position.y +0.0020;
      kinematics_msg.position.z = present_position.position.z -0.0005;

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

      kinematics_msg.position.x = present_position.position.x +0.004;
      kinematics_msg.position.y = present_position.position.y -0.004;
      kinematics_msg.position.z = present_position.position.z +0.01;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "r";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("11");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "r";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
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
         kinematics_msg.position.z = 0.0445 - test*0.0009 ;
       }
       if(test ==4)
       {
         kinematics_msg.position.z = 0.043 - test*0.00015;
       }
       else
       {
         kinematics_msg.position.z = 0.043 - test*0.00046;
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
       kinematics_msg.position.y = present_position.position.y + 0.0040 + test*0.001;
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
      kinematics_msg.position.z = present_position.position.z- 0.0075;

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

      kinematics_msg.position.x = present_position.position.x + 0.0025 + 0.00025*test;
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

      kinematics_msg.position.x = present_position.position.x-0.0008+ test*0.0005;
      kinematics_msg.position.y = present_position.position.y - 0.009+ test*0.0004;
      kinematics_msg.position.z = present_position.position.z+0.002;

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

      kinematics_msg.position.x = present_position.position.x-0.001- test*0.0006;
      kinematics_msg.position.y = present_position.position.y - 0.006+ test*0.00015;
      kinematics_msg.position.z = present_position.position.z+0.002;

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

      kinematics_msg.position.x = present_position.position.x+0.001- test*0.0006;
      kinematics_msg.position.y = present_position.position.y + 0.006+ test*0.00015;
      kinematics_msg.position.z = present_position.position.z+0.006;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
    else if(cnt==14 && write_flag ==1 && flag ==0)
    {
     // ROS_INFO("13");
      ROS_INFO("16");
     //   kinematics_msg.position.x = present_position.position.x;
      if(test <4)
      {
        if(test ==2)
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
        kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
      }
      else if(test == 5)
      {
        kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
      }
      else if(test ==6)
      {
        kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
      }
      else
      {
        kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
      }



      if(test == 1)
      {
         kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
         kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
      }
      else if(test >6)
      {


        kinematics_msg.position.y =  0.0;

        test = 0;
      }
      else
      {

          kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
      }
      kinematics_msg.position.z = 0.060;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "s";
      work_status_pub.publish(work_msg);

      write_flag =0;
      cnt =0;
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


      if(test==2)
      {
        kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.043 - test*0.0004;
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
    kinematics_msg.position.x = present_position.position.x +0.012;
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
    kinematics_msg.position.x = present_position.position.x -0.009;
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
    kinematics_msg.position.z = present_position.position.z -0.0045;
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
   // ROS_INFO("13");
    ROS_INFO("10");
   //   kinematics_msg.position.x = present_position.position.x;
    if(test <4)
    {
      if(test ==2)
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
      kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
    }
    else if(test == 5)
    {
      kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
    }
    else if(test ==6)
    {
      kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
    }
    else
    {
      kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
    }



    if(test == 1)
    {
       kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
       kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
    }
    else if(test >6)
    {


      kinematics_msg.position.y =  0.0;

      test = 0;
    }
    else
    {

        kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
    }
    kinematics_msg.position.z = 0.060;

    point_kinematics_msg_pub.publish(kinematics_msg);

    std_msgs::String work_msg;
    work_msg.data = "t";
    work_status_pub.publish(work_msg);

    write_flag =0;
    cnt =0;
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
        kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.043 - test*0.0004;
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

    kinematics_msg.position.x = present_position.position.x;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z+0.005;

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

    kinematics_msg.position.x = present_position.position.x+0.0025;
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z;

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
    kinematics_msg.position.y = present_position.position.y;
    kinematics_msg.position.z = present_position.position.z-0.0065;

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

     kinematics_msg.position.x = present_position.position.x +0.0075 -test*0.0005;
     kinematics_msg.position.y = present_position.position.y -0.0023 +test*0.0003;
     kinematics_msg.position.z = present_position.position.z -0.0005;

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

     kinematics_msg.position.x = present_position.position.x +0.0005;
     kinematics_msg.position.y = present_position.position.y +0.006;
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

     kinematics_msg.position.x = present_position.position.x -0.0105;
     kinematics_msg.position.y = present_position.position.y +0.0015;
     kinematics_msg.position.z = present_position.position.z -0.0005;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "u";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");

     kinematics_msg.position.x = present_position.position.x -0.0027;
     kinematics_msg.position.y = present_position.position.y +0.0013;
     kinematics_msg.position.z = present_position.position.z -0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "u";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("10");

     kinematics_msg.position.x = present_position.position.x +0.0027;
     kinematics_msg.position.y = present_position.position.y +0.0026;
     kinematics_msg.position.z = present_position.position.z +0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "u";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
     ROS_INFO("11");

     kinematics_msg.position.x = present_position.position.x +0.0135;
     kinematics_msg.position.y = present_position.position.y -0.0006 - test*0.0003;
     kinematics_msg.position.z = present_position.position.z +0.001;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "u";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
    else if(cnt==10 && write_flag ==1 && flag ==0)
    {
      ROS_INFO("12");

      kinematics_msg.position.x = present_position.position.x -0.01;
      kinematics_msg.position.y = present_position.position.y -0.0006;
      kinematics_msg.position.z = present_position.position.z +0.008;

      point_kinematics_msg_pub.publish(kinematics_msg);

      std_msgs::String work_msg;
      work_msg.data = "u";
      work_status_pub.publish(work_msg);
      write_flag =0;
      cnt++;
    }
   else if(cnt==11 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("13");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "u";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
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


      if(test==2)
      {
        kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else if(test ==4)
      {
        kinematics_msg.position.z = 0.0445 - test*0.0009;
      }
      else
      {
        kinematics_msg.position.z = 0.043 - test*0.0004;
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
    kinematics_msg.position.z = present_position.position.z-0.0065;

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
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==8 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("10");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "v";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
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


      if(test==2)
      {
        kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.043 - test*0.0003;
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
    kinematics_msg.position.z = present_position.position.z-0.0065;

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

     kinematics_msg.position.x = present_position.position.x +0.0075 -test*0.0005;
     kinematics_msg.position.y = present_position.position.y +0.0023 -test*0.0003;
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
     kinematics_msg.position.y = present_position.position.y +0.0023 -test*0.00015;
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
      kinematics_msg.position.y = present_position.position.y +0.0023 -test*0.0005;
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
      kinematics_msg.position.y = present_position.position.y +0.0023 -test*0.00015;
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
     kinematics_msg.position.y = present_position.position.y -0.0013+test*0.00015;
     kinematics_msg.position.z = present_position.position.z +0.006;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "w";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==10 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("12");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "w";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
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


      if(test==2)
      {
        kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.0430 - test*0.0003;
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
    // ROS_INFO("13");
     ROS_INFO("12");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "x";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
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


      if(test==2)
      {
        kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.043 - test*0.0004;
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
     work_msg.data = "z";
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
     kinematics_msg.position.z = present_position.position.z-0.006;

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

     kinematics_msg.position.x = present_position.position.x +0.0055;
     kinematics_msg.position.y = present_position.position.y +0.0025;
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

     kinematics_msg.position.x = present_position.position.x -0.005 -0.0002*test;
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
     kinematics_msg.position.y = present_position.position.y -0.0055 -test*0.0002;
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

     kinematics_msg.position.x = present_position.position.x +0.0025;
     kinematics_msg.position.y = present_position.position.y +0.0015 -test*0.0002;
     kinematics_msg.position.z = present_position.position.z +0.006;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "y";
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==12 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("14");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "y";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
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


      if(test==2)
      {
        kinematics_msg.position.z = 0.0445 - test*0.0009 ;
      }
      else
      {
        kinematics_msg.position.z = 0.043 - test*0.0004;
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

     kinematics_msg.position.x = present_position.position.x+0.0015;
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
     kinematics_msg.position.y = present_position.position.y + 0.006;
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

     kinematics_msg.position.x = present_position.position.x +0.0050;
     kinematics_msg.position.y = present_position.position.y -0.01 -test*0.0002;
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
       kinematics_msg.position.y = present_position.position.y + 0.008;
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
     work_status_pub.publish(work_msg);
     write_flag =0;
     cnt++;
   }
   else if(cnt==9 && write_flag ==1 && flag ==0)
   {
    // ROS_INFO("13");
     ROS_INFO("11");
    //   kinematics_msg.position.x = present_position.position.x;
     if(test <4)
     {
       if(test ==2)
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
       kinematics_msg.position.x =  0.066 + (test-1)*0.0013;
     }
     else if(test == 5)
     {
       kinematics_msg.position.x =  0.066 + (test-1)*0.0012;
     }
     else if(test ==6)
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.00075;
     }
     else
     {
       kinematics_msg.position.x =  0.066 - (test-1)*0.0008;
     }



     if(test == 1)
     {
        kinematics_msg.position.y =  present_position.position.y + (test*0.0105);

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
        kinematics_msg.position.y =  present_position.position.y + (test*0.0018);
     }
     else if(test >6)
     {


       kinematics_msg.position.y =  0.0;

       test = 0;
     }
     else
     {

         kinematics_msg.position.y =  present_position.position.y + (test*0.0036);
     }
     kinematics_msg.position.z = 0.060;

     point_kinematics_msg_pub.publish(kinematics_msg);

     std_msgs::String work_msg;
     work_msg.data = "z";
     work_status_pub.publish(work_msg);

     write_flag =0;
     cnt =0;
    }
  }
 }
}



