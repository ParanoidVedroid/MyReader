#pragma once
#include "DiskReader.h"
#include "FileSystemParent.h"
#include "NTFS_FS.h"

typedef struct
{
	BYTE jump[3];
	char sign[8];
}OEM;


class FSFactory
{
public:
	static FileSystemParent* CreateFS(DiskReader *dr);
};

