#pragma once

/*
	(C) by FORCE67 2017
	you may only share this file with permission.
*/

#include "WinHttpClient.h"

namespace net
{
	class requests
	{
	private:
		wchar_t m_UserAgent[255];
		bool certificates;
	public:
		requests(wchar_t * useragent,bool certificate)
		{
			wcsncpy_s(m_UserAgent, useragent, sizeof(useragent));
			certificates = certificate;
		}

		// usual post method
		std::wstring Post(bool header, wchar_t * url, const char * postdata, ...)
		{
			static char buffer[32768];

			va_list ap;
			va_start(ap, postdata);
			int length = vsnprintf(buffer, 32768, postdata, ap);
			va_end(ap);

			WinHttpClient client(url);

			client.SetRequireValidSslCertificates(this->certificates);

			// Useragent 
			client.SetUserAgent(this->m_UserAgent);

			// Set post data.
			string data(buffer);
			client.SetAdditionalDataToSend((BYTE *)data.c_str(), data.size());

			// Set request headers.
			wchar_t szSize[50] = L"";
			swprintf_s(szSize, L"%zd", data.size()); //d
			wstring headers = L"Content-Length: ";
			headers += szSize;
			headers += L"\r\nContent-Type: application/x-www-form-urlencoded\r\n";
			client.SetAdditionalRequestHeaders(headers);

			// Send HTTP post request.
			client.SendHttpRequest(L"POST");

			return header ? client.GetResponseHeader() : client.GetResponseContent();
		}

		// Usual get method
		std::wstring Get(bool header,wchar_t * url)
		{
			// Set URL.
			WinHttpClient client(url);

			client.SetRequireValidSslCertificates(this->certificates);

			// Useragent 
			client.SetUserAgent(this->m_UserAgent);

			// Send HTTP request, a GET request by default.
			client.SendHttpRequest();

			return header ? client.GetResponseHeader() : client.GetResponseContent();
		}
		
		bool DownLoadFile(const wchar_t * url, const wchar_t * physicalalloc)
		{
			WinHttpClient downloadClient(url);

			// Useragent 
			downloadClient.SetUserAgent(this->m_UserAgent);

			return downloadClient.SaveResponseToFile(physicalalloc);
		}

	};
}