#include "pch.h"
#include "NTFS_FS.h"


NTFS_FS::NTFS_FS(DiskReader *dr)
{
	_handle = dr;

	BYTE* buff = _handle->ReadData(0, 1024);

	NTFS_BOOT_RECORD *bootSector = (NTFS_BOOT_RECORD*)buff;

	_jump = bootSector->jump;
	_signature = (char*)bootSector->oem_id;
	_bytesPerSector = *(UINT16*)bootSector->bytes_per_sector;
	_sectorsPerCluster = (UINT16)bootSector->sectors_per_cluster;
	_totalSectors = *(UINT32*)bootSector->total_sectors;

	_bytesPerCluster = _bytesPerSector * _sectorsPerCluster;
	_totalClusters = _totalSectors / _sectorsPerCluster;
	_totalCapasity = _totalClusters * _bytesPerCluster;
}


NTFS_FS::~NTFS_FS()
{
}
