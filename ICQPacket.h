#pragma once

#include "ICQPacket_define.h"
#include "Utils.h"
#include "Strings.h"
#include "Net.h"

class ICQPacket
{
private:
	char *pPacket;
	int nPacketSize;

	unsigned char GetFLAPChannel();
	void SetFLAPChannel(unsigned char Channel);
	unsigned short GetFLAPSequence();
	void SetFLAPSequence(unsigned short Sequence);
	unsigned short GetFLAPDataSize();
	void SetFLAPDataSize(unsigned short DataSize);
	bool IsFLAPPacket();
	void SetFLAPHeader(char Channel,short Sequence);
	int Add_u8(unsigned char cU8);
	int Add_u16_BE(unsigned short sU16);
	int Add_u32_BE(unsigned int nU32);
	int Add_blob(char *bData,int nDataSize);
	int Add_string(TCHAR *pszString);
	int Add_TLVheader(unsigned short Type,unsigned short Length);
	int Add_TLV_u16(unsigned short Type,unsigned short sU16);
	int Add_TLV_u32(unsigned short Type,unsigned int nU32);
	int Add_TLV_blob(unsigned short Type,char *bData,int nDataSize);
	int Add_TLV_string(unsigned short Type,TCHAR *pszString);
	int Add_TLV_empty(unsigned short Type);
	int Add_TLV_password(unsigned short Type,TCHAR *pszPassword);
	bool IsTLVPresent(unsigned short Type);
	char *GetTLVPointer(unsigned short Type);
	unsigned short GetTLVTypeFromOffset(char *pOffset);
	unsigned short GetTLVLehgthFromOffset(char *pOffset);
public:
	ICQPacket(void);
	~ICQPacket(void);
	char *GetPacketPointer();
	int GetPacketSize();
	int Recv(SOCKET sock);
	int Send(SOCKET sock);
	bool IsHelloPacket();
	int CreateLoginPacket(int nSequence,TCHAR *pszUIN,TCHAR *pszPassword);
	int GetTLV_blob(unsigned short Type,char *pBuffer,int nBufferSize);
	int GetTLV_string(unsigned short Type,TCHAR *pszBuffer,int nBufferLength);
	
};