enum MessagesId
	: byte {
		ID_START_ADQ = 0x00,
		ID_STOP_ADQ = 0x01,
		ID_SIGNALS_CFG = 0x02,
		ID_PARAMETERS_CFG = 0x03
};

enum MessagesMask
	:byte {
		ID_MASK = B00011111,
		TYPE_MASK = 0B11100000,
};

enum MessagesType: byte {
	COMMAND = 0x00,
	DELTA_STATUS = 0x01,
	DATA_REQUEST = 0x02
};



/*
 const byte MSG_ID_START_ADQ = 0x00;
 const byte MSG_ID_STOP_ADQ = 0x01;
 const byte MSG_ID_SIGNALS_CFG = 0x02;
 const byte MSG_ID_PARAMETERS_CFG = 0x03;
 */
