/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            createDataString
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
String createDataString() {
  
        ardStruct151 data151;
    bus.readData(data151);

    Serial.println(data151.deviceId);
    Serial.println(data151.hDHT);
    Serial.println(data151.tDHT);
    Serial.println(data151.freRam);
    Serial.println(data151.timeWork);

    Serial.println();
    Serial.println();
  
  String resultData;

    resultData.concat(F("{\n"));
  resultData.concat(F("device: "));
  resultData.concat(DEVICE);
  resultData.concat(F(",\n"));
  resultData.concat(F("deviceId: "));
  resultData.concat(DEVICE_ID);  
    resultData.concat(F(",\n"));
  resultData.concat(F("version: "));
  resultData.concat(VERSION);
   resultData.concat(F(",\n"));

  resultData.concat(F("data:"));
    resultData.concat(F("\t{\n"));
   resultData.concat(F("\tfromDeviceId: "));
  resultData.concat(data151.deviceId);  
    resultData.concat(F(",\n"));
    resultData.concat(F("\tTemperature *C: "));
    resultData.concat(data151.tDHT);
  resultData.concat(F(",\n"));
   resultData.concat(F("\tHumidity %: "));
    resultData.concat(data151.hDHT);
  resultData.concat(F(",\n"));
  resultData.concat(F("\tfreeRam: "));
  resultData.concat(data151.freRam);
    resultData.concat(F(",\n"));
  resultData.concat(F("\tupTime: "));
  resultData.concat(upTime(data151.timeWork));
  resultData.concat(F("\n\t}"));
  
  resultData.concat(F(",\n"));
  resultData.concat(F("freeRam: "));
  resultData.concat(freeRam());
    resultData.concat(F(",\n"));
  resultData.concat(F("upTime: "));
  resultData.concat(upTime(millis()));
  resultData.concat(F("\n}"));

  return resultData;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
