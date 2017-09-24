
#include "RyeolHttpClient.h"
#include <istream>
#include <ostream>
#include <streambuf>
using namespace std;
using namespace Ryeol;

const size_t BUFF_SIZE = 1024*1024;//1M

class CRequest
{
public:
	CRequest();
	void SetCookie(const char* cookie);
	bool RequestUrl(const char* url,ostream& out);
	bool RequestUrl(const char* url,streambuf& out);
	bool RequestUrl(const char* url,string& out);
	void SetUTF8toGB2312(bool flag);
private:
	CHttpResponse* RequestUrl(const char* url);
	bool ReadResponse(string& buf);
	CHttpClient m_client;
	CHttpResponse* m_response;
	bool m_uft8;


};