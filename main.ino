//algoritmo para seguir a linha

/*
pino 2 sensor de luz

Pino 10 - Dist Echo 
Pino 8 Dist Trig

pino 6 e 7 -> sentido do motor esquerdo
pino 9 -> PWM do motor esquerdo

pino 4 e 5 -> sentido do motor direito
pino 3 -> PWM do motor direito
*/

// andar(0); -> trás
// andar(1); -> frente


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

  for(int i = 0 ; i < 15 ; i++){
    parkinson();
  }
} 

void andar(bool dir, int pot){
  if(dir == 0){
    digitalWrite(6, 1);
    digitalWrite(7, 0);
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    analogWrite(3, pot);
    analogWrite(9, pot);
  }
  else{
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    analogWrite(3, pot);
    analogWrite(9, pot);
  }
}

void curva(bool dir, int pot){
  if(dir == 0){
    digitalWrite(6, 1);
    digitalWrite(7, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    analogWrite(3, pot);
    analogWrite(9, pot);
  }

   else{
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    analogWrite(3, pot);
    analogWrite(9, pot);
  }

}

void parkinson(){
  /*não pensei nos parâmetros dessa disgraça*/
  int n = 2;
  meiaCurva(1, 100);
  delay(333/n);
  andar(1, 150);
  delay(800);
  meiaCurva(0, 100);
  delay(333/n);
  andar(1, 150);
  delay(800);

}

void meiaCurva(bool dir, int pot){
   if(dir == 0){
    digitalWrite(6, 1);
    digitalWrite(7, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    analogWrite(3, 0);
    analogWrite(9, pot);
}

   else{
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    analogWrite(3, pot);
    analogWrite(9, 0);
  }

}

