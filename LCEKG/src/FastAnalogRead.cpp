/*
 * FastAnalogRead.cpp
 *
 *  Created on: 16 ene. 2017
 *      Author: idduarte
 */

#include "FastAnalogRead.h"

FastAnalogRead::FastAnalogRead() {
	// TODO Auto-generated constructor stub

}

FastAnalogRead::~FastAnalogRead() {
	// TODO Auto-generated destructor stub
}

uint16_t FastAnalogRead::getValue(uint8_t chanel) {
	return analogRead(chanel);
}

void FastAnalogRead::setPrescalerValue(byte ps) {
	ADCSRA &= ~ADCUtils::CLEAR;  // remove bits set by Arduino library
	ADCSRA |= ps; // set prescaler PS
}
