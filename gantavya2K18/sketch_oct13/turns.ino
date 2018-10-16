void rightTurn(){
  getVal();
  Motors.right(turnSpeed);
  while(s[3] || s[4])
  {
    getVal();
  }
  while((!s[3]) || (!s[4]))
  {
    getVal();
  }
}

void leftTurn(){
  getVal();
  Motors.left(turnSpeed);
  while(s[3] || s[4])
  {
   getVal();
  }
  while((!s[3]) || (!s[4]))
  {
    getVal();
  }
}

void turn(char direction)
{
  switch(direction)
  {
  case 'L':
    // Turn left.
    leftTurn();
    break;
  case 'R':
    // Turn right.
    rightTurn();
    break;
  case 'B':
    // Turn around.
    turnAround();
    break;
  case 'S':
    Motors.forward(BaseSpeed);
    delay(10);// Don't do anything!
    break;
  }
  Motors.stp();
  delay(20);
  align();
}

void turnAround(){
  getVal();
  Motors.left(turnSpeed);
  while((!s[3]) || (!s[4]))
  {
    getVal();
  }
}
