#pragma once
#include <ostream>
using std::ostream;
#include <vector>
using std::vector;
#include <cstddef>
#include <memory>
using std::shared_ptr;
#include <string>
using std::string;
#include <set>
using std::set;
using std::getline;
#include "make_plural.h"

class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string > ::size_type;
	QueryResult(std::string s,
		std::shared_ptr<std::set<line_no>> p,
		std::shared_ptr<std::vector<std::string>> f):
		sought(s),lines(p),file(f){}
	typedef std::set<line_no>::const_iterator line_it;
	line_it begin() const { return lines->cbegin(); }
	line_it end() const { return lines->cend(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

ostream &print(ostream& os, const QueryResult& qr);



