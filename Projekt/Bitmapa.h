#pragma once

/*
Klasa abstrakcyjna Bitmapa
*/
class Bitmapa
{
public:

	virtual unsigned get_length() const = 0;
	virtual unsigned get_width() const = 0;
	virtual bool & operator() (unsigned x, unsigned y) = 0;
	virtual bool operator() (unsigned x, unsigned y) const = 0;

	virtual ~Bitmapa() {}
};

