
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

int B_b_J1, B_b_J2, B_p_inicio;
int a;
int b;
void setup() {
  Serial.begin(9600);
  pinMode(J1_0,OUTPUT);
  pinMode(J1_1,OUTPUT);
  pinMode(J1_2,OUTPUT);
  pinMode(J1_3,OUTPUT);
  pinMode(J1_4,OUTPUT);
  pinMode(J1_5,OUTPUT);
  pinMode(J1_6,OUTPUT);
  pinMode(J1_7,OUTPUT);
  pinMode(J2_0,OUTPUT);
  pinMode(J2_1,OUTPUT);
  pinMode(J2_2,OUTPUT);
  pinMode(J2_3,OUTPUT);
  pinMode(J2_4,OUTPUT);
  pinMode(J2_5,OUTPUT);
  pinMode(J2_6,OUTPUT);
  pinMode(J2_7,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
  pinMode(PJ1,INPUT);
  pinMode(PJ2,INPUT);
  pinMode(start,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PJ1), blinkJ1, RISING);
  attachInterrupt(digitalPinToInterrupt(PJ2), blinkJ2, RISING);
  attachInterrupt(digitalPinToInterrupt(start), blink, RISING);
  a=0;
  b=0;
}

void loop() {
  
    if (B_p_inicio == 1){
      Serial.println("1");
      B_p_inicio = 0;
      Reset_J1();
      Reset_J2();
        digitalWrite(BLUE_LED,LOW);
        digitalWrite(RED_LED,HIGH);
        digitalWrite(GREEN_LED,LOW);
        delay(2000);
        digitalWrite(RED_LED,HIGH);
        digitalWrite(GREEN_LED,HIGH);
        delay(2000);
        digitalWrite(RED_LED,LOW);
      }
    if (digitalRead(GREEN_LED) == HIGH){
      if (B_b_J1 == 1){
        B_b_J1 = 0;
        J1();
        }
      if (B_b_J2 == 1){
        B_b_J2 = 0;
        J2();
        }
      }
    if (digitalRead(J1_7) == HIGH){
     // Reset_J2();
     B_b_J1 = 0;
     B_b_J2 = 0;
      digitalWrite(BLUE_LED,HIGH);
      digitalWrite(GREEN_LED,LOW);
      }
    if (digitalRead(J2_7) == HIGH){
     // Reset_J1();
     B_b_J1 = 0;
     B_b_J2 = 0;
      digitalWrite(BLUE_LED,HIGH);
      digitalWrite(GREEN_LED,LOW);
      digitalWrite(RED_LED,HIGH);
      }
}

void Reset_J1(){
  while (a!=1){
        J1();
        }
  }
void Reset_J2(){
  while (b!=1){
        J2();
        }
  }

void J1 (){
  switch (a){
    case 0:
      digitalWrite(J1_7,LOW);
    break;
    case 1:
      digitalWrite(J1_0,HIGH);
    break;
    case 2:
      digitalWrite(J1_0,LOW);
      digitalWrite(J1_1,HIGH);
    break;
    case 3:
      digitalWrite(J1_1,LOW);
      digitalWrite(J1_2,HIGH);
    break;
    case 4:
      digitalWrite(J1_2,LOW);
      digitalWrite(J1_3,HIGH);
    break;
    case 5:
      digitalWrite(J1_3,LOW);
      digitalWrite(J1_4,HIGH);
    break;
    case 6:
      digitalWrite(J1_4,LOW);
      digitalWrite(J1_5,HIGH);
    break;
    case 7:
      digitalWrite(J1_5,LOW);
      digitalWrite(J1_6,HIGH);
    break;
    case 8:
      digitalWrite(J1_6,LOW);
      digitalWrite(J1_7,HIGH);
      a=-1;
    break;
    }
    a++;
  }


void J2 (){
  switch (b){
    case 0:
      digitalWrite(J2_7,LOW);
    break;
    case 1:
      digitalWrite(J2_0,HIGH);
    break;
    case 2:
      digitalWrite(J2_0,LOW);
      digitalWrite(J2_1,HIGH);
    break;
    case 3:
      digitalWrite(J2_1,LOW);
      digitalWrite(J2_2,HIGH);
    break;
    case 4:
      digitalWrite(J2_2,LOW);
      digitalWrite(J2_3,HIGH);
    break;
    case 5:
      digitalWrite(J2_3,LOW);
      digitalWrite(J2_4,HIGH);
    break;
    case 6:
      digitalWrite(J2_4,LOW);
      digitalWrite(J2_5,HIGH);
    break;
    case 7:
      digitalWrite(J2_5,LOW);
      digitalWrite(J2_6,HIGH);
    break;
    case 8:
      digitalWrite(J2_6,LOW);
      digitalWrite(J2_7,HIGH);
      b=-1;
    break;
    }
    b++;
  }


void blinkJ1(){
  delay(200);
  B_b_J1 = 1;
  }

  
void blinkJ2(){
  delay(300);
  B_b_J2 = 1;
  }

  
void blink(){
  delay(100);
  Serial.println("Hola");
  B_p_inicio = 1;
  }
