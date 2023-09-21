#include <Ultrasonic.h> // biblioteca ultrassonico (temporario)
#define pino_trigger 4  //ultrassonico
#define pino_echo 5     //ultrassonico
Ultrasonic ultrasonic(pino_trigger, pino_echo); //ultrassonico

#include <WiFi.h> //conexão wifi
#include <WiFiClientSecure.h> //biblioteca para conexão como cliente em sites

WiFiClientSecure client;
String textFix = "GET /forms/d/e/1FAIpQLSdg3z6ex3eqmtq50QU3exj6IZ96m6zCcOUUZiX2aO1Va6UClw/formResponse?ifq&entry.353115888="; //link formulario ( envio de dados para planilha )

String usuarioWifi = "usuario"; //usuario wifi 
String senhaWifi = "senha"; //senha wifi

boolean sensor1 = 0; //No projeto final serão inputs (HIGH ou LOW), sera o pino que recebe o sinal do sensor
boolean sensor2 = 0; //No projeto final serão inputs (HIGH ou LOW), sera o pino que recebe o sinal do sensor

boolean stSensor1 = 0; //recebe informação de leitura do sensor (se leitura existir == 1)
boolean stSensor2 = 0; //recebe informação de leitura do sensor (se leitura existir == 1)
int statusSensores[6];  //Variavel global dos sensores que libera proxima função (verificação nuvem)

boolean stNuvem = 0;  //Variavel global do sistema de envio dos dados que libera proxima função ()

float tempoSensor1;
float tempoSensor2;
float tempoSensor3;
float tempoSensor4;
float tempoSensor5;
float tempoSensor6;

const float distanciaSensor1 = 1;
const float distanciaSensor2 = 2;
const float distanciaSensor3 = 3;
const float distanciaSensor4 = 4;
const float distanciaSensor5 = 5;
const float distanciaSensor6 = 6;


void statusSensores();
void statusNuvem();
void leituraSensores();
void tratamentoDados();
void envioNuvem();
void sensorUltraSonico();

void setup(){
  Serial.begin(9600);
  
 // pinMode(sensor1, INPUT); Comentario pois funcionara em modo de prototipagem
 // pinMode(sensor2, INPUT); Comentario pois funcionara em modo de prototipagem

  WiFi.mode(WIFI_STA);//Habilita o modo estaçao
  WiFi.begin(usuarioWifi, senhaWifi);//Conecta na rede
  client.setInsecure(); // define a conexão do cliente como segura.
}

void loop(){
  
  statusSensores();

  if (stSensor == 1){ //precisa adicionar "contato de selo" para não ficar flodando a conexão com nuvem
    statusNuvem();
  }

  if (stNuvem = 1){  //precisa adicionar "contato de selo" para não ficar flodando processo pronto para iniciar
    Serial.println("Sistema pronto para iniciar o processo");
  }


  
}

void statusSensores(){



  // if (sensor1 == true){ //verifica sensor 1
  //   Serial.println("Sensores 1 prontos");
  //   statusSensores[0] = 1;
  // } else {
  //   Serial.println("Verificar conexão do sensor 1")
  //   statusSensores[0] = 0;
  // }

  // if (sensor2 == true){ //verifica sensor 2
  //   Serial.println("Sensor 1 pront");
  //   statusSensores[1] = 1;
  // } else {
  //   Serial.println("Verificar conexão do sensor 2")
  //   statusSensores[1] = 0;
  // }

  //   if (sensor3 == true){ //verifica sensor 3
  //   Serial.println("Sensor 3 pronto");
  //   statusSensores[2] = 1;
  // } else {
  //   Serial.println("Verificar conexão do sensor 3")
  //   statusSensores[2] = 0;
  // }

  //   if (stSensor4 == true){ //verifica sensor 4
  //   Serial.println("Sensor 4 pronto");
  //   statusSensores[3] = 1
  // } else {
  //   Serial.println("Verificar conexão do sensor 4")
  // }

  //   if (stSensor5 == true){ //verifica sensor 5
  //   Serial.println("Sensor 5 pronto");
  //   statusSensores[4] = 1
  // } else {
  //   Serial.println("Verificar conexão do sensor 5")
  // }

  //   if (stSensor6 == true){ //verifica sensor 6
  //   Serial.println("Sensor 6 pronto");
  //   statusSensores[5] = 1
  // } else {
  //   Serial.println("Verificar conexão do sensor 6")
  // }

}

void statusNuvem(){
  if (!client.connect("docs.google.com", 443))
    Serial.println("Não foi possivel estabelecer conexão com o servidor");
  else {
    Serial.println("Conexão com o servidor foi estabelecida");
    stNuvem = 1;
  }

}

void leituraSensores(){

}

void tratamentoDados(){


}

void envioNuvem(){
  if (client.connect("docs.google.com", 443) == 1)//Tenta se conectar ao servidor do Google docs na porta 443 (HTTPS)
  {
    String toSend = textFix;//Atribuimos a String auxiliar na nova String que sera enviada
    toSend +=   sensor1;
    toSend +=   ",";
    toSend +=   sensor2;
    toSend +=   ",";
    toSend +=   sensor3;
    toSend +=   ",";
    toSend +=   sensor4;
    toSend +=   ",";
    toSend +=   sensor5;
    toSend +=   ",";
    toSend +=   sensor6;
    toSend +=   ",";
    toSend +=   tempoSensor1;
    toSend +=   ",";
    toSend +=   tempoSensor2;
    toSend +=   ",";
    toSend +=   tempoSensor3;
    toSend +=   ",";
    toSend +=   tempoSensor4;
    toSend +=   ",";
    toSend +=   tempoSensor5;
    toSend +=   ",";
    toSend +=   tempoSensor6;
    
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

void sensorUltraSonico(){
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  if(sensor1 == 0){
    if (cmMsec <= 10){
    
    }
  }
  delay(100);

}
