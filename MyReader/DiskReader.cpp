#include "pch.h"
#include "DiskReader.h"


DiskReader::DiskReader(string diskPath)
{
	wstring diskName(diskPath.begin(), diskPath.end());

	_diskHandle = CreateFileW(
		diskName.c_str(),					// Имя раздела
		GENERIC_READ,						// Режим доступа
		FILE_SHARE_READ | FILE_SHARE_WRITE,	// Режим совместной работы
		NULL,								// Атрибуты безопасности
		OPEN_EXISTING,						// Способ открытия
		FILE_ATTRIBUTE_NORMAL,				// Флаги и атрибуты
		NULL								// Иидентификатор файла шаблона с правами доступа GENERIC_READ
	);

	if (_diskHandle == INVALID_HANDLE_VALUE)
		throw exception("\nDisk opening error!");

	cout << "\nDisk " << diskPath << " opened successfuly!" << endl;

}
BYTE* DiskReader::ReadData(int startPos, int buffSize)
{
	BYTE* buffer = new BYTE[buffSize];

	ULONGLONG startOffset = (ULONGLONG)startPos;
	DWORD bytesToRead = (DWORD)buffSize;
	DWORD bytesRead;

	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart = startOffset;

	unsigned long currentPosition = SetFilePointer(
		_diskHandle,
		sectorOffset.LowPart,
		&sectorOffset.HighPart,
		FILE_BEGIN
	);

	bool result = ReadFile(_diskHandle, buffer, buffSize, &bytesRead, NULL);

	if (!result || bytesRead != buffSize)
		throw exception("Data reading error!");

	return buffer;
}

DiskReader::~DiskReader()
{
	CloseHandle(_diskHandle);
}
