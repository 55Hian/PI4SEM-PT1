const int sensor1 = 2;  // define o pino do sensor
const int sensor2 = 3;  // define o pino do sensor
const int sensor3 = 4;  // define o pino do sensor
const int sensor4 = 5;  // define o pino do sensor
const int sensor5 = 6;  // define o pino do sensor
const int sensor6 = 7;  // define o pino do sensor
const int sensor7 = 8;  // define o pino do sensor
const int sensor8 = 9;  // define o pino do sensor
const int sensor9 = 10; // define o pino do sensor

const int tempo = 10; // tempo de fluxo ( não utilizado)

const int led = 11; // define o pino do led

boolean estadoSensor1;  //recebe leitura do pino do sensor
boolean estadoSensor2;  //recebe leitura do pino do sensor
boolean estadoSensor3;  //recebe leitura do pino do sensor
boolean estadoSensor4;  //recebe leitura do pino do sensor
boolean estadoSensor5;  //recebe leitura do pino do sensor
boolean estadoSensor6;  //recebe leitura do pino do sensor
boolean estadoSensor7;  //recebe leitura do pino do sensor
boolean estadoSensor8;  //recebe leitura do pino do sensor
boolean estadoSensor9;  //recebe leitura do pino do sensor

double millisIniciaProcesso = millis();

double millisTempoSensor1 = millis();
double millisTempoSensor2 = millis();
double millisTempoSensor3 = millis();
double millisTempoSensor4 = millis();
double millisTempoSensor5 = millis();
double millisTempoSensor6 = millis();
double millisTempoSensor7 = millis();
double millisTempoSensor8 = millis();
double millisTempoSensor9 = millis();

unsigned long resetmillis;

const double distanciaSensor1 = 0;
const double distanciaSensor2 = 1;
const double distanciaSensor3 = 2;
const double distanciaSensor4 = 3;
const double distanciaSensor5 = 4;
const double distanciaSensor6 = 5;
const double distanciaSensor7 = 6;
const double distanciaSensor8 = 7;
const double distanciaSensor9 = 8;


boolean inicioProcesso = false;
boolean liberasensor1 = false;
boolean liberasensor2 = false;
boolean liberasensor3 = false;
boolean liberasensor4 = false;
boolean liberasensor5 = false;
boolean liberasensor6 = false;
boolean liberasensor7 = false;
boolean liberasensor8 = false;
boolean liberasensor9 = false;

boolean controleSensor1 = true;

boolean liberaCalculos = false;


boolean verificaProcesso = true;
boolean zeraTempoInicioProcesso = true;

boolean acionamentoSensor1 = false;
boolean acionamentoSensor2 = false;
boolean acionamentoSensor3 = false;
boolean acionamentoSensor4 = false;
boolean acionamentoSensor5 = false;
boolean acionamentoSensor6 = false;
boolean acionamentoSensor7 = false;
boolean acionamentoSensor8 = false;
boolean acionamentoSensor9 = false;

double tempoplacaligada = millis();
void setup() {
  tempoplacaligada = millis();
  
  pinMode(led, OUTPUT);
  
  pinMode(sensor1, INPUT_PULLUP);
  pinMode(sensor2, INPUT_PULLUP);
  pinMode(sensor3, INPUT_PULLUP);
  pinMode(sensor4, INPUT_PULLUP);
  pinMode(sensor5, INPUT_PULLUP);
  pinMode(sensor6, INPUT_PULLUP);
  pinMode(sensor7, INPUT_PULLUP);
  pinMode(sensor8, INPUT_PULLUP);
  pinMode(sensor9, INPUT_PULLUP);

  Serial.begin(9600);// Inicia a comunicação serial 
  
  
  }

void loop() {


  estadoSensor9 = digitalRead(sensor9);
  if (estadoSensor9 == 0 && verificaProcesso == true){

    
    
    if(zeraTempoInicioProcesso == true){
     millisIniciaProcesso = millis();
     zeraTempoInicioProcesso = false;
    }
    
    if((millis() - millisIniciaProcesso) > 3000){
      Serial.println("Iniciando sistema de leitura.");
      inicioProcesso = true;

      digitalWrite(led, HIGH); 
      delay(1000);
      digitalWrite(led, LOW); 
      delay(500);
      digitalWrite(led, HIGH); 
      delay(1000);
      digitalWrite(led, LOW); 

      Serial.println("Sistema de leitura iniciado com sucesso!");
      verificaProcesso = false;
      
    } 
  } else{
      millisIniciaProcesso = millis();
    }

  if(inicioProcesso == true){
    if (controleSensor1 == true){
    liberasensor1 = true;
    controleSensor1 = false;
    }
    
    if(liberasensor1 == true){
         
    estadoSensor1 = digitalRead(sensor1);
    if(estadoSensor1 == 0){

      acionamentoSensor1 = true;
      millisTempoSensor1 = millis();
      liberasensor2 = true;

      Serial.println("Sensor 1");
      Serial.println(acionamentoSensor1);
      Serial.println(millisTempoSensor1);
      Serial.println("-----------------");
      liberasensor1 = false;
    }
    }
    
    if(liberasensor2 == true){
       estadoSensor2 = digitalRead(sensor2);
    if(estadoSensor2 == 0){   
       acionamentoSensor2 = true;
       millisTempoSensor2 = millis();
       liberasensor3 = true;

      Serial.println("Sensor 2");
      Serial.println(acionamentoSensor2);
      Serial.println(millisTempoSensor2);
      Serial.println("-----------------");
      liberasensor2 = false;
    }
    }
    
    if(liberasensor3 == true){
    estadoSensor3 = digitalRead(sensor3);
    if(estadoSensor3 == 0){ 
    acionamentoSensor3 = true;
    millisTempoSensor3 = millis();
    liberasensor4 = true;

      Serial.println("Sensor 3");
      Serial.println(acionamentoSensor3);
      Serial.println(millisTempoSensor3);
      Serial.println("-----------------");

    liberasensor3 = false;
    }
    }

    if(liberasensor4 == true){
    estadoSensor4 = digitalRead(sensor4);
    if(estadoSensor4 == 0){ 
    acionamentoSensor4 = true;
    millisTempoSensor4 = millis();
    liberasensor5 = true;

      Serial.println("Sensor 4");
      Serial.println(acionamentoSensor4);
      Serial.println(millisTempoSensor4);
      Serial.println("-----------------");

    liberasensor4 = false;
    }
    }

    if(liberasensor5 == true){
    estadoSensor5 = digitalRead(sensor5);
    if(estadoSensor5 == 0){ 
    acionamentoSensor5 = true;
    millisTempoSensor5 = millis();
    liberasensor6 = true;

      Serial.println("Sensor 5");
      Serial.println(acionamentoSensor5);
      Serial.println(millisTempoSensor5);
      Serial.println("-----------------");

    liberasensor5 = false;
    }
    }

    if(liberasensor6 == true){
    estadoSensor6 = digitalRead(sensor6);
    if(estadoSensor6 == 0){ 
    acionamentoSensor6 = true;
    millisTempoSensor6 = millis();
    liberasensor7 = true;

      Serial.println("Sensor 6");
      Serial.println(acionamentoSensor6);
      Serial.println(millisTempoSensor6);
      Serial.println("-----------------");

    liberasensor6 = false;
    }
    }

    
    if(liberasensor7 == true){
    estadoSensor7 = digitalRead(sensor7);
    if(estadoSensor7 == 0){ 
    acionamentoSensor7 = true;
    millisTempoSensor7 = millis();
    liberasensor8 = true;

      Serial.println("Sensor 7");
      Serial.println(acionamentoSensor7);
      Serial.println(millisTempoSensor7);
      Serial.println("-----------------");

    liberasensor7 = false;
    }
    }

    if(liberasensor8 == true){
    estadoSensor8 = digitalRead(sensor8);
    if(estadoSensor8 == 0){ 
    acionamentoSensor8 = true;
    millisTempoSensor8 = millis();
    liberasensor9 = true;

      Serial.println("Sensor 8");
      Serial.println(acionamentoSensor8);
      Serial.println(millisTempoSensor8);
      Serial.println("-----------------");

    liberasensor8 = false;
    }
    }

    if(liberasensor9 == true){
    estadoSensor9 = digitalRead(sensor9);
    if(estadoSensor9 == 0){ 
    acionamentoSensor9 = true;
    millisTempoSensor9 = millis();
    //liberasensor10 = true;
    liberaCalculos = true;
    
      Serial.println("Sensor 9");
      Serial.println(acionamentoSensor9);
      Serial.println(millisTempoSensor9);
      Serial.println("-----------------");

    liberasensor9 = false;
    }
    }
    if(liberaCalculos == true){

      Serial.print("debugger: tempo no millisIniciaProcesso é de:");
      Serial.print(millisIniciaProcesso);
      Serial.println(" milisegundos");

      
      Serial.print("debugger: tempo no tempoplacaligada é de:");
      Serial.print(tempoplacaligada);
      Serial.println(" milisegundos");

      Serial.print("debugger: tempo no sensor 1 é de:");
      Serial.print(millisTempoSensor1);
      Serial.println(" milisegundos");


  double diferencaTempoPlaca = millisTempoSensor1 - tempoplacaligada;

      Serial.print("debugger: tempo no diferencaTempoPlaca é de:");
      Serial.print(diferencaTempoPlaca);
      Serial.println(" milisegundos");
  
  millisTempoSensor1 = millisTempoSensor1 - diferencaTempoPlaca;
  millisTempoSensor2 = millisTempoSensor2 - diferencaTempoPlaca;
  millisTempoSensor3 = millisTempoSensor3 - diferencaTempoPlaca;
  millisTempoSensor4 = millisTempoSensor4 - diferencaTempoPlaca;
  millisTempoSensor5 = millisTempoSensor5 - diferencaTempoPlaca;
  millisTempoSensor6 = millisTempoSensor6 - diferencaTempoPlaca;
  millisTempoSensor7 = millisTempoSensor7 - diferencaTempoPlaca;
  millisTempoSensor8 = millisTempoSensor8 - diferencaTempoPlaca;
  millisTempoSensor9 = millisTempoSensor9 - diferencaTempoPlaca;

      
      Serial.print("tempo no sensor 1 é de:");
      Serial.print(millisTempoSensor1);
      Serial.println(" milisegundos");

      Serial.print("tempo no sensor 2 é de:");
      Serial.print(millisTempoSensor2);
      Serial.println(" milisegundos");

      Serial.print("tempo no sensor 3 é de:");
      Serial.print(millisTempoSensor3);
      Serial.println(" milisegundos");

      Serial.print("tempo no sensor 4 é de:");
      Serial.print(millisTempoSensor4);
      Serial.println(" milisegundos");

      Serial.print("tempo no sensor 5 é de:");
      Serial.print(millisTempoSensor5);
      Serial.println(" milisegundos");

      Serial.print("tempo no sensor 6 é de:");
      Serial.print(millisTempoSensor6);
      Serial.println(" milisegundos");

      Serial.print("tempo no sensor 7 é de:");
      Serial.print(millisTempoSensor7);
      Serial.println(" milisegundos");

      Serial.print("tempo no sensor 8 é de:");
      Serial.print(millisTempoSensor8);
      Serial.println(" milisegundos");

      Serial.print("tempo no sensor 9 é de:");
      Serial.print(millisTempoSensor9);
      Serial.println(" milisegundos");

      Serial.println("-----------------");
      
  double tempoSensor1_ms = millisTempoSensor1 / 1000;
  double tempoSensor2_ms = millisTempoSensor2 / 1000;
  double tempoSensor3_ms = millisTempoSensor3 / 1000;
  double tempoSensor4_ms = millisTempoSensor4 / 1000;
  double tempoSensor5_ms = millisTempoSensor5 / 1000;
  double tempoSensor6_ms = millisTempoSensor6 / 1000;
  double tempoSensor7_ms = millisTempoSensor7 / 1000;
  double tempoSensor8_ms = millisTempoSensor8 / 1000;
  double tempoSensor9_ms = millisTempoSensor9 / 1000;

      Serial.print("tempo no sensor 1 é de:");
      Serial.print(tempoSensor1_ms);
      Serial.println(" segundos");

      Serial.print("tempo no sensor 2 é de:");
      Serial.print(tempoSensor2_ms);
      Serial.println(" segundos");

      Serial.print("tempo no sensor 3 é de:");
      Serial.print(tempoSensor3_ms);
      Serial.println(" segundos");

      Serial.print("tempo no sensor 4 é de:");
      Serial.print(tempoSensor4_ms);
      Serial.println(" segundos");

      Serial.print("tempo no sensor 5 é de:");
      Serial.print(tempoSensor5_ms);
      Serial.println(" segundos");

      Serial.print("tempo no sensor 6 é de:");
      Serial.print(tempoSensor6_ms);
      Serial.println(" segundos");

      Serial.print("tempo no sensor 7 é de:");
      Serial.print(tempoSensor7_ms);
      Serial.println(" segundos");

      Serial.print("tempo no sensor 8 é de:");
      Serial.print(tempoSensor8_ms);
      Serial.println(" segundos");

      Serial.print("tempo no sensor 9 é de:");
      Serial.print(tempoSensor9_ms);
      Serial.println(" segundos");
      
      Serial.println("-----------------");
  double velocidadeMediaSensor1 = 0;
      Serial.print("velocidade no sensor 1 é de:");
      Serial.print(velocidadeMediaSensor1);
      Serial.println(" metros por segundos");
      
  double velocidadeMediaSensor2 = (distanciaSensor2 - distanciaSensor1)/(tempoSensor2_ms - tempoSensor1_ms);
      Serial.print("velocidade no sensor 2 é de:");
      Serial.print(velocidadeMediaSensor2);
      Serial.println(" metros por segundos");

  double velocidadeMediaSensor3 = (distanciaSensor3 - distanciaSensor2)/(tempoSensor3_ms - tempoSensor2_ms);
      Serial.print("velocidade no sensor 3 é de:");
      Serial.print(velocidadeMediaSensor3);
      Serial.println(" metros por segundos");

  double velocidadeMediaSensor4 = (distanciaSensor4 - distanciaSensor3)/(tempoSensor4_ms - tempoSensor3_ms);
      Serial.print("velocidade no sensor 4 é de:");
      Serial.print(velocidadeMediaSensor4);
      Serial.println(" metros por segundos");

  double velocidadeMediaSensor5 = (distanciaSensor5 - distanciaSensor4)/(tempoSensor5_ms - tempoSensor4_ms);
      Serial.print("velocidade no sensor 5 é de:");
      Serial.print(velocidadeMediaSensor5);
      Serial.println(" metros por segundos");

  double velocidadeMediaSensor6 = (distanciaSensor6 - distanciaSensor5)/(tempoSensor6_ms - tempoSensor5_ms);
      Serial.print("velocidade no sensor 6 é de:");
      Serial.print(velocidadeMediaSensor6);
      Serial.println(" metros por segundos");

  double velocidadeMediaSensor7 = (distanciaSensor7 - distanciaSensor6)/(tempoSensor7_ms - tempoSensor6_ms);
      Serial.print("velocidade no sensor 7 é de:");
      Serial.print(velocidadeMediaSensor7);
      Serial.println(" metros por segundos");

  double velocidadeMediaSensor8 = (distanciaSensor8 - distanciaSensor7)/(tempoSensor8_ms - tempoSensor7_ms);
      Serial.print("velocidade no sensor 8 é de:");
      Serial.print(velocidadeMediaSensor8);
      Serial.println(" metros por segundos");

  double velocidadeMediaSensor9 = (distanciaSensor9 - distanciaSensor8)/(tempoSensor9_ms - tempoSensor8_ms);
      Serial.print("velocidade no sensor 9 é de:");
      Serial.print(velocidadeMediaSensor9);
      Serial.println(" metros por segundos");

      

      Serial.println("-----------------");
  double aceleracaoMediaSensor1 = 0;
      Serial.print("Aceleração no sensor 1 é de:");
      Serial.print(aceleracaoMediaSensor1);
      Serial.println(" metros por segundos²");
      
  double aceleracaoMediaSensor2 = (velocidadeMediaSensor2 - velocidadeMediaSensor1)/(tempoSensor2_ms - tempoSensor1_ms);
      Serial.print("Aceleração no sensor 2 é de:");
      Serial.print(aceleracaoMediaSensor2);
      Serial.println(" metros por segundos²");

  double aceleracaoMediaSensor3 = (velocidadeMediaSensor3 - velocidadeMediaSensor2)/(tempoSensor3_ms - tempoSensor2_ms);
      Serial.print("Aceleração no sensor 3 é de:");
      Serial.print(aceleracaoMediaSensor3);
      Serial.println(" metros por segundos²");

  double aceleracaoMediaSensor4 = (velocidadeMediaSensor4 - velocidadeMediaSensor3)/(tempoSensor4_ms - tempoSensor3_ms);
      Serial.print("Aceleração no sensor 4 é de:");
      Serial.print(aceleracaoMediaSensor4);
      Serial.println(" metros por segundos²");

  double aceleracaoMediaSensor5 = (velocidadeMediaSensor5 - velocidadeMediaSensor4)/(tempoSensor5_ms - tempoSensor4_ms);
      Serial.print("Aceleração no sensor 5 é de:");
      Serial.print(aceleracaoMediaSensor5);
      Serial.println(" metros por segundos²");

  double aceleracaoMediaSensor6 = (velocidadeMediaSensor6 - velocidadeMediaSensor5)/(tempoSensor6_ms - tempoSensor5_ms);
      Serial.print("Aceleração no sensor 6 é de:");
      Serial.print(aceleracaoMediaSensor6);
      Serial.println(" metros por segundos²");

  double aceleracaoMediaSensor7 = (velocidadeMediaSensor7 - velocidadeMediaSensor6)/(tempoSensor7_ms - tempoSensor6_ms);
      Serial.print("Aceleração no sensor 7 é de:");
      Serial.print(aceleracaoMediaSensor7);
      Serial.println(" metros por segundos²");

  double aceleracaoMediaSensor8 = (velocidadeMediaSensor8 - velocidadeMediaSensor7)/(tempoSensor8_ms - tempoSensor7_ms);
      Serial.print("Aceleração no sensor 8 é de:");
      Serial.print(aceleracaoMediaSensor8);
      Serial.println(" metros por segundos²");

  double aceleracaoMediaSensor9 = (velocidadeMediaSensor9 - velocidadeMediaSensor8)/(tempoSensor9_ms - tempoSensor8_ms);
      Serial.print("Aceleração no sensor 9 é de:");
      Serial.print(aceleracaoMediaSensor9);
      Serial.println(" metros por segundos²");
      
      liberaCalculos = false;
      
    }
  }
}
