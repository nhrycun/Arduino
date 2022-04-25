int switchState = 0;

void setup() {
//Three LED outputs to connect to the Anodes
  pinMode(3, OUTPUT); //Green LED
  pinMode(4, OUTPUT); //Red LED
  pinMode(6, OUTPUT); //Red LED

//The Input From the Switch
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2); //This checks the sate of pin 2
  lightsFlashing();

void lightsFlashing(){
  
if(switchState == LOW) {
  // The button is not pressed
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
}
//Button is pressed
else{
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
digitalWrite(6, HIGH);

delay(100); //on length
digitalWrite(4, LOW);
delay(150); //off length
digitalWrite(6, LOW);
delay(100); //off length
}
}

}
