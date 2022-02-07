/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
                                                                   rooms.ino 
                                            Copyright © 2022, Zigfred & Nik.S
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\                            
  Arduino Pro Mini:
Скетч использует 16998 байт (55%) памяти устройства. Всего доступно 30720 байт.
Глобальные переменные используют 727 байт (35%) динамической памяти.
/*****************************************************************************\
  Сервер bedbath выдает данные:
    цифровые:
датчик температуры и влажности DHT (pin D9)
/*****************************************************************************/

//  Блок DEVICE  --------------------------------------------------------------
//  Arduino Pro Mini
#define DEVICE "room_kitchen"
#define DEVICE_ID 151
#define VERSION 1

//  Блок libraries  -----------------------------------------------------------
#include <mString.h>
#include "dhtnew.h"

//  Блок settings  ------------------------------------------------------------
#include "room_kitchen_init.h"

//	end init  -----------------------------------------------------------------

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void setup() {
  pinMode(pinDHT_VCC, OUTPUT);      // устанавливает режим работы - выход

  Serial.begin(9600);
  Serial.println("Serial.begin(9600)");
  Serial.println();
  
  digitalWrite(pinDHT_VCC, HIGH);   // включает +5v
  
  attachInterrupt(0, isr, CHANGE);

 // preMillis = millis();

}



// GyverTransfer читает в прерывании
void isr() {
  trans.tickISR();
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            loop
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void loop() {
// здесь принимаются данные
  // если это аппаратный сериал - слишком часто его опрашивать даже не нужно
  bus.tick();

  // приняли данные
  if (bus.gotRequest()) {
    Serial.print("request from: ");
    Serial.println(bus.getTXaddress());

    // ответили
    //bus.sendAck(bus.getTXaddress());

    // ИЛИ отправили дату в ответ

    thDHT();
    
    // отправляем каждые 2 секунды
    send();
  }

	resetChecker();
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            info
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
09.01.2022 v1 UART --> UART
22.01.2022 v2 GyverTransfer
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            end
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
