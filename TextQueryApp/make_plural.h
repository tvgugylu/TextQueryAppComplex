#pragma once
#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

inline
string make_plural(size_t cstr, const string &word,
	const string &ending)
{
	return (cstr > 1) ? word + ending : word;
}
