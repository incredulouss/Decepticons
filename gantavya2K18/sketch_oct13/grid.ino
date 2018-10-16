int counter =0;
int gridVal = 5;

void grid()
{
  pid();
   if(counter == (gridVal* gridVal))
   {
          Motors.stp();delay(stopDelay);
     // state= RIGHT_WALL_FOLLOW;
      return;
    }
  unsigned char foundNode=0;    
  unsigned char foundLeft=0;
  unsigned char foundRight=0;
  unsigned char foundStraight=0;
  Motors.forward(70);        //70
  delay(15);           //15
  getVal();//2ms delay
   if(s[0] && s[7])
   {

     counter++;
   }
   if(s[0] == 1)
    {foundLeft=1;
    
 
 


  
}

