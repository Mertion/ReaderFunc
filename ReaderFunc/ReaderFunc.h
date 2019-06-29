// ReaderFunc.h : ReaderFunc DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
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
// �йش���ʵ�ֵ���Ϣ������� ReaderFunc.cpp
//

class CReaderFuncApp : public CWinApp
{
public:
	CReaderFuncApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

typedef int (CALLBACK *fnCardOSTestFunc)(CReaderforCus* hReader,unsigned long InputVcc,unsigned long Refer,unsigned long Cmask,unsigned long Vl,unsigned long Vh,unsigned long* pOpen,unsigned long* pShort,OSVoltage& osVol);
fnCardOSTestFunc m_FCardOSTestFunc = NULL;

typedef int (CALLBACK *fnWriteLogFunc)(CReaderforCus* hReader,char* pLogInfo,int nLog);
fnWriteLogFunc m_FWriteLogFunc = NULL;
