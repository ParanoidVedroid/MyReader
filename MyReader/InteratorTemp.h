#pragma once

template <class Element>
class IteratorTemp
{
public:
	IteratorTemp() {};
	
	virtual void First() {};
	virtual void Next() {};
	virtual bool IsDone() { return true; }
	Element* GetCurrent() {};

	~IteratorTemp() {};

};