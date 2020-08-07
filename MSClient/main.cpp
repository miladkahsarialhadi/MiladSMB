#include <SMBClient.h>

int wmain(int argc, const wchar_t* argv[])
{
	SMBFileSystem MiladSMBClient(L"WTwo", L"C$", L"Users\\W2\\Desktop\\");
	
	if (MiladSMBClient.MSC_CheckConnection())
	{
		MiladSMBClient.MSC_ListFilesDirectories(L"C:\\Users\\W2\\");
	}
	else
	{
		std::wcout << L"We have not a connection with remote machine." << std::endl;
	}

	system("PAUSE");

	return 0;
}