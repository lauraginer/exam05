/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 21:22:52 by lauragm           #+#    #+#             */
/*   Updated: 2026/10/06 21:26:58 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
class vect2
{
	private:
		int x;
		int y;
	
	public:
	//Funciones principales requeridas por el main.cpp	
		vect2();
		vect2(int x, int y);
		vect2(const vect2 &copy);
		vect2& operator=(const vect2 &copy);

	//Funciones explícitas del ejercicio
		int& operator[](int index);
		int operator[](int index) const;

		vect2 operator+(const vect2 &v) const;
		vect2 operator-(const vect2 &v) const;
		vect2 operator*(int s) const;
		vect2 operator-() const; //operador de negación unaria
		vect2& operator+=(const vect2 &v);
		vect2& operator-=(const vect2 &v);
		vect2& operator*=(int s);
		
		vect2& operator++(); //incrementa
		vect2 operator++(int); //"no incrementa"
		vect2& operator--();
		vect2 operator--(int);

		bool operator==(const vect2 &v) const;
		bool operator!=(const vect2 &v) const;		
		
		friend std::ostream& operator<<(std::ostream& os, const vect2 &v);
		friend vect2 operator*(int s, const vect2 &v);
};

#endif