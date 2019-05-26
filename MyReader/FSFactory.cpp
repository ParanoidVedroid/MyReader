#include "pch.h"
#include "FSFactory.h"

FileSystemParent* FSFactory::CreateFS(DiskReader *dr)
{
	OEM *oem = (OEM*)dr->ReadData(0, 1024);
	if (!strcmp(oem->sign, "NTFS    "))
		return new NTFS_FS(dr);

	throw exception("This file system does not exists");

}

