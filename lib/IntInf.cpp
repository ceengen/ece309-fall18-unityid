#include <iostream>
using namespace std;

#include <stdio.h>

class IntInf{
private:
	int num;
	bool negInf;
	bool posInf;

public:
	IntInf();
	IntInf operator =(const IntInf& rhs) const;
	IntInf operator +(const IntInf& rhs) const;
	IntInf operator -(const IntInf& rhs) const;
	IntInf operator *(const IntInf& rhs) const;
	IntInf operator /(const IntInf& rhs) const;
	bool operator ==(const IntInf& rhs) const;
	bool operator >(const IntInf& rhs) const;
	bool operator <(const IntInf& rhs) const;
};

IntInf IntInf::operator +(const IntInf& rhs){
	if(posInf || rhs.posInf) //either is +infinity
	{
		posInf = true;
		negInf = false;
	}
	else if(negInf || rhs.negInf) //neither is +infinity and one is -infinity
	{
		posInf = false;
		negInf = true;
	}
	else //both integers
	{
		num = num + rhs.num;
	}
	return this;
}
