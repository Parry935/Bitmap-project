#include "BitmapaExt.h"


unsigned BitmapaExt::get_length() const
{
	return length;
}

unsigned BitmapaExt::get_width() const
{
	return width;
}


bool & BitmapaExt::operator()(unsigned x, unsigned y)
{
	return bitmapa[x][y];
}

bool BitmapaExt::operator()(unsigned x, unsigned y) const
{
	return bitmapa[x][y];
}


