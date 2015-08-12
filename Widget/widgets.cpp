// #define _CRT_SECURE_NO_WARNINGS
// 
// #include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

// int main()
// {
// 	unsigned int uLength = 1024 * 1024 * 250;
// 	char*  toSave = new char[uLength];
// 	memset(toSave, 1, uLength);
// 	std::string toSaveStr = toSave;
// 	fstream out;
// 	out.open("D:\\test.txt");
// 	if (out.is_open())
// 	{
// 		out.write(const_cast<char*>(toSaveStr.c_str()), toSaveStr.size());
// 	}
// 	else
// 	{
// 		DWORD d = GetLastError();
// 		std::cout << d << std::endl;
// 		std::cout << "open file failed" << std::endl;
// 	}
//     system("pause");
//     return 0;
// }

int main()
{
	LARGE_INTEGER m_nFreq;
	LARGE_INTEGER m_nBeginTime;
	LARGE_INTEGER nEndTime;

	HANDLE hFile = CreateFileA(
		"D:/test.txt",
		GENERIC_READ,
		0, 
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 
		NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		cout << "�ļ��򿪳ɹ�~!\n";
	}
	else
	{
		cout << "�ļ���ʧ�ܣ�\n";
		DWORD d = GetLastError();
		cout << d << endl;
		return -1;
	}


	DWORD dwFileSize = GetFileSize(hFile, NULL);

	HANDLE hFileMap = CreateFileMapping(
		hFile, 
		NULL, 
		PAGE_READWRITE, 
		0, 
		0,
		NULL);
	if (hFileMap != NULL)
	{
		cout << "�ڴ�ӳ���ļ������ɹ�~!\n";
	}
	else
	{
		cout << "�ڴ�ӳ���ļ�����ʧ��~��" << endl;
	}

	PVOID pvFile = MapViewOfFile( 
		hFileMap,
		FILE_MAP_WRITE, 
		0, 
		0, 
		0); 
	if (pvFile != NULL)
	{
		cout << "�ļ�����ӳ�䵽���̵ĵ�ַ�ɹ�~!\n";
	}
	else
	{
		cout << "�ļ�����ӳ�䵽���̵ĵ�ַ�ɹ�~!\n";
	}

	char *p = (char*)pvFile;
	char* dest = new char[dwFileSize];
	memset(dest, 0, dwFileSize);

	QueryPerformanceFrequency(&m_nFreq);
	QueryPerformanceCounter(&m_nBeginTime);
	memcpy(dest, p, dwFileSize);
	QueryPerformanceCounter(&nEndTime);
	cout << (nEndTime.QuadPart - m_nBeginTime.QuadPart) * 1000 / m_nFreq.QuadPart << endl;

	return 0; 
}