
#include "pch.h"
#include <iostream>
#include <windows.h>
#include <string>
#include "DiskReader.h"
#include "FileSystemParent.h"
#include "NTFS_FS.h"
#include "ExFat_FS.h"

using namespace std;

int main()
{
	string str = "\\\\.\\F:";

	DiskReader *dr = NULL;
	NTFS_FS *ntfs = NULL;


	BYTE *arr = NULL;

	try {
		dr = new DiskReader(str);
		arr = dr->ReadData(0,1024);


		ntfs = new NTFS_FS(dr);
		ntfs->ShowInfo();

	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	
	delete ntfs;
	delete dr;
	


}

