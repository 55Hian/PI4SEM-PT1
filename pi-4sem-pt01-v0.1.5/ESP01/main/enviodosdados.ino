const int httpsPort = 443;

void enviodosdados(){
  
  HTTPClient http;

  tempoEnvio = millis() - tempoEnvio;
  String url = String("https://script.google.com") + "/macros/s/" + GScriptId + "/exec?" + 
  "value1=" + acionamentoSensor1 + "&value2=" + acionamentoSensor2 + "&value3=" + acionamentoSensor3 + "&value4=" + acionamentoSensor4 + 
  "&value5=" + tempoSensor1_ms + "&value6=" + tempoSensor2_ms + "&value7=" + tempoSensor3_ms + "&value8=" + tempoSensor4_ms + 
  "&value9=" + velocidadeMediaSensor1 + "&value10=" + velocidadeMediaSensor2 + "&value11=" + velocidadeMediaSensor3 + "&value12=" + velocidadeMediaSensor4 + 
  "&value13=" + aceleracaoMediaSensor1 + "&value14=" + aceleracaoMediaSensor2 + "&value15=" + aceleracaoMediaSensor3 + "&value16=" + aceleracaoMediaSensor4;
  
  tempoEnvio = millis();
  
  Serial.print("Making a request");
  http.begin(url.c_str()); //Specify the URL and certificate
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  int httpCode = http.GET();
  String payload;
  if (httpCode > 0) { //Check for the returning code
    payload = http.getString();

    Serial.println(httpCode);
    Serial.println(payload);
    //     testdrawstyles(payload);
    //if (httpCode == 200 or httpCode == 201) tempPing.Saida(0);
  }
  else {
    Serial.println("Error on HTTP request");
  }
  http.end();
}
