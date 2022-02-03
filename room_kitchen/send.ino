void send()
{
 
    myDHT.read();
    hDHT = myDHT.getHumidity();
    tDHT = myDHT.getTemperature();
      Serial.print("temp = ");
      Serial.print(tDHT,1);
      Serial.print("     hum = ");
      Serial.println(hDHT);
      

String data151;
  data151 = "device: ";
  data151 += DEVICE;
  data151 += ", DEVICE_ID: ";
  data151 += DEVICE_ID;
  data151 += ", tempC: ";
  data151 += tDHT;
  data151 += ", hum%: ";
  data151 += hDHT;
  data151 += ", freeRam: ";
  data151 += freeRam();
  data151 += ", millis: ";
  data151 += millis();

  tx.println(data151);

  // Serial.println(freeRam());
}
