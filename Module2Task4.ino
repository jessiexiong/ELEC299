void setup() {
  // put your setup code here, to run once:
    //initialize pins
  //E1
  pinMode(6, OUTPUT);
  //M1
  pinMode(7, OUTPUT);
  //E2
  pinMode(5, OUTPUT);
  //M2
  pinMode(4, OUTPUT);


    //initialize wheel as input
  pinMode(wheel, INPUT);
  attachInterrupt(0, forward, CHANGE);
  attachInterrupt(1, backward, CHANGE);
  Serial.begin(9600);
}

void loop() {

    
}

  void forward ()
  {
    digitalWrite(7, HIGH);
    analogWrite(6, 128);
    digitalWrite(4, LOW);
    analogWrite(5, 128);
  }

  void backward()
  {
        digitalWrite(7, LOW);
    analogWrite(6, 128);
    digitalWrite(4, HIGH);
    analogWrite(5, 128);
  }
