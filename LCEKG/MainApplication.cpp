#include <Arduino.h>
#include "MainApplication.h"


void clearBuffer();
void configureADQ();
void processMessage();

boolean isCommandRecived = false;
boolean isExecutting = false;
byte messageRecived[MessageConstants::SIZE];
Message message;

void setup() {
	Serial.begin(115200);
}

void loop() {
	if (isCommandRecived) {
		processMessage();
		isCommandRecived = false;
	} else if (isExecutting) {
		//TODO
	}
}

void serialEvent() {
	while (Serial.available()) {
		Serial.readBytes(messageRecived, MessageConstants::SIZE);
		message.type = (messageRecived[MessageConstants::TYPE_FIELD]
				& MessagesByteMask::TYPE_MASK) >> ShiftRegister::FIVE_BITS;
		message.messageID = messageRecived[MessageConstants::ID_FIELD]
				& MessagesByteMask::ID_MASK;
		message.signalID =
				(((uint16_t) (messageRecived[MessageConstants::SIGNAL_ID_FIELD_1])
						<< ShiftRegister::ONE_BYTE) & MessagesLongMask::MASK_BYTE_1)
						| (((byte) (messageRecived[MessageConstants::SIGNAL_ID_FIELD_2])));
		message.data =
				(((uint16_t) (messageRecived[MessageConstants::DATA_FIELD_1])
						<< ShiftRegister::ONE_BYTE) & MessagesLongMask::MASK_BYTE_1)
						| (((byte) (messageRecived[MessageConstants::DATA_FIELD_2])));
		message.timeStamp =
				(((unsigned long) (messageRecived[MessageConstants::TIMESTAMP_FIELD_1])
						<< ShiftRegister::THREE_BYTES)
						& MessagesLongMask::MASK_BYTE_3)
						| (((unsigned long) (messageRecived[MessageConstants::TIMESTAMP_FIELD_2])
								<< ShiftRegister::TWO_BYTES)
								& MessagesLongMask::MASK_BYTE_2)
						| (((unsigned long) (messageRecived[MessageConstants::TIMESTAMP_FIELD_3])
								<< ShiftRegister::ONE_BYTE)
								& MessagesLongMask::MASK_BYTE_1)
						| messageRecived[MessageConstants::TIMESTAMP_FIELD_4];
		isCommandRecived = true;
		clearBuffer();
	}
}

void processMessage() {
	switch (message.type) {
	case MessagesType::COMMAND:
		//TODO
		switch (message.messageID) {
		case MessagesId::ID_START_ADQ:
			//TODO
			break;
		case MessagesId::ID_STOP_ADQ:
			//TODO
			break;
		case MessagesId::ID_SIGNALS_CFG:
			//TODO
			break;
		case MessagesId::ID_PARAMETERS_CFG:
			//TODO
			break;
		default:
			break;
		}
		break;
	case MessagesType::DELTA_STATUS:
		//TODO
		break;
	case MessagesType::DATA_REQUEST:
		//TODO
		break;
	default:
		//TODO
		break;
	}
}

void clearBuffer() {
	for (byte i = 0; i < MessageConstants::SIZE; i++) {
		messageRecived[i] = 0;
	}
	Serial.flush();
}
void configureADQ() {
	//TODO
}
