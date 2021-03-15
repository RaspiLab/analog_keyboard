int keyPressed = 0;
int keyboardPin = A7;
int keyboardValue = 0;
int led = 13;

void setup(){
   Serial.begin(9600);
   pinMode(led,OUTPUT);
}

void loop(){
  if (Serial.available()){
    String data = Serial.readStringUntil('\n');
    if (data == "AG"){Serial.println(data);Serial.println("ACK");}
  }
  keyboardValue = analogRead(keyboardPin);
  if(keyboardValue > 400){
    teclado_press(keyboardValue);
    digitalWrite(led,HIGH);
    delay(333);
    Serial.println(keyPressed);
    digitalWrite(led,LOW); 
  }
}

void teclado_press(int keyVal){
  
  if((keyVal >= 1018) && (keyVal < 1024)){ keyPressed = 1;}
  if((keyVal >= 925) && (keyVal <= 935)) { keyPressed = 2;}  
  if((keyVal >= 848) && (keyVal <= 858)) { keyPressed = 3;}
  if((keyVal >= 782) && (keyVal <= 792)) { keyPressed = 4;}
  if((keyVal >= 725) && (keyVal <= 730)) { keyPressed = 5;}
  if((keyVal >= 675) && (keyVal <= 685)) { keyPressed = 6;}
  if((keyVal >= 635) && (keyVal <= 645)) { keyPressed = 7;}
  if((keyVal >= 595) && (keyVal <= 605)) { keyPressed = 8;}
  if((keyVal >= 562) && (keyVal <= 572)) { keyPressed = 9;}
  if((keyVal >= 505) && (keyVal <= 515)) { keyPressed = 0;}
  if((keyVal >= 530) && (keyVal <= 540)) { keyPressed = 10;}
  if((keyVal >= 480) && (keyVal <= 490)) { keyPressed = 11;}
  
}
