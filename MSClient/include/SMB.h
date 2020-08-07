#pragma once

/*
* Milad SMB Client v1.0.0
* by Milad Kahsari Alhadi
*/

#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <iterator>

// Version structure can hold version info of the program 
// and then we can parse it and show it to end user
struct Version
{
	int max;
	int min;
	int revise;
	std::wstring arch;
	std::wstring codename;
};


// Base class of the Milad SMB Client which provide basic capability to work with
// CIFS based path in windows operating system and get access to remote machine 
// with help of SMB protocol and universal path

class SMBInit
{
protected:
	// Save remote machine name
	std::wstring m_remote_machine;

	// Save the share name 
	std::wstring m_share_name;

	// Save the directory path which we wanted to get access to it
	std::wstring m_dir_name;

	// Save the full SMB path to work correctly 
	std::wstring m_smb_path;

public:
	// Initialize member variables with required information
	SMBInit(std::wstring arg_name, std::wstring arg_share_name, std::wstring arg_dir_name);

	// It return current version of the library
	Version MSC_Version();

	// Form SMB path for further working and tasks
	void MSC_PrepareSmbPath();
	
	// Initialize dir member variable with required information manually
	void MSC_DirectoryChange(std::wstring arg_dir_name);

	// Create files/directory on remote machines
	bool MSC_CreateFileDirectorySMB(std::wstring arg_path);
	
	// Delete files/directory on remote machines 
	bool MSC_DeleteFileDirectorySMB(std::wstring arg_path);

	// Check and verify the connection with the remote machine
	bool MSC_CheckConnection();

	// Tokenize a string and return a vector of its parts
	std::vector<std::wstring> MSC_StringTokenizer(const std::wstring& arg_string, wchar_t arg_delimiter);

	// Destructor of the object
	~SMBInit();
};

