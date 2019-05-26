#pragma once
#include <iostream>
#include <windows.h>
#include "Cluster.h"
#include "InteratorTemp.h"
#include "FileSystemParent.h"

class Iterator : public IteratorTemp<Cluster>
{
public:
	Iterator(FileSystemParent *fs);

	virtual void First();
	virtual void Next();
	virtual bool IsDone();
	virtual Cluster* GetCurrent();

	UINT32 GetCurrentNumber();

	~Iterator();

protected:
	FileSystemParent* _fs;
	UINT32 _cursor;
};

