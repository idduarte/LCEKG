enum SignalsID
	: byte {
		D1 = 0x00,
		D2 = 0x01,
		D3 = 0x02,
		aVL = 0x03,
		aVR = 0x04,
		aVF = 0x05,
		V1 = 0x06,
		V2 = 0x07,
		V3 = 0x08,
		V4 = 0x09,
		V5 = 0x10,
		V6 = 0x11
};

enum SignalsMask
	: byte {
		D1_MASK_BYTE_0 = 0x01,
		D2_MASK_BYTE_0 = 0x02,
		D3_MASK_BYTE_0 = 0x04,
		aVL_MASK_BYTE_0 = 0x08,
		aVR_MASK_BYTE_1 = 0x01,
		aVF_MASK_BYTE_1 = 0x02,
		V1_MASK_BYTE_1 = 0x04,
		V2_MASK_BYTE_1 = 0x08,
		V3_MASK_BYTE_2 = 0x01,
		V4_MASK_BYTE_2 = 0x02,
		V5_MASK_BYTE_2 = 0x04,
		V6_MASK_BYTE_2 = 0x08
};
