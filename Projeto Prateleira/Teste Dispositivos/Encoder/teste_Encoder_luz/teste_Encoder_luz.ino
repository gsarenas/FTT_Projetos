#define out 2 // pinos 2, 3, 18, 19, 20, 21

int j = 0;
int atual = 0;
int anterior = 0;
float angulo = 0; // a = (i*360)/20


void setup() {
  pinMode(out, INPUT);
  Serial.begin(9600);
}

void loop() {
  attachInterrupt(digitalPinToInterrupt(out), contador, FALLING); // chama função 'contador' no evento de borda de descida
  angulo = (j*360)/20;
  
  Serial.print("j: ");
  Serial.print(j);
  Serial.print('\t');
  Serial.print("angulo: ");
  Serial.print(angulo);
  Serial.println();
}

void contador() { // realiza contagem de pulsos
  j++;
}
