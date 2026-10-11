/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 19:34:36 by lauragm           #+#    #+#             */
/*   Updated: 2026/10/11 22:02:11 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

bigint::bigint(): s("0"){
}
bigint::bigint(unsigned int n)
{
	std::ostringstream os; //funciona como un std::cout, pero lo imprimido se fuarda dentro de os
	os << n; //guarda "n" como caracteres dentro de os 
	s = os.str();
}
bigint::bigint(const bigint &copy): s(copy.s){
}
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
			sum += s[i--] - '0'; //s[i] - '0' convierte el caracter en número
		if(j >= 0)
			sum += b.s[j--] - '0';
		
		r.insert(r.begin(), char('0' + sum % 10)); //sum % 10 es el dígito que se escribe en esta columna
		carry = sum / 10; //0 o 1 para la siguiente columna
	}
	s = r;
	return(*this);
}
bigint bigint::operator+(const bigint &b) const
{
	return(bigint(*this) += b);
}