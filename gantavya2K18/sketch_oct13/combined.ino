void runAll()
{
  switch(state)
  {
    case MAZE:  maze();
    break;
    case RIGHT_WALL_FOLLOW : followRightWall();
    break;
    case LEFT_WALL_FOLLOW: followLeftWall();
    break;
//    case BLOCK_DETECTION: blinking();
  //  break;
    //case BLINK: blinking();
    //break;
  }
}

