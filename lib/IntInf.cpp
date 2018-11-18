#include "IntInf.h"
#include <stdio.h>

IntInf::IntInf(int n, bool neg, bool pos, bool u)
{
	num = n;
	negInf=neg;
	posInf=pos;
	undefined = u;
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

IntInf IntInf::operator *(const IntInf& rhs) const{
	IntInf result;
	if((!posInf && !negInf)&&(!rhs.posInf && !rhs.posInf)) //both integers
	{
		result.num = num * rhs.num;
	}
	else if((!posInf && !negInf && num == 0)||(!rhs.posInf && !rhs.posInf && rhs.num ==0)) //one is zero
	{
		result.num =0;
	}	
	else if(negInf && rhs.negInf) //both neg inf
	{
		result.posInf = true;
	}
	else if(posInf && rhs.posInf) //both pos inf
	{
		result.posInf = true;
	}
	else if((posInf && rhs.negInf) || (negInf && rhs.posInf)) //one neg inf other pos inf
	{
		result.negInf = true;
	}
	else if(posInf || rhs.posInf) //one pos inf other int
	{
		result.posInf = true;
	}
	else if(negInf || rhs.negInf) //one neg inf other int
	{
		result.negInf = true;
	}
	return result;	
}

IntInf IntInf::operator /(const IntInf& rhs) const{
	IntInf result;
	if((!rhs.posInf && !rhs.posInf && rhs.num ==0)) //dividing by zero
	{
		result.undefined =true;
		printf("Error dividing by zero");
	}
	else if(posInf && rhs.posInf) //both pos inf
	{
		result.posInf = true;
	}
	else if(negInf && rhs.negInf) //both neg inf
	{
		result.posInf = true;
	}
	else if((posInf && rhs.negInf) || (negInf && rhs.posInf)) //one neg inf other pos inf
	{
		result.negInf = false;
	}
	else if(rhs.negInf || rhs.posInf) //dividing int by inf
	{
		result.num =0;
	}
	else if(posInf) //dividing +inf by int
	{
		result.posInf = true;
	}
	else if(negInf) //dividing -inf by int
	{
		result.negInf = true;
	}
	else //both int
	{
		result.num = num / rhs.num;
	}
	
	return result;
}

bool IntInf::operator ==(const IntInf& rhs) const{
	if((!posInf && !negInf) && (!rhs.posInf && !rhs.posInf)) //compairing two integers
	{
		if(num == rhs.num)
			return true;
		else
			return false;
	}
	else //comparing something to infinity
	{
		return false;
	}
}

bool IntInf::operator >(const IntInf& rhs) const{
	if(posInf && rhs.posInf) //both pos inf
	{
		return false;
	}
	else if(negInf && rhs.negInf) //both neg inf
	{
		return true;
	}
	else if(posInf) //compairing pos inf to something else
	{
		return true;
	}
	if((!posInf && !negInf) && (!rhs.posInf && !rhs.posInf)) //compairing two integers
	{
		if(num > rhs.num)
			return true;
		else
			return false;
	}
	else if(rhs.negInf) //comparing something to neg inf
	{
		return true;
	}
	else
		return false;
}

bool IntInf::operator <(const IntInf& rhs) const{
	if(posInf && rhs.posInf) //both pos inf
	{
		return true;
	}
	else if(negInf && rhs.negInf) //both neg inf
	{
		return false;
	}
	else if(negInf) //compairing neg inf to something else
	{
		return true;
	}
	if((!posInf && !negInf) && (!rhs.posInf && !rhs.posInf)) //compairing two integers
	{
		if(num < rhs.num)
			return true;
		else
			return false;
	}
	else if(rhs.posInf) //comparing something to pos inf
	{
		return true;
	}
	else
		return false;
}
