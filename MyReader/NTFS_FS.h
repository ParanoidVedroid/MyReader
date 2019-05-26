#pragma once
#include "FileSystemParent.h"
#include "DiskReader.h"

typedef struct
{
	BYTE	jump[3];		
	BYTE	oem_id[8];
	BYTE	bytes_per_sector[2];
	BYTE	sectors_per_cluster;
	BYTE	padding[26];
	BYTE	total_sectors[8];
} NTFS_BOOT_RECORD;

class NTFS_FS : public FileSystemParent
{
public:
	
	NTFS_FS(DiskReader *dr);


	~NTFS_FS();
};

