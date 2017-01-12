/*
 * MsgManager.h
 *
 *  Created on: 12/01/2017
 *      Author: wancho
 */

#ifndef MSGMANAGER_H_
#define MSGMANAGER_H_

class MsgManager {
	byte *msg;
public:
	MsgManager(byte *m);
	virtual ~MsgManager();
	void Decode();
};

#endif /* MSGMANAGER_H_ */
