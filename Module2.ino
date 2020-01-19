const int led = 13;


const int buttonPin = 2;
int buttonState = 0;  
const int wheel = 10;

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

  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

  //initialize led as output
  pinMode(led, OUTPUT);

  //initialize wheel as input
  pinMode(wheel, INPUT);
}

void loop() {
  /*
  buttonState = digitalRead(buttonPin);
  while(buttonState == HIGH)
  {
    Serial.print("test");
      buttonState = digitalRead(buttonPin);
    if(buttonState==LOW){
      break;
    }
  }

*/
  int wheelencoder = digitalRead(wheel);

  //if the wheel is being turned, it will output LOW
  if(wheelencoder==LOW)
  {
    Serial.println(wheelencoder);
    digitalWrite(led, HIGH); 
  }
  else
  {
    Serial.println(wheelencoder);
    digitalWrite(led, LOW);
  }

  /*
  //right motor (M1) to turn forward, left motor (M2) to turn backward
  digitalWrite(7, HIGH);
  analogWrite(6, 150);
  digitalWrite(4, LOW);
  analogWrite(5, 150);
  */
}
