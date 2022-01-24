/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            createDataString
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
String createDataString() {
  
    struct151 data151;
    bus.readData(data151);
    
GBUSstatus checkGBUS(SOFTUART_BUF_SIZE, 20, 20, 100);
/*
GBUSstatus checkGBUS(uint8_t* buffer, uint8_t bufSize, uint8_t amount, uint8_t addr) {
    if (buffer[0] > bufSize) return RX_OVERFLOW;									// буфер переполнен
    if (amount > GBUS_OFFSET && amount > buffer[0]) return RX_OVERFLOW;				// пакет слишком большой
    if (buffer[1] != addr && buffer[1] != 255) return RX_ADDRESS_ERROR;				// не наш адрес
    if (amount < GBUS_OFFSET || (amount > GBUS_OFFSET && amount < buffer[0])) return RX_ABORT;		// передача прервана	
    if (GBUS_CRC) if (GBUS_crc_bytes(buffer, amount) != 0) return RX_CRC_ERROR;		// данные повреждены			
    if (buffer[0] == 0) return RX_REQUEST;											// реквест				
    if (buffer[0] == 1) return RX_ACK;												// подтверждение
    return RX_DATA;																	// данные приняты успешно
}


   if (checkGBUS == RX_CRC_ERROR)
   {
     errorCRC++;
   }
   else
   {
     valn++;
   }
  */ 
 

 //   Serial.println(getTXaddress());
    Serial.println(data151.deviceId);
    Serial.println(data151.hDHT);
    Serial.println(data151.tDHT);
    Serial.println(data151.freRam);
    Serial.println(data151.timeWork);

  if (data151.deviceId != 151)
   {
     errorCRC++;
   }
   else
   {
     valn++;
   }

    Serial.println();
  
  String resultData;

    resultData.concat(F("{"));
//      resultData.concat(F("\ndeviceId: "));

    resultData.concat(F("\n"));
  resultData.concat(F("\"device\": \""));
  resultData.concat(DEVICE);
    resultData.concat(F("\",\n"));
  resultData.concat(F("\"deviceId\": "));
  resultData.concat(DEVICE_ID);  
    resultData.concat(F(",\n"));
  resultData.concat(F("version: "));
  resultData.concat(VERSION);
   resultData.concat(F(",\n"));
  resultData.concat(F("UART <---> UART"));
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
    resultData.concat(F(",\n"));
  resultData.concat(F("EtherClient: "));
  resultData.concat(etherClient);
    resultData.concat(F(",\n"));
  resultData.concat(F("up N: "));
  resultData.concat(valn);
     resultData.concat(F(",\n"));
  resultData.concat(F("CRCerror: "));
  resultData.concat(errorCRC);
  resultData.concat(F("\n}"));

  return resultData;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
