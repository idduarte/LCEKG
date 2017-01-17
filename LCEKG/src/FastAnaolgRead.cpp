/*
 * FastAnaolgRead.cpp
 *
 *  Created on: 16 ene. 2017
 *      Author: idduarte
 */

#include "FastAnaolgRead.h"

FastAnaolgRead::~FastAnaolgRead() {
}

uint16_t FastAnaolgRead::readValue(uint8_t chanel) {
	return analogRead(chanel);
}

FastAnaolgRead::FastAnaolgRead() {
}

void FastAnaolgRead::setPrescaler(byte ps) {
	  ADCSRA &= ~ADCUtils::CLEAR;  // remove bits set by Arduino library
	  ADCSRA |= ps; // set prescaler PS
}
