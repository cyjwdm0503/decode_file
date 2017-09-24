#include "request.h"
#include "utf8togb2312.h"
#include <iostream>
CRequest::CRequest()
{
		// Initialize the User Agent
		m_client.SetInternet ("My Custom User Agent") ;

		// Specifies whether to use UTF-8 encoding. (This uses ANSI encoding)
		// Default is FALSE
		m_client.SetUseUtf8 (FALSE) ;

		// Specifies a code page for ANSI strings. (This uses Korean)
		// Default is CP_ACP
		m_client.SetAnsiCodePage (949) ;

		// Add user's custom HTTP headers
		m_client.AddHeader("Host","xueqiu.com");
		m_client.AddHeader("Connection","keep-alive");
		m_client.AddHeader("User-Agent:","Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36");
		m_client.AddHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8");
		m_client.AddHeader("Accept-Encoding","gzip, deflate, br");
		m_client.AddHeader("Accept-Language","zh-CN,zh;q=0.8,en;q=0.6");
		//m_client.AddHeader (("Ryeol-Magic"), ("My Magic Header")) ;
		//m_client.AddHeader (("User-Magic"), ("User's Magic Header")) ;

		//m_client.
		m_response = NULL;
		m_uft8 =  false;
		
}

bool CRequest::RequestUrl( const char* url,ostream& out )
{
	string str;
	if(!RequestUrl(url))
		return false;
	
	if(!ReadResponse(str))
		return false;
	else
	{
		out.write(str.data(),str.size());
		return true;
	}

}

bool CRequest::RequestUrl( const char* url,streambuf& out )
{
	string str;
	if(!RequestUrl(url))
		return false;

	if(!ReadResponse(str))
		return false;
	else
	{
		out.pubsetbuf((char*)str.data(),str.size());
		return true;
	}
}

bool CRequest::RequestUrl( const char* url,string& out )
{
	string str;
	if(!RequestUrl(url))
		return false;

	if(!ReadResponse(str))
		return false;
	else
	{
		out = str;
		return true;
	}
}

CHttpResponse* CRequest::RequestUrl( const char* url )
{
	try
	{
		m_response  = m_client.RequestGet(url);
	}
	catch (httpclientexception& e)
	{
		std::cerr<<e.what()<<std::endl;
		return NULL;
	}
	return m_response;
}

void CRequest::SetCookie(const char* cookie)
{
	m_client.AddHeader("Cookie",cookie);
}

bool CRequest::ReadResponse( string& buf )
{
	char* tmp =  new char[BUFF_SIZE];
	int len = -1;
	if(m_response != NULL)
	{
		try
		{
			len = m_response->ReadContent((BYTE*)tmp,BUFF_SIZE);
			//std::cout<<tmp<<endl;

			FILE* codeFile = fopen("tmp.data","w");
			if(codeFile != NULL)
			{
				std::fwrite(tmp,1,len,codeFile);
				std::fflush(codeFile);
				std::fclose(codeFile);
				cout<<"write tmp over"<<endl;
			}


		}
		catch (httpclientexception& e)
		{
			std::cerr<<e.what()<<std::endl;
			return false;
		}

		if(m_uft8 == true)
		{
			string utfstr(tmp,len);
			string ascistr = Utf8ToAscii(utfstr);
			memset(tmp,0,BUFF_SIZE);
			buf.append(ascistr.c_str(),ascistr.size());
		}
		else
			buf.append(tmp,len);
	}
	return true;
}

void CRequest::SetUTF8toGB2312( bool flag )
{
	m_uft8 =  flag;
}

