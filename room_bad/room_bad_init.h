/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            settings bedbath
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//	#include "room_kitchen_init.h"
//  Блок GBUS UART  -----------------------------------------------------------
// принимаем запрос и отправляем в ответ данные с АЦП
#define GT_PRINT_MODE   // для отправки через print
#define GT_STREAM_MODE  // STREAM_MODE нужен для работы GBUS
#include <GyverTransfer.h>
GyverTransfer<2, GT_TRX, 2400, 20> trans;

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
