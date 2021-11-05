#define ENCA 21 
#define ENCB 20 

volatile int posi = 0;
float ang;

void setup() {
  Serial.begin(9600);
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,FALLING);
  Serial.println("target pos");
}

void loop() {
  int pos = 0; 
  noInterrupts(); // disable interrupts temporarily while reading
  pos = posi;
  interrupts(); // turn interrupts back on

  ang = pos*360.00/400.00;
  Serial.print("Pos: ");
  Serial.print(pos);
  Serial.print('\t');
  Serial.print("Angle: ");
  Serial.print(ang);
  Serial.println();
}

void readEncoder(){
  int b = digitalRead(ENCB);
  if(b > 0){
    posi++;
  }
  else{
    posi--;
  }
}
