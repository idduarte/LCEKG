#include <Arduino.h>
//PRUEBA DE GIT
#include "lib/messages/MessagesEnumeration.h"
#include "lib/messages/MessageStructure.h"
#include "lib/signals/SignalsEnumeration.h"
#include "lib/util/BitsUtils.h"
#include "lib/util/ByteUtils.h"


//Prototipes
void processMessage();
void clearBuffer();
void configureADQ();

boolean isCommandRecived = false;
boolean isExecutting = false;
byte messageRecived[8];
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
		message.type = (messageRecived[ByteSelector::BYTE_0]
				& MessagesByteMask::TYPE_MASK) >> ShiftRegister::FIVE_BITS;
		message.messageID = messageRecived[ByteSelector::BYTE_0]
				& MessagesByteMask::ID_MASK;
		message.signalID =
				(((uint16_t) (messageRecived[ByteSelector::BYTE_1])
						<< ShiftRegister::ONE_BYTE) & MessagesLongMask::MASK_BYTE_1)
						| (((byte) (messageRecived[ByteSelector::BYTE_2])));
		message.data =
				(((uint16_t) (messageRecived[ByteSelector::BYTE_3])
						<< ShiftRegister::ONE_BYTE) & MessagesLongMask::MASK_BYTE_1)
						| (((byte) (messageRecived[ByteSelector::BYTE_4])));
		message.timeStamp =
				(((unsigned long) (messageRecived[ByteSelector::BYTE_5])
						<< ShiftRegister::THREE_BYTES)
						& MessagesLongMask::MASK_BYTE_3)
						| (((unsigned long) (messageRecived[ByteSelector::BYTE_6])
								<< ShiftRegister::TWO_BYTES)
								& MessagesLongMask::MASK_BYTE_2)
						| (((unsigned long) (messageRecived[ByteSelector::BYTE_7])
								<< ShiftRegister::ONE_BYTE)
								& MessagesLongMask::MASK_BYTE_1)
						| messageRecived[ByteSelector::BYTE_8];
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
