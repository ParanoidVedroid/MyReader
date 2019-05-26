#pragma once
#include <iostream>
#include <windows.h>

class Cluster
{
private:
	BYTE* _data;
	UINT16 _size;

public:
	Cluster(BYTE* data, UINT16 size);
	BYTE* GetData();
	void PrintData();

};

