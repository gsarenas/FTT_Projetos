// pushbutton
#define btn1 13 // pushbutton liga motor até pos n
#define btn2 12
#define btn3 11
#define btn4 10
#define btn5 9

// limit switches
#define End1 8 // limit switch desliga motor na pos n
#define End2 7
#define End3 6
#define End4 5
#define End5 4

// motor driver
#define RPWM_Out 3

int btnState1 = 0; // variável para ler o status do pushbutton
int btnState2 = 0;
int btnState3 = 0; 
int btnState4 = 0; 
int btnState5 = 0;  

int endState1 = 0; // variável para ler o status do limit switch
int endState2 = 0; 
int endState3 = 0; 
int endState4 = 0; 
int endState5 = 0;

int i = 0; // variável auxiliar on-off
int j = 0;
int k = 0;
int u = 0;
int v = 0;

void setup() {
  // pushbuttons e limit switches: INPUT com resistor de pull-down
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
  
  pinMode(End1, INPUT);
  pinMode(End2, INPUT);
  pinMode(End3, INPUT);
  pinMode(End4, INPUT);
  pinMode(End5, INPUT);
  
  // configuração da porta de saída do motor, desliga motor
  pinMode(RPWM_Out, OUTPUT);
  analogWrite(RPWM_Out, 0);

  // inicia comunicação serial
  Serial.begin(9600);
}

void loop() { 
  controleMotor(); // lê os estados dos botões e controla o motor
  controleSerial(); // mostra os valores dos estados dos pushbuttons
}

void controleMotor() {
  // lê o valor do pushbutton
  btnState1 = digitalRead(btn1);
  btnState2 = digitalRead(btn2);
  btnState3 = digitalRead(btn3);
  btnState4 = digitalRead(btn4);
  btnState5 = digitalRead(btn5);

  // lê o valor do limit switch
  endState1 = digitalRead(End1);
  endState2 = digitalRead(End2);
  endState3 = digitalRead(End3);
  endState4 = digitalRead(End4);
  endState5 = digitalRead(End5);

  // controle do motor com pushbuttons e limit switches
  if (btnState1 == HIGH) {
      analogWrite(RPWM_Out, 50);
      i = 1;
      j = 0;
      k = 0;
      u = 0;
      v = 0;
  }
  if (endState1 == HIGH && i == 1)  {
      analogWrite(RPWM_Out, 0);
      i = 0;
      j = 0;
      k = 0;
      u = 0;
      v = 0;
  } 
  if (btnState2 == HIGH) {
      analogWrite(RPWM_Out, 50);
      i = 0;
      j = 1;
      k = 0;
      u = 0;
      v = 0;
  }
  if (endState2 == HIGH && j == 1)  {
      analogWrite(RPWM_Out, 0);
      i = 0;
      j = 0;
      k = 0;
      u = 0;
      v = 0;
  } 
  if (btnState3 == HIGH) {
      analogWrite(RPWM_Out, 50);
      i = 0;
      j = 0;
      k = 1;
      u = 0;
      v = 0;
  }
  if (endState3 == HIGH && k == 1)  {
      analogWrite(RPWM_Out, 0);
      i = 0;
      j = 0;
      k = 0;
      u = 0;
      v = 0;
  } 
  if (btnState4 == HIGH) {
      analogWrite(RPWM_Out, 50);
      i = 0;
      j = 0;
      k = 0;
      u = 1;
      v = 0;
  }
  if (endState4 == HIGH && u == 1)  {
      analogWrite(RPWM_Out, 0);
      i = 0;
      j = 0;
      k = 0;
      u = 0;
      v = 0;
  } 
  if (btnState5 == HIGH) {
      analogWrite(RPWM_Out, 50);
      i = 0;
      j = 0;
      k = 0;
      u = 0;
      v = 1;
  }
  if (endState5 == HIGH && v == 1)  {
      analogWrite(RPWM_Out, 0);
      i = 0;
      j = 0;
      k = 0;
      u = 0;
      v = 0;
  }
}

void controleSerial() { 
  // visualização das variáveis no monitor serial
  Serial.print("btnState1: ");
  Serial.print(btnState1);
  Serial.print('\t');
  Serial.print("endState1: ");
  Serial.print(endState1);
  Serial.print('\t');
  
  Serial.print("btnState2: ");
  Serial.print(btnState2);
  Serial.print('\t');
  Serial.print("endState2: ");
  Serial.print(endState2);
  Serial.print('\t');
  
  Serial.print("btnState3: ");
  Serial.print(btnState3);
  Serial.print('\t');
  Serial.print("endState3: ");
  Serial.print(endState3);
  Serial.print('\t');
  
  Serial.print("btnState4: ");
  Serial.print(btnState4);
  Serial.print('\t');
  Serial.print("endState4: ");
  Serial.print(endState4);
  Serial.print('\t');
  
  Serial.print("btnState5: ");
  Serial.print(btnState5);
  Serial.print('\t');
  Serial.print("endState5: ");
  Serial.print(endState5);
  Serial.print('\t');
  
  Serial.println();
}



  
