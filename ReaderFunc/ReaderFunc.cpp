// ReaderFunc.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "ReaderFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//


// CReaderFuncApp

BEGIN_MESSAGE_MAP(CReaderFuncApp, CWinApp)
END_MESSAGE_MAP()


// CReaderFuncApp ����

CReaderFuncApp::CReaderFuncApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CReaderFuncApp ����

CReaderFuncApp theApp;


// CReaderFuncApp ��ʼ��


BOOL CReaderFuncApp::InitInstance()
{
	CWinApp::InitInstance();
	return TRUE;
}

int _stdcall RegisterCardOSTest(fnCardOSTestFunc pFunc)
{
	m_FCardOSTestFunc = pFunc;
	return 0;
}

int _stdcall CardOSTestFunc(CReaderforCus* hReader,unsigned long InputVcc,unsigned long Refer,unsigned long Cmask,unsigned long Vl,unsigned long Vh,unsigned long* pOpen,unsigned long* pShort,OSVoltage& osVol)
{
	if (m_FCardOSTestFunc!=NULL)
	{
		return m_FCardOSTestFunc(hReader,InputVcc,Refer,Cmask,Vl,Vh,pOpen,pShort,osVol);
	}
}

int _stdcall RegisterWriteLog(fnWriteLogFunc pFunc)
{
	m_FWriteLogFunc = pFunc;
	return 0;
}

int _stdcall WriteLogFunc(CReaderforCus* hReader,char* pLogInfo,int nLog)
{
	if (m_FWriteLogFunc!=NULL)
	{
		return m_FWriteLogFunc(hReader,pLogInfo,nLog);
	}
}



