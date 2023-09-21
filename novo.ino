//algoritmo para seguir a linha

/*
pino 2 sensor de luz

digitalRead = 1 -> branco

Pino 10 - Dist Echo 
Pino 8 Dist Trig

pino 6 e 7 -> sentido do motor esquerdo
pino 9 -> PWM do motor esquerdo

pino 4 e 5 -> sentido do motor direito
pino 3 -> PWM do motor direito

 meiaCurva(1, 95);   ASSIM ELE VAI RETO
  delay(500);
  meiaCurva(0,80);
  delay(500);
*/

// andar(0); -> trás
// andar(1); -> frente

#include <math.h>
#include <DistanceSensor.h>

const int echoPin = 10;
const int trigPin = 8;
DistanceSensor sensor(trigPin, echoPin);
void setup() {
  // put your setup code here, to run once:
  //sensor optico
  Serial.begin(9600);
  pinMode(2, INPUT); 

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  

}

void loop() {
  // put your main code here, to run repeatedly:
  /*int viuPreto = digitalRead(2);
  int foiParaEsquerda = 0;
  int foiParaDireita = 1;
  Serial.println(viuPreto);
  if(viuPreto == 0){    
    curva(1, 100);   
    delay(5);
    Serial.println("to vendo carai");
  }

  else{
    curva(0, 100);
    delay(5);
    Serial.println("n to vendo n carai");
  }
*/

/*

  for(int i = 0 ; i < 15 ; i++){
    parkinson(70);
  }
*/
int distancia =  sensor.getCM();



 seguirLinha();


  
}

void andar(bool dir, int pot){
  int np = map(pot, 0, 100, 0, 95*2);
  int npp = map(pot, 0, 100, 0, 80*2);
  if(dir == 0){
    digitalWrite(6, 1);
    digitalWrite(7, 0);
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    analogWrite(3, np);
    analogWrite(9, npp);
  }
  else{
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    analogWrite(3, np);
    analogWrite(9, npp);
  }
}

void curva(bool dir, int pot){
  int np = map(pot, 0, 100, 0, 95*2);
  int npp = map(pot, 0, 100, 0, 80*2);
  if(dir == 0){
    digitalWrite(6, 1);
    digitalWrite(7, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    analogWrite(3, np);
    analogWrite(9, npp);
  }

   else{
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    analogWrite(3, np);
    analogWrite(9, npp);
  }

}

void parkinson(int pot){
  /*não pensei nos parâmetros dessa disgraça*/
  float n = 1;
  meiaCurva(0, pot);
  delay(333/n);
}

void meiaCurva(bool dir, int pot){
  int np = map(pot, 0, 100, 0, 95*2);
  int npp = map(pot, 0, 100, 0, 80*2);
   if(dir == 0){
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    analogWrite(3, 0);
    analogWrite(9, npp);
}

   else{
    digitalWrite(6, 1);
    digitalWrite(7, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    analogWrite(3, np);
    analogWrite(9, 0);
  }
}

void seguirLinha(){
  // isso aqui vai checando pelo preto apenas pelo lado direito
  int viuBranco = digitalRead(2);
  if(viuBranco == 1){
    meiaCurva(1, 65);
  }
  
  if(viuBranco == 0){
    meiaCurva(0, 100);
    delay(75);
  }
}
