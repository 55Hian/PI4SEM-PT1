void iniciarprocesso(){

  boolean estadoSensor9;  //recebe leitura do pino do sensor
  
  estadoSensor9 = digitalRead(sensor9); // Realiza leitura do pino 9 e inicia metodo ( responsavel por iniciar o processo - temporario, necessario alterar no projeto final)

  if (estadoSensor9 == 0 && verificaProcesso == true) { // se pino 9 enviou sinal e o processo pode ser iniciado

    if (zeraTempoInicioProcesso == true) { // se o tempo inicial do processo pode ser resetado

      millisIniciaProcesso = millis(); // Resetar tempo inicial do processo
      zeraTempoInicioProcesso = false; // Indica que o tempo inicial do processo não pode mais ser resetado

    }

    if ((millis() - millisIniciaProcesso) > 3000) { // se o tempo de inicio do processo for maior que 3 segundos

      Serial.println("Iniciando sistema de leitura.");

      inicioProcesso = true; // processo pode ser iniciado
      verificaProcesso = false; //Processo ja foi iniciado, metodo inicial pode ser desabilitado.

    }
  } else { // se o botão não foi pressionado por 3 segundo

    millisIniciaProcesso = millis(); // resetar tempo de contagem do botão de inicio do processo
  }
}
