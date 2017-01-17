/*
 * FastAnalogRead.h
 *
 *  Created on: 16 ene. 2017
 *      Author: idduarte
 */

#ifndef SRC_FASTANALOGREAD_H_
#define SRC_FASTANALOGREAD_H_
#include<Arduino.h>

class FastAnalogRead {
public:
	FastAnalogRead();
	virtual ~FastAnalogRead();
	uint16_t getValue(uint8_t ch);
	void setPrescalerValue(byte ps);
	uint16_t getOversampledValue(uint8_t ch, uint8_t b);
};

#endif /* SRC_FASTANALOGREAD_H_ */

enum ADCPrescalerConstans
	: byte {
		PS_2 = 1,
		PS_4 = 2,
		PS_8 = 3,
		PS_16 = 4,
		PS_32 = 5,
		PS_64 = 6,
		PS_128 = 7
};

enum ADCUtils :byte{
		CLEAR = 7
};
