int button1 = 2;

void setup()
{
  //setup outputs
  pinMode(3,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);

  pinMode(10,OUTPUT);

  //setup button
  pinMode(button1,INPUT_PULLUP);

  Serial.begin(9600);
}

void wheelOff() {
  //analogWrite(10,0);
  digitalWrite(10,LOW);
}

void wheelOn(int spd) {
  analogWrite(10,spd);
}

void rgbSequence() {
  digitalWrite(3,HIGH);
  delay(100);
  digitalWrite(3,LOW);
  
  digitalWrite(6,HIGH);
  delay(100);
  digitalWrite(6,LOW);
  
  digitalWrite(9,HIGH);
  delay(100);
  digitalWrite(9,LOW);
}

void rgbOff() {
  digitalWrite(3,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
}
void loop()
{
  int i;

  
  // if button is pressed, do this...
  if (digitalRead(button1)==LOW){
    Serial.println("ON!!");
 /*   wheelOn(100);
    for (i=0;i<5;i++) rgbSequence();
    wheelOn(150);
    for (i=0;i<5;i++) rgbSequence();
    wheelOn(200);
    for (i=0;i<5;i++) rgbSequence();
    */
    wheelOn(150);
    for (i=0;i<3;i++) rgbSequence();

    wheelOn(200);
    for (i=0;i<5;i++) rgbSequence();

    wheelOn(255);
    for (i=0;i<10;i++) rgbSequence();
    
    wheelOn(random(150,255));
    for (i=random(1,10);i<10;i++) rgbSequence();

    wheelOn(random(120,150));
    for (i=random(1,10);i<10;i++) rgbSequence();

  }
  // else do this...
  else {
    Serial.println("OFF!");
    wheelOff();
    rgbOff();
  }

 
  
}

