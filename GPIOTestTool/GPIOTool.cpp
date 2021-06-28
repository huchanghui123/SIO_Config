#include "pch.h"
#include "GPIOTool.h"
#include "dll/OlsApiInitExt.h"


int superio_inw(int reg)
{
	int val;
	WriteIoPortByte(REG, reg++);
	val = ReadIoPortByte(VAL) << 8;
	WriteIoPortByte(REG, reg);
	val |= ReadIoPortByte(VAL);
	return val;
}

void GPIOTool::SioInit()
{
	WriteIoPortByte(REG, 0x87);
	WriteIoPortByte(REG, 0x01);
	WriteIoPortByte(REG, 0x55);
	WriteIoPortByte(REG, 0x55);
}

void GPIOTool::SioExit()
{
	WriteIoPortByte(0x20, REG);
	WriteIoPortByte(0x20, VAL);
}

int GPIOTool::GetChipName()
{
	SioInit();

	WriteIoPortByte(REG, LDNREG);
	WriteIoPortByte(VAL, GPIO);

	chipName = superio_inw(0x20);

	SioExit();

	return chipName;
}

void GPIOTool::MyWriteIoPortByte(WORD reg, BYTE val)
{
	SioInit();

	WriteIoPortByte(REG, reg);
	WriteIoPortByte(VAL, val);

	SioExit();
}

BYTE GPIOTool::MyReadIoPortByte(BYTE reg)
{
	
	SioInit();

	WriteIoPortByte(REG, reg);
	BYTE val = ReadIoPortByte(VAL);

	SioExit();
	
	return val;
}

void GPIOTool::MyWriteIoPortByteEx(WORD addr, BYTE val)
{
	SioInit();

	WriteIoPortByte(addr, val);

	SioExit();
}




