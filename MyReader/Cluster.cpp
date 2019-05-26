#include "pch.h"
#include "Cluster.h"


Cluster::Cluster(BYTE* data, UINT16 size)
{
	_data = data;
	_size = size;
}

BYTE* Cluster::GetData()
{
	return _data;
}

void Cluster::PrintData()
{
	for (int i = 1; i < _size + 1; i++)
	{
		printf("%02X ", _data[i - 1]);

		if (i % 16 == 0) std::cout << std::endl;
		else if (i % 8 == 0) std::cout << "  ";
	}
}

