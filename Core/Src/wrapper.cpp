#include <l6470.hpp>
#include "wrapper.hpp"
#include "gpio.h"
#include "spi.h"

/* Pre-Processor Begin */
/* Pre-Processor End */

/* Enum, Struct Begin */

/* Enum, Struct End */

/* Function Prototype Begin */

/* Function Prototype End */

/* Variable Begin */
//l6470::L6470 l6470_driver(hspi1,{SPI1_CS_GPIO_Port,SPI1_CS_Pin},{L6470_BUSY_GPIO_Port,L6470_BUSY_Pin},1000);
l6470::L6470 l6470_driver(hspi1,{SPI1_CS_GPIO_Port,SPI1_CS_Pin});
/* Variable End */

void init(void){
	// driver
//	HAL_SPI_DeInit(&hspi1);
//	HAL_SPI_Init(&hspi1);
//
//
//	HAL_Delay(10);
//
//	l6470_driver.init(1);
//	HAL_Delay(1);
//	l6470_driver.voltage_acc (0xDF);
//	HAL_Delay(1);
//	l6470_driver.voltage_dec (0xDF);
//	HAL_Delay(1);
//	l6470_driver.voltage_run (0xDF);
//	HAL_Delay(1);
//	l6470_driver.voltage_hold(0x30);
//
//	HAL_Delay(1000);
//
//	l6470_driver.Goto(5000);
//	HAL_Delay(5000);
//
//	l6470_driver.Run(1000, false);
//	HAL_Delay(1000);
//
//	l6470_driver.SoftStop();
//	HAL_Delay(1000);
//
//	l6470_driver.Goto(0);
	// bigstone
	l6470_driver.begin();
	l6470_driver.set_hold_kval(0xff);

	l6470_driver.soft_reset();

	l6470_driver.set_param(l6470::Address::ADR_ACC,0x40);
	l6470_driver.set_param(l6470::Address::ADR_DEC,0x40);
	l6470_driver.set_param(l6470::Address::ADR_MAX_SPEED,0x030);
	l6470_driver.set_param(l6470::Address::ADR_MIN_SPEED,0x00);
	l6470_driver.set_param(l6470::Address::ADR_FS_SPD,0x3ff);
	l6470_driver.set_param(l6470::Address::ADR_KVAL_HOLD,0x50);
	l6470_driver.set_param(l6470::Address::ADR_KVAL_RUN,0x50);
	l6470_driver.set_param(l6470::Address::ADR_KVAL_ACC,0x50);
	l6470_driver.set_param(l6470::Address::ADR_KVAL_DEC,0xf50);
	l6470_driver.set_param(l6470::Address::ADR_STEP_MODE,0x07);

//	l6470_driver.run(0x030000,l6470::Direction::CW);

	l6470_driver.go_to(5000);
	HAL_Delay(5000);

	l6470_driver.run(1000, l6470::Direction::CCW);
	HAL_Delay(1000);

	l6470_driver.soft_stop();
	HAL_Delay(1000);

	l6470_driver.go_to(0);
}

void loop(void){

}

/* Function Body Begin */

/* Function Body End */
