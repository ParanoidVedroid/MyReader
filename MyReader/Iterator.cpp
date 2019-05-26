#include "pch.h"
#include "Iterator.h"


Iterator::Iterator(FileSystemParent *fs) : IteratorTemp()
{
	_fs = fs;
}

void Iterator::First()
{
	_cursor = 0;
}

void Iterator::Next()
{
	_cursor++;
}

bool Iterator::IsDone()
{
	return _cursor + 1 == _fs->GetClustersCount();
}

Cluster* Iterator::GetCurrent()
{
	return _fs->ReadCluster(_cursor);
}


UINT32 Iterator::GetCurrentNumber()
{
	return _cursor;
}

Iterator::~Iterator()
{
}