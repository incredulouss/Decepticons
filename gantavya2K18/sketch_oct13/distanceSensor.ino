#define LEFT_IR A9
#define MID_IR A8
#define RIGHT_IR A10

#define SAMPLES 5

void distanceInit()
{
  pinMode(LEFT_IR,INPUT);
  pinMode(MID_IR,INPUT);
  pinMode(RIGHT_IR,INPUT);
}

int getRightDistance()
{
  int a=analogReadMedian(LEFT_IR,SAMPLES);
  a=constrain(a,2,600);
  a=map(a,600,2,0,1000);
  return a;
}

int getLeftDistance()
{
  int a=analogReadMedian(RIGHT_IR,SAMPLES);
  a=constrain(a,2,600);
  a=map(a,600,2,0,1000);
  return a;
}
int getMidDistance()
{
  int a=analogReadMedian(MID_IR,SAMPLES);
  a=constrain(a,2,600);
  a=map(a,600,2,0,1000);
  return a;
}

void getAllDistance()
{
  leftd=getLeftDistance();
  midd=getMidDistance();
  rightd=getRightDistance();
}

