#pragma once
#include "ResourceBase.h"

class Texture : public ResourceBase
{
public:
	Texture();
	virtual ~Texture();

public:
	Texture*			LoadBMP(HWND hwnd, const wstring& path);
	HDC					GetDC();
	void				SetSize(Vector2DInt size) { _size = size; }
	Vector2DInt			GetSize() { return _size; }
	void				SetTranparent(uint32 transparent) { _transparent = transparent; }
	uint32				GetTransparent() { return _transparent; }

private:
	HDC				_hdc = {};
	HBITMAP			_bitmap = {};
	Vector2DInt		_size = {};
	uint32			_transparent; 
	// BMP포맷이 RGB값 밖에 없기 때문에 없는 A를 보충하기 위해 transparent 내포

};

