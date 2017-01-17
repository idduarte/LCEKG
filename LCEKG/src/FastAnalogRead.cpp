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

uint16_t FastAnalogRead::getValue(uint8_t ch) {
	return analogRead(ch);
}

void FastAnalogRead::setPrescalerValue(byte ps) {
	ADCSRA &= ~ADCUtils::CLEAR;  // remove bits set by Arduino library
	ADCSRA |= ps; // set prescaler PS
}

uint16_t FastAnalogRead::getOversampledValue(uint8_t ch, uint8_t b) {
	uint16_t value = 0;
	for(int i = 0; i<(1<<b);i++){
		value+=analogRead(ch);
	}
	return (uint16_t)(value>>b);
}
