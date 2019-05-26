#include "pch.h"
#include "ExFat_FS.h"


ExFat_FS::ExFat_FS(DiskReader *dr)
{
	_handle = dr;

	BYTE* buff = _handle->ReadData(0x100000, 0x6F);
	EXFAT_BOOT_RECORD *bootSector = (EXFAT_BOOT_RECORD*)buff;

	_jump = bootSector->jump;
	_signature = (char*)bootSector->oem_id;
	_bytesPerSector = *(UINT16*)bootSector->bytes_per_sector_shift;
	_sectorsPerCluster = (UINT16)bootSector->sectors_per_cluster_shift;
	_totalSectors = *(UINT32*)bootSector->volume_length;

	_bytesPerCluster = _bytesPerSector * _sectorsPerCluster;
	_totalClusters = _totalSectors / _sectorsPerCluster;
	_totalCapasity = _totalClusters * _bytesPerCluster;



}


ExFat_FS::~ExFat_FS()
{
}
