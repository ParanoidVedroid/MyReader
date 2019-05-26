#include "pch.h"
#include "FileSystemParent.h"


FileSystemParent::FileSystemParent()
{
}

void FileSystemParent::ShowInfo()
{
	cout << "Signature: " << _signature << endl <<
		"Bytes per sector: " << _bytesPerSector << endl <<
		"Bytes per cluster " << _bytesPerCluster << endl <<
		"Sector count: " << _totalSectors << endl <<
		"Clusters count: " << _totalClusters << endl <<
		"Total capacity, bytes: " << _totalCapasity << endl;
}

FileSystemParent::~FileSystemParent()
{
}
