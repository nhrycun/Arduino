const int sensorPin = 4;

//Set up some global variables for the light level an initial value.
int lightInit = 0;  // initial value
int lightVal = 0;   // light reading
float lightValFloat = 0;
float logLightVal;

void setup() {
  Serial.begin(9600);

  lightInit = analogRead(sensorPin);

  //we will take a single reading from the light sensor and store it in the lightCal        //variable. This will give us a prelinary value to compare against in the loop
}
void loop() {
  lightVal = analogRead(sensorPin);  // read the current light levels
  lightValFloat = analogRead(sensorPin);
                                     //if lightVal is less than our initial reading withing a threshold then it is dark.
  logLightVal = (lightValFloat / 2450);
  Serial.print(lightVal);
  Serial.print(" ");
  Serial.println(logLightVal, 6); //the six is for the number of decimal places that I want the calculation to
  delay(500);
}