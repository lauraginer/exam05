/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 19:34:33 by lauragm           #+#    #+#             */
/*   Updated: 2026/10/15 21:03:22 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <sstream>

class bigint{
	private:
		std::string s;
	
	public:
		bigint();
		bigint(unsigned int n);
		bigint(const bigint &copy);
		bigint& operator=(const bigint &copy);

		//Funciones principales requeridas por el main.cpp	
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
		
		bigint& operator>>=(const bigint &b);
		bigint& operator<<=(const bigint &b);
		bigint operator<<(const bigint &b) const;
		bigint operator>>(const bigint &b) const;

		friend std::ostream& operator<<(std::ostream &os, const bigint &b);

};

#endif