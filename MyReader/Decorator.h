#pragma once
#include "InteratorTemp.h"
#include "Cluster.h"
#include "Iterator.h"

BYTE pdfSignature[] = { 0x25, 0x50, 0x44, 0x46, 0x2D };

class Decorator : public IteratorTemp<Cluster>
{
	
private:
	Iterator *simpleIterator;

	bool Is_PDF(BYTE* data)
	{
		for (int i = 0; i < 5; i++)
		{
			if (pdfSignature[i] == data[i]) continue;
			else return false;
		}

		return true;
	}
	
public:
	Decorator(Iterator *it) {
		simpleIterator = it;
	}

	virtual void First()
	{
		simpleIterator->First();
		while (!simpleIterator->IsDone())
		{
			Cluster *cluster = simpleIterator->GetCurrent();
			if (Is_PDF(cluster->GetData())) break;
			simpleIterator->Next();
		}

	}

	virtual void Next()
	{
		while (!simpleIterator->IsDone())
		{
			simpleIterator->Next();
			Cluster *cluster = simpleIterator->GetCurrent();
			if (Is_PDF(cluster->GetData())) break;
		}
	}

	virtual bool IsDone()
	{
		return simpleIterator->IsDone();
	}

	Cluster* GetCurrent()
	{
		return simpleIterator->GetCurrent();
	}


	UINT32 GetCurrentNumber() {
		return simpleIterator->GetCurrentNumber();
	}


	~Decorator() {};
};

