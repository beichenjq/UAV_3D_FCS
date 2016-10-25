/***************************************************************
* Copyright (c) 2016, �µ���
* All rights reserved.
*
* �ļ����ƣ�UdpClient.cpp
* ժ    Ҫ������Ŀ��TCPͨ�����ʵ���ļ���
*
* ��ǰ�汾��1.0
* ��    �ߣ��µ���
* ������ڣ�2016-10-25
***************************************************************/
#include "stdafx.h"
#include "UdpClient.h"


CUdpClient::CUdpClient() : m_Pump(), m_client(m_Pump)
{


}


CUdpClient::~CUdpClient()
{
}

/*! @function
********************************************************************************
* ������   : StartUdpConnect
* ����     : ����UDP���� 
* ����     : void
* ����ֵ   : void
* ����     : �µ��� �ϲ����մ�ѧ��Ϣ����ѧԺ�Զ�����ϵ
* ����     : 2016-10-25
*******************************************************************************/
void CUdpClient::StartUdpConnect()
{ 
	m_Pump.start_service();
}


/*! @function
********************************************************************************
* ������   : StopUdpConnect
* ����     : �Ͽ�UDP����
* ����     : void
* ����ֵ   : void
* ����     : �µ��� �ϲ����մ�ѧ��Ϣ����ѧԺ�Զ�����ϵ
* ����     : 2016-10-25
*******************************************************************************/
void CUdpClient::StopUdpConnect()
{
	if (m_Pump.is_running())
	{
		m_Pump.stop_service();
	}
	
}

/*! @function
********************************************************************************
* ������   : SetLocalPort
* ����     : ����UDP�ı��ض˿�
* ����     : LocalPort : ���ؼ����Ķ˿�
* ����ֵ   : void
* ����     : �µ��� �ϲ����մ�ѧ��Ϣ����ѧԺ�Զ�����ϵ
* ����     : 2016-10-25
*******************************************************************************/
void CUdpClient::SetLocalPort(const unsigned short LocalPort)
{
	m_client.set_local_addr(LocalPort);
}

/*! @function
********************************************************************************
* ������   : SetUdpAddr
* ����     : �������ӵ�UDP�������˿�ip��port
* ����     : ip : ���ؼ���UDP������ip
			 port�����ؼ�����UDP�������˿�
* ����ֵ   : void
* ����     : �µ��� �ϲ����մ�ѧ��Ϣ����ѧԺ�Զ�����ϵ
* ����     : 2016-10-25
*******************************************************************************/
void CUdpClient::SetUdpAddr(const std::string& ip, const unsigned short PeerPort)
{
	m_PeerAddr = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(ip), PeerPort);
}