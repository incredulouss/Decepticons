//
//
void calibrateSensors()     /////////////// function to calibrate ///
{
  for(int i=0; i<400; i++)
  {
    if(i<=100||i>=285)
    Motors.right(50);
    else
    Motors.left(50);
    calibrate();   
    delay(4);
  }
  Motors.stp();
}
void calibrate(){
  emitterOn();
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    int s=analogRead(sensors[i]);
    if(calMax[i]<s)
    calMax[i]=s;
    if(calMin[i]>s)
    calMin[i]=s;
  }
  emitterOff();
}
void getVal()
{
   position = readLine(s);
}

void printCalibratedvalues(){
  Serial.print("calibrated Max-");
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(calMax[i]);
    Serial.print("   ");
  }
  Serial.println();
  Serial.print("calibrated Min-");
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(calMin[i]);
    Serial.print("   ");
  }
  Serial.println();
}

void IRinit(){
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    pinMode(sensors[i], INPUT);
  }
  pinMode(EMITTER_PIN, OUTPUT);
  Serial.begin(9600);
}

void emitterOn(){
  digitalWrite(EMITTER_PIN,1);
  delayMicroseconds(700);
}
void emitterOff(){
  digitalWrite(EMITTER_PIN,0);
  delayMicroseconds(700);
}

//********************************************************************************************************************************************************************************************


//********************************************************************************************************************************************************************************************

int* readRaw(){
  static int sensorValue[NUM_SENSORS];
  emitterOn();
  for(int i=0;i<NUM_SENSORS;i++){
    sensorValue[i]=analogRead(sensors[i]);
  }
  emitterOff();
  return sensorValue;
}

void printReadRaw(){
  int *a=readRaw();
  Serial.print("Raw Values-");
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(a[i]);
    Serial.print("   ");
  }
  Serial.println();
}

int* readNormalized(){
  static int sensorValue[NUM_SENSORS];
  emitterOn();
  for(int i=0;i<NUM_SENSORS;i++){
    int s=analogRead(sensors[i]);
    if(s <= calMin[i])
    s=0;
    else if(s>=calMax[i])
    s=1000;
    else
    s=map(s,calMin[i],calMax[i],0,1000);
    sensorValue[i]=s;
  }
  emitterOff();
  return sensorValue;
}

void printReadNormalized(){
  Serial.print("Normalized Value-");
  int *a=readNormalized();
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(a[i]);
    Serial.print("   ");
  }
  Serial.println();
}

 int readLine(int *onLine){
  unsigned long avg=0;
  uint32_t sum=0;
  boolean isOnLine=false;
  int *normalizedVlaue=readNormalized();
  for (int i = 0; i < NUM_SENSORS; i++)
  {   
    if(normalizedVlaue[i]>50){
      avg+= ((long)normalizedVlaue[i]*(1000*i));
      sum+= normalizedVlaue[i];
    }
    if(normalizedVlaue[i]>LINE_THRESHOLD)
      {
        onLine[i]=1;
        isOnLine=true;
      }
    else
      onLine[i]=0;
  }
  if(!isOnLine){
    if(lastValue < (NUM_SENSORS - 1)*1000/2)
            return 0;

    else
            return (NUM_SENSORS-1)*1000;
  }
  lastValue=avg/sum;
  return lastValue;
} 

void printReadLine(){
  int dig[NUM_SENSORS];
  int a=readLine(dig);
  Serial.print("Line Position- ");
  Serial.println(a);
  Serial.print("Online- ");
    for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(dig[i]);
    Serial.print("   ");
  }
  Serial.println();
  Serial.println();
}


