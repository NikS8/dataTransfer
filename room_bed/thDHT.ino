//
void thDHT() {
  /*
    myDHT.read();
    hDHT = myDHT.getHumidity();
    tDHT = myDHT.getTemperature();
    */
      Serial.print("temp = ");
      Serial.print(tDHT,1);
      Serial.print("     hum = ");
      Serial.println(hDHT);
  
}
//
