int counter =0;
int gridVal = 5;
int temp = 0;
void grid()
{
  pid();
  Motors.forward(70);        //70
  delay(15);           //15
  getVal();//2ms delay
   if(counter == (gridVal* gridVal))
   {
     Motors.stp();delay(stopDelay);
     return;
   }
   if((s[0] && s[7])||s[0]||s[7])
   {
    Motors.forward(50);
    delay(15);  //delay for grid
    getVal();
     if(s[0]||s[7])
      counter+=1;
     
       if((counter%gridVal==0)||(counter%gridVal==1))
     { 

         tempp = int(counter/gridVal);
         if(tempp%2==0)
         turn(R);     
     } 
      else 
         turn(L);
     
}

