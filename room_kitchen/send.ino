void sendUART()
{
  ardStruct151 data151;

  data151.deviceId = 151;
  data151.hDHT = hDHT;
  data151.tDHT = tDHT;
  data151.freRam = freeRam();
  data151.timeWork = millis();

  bus.sendData(100, data151); // на адрес 100

  //  Serial.println(data151);
  // Serial.println(freeRam());
}
