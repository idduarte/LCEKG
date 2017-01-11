#include <Arduino.h>
//PRUEBA DE GIT
#include "lib/messages/MessagesEnumeration.h"
#include "lib/messages/MessageStructure.h"
#include "lib/signals/SignalsEnumeration.h"
#include "lib/util/BitsUtils.h"

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
    }else if(isExecutting){
      //TODO
    }
  }


  void serialEvent() {
    while (Serial.available()) {
      Serial.readBytes(messageRecived,MessageZise::SIZE);
      message.type = (messageRecived[0] & MessagesMask::TYPE_MASK) >>BitRotate::FIVE_BITS;
      message.messageID = messageRecived[0] & MessagesMask::ID_MASK;
      message.signalID = messageRecived[1];
      message.data = (((unsigned int)(messageRecived[2]) << BitRotate::ONE_BYTE) & 0xFF00) | messageRecived[3];
      message.timeStamp = (((unsigned long)(messageRecived[4]) << BitRotate::THREE_BYTES) & 0xFF000000) |
                          (((unsigned long)(messageRecived[5]) << BitRotate::TWO_BYTES) & 0xFF0000) |
                          (((unsigned long)(messageRecived[6]) << BitRotate::ONE_BYTE) & 0xFF00) |
                          messageRecived[7];
      isCommandRecived = true;
      clearBuffer();
    }
  }

  void processMessage(){
    switch(message.type){
      case MessagesType::COMMAND:
      //TODO
        switch(message.messageID){
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

  void clearBuffer(){
    for(byte i = 0; i < 8; i++){
      messageRecived[i]=0;
    }
    Serial.flush();
  }
  void configureADQ(){
    //TODO
  }
