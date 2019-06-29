// ReaderFunc.h : ReaderFunc DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "ReaderforCus.h"

struct OSVoltage
{
	int C1V;
	int C2V;
	int C3V;
	int C4V;
	int C5V;
	int C6V;
	int C7V;
	int C8V;
};

// CReaderFuncApp
// 有关此类实现的信息，请参阅 ReaderFunc.cpp
//

class CReaderFuncApp : public CWinApp
{
public:
	CReaderFuncApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

typedef int (CALLBACK *fnCardOSTestFunc)(CReaderforCus* hReader,unsigned long InputVcc,unsigned long Refer,unsigned long Cmask,unsigned long Vl,unsigned long Vh,unsigned long* pOpen,unsigned long* pShort,OSVoltage& osVol);
fnCardOSTestFunc m_FCardOSTestFunc = NULL;

typedef int (CALLBACK *fnWriteLogFunc)(CReaderforCus* hReader,char* pLogInfo,int nLog);
fnWriteLogFunc m_FWriteLogFunc = NULL;
