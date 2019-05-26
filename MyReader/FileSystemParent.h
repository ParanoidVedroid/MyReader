#pragma once
#include <windows.h>
#include <string>
#include "DiskReader.h"
#include "Cluster.h"

using namespace std;

class FileSystemParent
{
public:
	FileSystemParent();

	void ShowInfo();
	Cluster* ReadCluster(UINT32 number);
	UINT32 GetClustersCount();

	~FileSystemParent();
protected:
	DiskReader* _handle;
	BYTE* _jump;
	string _signature;
	UINT16 _bytesPerSector;
	UINT16 _sectorsPerCluster;
	UINT32 _totalSectors;
	UINT16 _bytesPerCluster;
	UINT32 _totalClusters;
	UINT64 _totalCapasity;


};

