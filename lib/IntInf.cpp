#include "IntInf.h"
#include <stdio.h>

IntInf::IntInf(int n, bool neg, bool pos)
{
	num = n;
	negInf=neg;
	posInf=pos;
}

IntInf IntInf::operator =(const IntInf& rhs) const{
	IntInf result;
	result.num = rhs.num;
	result.posInf = rhs.posInf;
	result.negInf = rhs.negInf;
	return result;
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

IntInf IntInf::operator -(const IntInf& rhs) const{
	IntInf result;
	if(posInf && rhs.posInf) //if both +inf
	{
		result.posInf = true;
	}
	else if(rhs.posInf) //this not +inf and rhs is posInf
	{
		result.negInf = true;
	}
	else if(posInf) //this +inf, rhs !+inf
	{
		result.posInf = true;
	}
	else if(negInf && rhs.negInf) //both -inf
	{
		result.negInf = true;
	}
	else if(rhs.negInf) //this !negInf and rhs = -inf
	{
		result.posInf = true;
	}
	else if(negInf) //this -inf, rhs !-inf
	{
		result.negInf = true;
	}
	else //both integers
	{
		result.num = num + rhs.num;
	}
	return result;	
}
