/**
 *                   ESTRUCTURA DEL MENSAJE
 *
 * |type2 |type1 |type0 |msid4 |msid3 |msid2 |msid1 |msid0 | BYTE 0
 * |sgid15|sgid14|sgid13|sgid12|sgid11|sgid10|sgid09|sgid08| BYTE 1
 * |sgid7 |sgid6 |sgid5 |sgid4 |sgid3 |sgid2 |sgid1 |sgid0 | BYTE 2
 * |                       DATA BYTE 1                     | BYTE 3
 * |                       DATA BYTE 2                     | BYTE 4
 * |                       TIME BYTE 1                     | BYTE 5
 * |                       TIME BYTE 2                     | BYTE 6
 * |                       TIME BYTE 3                     | BYTE 7
 * |                       TIME BYTE 4                     | BYTE 8
 *
 */


struct Message{
  byte type;
  byte messageID;
  uint16_t signalID;
  uint16_t data;
  unsigned long timeStamp;
};
