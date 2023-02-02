void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
     analogWrite(9,255);
}

// Sensor pins
#define sensorPower 7
#define sensorPin A0

void setup2() {
    pinMode(sensorPower, OUTPUT);

    // Initially keep the sensor OFF
    digitalWrite(sensorPower, LOW);

    Serial.begin(9600);
}

void loop2() {
    //get the reading from the function below and print it
    Serial.print("Analog output: ");
    Serial.println(readSensor1());

    delay(1000);
}

//  This function returns the analog soil moisture measurement
int readSensor1() {
    digitalWrite(sensorPower, HIGH);    // Turn the sensor ON
    delay(10);                            // Allow power to settle
    int val = analogRead(sensorPin);    // Read the analog value form sensor
    digitalWrite(sensorPower, LOW);        // Turn the sensor OFF
    return val;                            // Return analog moisture value

}

int ir;
void setup1(){


Serial.begin(9600);
pinMode(6,OUTPUT);
pinMode(A0,INPUT);
}
void loop1(){

ir = analogRead(A0);
  if(ir>120) {
digitalWrite(6,LOW);
  }
  else 
digitalWrite(6,HIGH);
}