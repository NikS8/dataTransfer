void send()
{
 
    myDHT.read();
    hDHT = myDHT.getHumidity();
    tDHT = myDHT.getTemperature();
      Serial.print("temp = ");
      Serial.print(tDHT,1);
      Serial.print("     hum = ");
      Serial.println(hDHT);
      
  tx.print("device: ");
  tx.println(DEVICE);
  tx.print("deviceId: ");
  tx.println(DEVICE_ID);

  tx.print("temp: ");
  tx.println(tDHT);
  
  tx.print("hum: ");
  tx.println(hDHT);
  
  tx.print("freeRam: ");
  tx.println(freeRam());
 
  tx.print("upTime: ");
  tx.println(millis());

  // Serial.println(freeRam());
}
