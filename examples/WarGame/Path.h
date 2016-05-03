#ifndef PATH_H
#define PATH_H

#include "Texture.h"
#include <StreamTexture.h>

typedef std::pair<int, int> Position;

namespace path
{
	inline void setPathColor(yam2d::StreamTexture* t, int x, int y)
	{
		t->getPixel(x, y)[0] = 0xff;
		t->getPixel(x, y)[1] = 0x00;
		t->getPixel(x, y)[2] = 0xff;
	}

	inline bool isRed(unsigned char* p)
	{
		return p[0] > 200;
	}

	inline bool isGreen(unsigned char* p)
	{
		return p[1] > 200;
	}

	inline bool isBlue(unsigned char* p)
	{
		return p[2] > 200;
	}
}

#endif