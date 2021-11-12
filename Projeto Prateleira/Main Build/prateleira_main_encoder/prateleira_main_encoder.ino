// pushbutton
#define btn1 13 // pushbutton liga motor até pos n
#define btn2 12
#define btn3 11
#define btn4 10
#define btn5 9
#define btn6 8 // pushbutton modo de calibração

// motor driver
#define RPWM 3 // porta pwm motor

// encoder
#define encIN 2 // pinos 2, 3, 18, 19, 20, 21 necessários para usar com attachInterrupt no Arduino Mega

int btnState1 = 0; // variável para ler o status do pushbutton
int btnState2 = 0;
int btnState3 = 0; 
int btnState4 = 0; 
int btnState5 = 0;  
int btnState6 = 0;

int j = 0; // variável contadora de pulsos e posição
int i = 0;
int target = 0;

void setup() {
  // pushbuttons e limit switch: INPUT com resistor de pull-down
  pinMode(btn1, INPUT); // botões para controle do motor até posição n
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
  pinMode(btn6, INPUT); // botão para calibração origem 'zero'
  
  // sinal do encoder
  pinMode(encIN, INPUT);

  // configuração da porta de saída do motor, desliga motor
  pinMode(RPWM, OUTPUT);
  analogWrite(RPWM, 0);

  // inicia comunicação serial
  Serial.begin(9600);

  // configura contador
  attachInterrupt(digitalPinToInterrupt(encIN), contador, FALLING); // chama função 'contador' no evento de borda de descida
}

void loop() { 
  controleMotor(); // lê os estados dos botões e controla o motor
  
  // controleSerial(); // mostra os valores dos estados dos pushbuttons e encoder
  // controleSerial() desativado para programa oficial da prateleira
  // dados da porta serial não são necessários
}

void contador() { // realiza contagem de pulsos
  j++;
  if (j >= 20) {
    j = 0;
  }
}

void controleMotor() {
  // lê o valor do pushbutton
  btnState1 = digitalRead(btn1);
  btnState2 = digitalRead(btn2); 
  btnState3 = digitalRead(btn3);
  btnState4 = digitalRead(btn4);
  btnState5 = digitalRead(btn5);
  btnState6 = digitalRead(btn6);
  
  // define posição atual como origem, j = 0, posição 5 (0º = 360º)
  if (btnState6 == HIGH) {
    analogWrite(RPWM, 0);
    j = 0;
    target = 0;
  }
  
  // controle do motor com pushbuttons e sinal do encoder
  if (btnState1 == HIGH) {
    target = 4;
    while (j != target) {
      analogWrite(RPWM, 50);
    }
    analogWrite(RPWM, 0);
  }

  if (btnState2 == HIGH) {
    target = 8;
    while (j != target) {
      analogWrite(RPWM, 50);
    }
    analogWrite(RPWM, 0);
  }

  if (btnState3 == HIGH) {
    target = 12;
    while (j != target) {
      analogWrite(RPWM, 50);
    }
    analogWrite(RPWM, 0);
  }

  if (btnState4 == HIGH) {
    target = 16;
    while (j != target) {
      analogWrite(RPWM, 50);
    }
    analogWrite(RPWM, 0);
  }

  if (btnState5 == HIGH) {
    target = 0;
    while (j != target) {
      analogWrite(RPWM, 50);
    }
    analogWrite(RPWM, 0);
  }
}

void controleSerial() { 
  // visualização das variáveis no monitor serial
  Serial.print("btnState1: ");
  Serial.print(btnState1);
  Serial.print('\t');

  Serial.print("btnState2: ");
  Serial.print(btnState2);
  Serial.print('\t');

  Serial.print("btnState3: ");
  Serial.print(btnState3);
  Serial.print('\t');
  
  Serial.print("btnState4: ");
  Serial.print(btnState4);
  Serial.print('\t');
  
  Serial.print("btnState5: ");
  Serial.print(btnState5);
  Serial.print('\t');

  Serial.print("btnState6: ");
  Serial.print(btnState6);
  Serial.print('\t');
  
  Serial.print("Posição: ");
  Serial.print(j);
  Serial.print('\t');
  
  Serial.print("PWM: ");
  Serial.print(RPWM);
  Serial.println();
}
