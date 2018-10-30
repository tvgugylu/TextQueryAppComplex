#pragma once
#include <string>
#include "QueryResult.h"
#include "TextQuery.h"
#include "Query_base.h"
class Query
{
public:
	Query();
	~Query();
	Query(const std::string&);
	QueryResult eval(const TextQuery& t) const
	{
		return q->eval(t);
	}
	std::string req() const
	{
		return q->rep();
	}

private:
	Query(std::shared_ptr<Query_base> query) :q(query) {}
	std::shared_ptr<Query_base> q;
};

