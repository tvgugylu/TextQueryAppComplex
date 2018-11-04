#pragma once
#include "Query_base.h"
#include "Query.h"
class BinaryQuery :
	public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) :
		lhs(l),rhs(r),opSym(s){}

	Query lhs, rhs;
	std::string opSym;

	std::string rep() const override
	{
		return "(" + lhs.req() + " " + opSym + " " + rhs.req() + ")";
	}
};

