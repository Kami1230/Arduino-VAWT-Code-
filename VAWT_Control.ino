// Set pins
const int voltagePin = A0;
const int currentPin = A1;

const int motorPin1 = 9;
const int motorPin2 = 10;

// Constants
const float VOLTAGE_FACTOR = 5.0 / 1023.0;
const float CURRENT_FACTOR = 0.1; 
const int ANGLE_STEP = 1; 
const int WAIT_TIME = 1000; 

// Variables
int currentAngle = 0; // Starting angle
float previousPower = 0;
float power = 0;
float v;
float c;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {
  v = analogRead(voltagePin);
  c = analogRead(currentPin);
  power = v * c;

  if (previousPower < power){
    currentAngle = currentAngle +  ANGLE_STEP;
  }
  else{
      currentAngle = currentAngle -  ANGLE_STEP;
  }

  currentAngle = constrain(currentAngle, 0, 180);
}
