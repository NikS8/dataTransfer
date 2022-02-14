/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            send
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
  void send(){
//byte data152;
  String data;
 // data = "152";

  data = "FROM_ID:";
  data += DEVICE_ID;
  data += ";humidity:";
  data += hDHT;
  data += ";temperature:";
  data += tDHT;
  data += ";freeRam:";
  data += freeRam();
  data += ";micros:";
  data += micros();
  data += ";millis:";
  data += millis();

//  trans.writeData(data152); 
   Serial.print("sending: ");
    Serial.println(data);
    trans.println(data);
//    Serial.println(data);
  // Serial.println(freeRam());
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/