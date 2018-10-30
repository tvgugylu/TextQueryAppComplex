#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
#include <cstdlib>

#include "TextQuery.h"
#include "make_plural.h"

void runQuery(ifstream &infile)
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for, or q to quit:";
		string s;
		if (!(cin >> s) || s == "q")
		{
			break;
		}
		print(cout, tq.query(s)) << endl;
	}
}

int main(int argc, char **argv)
{
	if (argc < 2 )
	{
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	ifstream infile(argv[1], ifstream::in);
	runQuery(infile);
	return 0;
}