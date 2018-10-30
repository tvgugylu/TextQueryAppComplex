#pragma once
#include <memory>
using std::shared_ptr;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <map>
using std::map;
#include <fstream>
using std::ifstream;
#include <set>
using std::set;
#include "QueryResult.h"

class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string > ::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

