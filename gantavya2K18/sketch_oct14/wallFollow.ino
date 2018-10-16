
#define FRONT_MIN (600)
#define FRONT_MIN_EXTREME (350)
#define WALL_SET_POINT (750)
#define WALL_MAX_DISTANCE (WALL_SET_POINT + 75)
#define WALL_MIN_DISTANCE (WALL_SET_POINT - 75)

#define BASE_SPEED (70)//60   70
#define MIN_SPEED (BASE_SPEED - 20)//20
#define MAX_SPEED (BASE_SPEED + 20 )//20
#define TURN_SPEED (40)

#define Kp (0.3)//0.13   0.3
#define Kdl (8)//0.45   8
#define Kdr (1)//0.45   8

void followLeftWall()
{
//  if(wallSwitch%5 == 0)
//  {
//    getval();
//    if(onWhite == 0)
//    {
//      if((!s[0]) && (!s[7]))
//        onWhite=1;
//    }
//    else
//    {
//      if(s[0] && s[7])
//      {
//        afterWallPID();
//        state=BLOCK_DETECTION;
//        wallSwitch=1;
//        onWhite=0;
//        return;
//      }
//    }
//    wallSwitch=1;
//  }
//  else
//    wallSwitch++;

  midd=getMidDistance();
  if(midd < FRONT_MIN)
  {
     Motors.right(TURN_SPEED); 
     while(midd < (FRONT_MIN+40))
       midd=getMidDistance();
     //stp();delay(70);
  }
  leftPid();
}

void leftPid()
{
  int left_set,right_set;
  leftd=getLeftDistance();
  int proximity = leftd;
  if(leftd > WALL_MAX_DISTANCE)
  {
    left_set = BASE_SPEED;
    right_set = MIN_SPEED-7;//--------------------------------------------------------------------------------------yaha change kiya h
  }
  else
  {
    int error = proximity - WALL_SET_POINT;
    int pd = error * Kp + (leftd-previousLeftd)*Kdl;
    left_set = BASE_SPEED + pd;
    right_set = BASE_SPEED - pd;
    previousLeftd=leftd;

    left_set=(left_set > BASE_SPEED) ? BASE_SPEED : left_set;
    right_set=(right_set > BASE_SPEED) ? BASE_SPEED : right_set;
  
    //left_set=(left_set > MAX_SPEED) ? MAX_SPEED : left_set;
    //right_set=(right_set > MAX_SPEED) ? MAX_SPEED : right_set;
    left_set=(left_set < MIN_SPEED) ? MIN_SPEED : left_set;
    right_set=(right_set < MIN_SPEED) ? MIN_SPEED : right_set;
  }
  digitalWrite(Motors.motorPower, 1); 
  digitalWrite(Motors.rightMotor1, 1);
  digitalWrite(Motors.rightMotor2, 0);
  analogWrite(Motors.rightMotorPWM, left_set);
  digitalWrite(Motors.leftMotor1, 1);
  digitalWrite(Motors.leftMotor2, 0);
  analogWrite(Motors.leftMotorPWM, right_set);
}
void followRightWall()
{

//  if(wallSwitch%5 == 0)
//  {
//    getval();
//    if(onWhite == 0)
//    {
//      if((!s[0]) && (!s[7]))
//        onWhite=1;
//    }
//    else
//    {
//      if(s[0] && s[7])
//      {
//        state=LEFT_WALL_FOLLOW;
//        forward(70);
//        delay(200);
//        wallSwitch=1;
//        onWhite=0;
//        return;
//      }
//    }
//    wallSwitch=1;
//  }
//  else
//    wallSwitch++;

  midd=getMidDistance();
  if(midd < FRONT_MIN)
  {
     Motors.left(TURN_SPEED); 
     while(midd < (FRONT_MIN+40))
       midd=getMidDistance();
     //stp();delay(70);
  }
  else
    rightPid();
}
void rightPid()
{
  static int switchFlag=0;
  int left_set,right_set;
  rightd=getRightDistance();
  if(rightd > WALL_MAX_DISTANCE)
  {
    left_set = MIN_SPEED -(3+4) ;//--------------------------------------------------------------------------------------yaha change kiya h +7 kiya h
    right_set = BASE_SPEED;  
  }
  else
  {
    int proximity = rightd;
    int error = proximity - WALL_SET_POINT;
    int pd = error * Kp + (rightd-previousRightd)*Kdr;
    left_set = BASE_SPEED - pd;
    right_set = BASE_SPEED + pd;
    previousRightd=rightd;

    left_set=(left_set > BASE_SPEED) ? BASE_SPEED : left_set;
    right_set=(right_set > BASE_SPEED) ? BASE_SPEED : right_set;
  
    //left_set=(left_set > MAX_SPEED) ? MAX_SPEED : left_set;
    //right_set=(right_set > MAX_SPEED) ? MAX_SPEED : right_set;
    left_set=(left_set < MIN_SPEED) ? MIN_SPEED : left_set;
    right_set=(right_set < MIN_SPEED) ? MIN_SPEED : right_set;
  }
  digitalWrite(Motors.motorPower, 1); 
  digitalWrite(Motors.rightMotor1, 1);
  digitalWrite(Motors.rightMotor2, 0);
  analogWrite(Motors.rightMotorPWM, left_set);
  digitalWrite(Motors.leftMotor1, 1);
  digitalWrite(Motors.leftMotor2, 0);
  analogWrite(Motors.leftMotorPWM, right_set);
  switchFlag=0;
}
