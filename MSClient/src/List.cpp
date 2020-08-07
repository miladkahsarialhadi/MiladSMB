#include "List.h"


SMBFileSystem::SMBFileSystem(std::wstring arg_name, std::wstring arg_share_name, std::wstring arg_dir_name)
	: SMBInit(arg_name, arg_share_name, arg_dir_name)
{ }

bool SMBFileSystem::MSC_Upload(std::wstring arg_source_path, std::wstring arg_dest_path)
{

}

bool SMBFileSystem::MSC_Download(std::wstring arg_source_path, std::wstring arg_dest_path)
{

}

bool SMBFileSystem::MSC_ListFilesDirectories(std::wstring arg_path)
{
	MSC_DirectoryChange(arg_path);
	for (const auto& entry : std::filesystem::directory_iterator(m_smb_path))
	{
		std::cout << entry.path() << std::endl;
	}
	return true;
}

bool SMBFileSystem::MSC_SetFileDirectoryAttribute(std::wstring arg_path)
{

}

bool SMBFileSystem::MSC_ShowFileDirectoryAttribute(std::wstring arg_path)
{

}
