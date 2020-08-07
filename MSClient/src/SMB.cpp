#include "SMB.h"

// Constructor will initialize member variables with required information
// to work with remote machines via SMB/CIFS standard path
SMBInit::SMBInit(std::wstring arg_name, std::wstring arg_share_name, std::wstring arg_dir_name)
{
	m_remote_machine = arg_name;
	m_share_name = arg_share_name;
	m_dir_name = arg_dir_name;

	MSC_PrepareSmbPath();
}

// Fills version structure member with library information
// we can use this information in advance 
Version SMBInit::MSC_Version()
{
	Version lib_version;
	lib_version.max = 1;
	lib_version.min = 0;
	lib_version.revise = 0;
#if _X86_
	lib_version.arch = L"x86";
#else
	lib_version.arch = L"x64";
#endif
	lib_version.codename = L"Luminary";

	return lib_version;
}

// Prepare main SMB path for further working and analysis
// but its static behavior couldn't solve our major problems
// because of that initializer help us to work with path dynamically
void SMBInit::MSC_PrepareSmbPath()
{
	m_smb_path = L"\\\\";
	m_smb_path.append(m_remote_machine);
	m_smb_path.append(L"\\");
	m_smb_path.append(m_share_name);
	m_smb_path.append(L"\\");
	m_smb_path.append(m_dir_name);
	m_smb_path.append(L"\\");
}

// Initializer will initialize dir member variables with a different path manually
// to work with remote machines via SMB/CIFS standard path
void SMBInit::MSC_DirectoryChange(std::wstring arg_dir_name)
{
	std::vector splited_path = MSC_StringTokenizer(arg_dir_name, L':');
	
	m_smb_path = L"\\\\";
	m_smb_path.append(m_remote_machine);
	m_smb_path.append(L"\\");
	m_smb_path.append(m_share_name);
	m_smb_path.append(splited_path.at(1));
}

// m_smb_path always points to a working directory 
// so we can always check what value it has and 
// how we wanted to work with that path in our program
bool SMBInit::MSC_CreateFileDirectorySMB(std::wstring arg_path)
{
	// Here we change m_smb_path default directory path 
	// to the directory that user passed to the function 
	// in order to create files or directories;
	MSC_DirectoryChange(arg_path);

	if (m_smb_path.find(L".") != std::string::npos)
	{
		std::wofstream file_directory;
		file_directory.open(m_smb_path);

		if (!file_directory)
		{
			return false;
		}
		else
		{
			return true;
			file_directory.close();
		}
	}
	else
	{
		if (std::filesystem::create_directory(m_smb_path))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool SMBInit::MSC_DeleteFileDirectorySMB(std::wstring arg_path)
{
	MSC_DirectoryChange(arg_path);
	if (std::filesystem::remove(m_smb_path))
	{
		return true;
	}
	else
	{
		return false;
	}
}


// Here we check connection with the remote machine filesystem
// if we can make a file on remote machine, it means we have a access to it
bool SMBInit::MSC_CheckConnection()
{
	if (MSC_CreateFileDirectorySMB(L"C:\\Users\\Temp.txt"))
	{
		MSC_DeleteFileDirectorySMB(L"C:\\Users\\Temp.txt");
		return true;
	}
	else
	{
		return false;
	}
}

// It can be used to tokenized a string based on a delimiter
// for example we can tokenized a path based ":".
std::vector<std::wstring> SMBInit::MSC_StringTokenizer(const std::wstring& arg_string, wchar_t arg_delimiter)
{
	std::vector<std::wstring> vector_splited_string;
	std::wstring token;
	std::wistringstream token_stream(arg_string);

	while (std::getline(token_stream, token, arg_delimiter))
	{
		vector_splited_string.push_back(token);
	}

	return vector_splited_string;
}


// Its a destructor to free and delete used objects
SMBInit::~SMBInit()
{

}
