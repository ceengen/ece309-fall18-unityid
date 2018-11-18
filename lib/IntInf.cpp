#include <iostream>
using namespace std;

#include <stdio.h>

class IntInf{
private:
	int num;
	bool negInf;
	bool posInf;

public:
	IntInf(int n=0, bool neg=false, bool pos=false);
	IntInf operator =(const IntInf& rhs) const;
	IntInf operator +(const IntInf& rhs) const;
	IntInf operator -(const IntInf& rhs) const;
	IntInf operator *(const IntInf& rhs) const;
	IntInf operator /(const IntInf& rhs) const;
	bool operator ==(const IntInf& rhs) const;
	bool operator >(const IntInf& rhs) const;
	bool operator <(const IntInf& rhs) const;
};

IntInf::IntInf(int n=0, bool neg=false, bool pos=false)
{
	num = n;
	negInf=neg;
	posInf=pos;
}

IntInf IntInf::operator +(const IntInf& rhs) const{
	InfInf result();
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
