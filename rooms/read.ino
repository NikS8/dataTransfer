//
void readUART() {
    // выводим сырые данные
    for (byte i = 0; i < bus.rawSize(); i++) {
      byte val = bus.buffer[i];
      Serial.print(bus.buffer[i]);
      Serial.print(',');
}
}