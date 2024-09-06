#include "wrapper.hpp"
#include <l6470.h>
#include <L6470_bigstone.h>
#include "gpio.h"
#include "spi.h"

/* Pre-Processor Begin */

/* Pre-Processor End */

/* Enum, Struct Begin */

/* Enum, Struct End */

/* Function Prototype Begin */

/* Function Prototype End */

/* Variable Begin */
l6470::L6470 l6470_driver(hspi1,{SPI1_CS_GPIO_Port,SPI1_CS_Pin},{L6470_BUSY_GPIO_Port,L6470_BUSY_Pin},1000);
l6470_big::L6470 l6470_driver_big(hspi1,{SPI1_CS_GPIO_Port,SPI1_CS_Pin});
/* Variable End */

void init(void){
	HAL_SPI_DeInit(&hspi1);
	HAL_SPI_Init(&hspi1);


	HAL_Delay(10);

	l6470_driver.init(1);
	HAL_Delay(1);
	l6470_driver.voltage_acc (0xDF);
	HAL_Delay(1);
	l6470_driver.voltage_dec (0xDF);
	HAL_Delay(1);
	l6470_driver.voltage_run (0xDF);
	HAL_Delay(1);
	l6470_driver.voltage_hold(0x30);

	HAL_Delay(1000);

	l6470_driver.Goto(5000);
	HAL_Delay(5000);

	l6470_driver.Run(1000, false);
	HAL_Delay(1000);

	l6470_driver.SoftStop();
	HAL_Delay(1000);

	l6470_driver.Goto(0);

	// bigstone
//	l6470_driver_big.begin();
//	l6470_driver_big.SetHoldKVAL(0xff);
//
//	l6470_driver_big.SoftReset();
//
//	l6470_driver_big.SetParam(ADR_ACC,2,0x40);
//	l6470_driver_big.SetParam(ADR_DEC,2,0x40);
//	l6470_driver_big.SetParam(ADR_MAX_SPEED,2,0x030);
//	l6470_driver_big.SetParam(ADR_MIN_SPEED,2,0x00);
//	l6470_driver_big.SetParam(ADR_FS_SPD,2,0x3ff);
//	l6470_driver_big.SetParam(ADR_KVAL_HOLD,1,0x50);
//	l6470_driver_big.SetParam(ADR_KVAL_RUN,1,0x50);
//	l6470_driver_big.SetParam(ADR_KVAL_ACC,1,0x50);
//	l6470_driver_big.SetParam(ADR_KVAL_DEC,1,0xf50);
//	l6470_driver_big.SetParam(ADR_STEP_MODE,1,0x07);
//
//	l6470_driver_big.run(0x030000,CW);
}

void loop(void){

}

/* Function Body Begin */

/* Function Body End */
