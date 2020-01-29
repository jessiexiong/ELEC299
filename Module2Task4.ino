const int wheel=2;

int wheelCount = 0;
int previousVal = 1;
int val;


//initialize time
  int volatile time1 = 0;
  int volatile time2 = 0;
  
void setup() {
  
  //initialize pins
  //E1
  pinMode(6, OUTPUT);
  //M1
  pinMode(7, OUTPUT);
  //E2
  pinMode(5, OUTPUT);
  //M2
  pinMode(4, OUTPUT);


//pin assignment for wheel encoders
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2), readspeed1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), readspeed2, CHANGE);
  Serial.begin(9600);

  
    //initialize wheel as input
  pinMode(wheel, INPUT);

    digitalWrite(7, HIGH);
    digitalWrite(4, HIGH);  
    analogWrite(6, 128);                                   
    analogWrite(5, 128);
}

void loop() {

  val=countEncoder();
   //move forward

  while (val<48)
  {
    digitalWrite(7, HIGH);
    digitalWrite(4, HIGH);  
    analogWrite(6, 128);                                   
    analogWrite(5, 128);

    //get value of count again
    val = countEncoder();

    Serial.println(val);
  }

  wheelCount=0;
  val = 0;
    while (val<32)
  {
    digitalWrite(7, LOW);
    analogWrite(6, 128);
    digitalWrite(4, LOW);                                     
    analogWrite(5, 128);

    //get value of count again
    val = countEncoder();
  }

  wheelCount=0;
  val = 0;
    while (val<8)
  {
    digitalWrite(7, HIGH);
    analogWrite(6, 128);
    digitalWrite(4, LOW);                                     
    analogWrite(5, 128);

    //get value of count again
    val = countEncoder();
  }
  
  
   
}

int countEncoder(){
  while(1){
    if(digitalRead(2)==HIGH)
    {
      while(1)
      {
        if (digitalRead(2)==LOW)
        {
          break;
        }
      }
      wheelCount++;
      return wheelCount++;
    }
  }
  }


  //calculate speed of motor 1
  void readspeed1()
  {
    time2 = millis();
    float t = time2 - time1; //calculate time
    float d = 16;//calculate distance
    float s = d/t;//calculate speed
    Serial.print("Speed of motor 1 is: ");
    Serial.println(s);

    time1 = millis();
  }
  
//calculate speed of motor 2
  void readspeed2()
  {
    time2 = millis();
    float t = time2 - time1; //calculate time
    float d = 16 ;//calculate distance
    float s = d/t; //calculate speed

    Serial.print("Speed of motor 2 is: ");
    Serial.println(s);

    time1 = millis();
  }
