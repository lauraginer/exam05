#include "bigint.hpp"

bigint::bigint(): s("0"){}
bigint::bigint(unsigned int n)
{
	std::ostringstream os;
	os << n;
	s = os.str();
}
bigint::bigint(const bigint &copy): s(copy.s){}
bigint& bigint::operator=(const bigint &copy)
{
	if(this != &copy)
		s = copy.s;
	return(*this);
}

bigint& bigint::operator+=(const bigint &b) //suma del cole
{
	std::string r;
	
	int i = s.size() - 1;
	int j = b.s.size() - 1;
	int carry = 0;
	while(i >= 0 || j >= 0 || carry)
	{
		int sum = carry;
		if(i >= 0)
			sum += s[i--] - '0';
		if(j >= 0)
			sum += b.s[j--] - '0';

		r.insert(r.begin(), char('0' + sum % 10));
		carry = sum / 10;
	}
	s = r;
	return(*this);
}

bigint bigint::operator+(const bigint &b) const
{
	return(bigint(*this) += b);
}

bigint& bigint::operator++()
{
	return(*this += 1);
}
bigint bigint::operator++(int)
{
	bigint temp = *this;
	*this += 1;
	return(temp);
}

bool bigint::operator==(const bigint &b) const
{
	return(s == b.s);
}
bool bigint::operator!=(const bigint &b) const
{
	return(!(*this == b));
}
bool bigint::operator<(const bigint &b) const
{
	if(s.size() != b.s.size())
		return(s.size() < b.s.size());
	return(s < b.s);
}
bool bigint::operator>(const bigint &b) const
{
	if(s.size() != b.s.size())
		return(s.size() > b.s.size());
	return(s > b.s);
}
bool bigint::operator>=(const bigint &b) const
{
	if(s.size() != b.s.size())
		return(s.size() > b.s.size());
	return(s >= b.s);
}
bool bigint::operator<=(const bigint &b) const
{
	if(s.size() != b.s.size())
		return(s.size() < b.s.size());
	return(s <= b.s);
}

bigint& bigint::operator<<=(const bigint &b)
{
	if(s != "0")
		s.append(std::strtoul(b.s.c_str(), 0, 10), '0');
	return(*this);
}
bigint bigint::operator<<(const bigint &b) const
{
	bigint temp = *this;
	return(temp <<= b);
}
bigint& bigint::operator>>=(const bigint &b)
{
	size_t n = std::strtoul(b.s.c_str(), 0, 10);
	if(n >= s.size())
		s = "0";
	else
		s.erase(s.size() - n);
	return(*this);
}
bigint bigint::operator>>(const bigint &b) const
{
	bigint temp = *this;
	return(temp >>= b);
}
std::ostream& operator<<(std::ostream &os, const bigint &b)
{
	os << b.s;
	return(os);
}