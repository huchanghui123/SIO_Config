#pragma once

#define REG 0x2e
#define VAL 0x2f
#define LDNREG 0x07
#define GPIO 0x07

class GPIOTool
{
public:
	int chipName;
	void SioInit();
	void SioExit();
	int GetChipName();
	void MyWriteIoPortByte(WORD, BYTE);
	BYTE MyReadIoPortByte(BYTE);
	void MyWriteIoPortByteEx(WORD, BYTE);
};

