#pragma once

#include "SMB.h"

class SMBInstrument : public SMBInit
{
public:
	std::wstring MSC_WMICommand(std::wstring arg_node_name);
	std::wstring MSC_QueryActiveUsers(std::wstring arg_node_name);
	std::wstring MSC_IpToHostName();
	std::wstring MSC_HostToIp();
};

