
#include "pch.h"
#include <iostream>
#include <windows.h>
#include <string>
#include "DiskReader.h"
#include "FileSystemParent.h"
#include "NTFS_FS.h"
#include "ExFat_FS.h"
#include "FSFactory.h"
#include "Decorator.h"

using namespace std;

int main()
{
	DiskReader *dr = NULL;
	FileSystemParent *fs = NULL;
	Cluster *c = NULL;
	Decorator *dec = NULL;

	string diskLetter;
	cout << "Partition path: ";
	getline(cin, diskLetter);

	try {
		
		dr = new DiskReader("\\\\.\\" + diskLetter + ":");
		fs = FSFactory::CreateFS(dr);

		while (true)
		{
			cout << "1. Show info\n" << "2. Show pdf clusters\n" << "3. Exit" << endl;
			
			int temp;
			cin >> temp;
			switch (temp)
			{
			case 1:
				fs->ShowInfo();
				break;
			case 2:
				dec = new Decorator(new Iterator(fs));
				for(dec->First(); !dec->IsDone(); dec->Next())
					printf(" 0x%08X\n", dec->GetCurrentNumber());
				cout << endl;
				break;
			case 3:
				return 0;
			default:
				break;
			}
		}

	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	
	delete dec;
	delete c;
	delete fs;
	delete dr;
	


}

