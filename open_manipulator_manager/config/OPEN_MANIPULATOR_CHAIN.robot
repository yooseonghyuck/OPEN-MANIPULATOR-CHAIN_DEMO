[ control info ]
control_cycle = 8   # milliseconds

[ port info ]
# PORT NAME  | BAUDRATE
/dev/ttyUSB0 | 1000000  | joint1

[ device info ]
# TYPE    | PORT NAME    | ID  | MODEL       | PROTOCOL | DEV NAME     | BULK READ ITEMS
dynamixel | /dev/ttyUSB0 | 1   | XM-430-W350 | 2.0      | joint1       | present_position
dynamixel | /dev/ttyUSB0 | 2   | XM-430-W350 | 2.0      | joint2       | present_position
dynamixel | /dev/ttyUSB0 | 3   | XM-430-W350 | 2.0      | joint3       | present_position
dynamixel | /dev/ttyUSB0 | 4   | XM-430-W350 | 2.0      | joint4       | present_position
dynamixel | /dev/ttyUSB0 | 5   | XM-430-W350 | 2.0      | grip_joint   | present_position
