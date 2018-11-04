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

