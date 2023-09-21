#include <WiFi.h> //conexão wifi
#include <WiFiClientSecure.h> //biblioteca para conexão como cliente em sites

WiFiClientSecure client;
String textFix = "GET /forms/d/e/1FAIpQLSdg3z6ex3eqmtq50QU3exj6IZ96m6zCcOUUZiX2aO1Va6UClw/formResponse?ifq&entry.353115888="; //link formulario ( envio de dados para planilha )

const int sensor1 = 2;  // define o pino do sensor
const int sensor2 = 3;  // define o pino do sensor
const int sensor3 = 4;  // define o pino do sensor
const int sensor4 = 5;  // define o pino do sensor
const int sensor5 = 6;  // define o pino do sensor
const int sensor6 = 7;  // define o pino do sensor
const int sensor7 = 8;  // define o pino do sensor
const int sensor8 = 9;  // define o pino do sensor
const int sensor9 = 10; // define o pino do sensor

const int led = 11; // define o pino do led

const int tempo = 10; // tempo de fluxo ( não utilizado)

boolean estadoSensor1;  //recebe leitura do pino do sensor
boolean estadoSensor2;  //recebe leitura do pino do sensor
boolean estadoSensor3;  //recebe leitura do pino do sensor
boolean estadoSensor4;  //recebe leitura do pino do sensor
boolean estadoSensor5;  //recebe leitura do pino do sensor
boolean estadoSensor6;  //recebe leitura do pino do sensor
boolean estadoSensor7;  //recebe leitura do pino do sensor
boolean estadoSensor8;  //recebe leitura do pino do sensor
boolean estadoSensor9;  //recebe leitura do pino do sensor

boolean inicioProcesso = false; //Limitador de processo de leitura dos sensores

boolean liberasensor1 = false;  //Limitador de processo de leitura dos sensores
boolean liberasensor2 = false;  //Limitador de processo de leitura dos sensores
boolean liberasensor3 = false;  //Limitador de processo de leitura dos sensores
boolean liberasensor4 = false;  //Limitador de processo de leitura dos sensores
boolean liberasensor5 = false;  //Limitador de processo de leitura dos sensores
boolean liberasensor6 = false;  //Limitador de processo de leitura dos sensores
boolean liberasensor7 = false;  //Limitador de processo de leitura dos sensores
boolean liberasensor8 = false;  //Limitador de processo de leitura dos sensores
boolean liberasensor9 = false;  //Limitador de processo de leitura dos sensores

boolean verificaProcesso = true; //limitador de primeiro ciclo (inicio proceeso)
boolean controleSensor1 = true; //limitador para inicio de processo
boolean zeraTempoInicioProcesso = true; //limitador para reset de millis de inicio processo

boolean liberaCalculos = false; //limitador para inicio de calculos

boolean acionamentoSensor1 = false; //Limitador do tipo cascata do processo de leitura dos sensores
boolean acionamentoSensor2 = false; //Limitador do tipo cascata do processo de leitura dos sensores
boolean acionamentoSensor3 = false; //Limitador do tipo cascata do processo de leitura dos sensores
boolean acionamentoSensor4 = false; //Limitador do tipo cascata do processo de leitura dos sensores
boolean acionamentoSensor5 = false; //Limitador do tipo cascata do processo de leitura dos sensores
boolean acionamentoSensor6 = false; //Limitador do tipo cascata do processo de leitura dos sensores
boolean acionamentoSensor7 = false; //Limitador do tipo cascata do processo de leitura dos sensores
boolean acionamentoSensor8 = false; //Limitador do tipo cascata do processo de leitura dos sensores
boolean acionamentoSensor9 = false; //Limitador do tipo cascata do processo de leitura dos sensores

double millisIniciaProcesso = millis(); //Inicia função millis para comparador de processo
double tempoplacaligada = millis(); //Inicia função de tempo para verificação de logica

const double distanciaSensor1 = 0;  //armazena distancia fisica de instalação do sensor
const double distanciaSensor2 = 1;  //armazena distancia fisica de instalação do sensor
const double distanciaSensor3 = 2;  //armazena distancia fisica de instalação do sensor
const double distanciaSensor4 = 3;  //armazena distancia fisica de instalação do sensor
const double distanciaSensor5 = 4;  //armazena distancia fisica de instalação do sensor
const double distanciaSensor6 = 5;  //armazena distancia fisica de instalação do sensor
const double distanciaSensor7 = 6;  //armazena distancia fisica de instalação do sensor
const double distanciaSensor8 = 7;  //armazena distancia fisica de instalação do sensor
const double distanciaSensor9 = 8;  //armazena distancia fisica de instalação do sensor

double millisTempoSensor1 = millis(); //armazena tempo de leitura do sensor
double millisTempoSensor2 = millis(); //armazena tempo de leitura do sensor
double millisTempoSensor3 = millis(); //armazena tempo de leitura do sensor
double millisTempoSensor4 = millis(); //armazena tempo de leitura do sensor
double millisTempoSensor5 = millis(); //armazena tempo de leitura do sensor
double millisTempoSensor6 = millis(); //armazena tempo de leitura do sensor
double millisTempoSensor7 = millis(); //armazena tempo de leitura do sensor
double millisTempoSensor8 = millis(); //armazena tempo de leitura do sensor
double millisTempoSensor9 = millis(); //armazena tempo de leitura do sensor

double tempoSensor1_ms;
double tempoSensor2_ms;
double tempoSensor3_ms;
double tempoSensor4_ms;
double tempoSensor5_ms;
double tempoSensor6_ms;
double tempoSensor7_ms;
double tempoSensor8_ms;
double tempoSensor9_ms;

double velocidadeMediaSensor1;
double velocidadeMediaSensor2;
double velocidadeMediaSensor3;
double velocidadeMediaSensor4;
double velocidadeMediaSensor5;
double velocidadeMediaSensor6;
double velocidadeMediaSensor7;
double velocidadeMediaSensor8;
double velocidadeMediaSensor9;

double aceleracaoMediaSensor1;
double aceleracaoMediaSensor2;
double aceleracaoMediaSensor3;
double aceleracaoMediaSensor4;
double aceleracaoMediaSensor5;
double aceleracaoMediaSensor6;
double aceleracaoMediaSensor7;
double aceleracaoMediaSensor8;
double aceleracaoMediaSensor9;

void setup() {

  Serial.println("Projeto:          PI-4SEM-PT01");
  Serial.println("Versão:           0.1.3");
  Serial.println("Data:             20/09/2023");
  Serial.println("Autor:            Hian A. Damaceno");
  Serial.println("Copyright notice: Código de sensoriamento de pista e envio de dados para nuvem.");

  Serial.println("Iniciando parametrização do sistema");

  tempoplacaligada = millis(); // armazena tempo de placa ao iniciar o processo

  pinMode(sensor1, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital
  pinMode(sensor2, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital
  pinMode(sensor3, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital
  pinMode(sensor4, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital
  pinMode(sensor5, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital
  pinMode(sensor6, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital
  pinMode(sensor7, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital
  pinMode(sensor8, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital
  pinMode(sensor9, INPUT_PULLUP); //Define os pinos de sensores como entradas de sinal digital

  pinMode(led, OUTPUT); //Degine pino de indicador visual como saida

  Serial.begin(115200); // Inicia comunicação serial

  WiFi.mode(WIFI_STA);//Habilita o modo estaçao
  WiFi.begin("usuarioWifi", "senhaWifi");//Conecta na rede

  delay(2000);//Espera um tempo para se conectar no WiFi

  client.setInsecure(); // define a conexão do cliente como segura.

}

void loop() {

  estadoSensor9 = digitalRead(sensor9); // Realiza leitura do pino 9 e inicia metodo ( responsavel por iniciar o processo - temporario, necessario alterar no projeto final)

  if (estadoSensor9 == 0 && verificaProcesso == true) { // se pino 9 enviou sinal e o processo pode ser iniciado

    if (zeraTempoInicioProcesso == true) { // se o tempo inicial do processo pode ser resetado

      millisIniciaProcesso = millis(); // Resetar tempo inicial do processo
      zeraTempoInicioProcesso = false; // Indica que o tempo inicial do processo não pode mais ser resetado

    }

    if ((millis() - millisIniciaProcesso) > 3000) { // se o tempo de inicio do processo for maior que 3 segundos

      Serial.println("Iniciando sistema de leitura.");

      inicioProcesso = true; // processo pode ser iniciado

      digitalWrite(led, HIGH);  // indicador visual de inicio de processo
      delay(1000);              // indicador visual de inicio de processo
      digitalWrite(led, LOW);   // indicador visual de inicio de processo
      delay(500);               // indicador visual de inicio de processo
      digitalWrite(led, HIGH);  // indicador visual de inicio de processo
      delay(1000);              // indicador visual de inicio de processo
      digitalWrite(led, LOW);   // indicador visual de inicio de processo

      Serial.println("Sistema de leitura iniciado com sucesso!");

      verificaProcesso = false; //Processo ja foi iniciado, metodo inicial pode ser desabilitado.

    }
  } else { // se o botão não foi pressionado por 3 segundo

    millisIniciaProcesso = millis(); // resetar tempo de contagem do botão de inicio do processo

  }

  if (inicioProcesso == true) { // se o processo esta pronto para iniciar

    if (controleSensor1 == true) { // se o sensor 1 esta liberado para atuar

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
        Serial.println(acionamentoSensor1);
        Serial.println(millisTempoSensor1);
        Serial.println("-----------------");

        liberasensor1 = false; // encerrar processo do sensor

      }
    }

    if (liberasensor2 == true) { // se o processo do sensor esta liberado, iniciar o processo

      estadoSensor2 = digitalRead(sensor2); // realizar leitura do sensor

      if (estadoSensor2 == 0) { // se o sensor envio sinal

        acionamentoSensor2 = true;  // variavel que será enviada para nuvem, sensor foi acionado
        millisTempoSensor2 = millis();  // armazenar tempo em que o sensor foi acionado
        liberasensor3 = true; //liberar processo do proximo sensor

        Serial.println("Sensor 2");
        Serial.println(acionamentoSensor2);
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
        Serial.println(acionamentoSensor3);
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
        liberasensor5 = true;

        Serial.println("Sensor 4");
        Serial.println(acionamentoSensor4);
        Serial.println(millisTempoSensor4);
        Serial.println("-----------------");

        liberasensor4 = false;

      }
    }

    if (liberasensor5 == true) {

      estadoSensor5 = digitalRead(sensor5);

      if (estadoSensor5 == 0) {

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

    if (liberasensor6 == true) {
      
      estadoSensor6 = digitalRead(sensor6);
      
      if (estadoSensor6 == 0) {
        
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


    if (liberasensor7 == true) {
      
      estadoSensor7 = digitalRead(sensor7);
      
      if (estadoSensor7 == 0) {
        
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

    if (liberasensor8 == true) {
      
      estadoSensor8 = digitalRead(sensor8);
      
      if (estadoSensor8 == 0) {
        
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

    if (liberasensor9 == true) {
      
      estadoSensor9 = digitalRead(sensor9);
      
      if (estadoSensor9 == 0) {
        
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
    
    if (liberaCalculos == true) {

      double diferencaTempoPlaca = millisTempoSensor1 - tempoplacaligada;

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

      tempoSensor1_ms = millisTempoSensor1 / 1000;
      tempoSensor2_ms = millisTempoSensor2 / 1000;
      tempoSensor3_ms = millisTempoSensor3 / 1000;
      tempoSensor4_ms = millisTempoSensor4 / 1000;
      tempoSensor5_ms = millisTempoSensor5 / 1000;
      tempoSensor6_ms = millisTempoSensor6 / 1000;
      tempoSensor7_ms = millisTempoSensor7 / 1000;
      tempoSensor8_ms = millisTempoSensor8 / 1000;
      tempoSensor9_ms = millisTempoSensor9 / 1000;

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

      velocidadeMediaSensor5 = (distanciaSensor5 - distanciaSensor4) / (tempoSensor5_ms - tempoSensor4_ms);
      Serial.print("velocidade no sensor 5 é de:");
      Serial.print(velocidadeMediaSensor5);
      Serial.println(" metros por segundos");

      velocidadeMediaSensor6 = (distanciaSensor6 - distanciaSensor5) / (tempoSensor6_ms - tempoSensor5_ms);
      Serial.print("velocidade no sensor 6 é de:");
      Serial.print(velocidadeMediaSensor6);
      Serial.println(" metros por segundos");

      velocidadeMediaSensor7 = (distanciaSensor7 - distanciaSensor6) / (tempoSensor7_ms - tempoSensor6_ms);
      Serial.print("velocidade no sensor 7 é de:");
      Serial.print(velocidadeMediaSensor7);
      Serial.println(" metros por segundos");

      velocidadeMediaSensor8 = (distanciaSensor8 - distanciaSensor7) / (tempoSensor8_ms - tempoSensor7_ms);
      Serial.print("velocidade no sensor 8 é de:");
      Serial.print(velocidadeMediaSensor8);
      Serial.println(" metros por segundos");

      velocidadeMediaSensor9 = (distanciaSensor9 - distanciaSensor8) / (tempoSensor9_ms - tempoSensor8_ms);
      Serial.print("velocidade no sensor 9 é de:");
      Serial.print(velocidadeMediaSensor9);
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

      aceleracaoMediaSensor6 = (velocidadeMediaSensor6 - velocidadeMediaSensor5) / (tempoSensor6_ms - tempoSensor5_ms);
      Serial.print("Aceleração no sensor 6 é de:");
      Serial.print(aceleracaoMediaSensor6);
      Serial.println(" metros por segundos²");

      aceleracaoMediaSensor7 = (velocidadeMediaSensor7 - velocidadeMediaSensor6) / (tempoSensor7_ms - tempoSensor6_ms);
      Serial.print("Aceleração no sensor 7 é de:");
      Serial.print(aceleracaoMediaSensor7);
      Serial.println(" metros por segundos²");

      aceleracaoMediaSensor8 = (velocidadeMediaSensor8 - velocidadeMediaSensor7) / (tempoSensor8_ms - tempoSensor7_ms);
      Serial.print("Aceleração no sensor 8 é de:");
      Serial.print(aceleracaoMediaSensor8);
      Serial.println(" metros por segundos²");

      aceleracaoMediaSensor9 = (velocidadeMediaSensor9 - velocidadeMediaSensor8) / (tempoSensor9_ms - tempoSensor8_ms);
      Serial.print("Aceleração no sensor 9 é de:");
      Serial.print(aceleracaoMediaSensor9);
      Serial.println(" metros por segundos²");

      liberaCalculos = false;

    }
  }
  
  if (client.connect("docs.google.com", 443) == 1)//Tenta se conectar ao servidor do Google docs na porta 443 (HTTPS)
  {
    String toSend = textFix;//Atribuimos a String auxiliar na nova String que sera enviada
    toSend +=   acionamentoSensor1;
    toSend +=   ",";
    toSend +=   acionamentoSensor2;
    toSend +=   ",";
    toSend +=   acionamentoSensor3;
    toSend +=   ",";
    toSend +=   acionamentoSensor4;
    toSend +=   ",";
    toSend +=   acionamentoSensor5;
    toSend +=   ",";
    toSend +=   acionamentoSensor6;
    toSend +=   ",";
    toSend +=   acionamentoSensor7;
    toSend +=   ",";
    toSend +=   acionamentoSensor8;
    toSend +=   ",";
    toSend +=   acionamentoSensor9;
    toSend +=   ",";
    //toSend +=   acionamentoSensor10;
    //toSend +=   ",";
    toSend +=   tempoSensor1_ms;
    toSend +=   ",";
    toSend +=   tempoSensor2_ms;
    toSend +=   ",";
    toSend +=   tempoSensor3_ms;
    toSend +=   ",";
    toSend +=   tempoSensor4_ms;
    toSend +=   ",";
    toSend +=   tempoSensor5_ms;
    toSend +=   ",";
    toSend +=   tempoSensor6_ms;
    toSend +=   ",";
    toSend +=   tempoSensor7_ms;
    toSend +=   ",";
    toSend +=   tempoSensor8_ms;
    toSend +=   ",";
    toSend +=   tempoSensor9_ms;
    toSend +=   ",";
    //toSend +=   tempoSensor10_ms;
    //toSend +=   ",";
    toSend +=   velocidadeMediaSensor1;
    toSend +=   ",";
    toSend +=   velocidadeMediaSensor2;
    toSend +=   ",";
    toSend +=   velocidadeMediaSensor3;
    toSend +=   ",";
    toSend +=   velocidadeMediaSensor4;
    toSend +=   ",";
    toSend +=   velocidadeMediaSensor5;
    toSend +=   ",";
    toSend +=   velocidadeMediaSensor6;
    toSend +=   ",";
    toSend +=   velocidadeMediaSensor7;
    toSend +=   ",";
    toSend +=   velocidadeMediaSensor8;
    toSend +=   ",";
    toSend +=   velocidadeMediaSensor9;
    toSend +=   ",";
    //toSend +=   velocidadeMediaSensor1;
    //toSend +=   ",";
    toSend +=   aceleracaoMediaSensor1;
    toSend +=   ",";
    toSend +=   aceleracaoMediaSensor2;
    toSend +=   ",";    
    toSend +=   aceleracaoMediaSensor3;
    toSend +=   ",";
    toSend +=   aceleracaoMediaSensor4;
    toSend +=   ",";    
    toSend +=   aceleracaoMediaSensor5;
    toSend +=   ",";
    toSend +=   aceleracaoMediaSensor6;
    toSend +=   ",";   
    toSend +=   aceleracaoMediaSensor7;
    toSend +=   ",";
    toSend +=   aceleracaoMediaSensor8;
    toSend +=   ",";    
    toSend +=   aceleracaoMediaSensor9;
    toSend +=   ",";
    //toSend +=   aceleracaoMediaSensor10;
    //toSend +=   ",";   
    
    toSend += "&submit=Submit HTTP/1.1";//Completamos o metodo GET para nosso formulario.

    client.println(toSend);//Enviamos o GET ao servidor-
    client.println("Host: docs.google.com");//-
    client.println();//-
    client.stop();//Encerramos a conexao com o servidor
    Serial.println("Dados enviados.");//Mostra no monitor que foi enviado
  }
  else
  {
    Serial.println("Erro ao se conectar");//Se nao for possivel conectar no servidor, ira avisar no monitor.
  }
}
