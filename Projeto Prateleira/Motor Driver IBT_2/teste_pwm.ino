#define RPWM_Out 3 // Arduino PWM output pin 5; connect to IBT-2 pin 1 (RPWM)

int i = 0;

void setup()
{
 pinMode(RPWM_Out, OUTPUT);
 analogWrite(RPWM_Out, 0);
}

void loop()
{
 while (i < 4) {
 analogWrite(RPWM_Out, 30);
 delay(2000);
 analogWrite(RPWM_Out, 0);
 delay(2000);
 analogWrite(RPWM_Out, 128);
 delay(2000);
 analogWrite(RPWM_Out, 0);
 delay(2000);
 i++;
 }
}
