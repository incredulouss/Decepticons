//#include <motors.h>


 #include "pins.h"
 #include "otors.h"

  otors Motors;     //object of the motors clss
int count = 0;
  void setup() 
  {

    Serial.begin(9600);
    IRinit();
    distanceInit();
    calibrateSensors();
    delay(5000);
    //printReadLine();
  }
  
  void loop()
  {
    
   runAll();
    int a =  getMidDistance();
    if(a<450)
    {
      state = RIGHT_WALL_FOLLOW;
    }


 }


 
  
  
