#include "../util/ByteUtils.h"
enum MessagesId
	: byte {
		ID_START_ADQ = 0x00,
		ID_STOP_ADQ = 0x01,
		ID_SIGNALS_CFG = 0x02,
		ID_PARAMETERS_CFG = 0x03
};

enum MessagesByteMask
	:byte {
		ID_MASK = 0B00011111,
		TYPE_MASK = 0B11100000,
		BYTE_MASK = 0XFF
};

enum MessagesLongMask
	:unsigned long {
		MASK_BYTE_0 = 0xFF,
		MASK_BYTE_1 = 0xFF00,
		MASK_BYTE_2 = 0xFF0000,
		MASK_BYTE_3 = 0XFF000000
};

enum MessagesType
	: byte {
		COMMAND = 0x00,
		DELTA_STATUS = 0x01,
		DATA_REQUEST = 0x02
};

enum MessageConstants
	:byte {
		SIZE = 9,
		TYPE_FIELD = ByteSelector::BYTE_0,
		ID_FIELD = ByteSelector::BYTE_0,
		SIGNAL_ID_FIELD_1 = ByteSelector::BYTE_1,
		SIGNAL_ID_FIELD_2 = ByteSelector::BYTE_2,
		DATA_FIELD_1 = ByteSelector::BYTE_3,
		DATA_FIELD_2 = ByteSelector::BYTE_4,
		TIMESTAMP_FIELD_1 = ByteSelector::BYTE_5,
		TIMESTAMP_FIELD_2 = ByteSelector::BYTE_6,
		TIMESTAMP_FIELD_3 = ByteSelector::BYTE_7,
		TIMESTAMP_FIELD_4 = ByteSelector::BYTE_8,
};
