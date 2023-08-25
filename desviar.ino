#define velocidadeEsquerdo 70
#define velocidadeDireito 77.5

void setup() {
  // put your setup code here, to run once:
  //sensor optico
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
  int obstaculo;

  obstaculo = 1;
  while(obstaculo != 5){
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    analogWrite(9, 100);


    analogWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    
    obstaculo = obstaculo + 1;
  }


  obstaculo = 1;
  while(obstaculo != 30){
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    analogWrite(9, velocidadeEsquerdo);
    analogWrite(3, velocidadeDireito);
    digitalWrite(4, 0);
    digitalWrite(5, 1);

    obstaculo = obstaculo + 1;
  }


} 
