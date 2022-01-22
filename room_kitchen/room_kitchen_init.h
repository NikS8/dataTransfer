/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            settings bedbath
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//	#include "room_kitchen_init.h"
//  Блок GBUS UART  -----------------------------------------------------------
// отправка данных по однопроводному юарту
GyverTransfer<2, GT_TRX, 2400, 20> tx;

struct struct151 {
  int deviceId = DEVICE_ID;
  int hDHT;
  float tDHT;
  int freRam;
  uint32_t timeWork;
};

//  Блок Energy Monitor  ------------------------------------------------------
/*
EnergyMonitor emon1;
EnergyMonitor emon2;
EnergyMonitor emon3;
*/
//  Блок DHT  -----------------------------------------------------------------
#define pinDHT_VCC 11    // пин VCC сенсора 
//#define pinDHT_GND 3    // пин GND сенсора 
#define pinDHT_OUT 12    // сигнальный пин 
DHTNEW myDHT(pinDHT_OUT);

float tDHT = 22.2;
int hDHT = 44;
uint32_t preMillis = millis();

//	Блок TIME  ----------------------------------------------------------------
#define RESET_UPTIME_TIME 43200000  //  = 30 * 24 * 60 * 60 * 1000 
// reset after 30 days uptime

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
