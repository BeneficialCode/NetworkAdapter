// NetworkAdapter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
#include <string>

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

void SetNetworkAdapter(std::wstring cmd);

int main() {
	std::wstring cmd = L"/c netsh interface set interface \"以太网\" DISABLE";
	SetNetworkAdapter(cmd);
	Sleep(4000);
	cmd = L"/c netsh interface set interface \"以太网\" ENABLE";
	SetNetworkAdapter(cmd);

	/*cmd = L"/c netsh interface set interface \"VMware Network Adapter VMnet8\" DISABLE";
	SetNetworkAdapter(cmd);
	Sleep(3000);
	cmd = L"/c netsh interface set interface \"VMware Network Adapter VMnet8\" ENABLE";
	SetNetworkAdapter(cmd);*/
	cmd = L"/c netsh interface set interface \"以太网\" ENABLE";
	SetNetworkAdapter(cmd);
}

void SetNetworkAdapter(std::wstring cmd) {
	ShellExecute(NULL, L"open", L"cmd", cmd.c_str(), NULL, SW_HIDE);
}
