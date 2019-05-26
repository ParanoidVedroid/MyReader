#pragma once
#include "FileSystemParent.h"

typedef struct
{
	BYTE jump[3];
	BYTE oem_id[8];
	BYTE padding_1[61];
	BYTE volume_length[8];
	BYTE fat_offset[4];
	BYTE fat_length[4];
	BYTE cluster_heap_offset[4];
	BYTE clusters_count[4];
	BYTE first_cluster_of_root_directory[4];
	BYTE padding_2[8];
	BYTE bytes_per_sector_shift;
	BYTE sectors_per_cluster_shift;
	BYTE number_of_fats;

} EXFAT_BOOT_RECORD;

class ExFat_FS : public FileSystemParent
{
public:

	ExFat_FS(DiskReader *dr);
	
	~ExFat_FS();
};

