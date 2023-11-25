#include <HTTPClient.h>
#include <Wifi.h>
#include "string.h"
#include <Ultrasonic.h>


const char* ssid     = "CACHORRO";     // login wifi
const char* password = "hi12345678"; // senha wifi

char *server = "script.google.com";  // Server URL
char *GScriptId = "AKfycbyUE57iXdUKcIFGmmWDlvwG-M3Jp603cKawPlfvUnqpxCraYGqkGMNOFtfkaBv5K8QA"; //planilha teste

WiFiClientSecure client;

long tempoEnvio = 0;

const int sensor1 = 14;  // define o pino do sensor (pino sem pull up interno)
const int sensor2 = 16;  // define o pino do sensor
const int sensor3 = 17;  // define o pino do sensor
const int sensor4 = 18;  // define o pino do sensor
const int sensor9 = 23; // define o pino do sensor

#define pino_trigger 4
#define pino_echo 5

Ultrasonic ultrasonic(pino_trigger, pino_echo);

const int led = 25  ; // define o pino do led
const int pinoSinaleiroFim = 35; // define o pino do sinaleiro

boolean estadoSensor1;  //recebe leitura do pino do sensor
boolean estadoSensor2;  //recebe leitura do pino do sensor
boolean estadoSensor3;  //recebe leitura do pino do sensor
boolean estadoSensor4;  //recebe leitura do pino do sensor
boolean estadoSensor5;  //recebe leitura do pino do sensor



boolean liberasensor1 = false;  //Limitador de processo de leitura dos sensores
boolean liberasensor2 = false;  //Limitador de processo de leitura dos sensores
boolean liberasensor3 = false;  //Limitador de processo de leitura dos sensores
boolean liberasensor4 = false;  //Limitador de processo de leitura dos sensores
boolean liberasensor5 = false;  //Limitador de processo de leitura dos sensores


boolean controleSensor1 = true; //limitador para inicio de processo


boolean liberaCalculos = false; //limitador para inicio de calculos

boolean acionamentoSensor1 = false; //Limitador do tipo cascata do processo de leitura dos sensores
boolean acionamentoSensor2 = false; //Limitador do tipo cascata do processo de leitura dos sensores
boolean acionamentoSensor3 = false; //Limitador do tipo cascata do processo de leitura dos sensores
boolean acionamentoSensor4 = false; //Limitador do tipo cascata do processo de leitura dos sensores
boolean acionamentoSensor5 = false; //Limitador do tipo cascata do processo de leitura dos sensores

boolean acionamentoSensor9 = false; //Limitador do tipo cascata do processo de leitura dos sensores

boolean acionaEnvioDeDados = false; //Aciona o envio dos dados

boolean resetSistema = false;


double tempoplacaligada = millis(); //Inicia função de tempo para verificação de logica

double millisTempoSensor1 = millis(); //armazena tempo de leitura do sensor
double millisTempoSensor2 = millis(); //armazena tempo de leitura do sensor
double millisTempoSensor3 = millis(); //armazena tempo de leitura do sensor
double millisTempoSensor4 = millis(); //armazena tempo de leitura do sensor
double millisTempoSensor5 = millis(); //armazena tempo de leitura do sensor
double millisTempoSensor9 = millis(); //armazena tempo de leitura do sensor

double millisIniciaProcesso = millis(); //Inicia função millis para comparador de processo

double tempoSensor9_ms;

boolean inicioProcesso = false; //Limitador de processo de leitura dos sensores
boolean verificaProcesso = true; //limitador de primeiro ciclo (inicio proceeso)
boolean zeraTempoInicioProcesso = true; //limitador para reset de millis de inicio processo

void enviodosdados();
void calculos();
void iniciarprocesso();

void setup() {
  Serial.begin(115200); // Inicia comunicação serial
  tempoplacaligada = millis(); // armazena tempo de placa ao iniciar o processo
  
  Serial.println("Projeto:          PI-4SEM-PT01");
  Serial.println("Versão:           0.1.3");
  Serial.println("Data:             20/09/2023");
  Serial.println("Autor:            Hian A. Damaceno");
  Serial.println("Copyright notice: Código de sensoriamento de pista e envio de dados para nuvem.");
  Serial.println(" ");
  Serial.println("Iniciando parametrização do sistema");
  Serial.println(" ");

  Serial.print("Conectando a rede Wifi: ");
  Serial.println(ssid);
  Serial.flush();
  WiFi.begin(ssid, password);
  Serial.println("");
  
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("");
  
  pinMode(sensor1, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital
  pinMode(sensor2, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital
  pinMode(sensor3, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital
  pinMode(sensor4, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital
  pinMode(sensor9, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital
  pinMode(led, OUTPUT); //Degine pino de indicador visual como saida
  pinMode(pinoSinaleiroFim, OUTPUT); //Degine pino de indicador visual como saida

  digitalWrite(led, LOW);
  digitalWrite(pinoSinaleiroFim, LOW);
  
  delay(2000);//Espera um tempo para se conectar no WiFi

  liberasensor1 = false;  //Limitador de processo de leitura dos sensores
  liberasensor2 = false;  //Limitador de processo de leitura dos sensores
  liberasensor3 = false;  //Limitador de processo de leitura dos sensores
  liberasensor4 = false;  //Limitador de processo de leitura dos sensores

  acionamentoSensor1 = false; //Limitador do tipo cascata do processo de leitura dos sensores
  acionamentoSensor2 = false; //Limitador do tipo cascata do processo de leitura dos sensores
  acionamentoSensor3 = false; //Limitador do tipo cascata do processo de leitura dos sensores
  acionamentoSensor4 = false; //Limitador do tipo cascata do processo de leitura dos sensores
      
  inicioProcesso = false;
  verificaProcesso = true;
  zeraTempoInicioProcesso = true;
  controleSensor1 = true;

  Serial.println("Parametrização do sistema concluida");
  Serial.println(" ");
}

void loop() {

iniciarprocesso();

  if (inicioProcesso == true) { // se o processo esta pronto para iniciar
    
    digitalWrite(led, HIGH);  // indicador visual de inicio de processo
    
    if (controleSensor1 == true) { // se o sensor 1 esta liberado para atuar
      Serial.println("Sistema de leitura iniciado com sucesso!");
      liberasensor1 = true; //liberar processo do sensor 1
      controleSensor1 = false; // se o sensor 1 esta liberado para atuar, desabilitar metodo de controle do sensor 1
    }

    if (liberasensor1 == true) { // se o processo do sensor esta liberado, iniciar o processo

      estadoSensor1 = digitalRead(sensor1); // realizar leitura do sensor

      if (estadoSensor1 == 0) { // se o sensor envio sinal

        acionamentoSensor1 = true;  // variavel que será enviada para nuvem, sensor foi acionado
        millisTempoSensor1 = millis();  // armazenar tempo em que o sensor foi acionado
        liberasensor2 = true; //liberar processo do proximo sensor

        Serial.println("Sensor 1");
        Serial.println(millisTempoSensor1);
        Serial.println("-----------------");

        liberasensor1 = false; // encerrar processo do sensor

      }
    }

    if (liberasensor2 == true) { // se o processo do sensor esta liberado, iniciar o processo

      estadoSensor2 = digitalRead(sensor2); // realizar leitura do sensor

      if (estadoSensor2 == 1) { // se o sensor envio sinal

        acionamentoSensor2 = true;  // variavel que será enviada para nuvem, sensor foi acionado
        millisTempoSensor2 = millis();  // armazenar tempo em que o sensor foi acionado
        liberasensor3 = true; //liberar processo do proximo sensor

        Serial.println("Sensor 2");
        Serial.println(millisTempoSensor2);
        Serial.println("-----------------");

        liberasensor2 = false;  // encerrar processo do sensor

      }
    }

    if (liberasensor3 == true) { // se o processo do sensor esta liberado, iniciar o processo

      estadoSensor3 = digitalRead(sensor3); // realizar leitura do sensor

      if (estadoSensor3 == 0) { // se o sensor envio sinal

        acionamentoSensor3 = true;  // variavel que será enviada para nuvem, sensor foi acionado
        millisTempoSensor3 = millis();  // armazenar tempo em que o sensor foi acionado
        liberasensor4 = true; //liberar processo do proximo sensor

        Serial.println("Sensor 3");
        Serial.println(millisTempoSensor3);
        Serial.println("-----------------");

        liberasensor3 = false;  // encerrar processo do sensor

      }
    }

    if (liberasensor4 == true) {

      estadoSensor4 = digitalRead(sensor4);

      if (estadoSensor4 == 0) {

        acionamentoSensor4 = true;
        millisTempoSensor4 = millis();

        Serial.println("Sensor 4");
        Serial.println(millisTempoSensor4);
        Serial.println("-----------------");

        liberasensor4 = false;

      }
    }

       if (liberasensor5 == true) {
        // Envia pulso para o disparar o sensor
        float cmMsec, inMsec;
        long microsec = ultrasonic.timing();
        cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
        Serial.println(cmMsec);
        if(cmMsec <= 17){
          estadoSensor5 = 0;
         }
         if (estadoSensor5 == 0) { 
          
          acionamentoSensor5 = true;
          millisTempoSensor5 = millis();
          liberaCalculos = true;
  
          Serial.println("Sensor 5");
          Serial.println(millisTempoSensor5);
          Serial.println("-----------------");
          digitalWrite(pinoSinaleiroFim, HIGH);  // indicador visual de CHEGADA
          liberasensor5 = false;

      }
    }
     
    if (liberaCalculos == true) {

      calculos();
      
      liberaCalculos = false;
      acionaEnvioDeDados = true;
      inicioProcesso = false;
    }
  }
  if(acionaEnvioDeDados == true){

  enviodosdados();
  
  resetSistema = true;
  acionaEnvioDeDados = false;
    }
   
    if(resetSistema == true){


      liberasensor1 = false;  //Limitador de processo de leitura dos sensores
      liberasensor2 = false;  //Limitador de processo de leitura dos sensores
      liberasensor3 = false;  //Limitador de processo de leitura dos sensores
      liberasensor4 = false;  //Limitador de processo de leitura dos sensores
      liberasensor5 = false;  //Limitador de processo de leitura dos sensores
      
      acionamentoSensor1 = false; //Limitador do tipo cascata do processo de leitura dos sensores
      acionamentoSensor2 = false; //Limitador do tipo cascata do processo de leitura dos sensores
      acionamentoSensor3 = false; //Limitador do tipo cascata do processo de leitura dos sensores
      acionamentoSensor4 = false; //Limitador do tipo cascata do processo de leitura dos sensores
      acionamentoSensor5 = false; //Limitador do tipo cascata do processo de leitura dos sensores

      inicioProcesso = false;
      verificaProcesso = true;
      zeraTempoInicioProcesso = true;
      controleSensor1 = true;

      digitalWrite(pinoSinaleiroFim, LOW);  // indicador visual de CHEGADA
      digitalWrite(led, LOW);  // indicador visual de inicio de processo
      Serial.println("Desligando sistema de leitura leitura.");

      resetSistema = false;
    } 
}
