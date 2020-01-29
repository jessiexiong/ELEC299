const int wheel=10;
int forward = 0;
int backward = 1;
int turn90 =2;
int wheelCount = 0;
int previousVal = 1;

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

  Serial.begin(9600);
    //initialize wheel as input
  pinMode(wheel, INPUT);
}

void loop() {

   int turnforward = countEncoder(forward, 48);
   int turnbackward = countEncoder(backward, 32);
   int turnat90 = countEncoder(turn90, 8);
}

int countEncoder(int direction, int max){


  //if moving forwards
  if(direction == 0)
  {
    digitalWrite(7, HIGH);
    analogWrite(6, 128);
    digitalWrite(4, HIGH);                                     
    analogWrite(5, 128);
    
    while(1)
    {
    int wheelencoder = digitalRead(wheel);

    if (wheelencoder!=previousVal)
    {
      wheelCount++;
      previousVal=wheelencoder;
      Serial.println(wheelCount);

    }

    if (wheelCount == 48)
    {
      break;
    }
    
    


    
    }
    
  }

  return wheelCount;

  /*if moving backwards
  else if (direction == 1)
  {
    for(int count=0; count< max; count++)
    {
    digitalWrite(7, LOW);
    analogWrite(6, 255);
    digitalWrite(4, LOW);
    analogWrite(5, 255);
    Serial.println(count);

    }
  }

  //if turning 90 degrees
   else if (direction == 2)
  {
    for(int count=0; count< max; count++)
    {
    Serial.println(count);
    digitalWrite(7, LOW);
    analogWrite(6, 255);
    
    digitalWrite(4, HIGH);
    analogWrite(5, 255);
    Serial.println(count);

    }

  }
  */
}
