#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <sstream>
#include <string>

class bigint{
	private:
		std::string s;

	public:
		bigint();
		bigint(unsigned int n);
		bigint(const bigint &copy);
		bigint& operator=(const bigint &copy);

		bigint& operator+=(const bigint &b);
		bigint operator+(const bigint &b) const;
		
		bigint& operator++();
		bigint operator++(int);

		bool operator==(const bigint &b) const;
		bool operator!=(const bigint &b) const;
		bool operator<(const bigint &b) const;
		bool operator>(const bigint &b) const;
		bool operator<=(const bigint &b) const;
		bool operator>=(const bigint &b) const;

		bigint& operator<<=(const bigint &b);
		bigint operator<<(const bigint &b) const;
		bigint& operator>>=(const bigint &b);
		bigint operator>>(const bigint &b) const;

		friend std::ostream& operator<<(std::ostream &os, const bigint &b);
};

#endif