typedef unsigned char uchar;
typedef unsigned short ushort;
class  CReaderforCus
{
public:
	virtual int GetIndex();
	virtual int GetConfig(char* cConfig,int nlen);
	virtual int SetConfig(char* cConfig,int nlen);
	virtual int SetVcc(int nVcc);
	virtual int SetFreq(int nFreq);
	virtual int SetVpp(int nVpp);
	virtual int	 Get_Reader_Handle(int &iModel,int &iNode,int &iID);
	virtual int	 CardOpen();
	virtual int	 CardReset(uchar*	ucATR,int* ATRLg);
	virtual int	 SetPPS(uchar * ucPPS,ushort nPPSLen);
	virtual int	 Transmit(uchar * ucSend,ushort nSend,uchar * ucRecv,ushort *nRecv,uchar*ucSW);
	virtual int	 CardClose();
	virtual int	 CardDownFile(char* File,int nLen);
	virtual int  CardExecute(char* File,int nLen);
	virtual int	 SetApduTimeout(int nApduTimeout);
	virtual int  CardResetWarm(uchar* ucATR,int* ATRLg);
	virtual int  CardOff();
};