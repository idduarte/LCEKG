/*
 * FastAnaolgRead.h
 *
 *  Created on: 16 ene. 2017
 *      Author: idduarte
 */
#include<Arduino.h>

#ifndef FASTANAOLGREAD_H_
#define FASTANAOLGREAD_H_

class FastAnaolgRead {
public:
	FastAnaolgRead();
	virtual ~FastAnaolgRead();
	uint16_t readValue(uint8_t chanel);
	void setPrescaler(byte ps);
};

#endif /* FASTANAOLGREAD_H_ */

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

