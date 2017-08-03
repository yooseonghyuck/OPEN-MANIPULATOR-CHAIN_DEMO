#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <std_msgs/String.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>

///////////////////////////////////////
#define KEYCODE_dot 0x2e
#define KEYCODE_0 0x30
#define KEYCODE_1 0X31
#define KEYCODE_2 0X32
#define KEYCODE_3 0X33
#define KEYCODE_4 0X34
#define KEYCODE_5 0X35
#define KEYCODE_6 0X36
#define KEYCODE_7 0X37
#define KEYCODE_8 0x38
#define KEYCODE_9 0x39
#define KEYCODE_a 0x61
#define KEYCODE_b 0x62
#define KEYCODE_c 0x63
#define KEYCODE_d 0x64
#define KEYCODE_e 0x65
#define KEYCODE_f 0x66
#define KEYCODE_g 0x67
#define KEYCODE_h 0x68
#define KEYCODE_i 0x69
#define KEYCODE_j 0x6a
#define KEYCODE_k 0x6b
#define KEYCODE_l 0x6c
#define KEYCODE_m 0x6d
#define KEYCODE_n 0x6e
#define KEYCODE_o 0x6f
#define KEYCODE_p 0x70
#define KEYCODE_q 0x71
#define KEYCODE_r 0x72
#define KEYCODE_s 0x73
#define KEYCODE_t 0x74
#define KEYCODE_u 0x75
#define KEYCODE_v 0x76
#define KEYCODE_w 0x77
#define KEYCODE_x 0x78
#define KEYCODE_y 0x79
#define KEYCODE_z 0x7a

class TeleopArm
{
public:
  TeleopArm();
  void keyLoop();
  /////////value//////
  std_msgs::String mssg;

private:


  ros::NodeHandle nh_;
  double linear_x, linear_y, linear_z, l_scale_, a_scale_;
  int flag;
  ros::Publisher twist_pub_;
  ros::Publisher alp_pub_;

};

TeleopArm::TeleopArm():
  linear_x(0),
  linear_y(0),
  linear_z(0),
  l_scale_(2.0)
  //ly_scale_(2.0)
{
  nh_.param("scale_linear_x", l_scale_, l_scale_);
  nh_.param("scale_linear_y", l_scale_, l_scale_);
  nh_.param("scale_linear_z", l_scale_, l_scale_);

  twist_pub_ = nh_.advertise<geometry_msgs::Pose>("open_manipulator/cmd_keyboard", 1);
  alp_pub_   = nh_.advertise<std_msgs::String>("open_manipulator/alp_keyboard_msg", 1);

  flag =0;
}

int kfd = 0;
struct termios cooked, raw;

void quit(int sig)
{
  (void)sig;
  tcsetattr(kfd, TCSANOW, &cooked);
  ros::shutdown();
  exit(0);
}
///////////////////////////
int getch()
{
  static struct termios oldt, newt;
  tcgetattr( STDIN_FILENO, &oldt);           // save old settings
  newt = oldt;
  newt.c_lflag &= ~(ICANON);                 // disable buffering
  tcsetattr( STDIN_FILENO, TCSANOW, &newt);  // apply new settings

  int c = getchar();  // read character (non-blocking)

  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);  // restore old settings
  return c;
}
/////////////////////////////
int main(int argc, char** argv)
{
/*
  while(true)
  {
    int c = getch();
    ROS_INFO("%d",c);
  }
*/
  ros::init(argc, argv, "teleop_Arm");
  TeleopArm teleop_Arm;

  signal(SIGINT,quit);

  teleop_Arm.keyLoop();

  return(0);

}


void TeleopArm::keyLoop()
{
  char c;
  bool dirty=false;


  // get the console in raw mode
  tcgetattr(kfd, &cooked);
  memcpy(&raw, &cooked, sizeof(struct termios));
  raw.c_lflag &=~ (ICANON | ECHO);
  // Setting a new line, then end of file
  raw.c_cc[VEOL] = 1;
  raw.c_cc[VEOF] = 2;
  tcsetattr(kfd, TCSANOW, &raw);

  puts("Reading from keyboard");
  puts("---------------------------");
  puts("Use arrow keys to move the maipulator.");


  for(;;)
  {
    // get the next event from the keyboard
    if(read(kfd, &c, 1) < 0)
    {
      perror("read():");
      exit(-1);
    }

    linear_x=linear_y=0;
    ROS_DEBUG("value: 0x%02X\n", c);

    switch(c)
    {
      case KEYCODE_8:
        ROS_DEBUG("UP");
        linear_x = -1.0;
        linear_y =  0.0;
        linear_z =  0.0;
        dirty = true;
        break;
      case KEYCODE_6:
        ROS_DEBUG("RIGHT");
        linear_x = 0.0;
        linear_y = 1.0;
        linear_z =  0.0;
        dirty = true;
        break;
      case KEYCODE_2:
        ROS_DEBUG("DOWN");
        linear_x = 1.0;
        linear_y = 0.0;
        linear_z =  0.0;
        dirty = true;
        break;
      case KEYCODE_4:
        ROS_DEBUG("LEFT");
        linear_x = 0.0;
        linear_y = -1.0;
        linear_z =  0.0;
        dirty = true;
        break;
      case KEYCODE_9:
        ROS_DEBUG("RIGHT & UP");
        linear_x =  -1.0;
        linear_y =  0.0;
        linear_z =  1.0;
        dirty = true;
        break;
      case KEYCODE_3:
        ROS_DEBUG("RIGHT & DOWN");
        linear_x =  1.0;
        linear_y =  0.0;
        linear_z =  -1.0;
        dirty = true;
        break;
      case KEYCODE_7:
        ROS_DEBUG("LEFT & UP");
        linear_x =  1.0;
        linear_y =  0.0;
        linear_z =  1.0;
        dirty = true;
        break;
      case KEYCODE_1:
        ROS_DEBUG("LEFT & DOWN");
        linear_x =  -1.0;
        linear_y =  0.0;
        linear_z =  -1.0;
        dirty = true;
        break;
      case KEYCODE_5:
        ROS_DEBUG("initialize");
        linear_x =  1.0;
        linear_y =  1.0;
        linear_z =  0.0;
        dirty = true;
        break;
      case KEYCODE_0:
        ROS_DEBUG("z position up");
        linear_x =  0.0;
        linear_y =  0.0;
        linear_z =  1.0;
        dirty = true;
        break;
      case KEYCODE_dot:
        ROS_DEBUG("z position down");
        linear_x =  0.0;
        linear_y =  1.0;
        linear_z =  1.0;
        dirty = true;
        break;
      case KEYCODE_a:
        ROS_DEBUG("write a");
        mssg.data = "a";
        flag =1;
        break;
      case KEYCODE_b:
        ROS_DEBUG("write b");
        mssg.data = "b";
        flag =1;
        break;
      case KEYCODE_c:
        ROS_DEBUG("write c");
        mssg.data = "c";
        flag =1;
        break;
      case KEYCODE_d:
        ROS_DEBUG("write d");
        mssg.data = "d";
        flag =1;
        break;
      case KEYCODE_e:
        ROS_DEBUG("write e");
        mssg.data = "e";
        flag =1;
        break;
      case KEYCODE_f:
        ROS_DEBUG("write f");
        mssg.data = "f";
        flag =1;
        break;
      case KEYCODE_g:
        ROS_DEBUG("write g");
        mssg.data = "g";
        flag =1;
        break;
      case KEYCODE_h:
        ROS_DEBUG("write h");
        mssg.data = "h";
        flag =1;
        break;
      case KEYCODE_i:
        ROS_DEBUG("write i");
        mssg.data = "i";
        flag =1;
        break;
      case KEYCODE_j:
        ROS_DEBUG("write j");
        mssg.data = "j";
        flag =1;
        break;
      case KEYCODE_k:
        ROS_DEBUG("write k");
        mssg.data = "k";
        flag =1;
        break;
      case KEYCODE_l:
        ROS_DEBUG("write l");
        mssg.data = "l";
        flag =1;
        break;
      case KEYCODE_m:
        ROS_DEBUG("write m");
        mssg.data = "m";
        flag =1;
        break;
      case KEYCODE_n:
        ROS_DEBUG("write n");
        mssg.data = "n";
        flag =1;
        break;
      case KEYCODE_o:
        ROS_DEBUG("write o");
        mssg.data = "o";
        flag =1;
        break;
      case KEYCODE_p:
        ROS_DEBUG("write p");
        mssg.data = "p";
        flag =1;
        break;
      case KEYCODE_q:
        ROS_DEBUG("write q");
        mssg.data = "q";
        flag =1;
        break;
      case KEYCODE_r:
        ROS_DEBUG("write r");
        mssg.data = "r";
        flag =1;
        break;
      case KEYCODE_s:
        ROS_DEBUG("write s");
        mssg.data = "s";
        flag =1;
        break;
      case KEYCODE_t:
        ROS_DEBUG("write t");
        mssg.data = "t";
        flag =1;
        break;
      case KEYCODE_u:
        ROS_DEBUG("write u");
        mssg.data = "u";
        flag =1;
        break;
      case KEYCODE_v:
        ROS_DEBUG("write v");
        mssg.data = "v";
        flag =1;
        break;
      case KEYCODE_w:
        ROS_DEBUG("write w");
        mssg.data = "w";
        flag =1;
        break;
      case KEYCODE_x:
        ROS_DEBUG("write x");
        mssg.data = "x";
        flag =1;
        break;
      case KEYCODE_y:
        ROS_DEBUG("write y");
        mssg.data = "y";
        flag =1;
        break;
      case KEYCODE_z:
        ROS_DEBUG("write z");
        mssg.data = "z";
        flag =1;
        break;


    }


    geometry_msgs::Pose posi;
    posi.position.x = linear_x;
        // a_scale_*angular_;
    posi.position.y = linear_y;
        //l_scale_*linear_;
    posi.position.z = linear_z;

    std_msgs::String alp_msg;
    alp_msg.data = mssg.data;

    if(dirty ==true)
    {
      twist_pub_.publish(posi);

      dirty=false;
    }
    else if(flag ==1)
    {
      alp_pub_.publish(alp_msg);
      flag =0;
    }
  }


  return;
}
