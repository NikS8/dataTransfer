//
void read() {
    // если приняты какие то данные (встроенный таймаут)
  if (rx.gotData()) {
//    Data151 data;
//  static byte count;
//  count++;
    // прочитать данные, если они
    // приняты корректно и соответствуют размеру
    if (rx.readDataCRC(data151)) {
//    if (rx.readData(data151)) {

    Serial.println(data151.hDHT);
    Serial.println(data151.tDHT);
    Serial.println(data151.freRam);
    Serial.println(data151.timeWork);

    Serial.println();
//    Serial.println();
//    Serial.println();

    } else {
      // иначе данные повреждены или не той длины!
      upError++;
      Serial.print("error   ");
      Serial.println(upError);
      // сами разбираем если нужно
      // .................      
    }
    rx.clearBuffer(); // обязательно вручную чистим буфер
  }
}
