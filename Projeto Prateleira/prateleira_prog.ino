// Motor A connections
const int btnPush1 = 6;     // the number of the pushbutton pin
const int btnPush2 = 5;     // the number of the pushbutton pin
const int btnEnd1 = 4;     // the number of the end switch pin
const int btnEnd2 = 3;     // the number of the end switch pin
int btnState1 = 0;         // variable for reading the pushbutton status
int i = 0;
int btnState2 = 0;         // variable for reading the pushbutton status
int j = 0;
int endState1 = 0;         // variable for reading the end switch status
int endState2 = 0;         // variable for reading the end switch status
int enA = 9;
int in1 = 8;
int in2 = 7;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // Set all the buttons to inputs
  pinMode(btnPush1, INPUT);
  pinMode(btnPush2, INPUT);
  pinMode(btnEnd1, INPUT);
  pinMode(btnEnd2, INPUT);
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  //digitalWrite(in3, LOW);
  //digitalWrite(in4, LOW);
  Serial.begin(9600);
}

void loop() { 
  // void loop funciona como void main do C#, você pode criar outras funções (void) e chamá-las no programa principal
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  
  // read the state of the pushbutton value
  btnState1 = digitalRead(btnPush1);
  btnState2 = digitalRead(btnPush2);
  endState1 = digitalRead(btnEnd1);
  endState2 = digitalRead(btnEnd2);
  
  if (btnState1 == HIGH) {
      analogWrite(enA, 255);
      // Turn on motor A & B
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      i = 1;
      j = 0;
  }
  if (endState1 == HIGH && i == 1)  {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
  } 
  
  if (btnState2 == HIGH) {
      analogWrite(enA, 255);
      // Turn on motor A & B
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      j = 1;
      i = 0;
  }
  if (endState2 == HIGH && j == 1)  {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
  } 
  Serial.print("btnState1: ");
  Serial.print(btnState1);
  Serial.println();
  Serial.print("btnState2: ");
  Serial.print(btnState2);
  Serial.println();
  Serial.print("endState1: ");
  Serial.print(endState1);
  Serial.println();
  Serial.print("endState2: ");
  Serial.print(endState2);
  Serial.println();
  
 
}
  // Now change motor directions
  //digitalWrite(in1, LOW);
  //digitalWrite(in2, HIGH);



  
