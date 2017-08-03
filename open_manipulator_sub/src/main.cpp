
#include "open_manipulator_sub/open_manipulator_sub.h"

int main( int argc , char **argv )
{
  ros::init( argc , argv , "open_manipulator_sub" );
  ROS_INFO("[Start] open_manipulator_sub");

  robotis_test::OpenManipulatorSub robotis;
  robotis.initialize();

  ros::Rate loop_rate(10);

  while (ros::ok())
  {

    robotis.process();

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
