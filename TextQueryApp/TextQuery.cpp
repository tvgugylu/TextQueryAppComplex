#include "TextQuery.h"
#include <sstream>
using std::istringstream;


TextQuery::TextQuery(std::ifstream &is) :file(new vector<string>)
{
	string text;
	while (getline(is,text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
			{
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string& sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc != wm.end())
	{
		return QueryResult(sought, loc->second, file);;
	}
	else
	{
		return QueryResult(sought, nodata, file);
	}
}

ostream &print(ostream& os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << endl;
	for (auto num : *qr.lines)
	{
		os << "\t(line " << num + 1 << ") "
			<< *(qr.file->begin() + num) << endl;
	}
	return os;
}
