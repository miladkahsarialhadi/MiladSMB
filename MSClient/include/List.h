#pragma once

#include "SMB.h"

class SMBFileSystem : public SMBInit
{
public:
	SMBFileSystem(std::wstring arg_name, std::wstring arg_share_name, std::wstring arg_dir_name);
	bool MSC_Upload(std::wstring arg_source_path, std::wstring arg_dest_path);
	bool MSC_Download(std::wstring arg_source_path, std::wstring arg_dest_path);
	bool MSC_ListFilesDirectories(std::wstring arg_path);
	bool MSC_SetFileDirectoryAttribute(std::wstring arg_path);
	bool MSC_ShowFileDirectoryAttribute(std::wstring arg_path);
};

