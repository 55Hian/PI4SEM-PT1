const double distanciaSensor1 = 0;  //armazena distancia fisica de instalação do sensor
const double distanciaSensor2 = 2;  //armazena distancia fisica de instalação do sensor
const double distanciaSensor3 = 4.5;  //armazena distancia fisica de instalação do sensor
const double distanciaSensor4 = 7.5;  //armazena distancia fisica de instalação do sensor
const double distanciaSensor5 = 9;  //armazena distancia fisica de instalação do sensor


double tempoSensor1_ms;
double tempoSensor2_ms;
double tempoSensor3_ms;
double tempoSensor4_ms;
double tempoSensor5_ms;

double velocidadeMediaSensor1;
double velocidadeMediaSensor2;
double velocidadeMediaSensor3;
double velocidadeMediaSensor4;
double velocidadeMediaSensor5;

double aceleracaoMediaSensor1;
double aceleracaoMediaSensor2;
double aceleracaoMediaSensor3;
double aceleracaoMediaSensor4;
double aceleracaoMediaSensor5;

void calculos(){
  double diferencaTempoPlaca = millisTempoSensor1 - tempoplacaligada;

  millisTempoSensor1 = millisTempoSensor1 - diferencaTempoPlaca;
  millisTempoSensor2 = millisTempoSensor2 - diferencaTempoPlaca;
  millisTempoSensor3 = millisTempoSensor3 - diferencaTempoPlaca;
  millisTempoSensor4 = millisTempoSensor4 - diferencaTempoPlaca;
  millisTempoSensor5 = millisTempoSensor5 - diferencaTempoPlaca;


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

  Serial.println("-----------------");

  tempoSensor1_ms = millisTempoSensor1 / 1000;
  tempoSensor2_ms = millisTempoSensor2 / 1000;
  tempoSensor3_ms = millisTempoSensor3 / 1000;
  tempoSensor4_ms = millisTempoSensor4 / 1000;
  tempoSensor5_ms = millisTempoSensor5 / 1000;
      
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

  velocidadeMediaSensor5 = (distanciaSensor5 - distanciaSensor4) / (tempoSensor5_ms - tempoSensor4_ms);
  Serial.print("velocidade no sensor 5 é de:");
  Serial.print(velocidadeMediaSensor5);
  Serial.println(" metros por segundos");

  Serial.println("-----------------");
  
  velocidadeMediaSensor1 = 0;
  Serial.print("velocidade no sensor 1 é de:");
  Serial.print(velocidadeMediaSensor1);
  Serial.println(" metros por segundos");

  velocidadeMediaSensor2 = (distanciaSensor2 - distanciaSensor1) / (tempoSensor2_ms - tempoSensor1_ms);
  Serial.print("velocidade no sensor 2 é de:");
  Serial.print(velocidadeMediaSensor2);
  Serial.println(" metros por segundos");

  velocidadeMediaSensor3 = (distanciaSensor3 - distanciaSensor2) / (tempoSensor3_ms - tempoSensor2_ms);
  Serial.print("velocidade no sensor 3 é de:");
  Serial.print(velocidadeMediaSensor3);
  Serial.println(" metros por segundos");

  velocidadeMediaSensor4 = (distanciaSensor4 - distanciaSensor3) / (tempoSensor4_ms - tempoSensor3_ms);
  Serial.print("velocidade no sensor 4 é de:");
  Serial.print(velocidadeMediaSensor4);
  Serial.println(" metros por segundos");
   
  Serial.println("-----------------");
    
  aceleracaoMediaSensor1 = 0;
  Serial.print("Aceleração no sensor 1 é de:");
  Serial.print(aceleracaoMediaSensor1);
  Serial.println(" metros por segundos²");

  aceleracaoMediaSensor2 = (velocidadeMediaSensor2 - velocidadeMediaSensor1) / (tempoSensor2_ms - tempoSensor1_ms);
  Serial.print("Aceleração no sensor 2 é de:");
  Serial.print(aceleracaoMediaSensor2);
  Serial.println(" metros por segundos²");

  aceleracaoMediaSensor3 = (velocidadeMediaSensor3 - velocidadeMediaSensor2) / (tempoSensor3_ms - tempoSensor2_ms);
  Serial.print("Aceleração no sensor 3 é de:");
  Serial.print(aceleracaoMediaSensor3);
  Serial.println(" metros por segundos²");
  
  aceleracaoMediaSensor4 = (velocidadeMediaSensor4 - velocidadeMediaSensor3) / (tempoSensor4_ms - tempoSensor3_ms);
  Serial.print("Aceleração no sensor 4 é de:");
  Serial.print(aceleracaoMediaSensor4);
  Serial.println(" metros por segundos²");

  aceleracaoMediaSensor5 = (velocidadeMediaSensor5 - velocidadeMediaSensor4) / (tempoSensor5_ms - tempoSensor4_ms);
  Serial.print("Aceleração no sensor 5 é de:");
  Serial.print(aceleracaoMediaSensor5);
  Serial.println(" metros por segundos²");
}
