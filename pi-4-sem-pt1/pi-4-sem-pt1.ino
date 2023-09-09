#include <Ultrasonic.h>
#define pino_trigger 4
#define pino_echo 5
Ultrasonic ultrasonic(pino_trigger, pino_echo);

#include <WiFi.h>
#include <WiFiClientSecure.h>

WiFiClientSecure client;
String textFix = "GET /forms/d/e/1FAIpQLSdg3z6ex3eqmtq50QU3exj6IZ96m6zCcOUUZiX2aO1Va6UClw/formResponse?ifq&entry.353115888="; //link formulario ( envio de dados para planilha )
 

boolean sensor1 = 0; //No projeto final serão inputs (HIGH ou LOW), sera o pino que recebe o sinal do sensor
boolean sensor2 = 0; //No projeto final serão inputs (HIGH ou LOW), sera o pino que recebe o sinal do sensor

boolean stSensor1 = 0;
boolean stSensor2 = 0;

boolean stSensor = 0;
boolean stNuvem = 0;

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
  WiFi.begin("CACHORRO", "hi12345678");//Conecta na rede
  client.setInsecure(); // seta a conexão do cliente como segura.
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
  if (stSensor1 == 1 && stSensor2 == 1){
    stSensor = 1;
    Serial.println("Sensores prontos");
  } else{
    Serial.println("Verificar conexão dos sensores");
  }
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
