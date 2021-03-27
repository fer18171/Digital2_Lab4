
const int J1_0 = 9;
const int J1_1 = 8;
const int J1_2 = 7;
const int J1_3 = 6;
const int J1_4 = 5;
const int J1_5 = 4;
const int J1_6 = 3;
const int J1_7 = 2;

const int J2_0 = 31;
const int J2_1 = 32;
const int J2_2 = 33;
const int J2_3 = 34;
const int J2_4 = 35;
const int J2_5 = 36;
const int J2_6 = 37;
const int J2_7 = 38;

const int PJ1 = 12;
const int PJ2 = 11;

const int start = PUSH2;
const int semaforo = 20;
int a;
void setup() {
  Serial.begin(9600);
  a=0;
}

void loop() {
  a+=1;
  if (a==255){
    a=0;
    }
    delay(10);
  analogWrite(RED_LED,11);
  analogWrite(GREEN_LED,181);
  analogWrite(BLUE_LED,175);
}
