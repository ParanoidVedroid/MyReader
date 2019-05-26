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

UINT32 FileSystemParent::GetClustersCount()
{
	return _totalClusters;
}

Cluster* FileSystemParent::ReadCluster(UINT32 number)
{
	UINT32 offset = number * _bytesPerCluster;
	BYTE* data = _handle->ReadData(offset, _bytesPerCluster);
	return new Cluster(data, _bytesPerCluster);
}

FileSystemParent::~FileSystemParent()
{
}
