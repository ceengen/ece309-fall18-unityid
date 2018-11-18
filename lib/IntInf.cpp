#include "IntInf.h"
#include <stdio.h>

IntInf::IntInf(int n, bool neg, bool pos)
{
	num = n;
	negInf=neg;
	posInf=pos;
}

IntInf IntInf::operator +(const IntInf& rhs) const{
	IntInf result;
	if(posInf || rhs.posInf) //either is +infinity
	{
		result.posInf = true;
	}
	else if(negInf || rhs.negInf) //neither is +infinity and one is -infinity
	{
		result.negInf = true;
	}
	else //both integers
	{
		result.num = num + rhs.num;
	}
	return result;
}
