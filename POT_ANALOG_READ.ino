#define POT A0

int AN0;
char vetor[5];

void setup() {
  pinMode(POT, INPUT);
  Serial.begin(9600);

}

void loop() {
  AN0 = analogRead(POT);
  sprintf(vetor, "A0: %4d", AN0); //armazenar valor (vetor que recebe dado, formatação do dado, de onde recebe o dado)
  Serial.println(vetor);
  delay(500);
}
