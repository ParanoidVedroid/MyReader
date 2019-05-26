#pragma once
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class DiskReader
{

public:

	DiskReader(string path_to_disk);
	BYTE* ReadData(int start_pos, int buff_size);

	~DiskReader();


private:
	HANDLE _diskHandle;

};


