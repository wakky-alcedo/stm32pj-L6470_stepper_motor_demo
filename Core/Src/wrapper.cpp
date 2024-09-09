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
l6470::L6470 l6470_driver(hspi1,{SPI1_CS_GPIO_Port,SPI1_CS_Pin}, 0xf);
/* Variable End */

void init(void){
	l6470_driver.init();
	l6470_driver.set_kval_hold(0xff);

	l6470_driver.soft_reset();

	l6470_driver.set_param(l6470::Address::ADR_ACC,2,0x40);
	l6470_driver.set_param(l6470::Address::ADR_DEC,2,0x40);
	l6470_driver.set_param(l6470::Address::ADR_MAX_SPEED,2,0x030);
	l6470_driver.set_param(l6470::Address::ADR_MIN_SPEED,2,0x00);
	l6470_driver.set_param(l6470::Address::ADR_FS_SPD,2,0x3ff);
	l6470_driver.set_param(l6470::Address::ADR_KVAL_HOLD,1,0x50);
	l6470_driver.set_param(l6470::Address::ADR_KVAL_RUN,1,0x50);
	l6470_driver.set_param(l6470::Address::ADR_KVAL_ACC,1,0x50);
	l6470_driver.set_param(l6470::Address::ADR_KVAL_DEC,1,0xf50);
	l6470_driver.set_param(l6470::Address::ADR_STEP_MODE,1,0x07);

//	l6470_driver.run(0x030000,l6470::Direction::CW);

	l6470_driver.go_to(5000);
	HAL_Delay(1000);

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
