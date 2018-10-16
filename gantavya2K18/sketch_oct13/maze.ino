#define LEFT_HAND_MAZE 1
void maze()
{
  pid();
  unsigned char foundLeft=0;
  unsigned char foundRight=0;
  unsigned char foundStraight=0;
  Motors.forward(70);        //70
  delay(15);           //15
  getVal();//2ms delay
    
  if(s[0])
    foundLeft=1;
  if(s[7])
    foundRight=1;
   Motors.forward(40);    //40
  delay(inchDelay);       //40
  getVal();
  if(s[0] && s[7])
    {
      Motors.stp();delay(stopDelay);
     // state= RIGHT_WALL_FOLLOW;
      return;
    }
  if(!VFlag)
    if(s[2] || s[3] || s[4] || s[5])
      foundStraight=1;

  char dir= findTurn(foundLeft,foundRight,foundStraight);
  
  turn(dir);
    
}

char findTurn(unsigned char left,unsigned char right,unsigned char straight)
{
  if(LEFT_HAND_MAZE)
  {
    if(left)
      return 'L';
    else if(straight)
      return 'S';
    else if(right)
      return 'R';
    else
      return 'B';
  }
  else
  {
    if(right)
      return 'R';
    else if(straight)
      return 'S';
    else if(left)
      return 'L';
    else
      return 'B';
  }
}
