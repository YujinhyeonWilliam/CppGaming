#pragma once
#include "ResourceBase.h"
class LineMesh : public ResourceBase
{
public:
	LineMesh();
	virtual ~LineMesh();

	void Save(wstring Path);
	void Load(wstring Path);
	void Render(HDC hdc, Pos pos) const;

protected:
	vector<pair<POINT, POINT>> _lines;
};

