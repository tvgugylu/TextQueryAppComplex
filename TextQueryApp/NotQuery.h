#pragma once
#include "Query_base.h"
class NotQuery :
	public Query_base
{
	friend Query operator~(const Query &);
private:
	NotQuery(const Query &q) :query(q) {}
	QueryResult eval(const TextQuery&) const override;
	std::string rep() const override
	{
		return "~ги" + query.req() + ")";
	}
	Query query;
	inline Query operator~(const Query &operand)
	{
		return std::shared_ptr<Query_base>(new NotQuery(operand));
	}
};

QueryResult NotQuery::eval(const TextQuery& text) const
{
	auto result = query.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (std::size_t n = 0; n != sz; ++n)
	{
		if (beg == end || *beg != n)
		{
			ret_lines->insert(n);
		}
		else if (beg != end)
		{
			++beg;
		}
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

