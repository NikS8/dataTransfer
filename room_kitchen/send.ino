void send()
{
  struct151 data151;

  data151.deviceId = 151;
  data151.hDHT = hDHT;
  data151.tDHT = tDHT;
  data151.freRam = freeRam();
  data151.timeWork = millis();

  tx.writeDataCRC(data151); 

  //  Serial.println(data151);
  // Serial.println(freeRam());
}
