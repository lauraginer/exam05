/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 21:22:50 by lauragm           #+#    #+#             */
/*   Updated: 2026/10/06 21:06:21 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"
/*la idea es implementar la funcion matemática, entonces hay que implementar, aparte de
los operadores de [] y <<, toooodas las funciones matematicas, que si -, *, --, ++, etc etc*/

vect2::vect2(): x(0), y(0){
}
vect2::vect2(int x, int y): x(x), y(y){
}
vect2::vect2(const vect2 &copy): x(copy.x), y(copy.y){
}
vect2& vect2::operator=(const vect2 &copy)
{
	if(this != &copy)
	{
		x = copy.x;
		y = copy.y;
	}
	return(*this);
}
int& vect2::operator[](int index)
{
	if(index == 0)
		return(x);
	else
		return(y);
}
int vect2::operator[](int index) const
{
	if(index == 0)
		return(x);
	else
		return(y);
}

//----No pertenecen a la clase----
vect2 operator*(int s, const vect2 &v)
{
	return(vect2(v.x * s, v.y * s));
}
std::ostream& operator<<(std::ostream& os, const vect2 &v)
{
	os << "{" << v[0] << ", " << v[1] << "}"; //utilizamos nuestro operador []
	return(os);
}

vect2 vect2::operator+(const vect2 &v) const
{
	return(vect2(x + v.x, y + v.y));
}
vect2 vect2::operator-(const vect2 &v) const
{
	return(vect2(x - v.x, y - v.y));
}
vect2 vect2::operator*(int s) const
{
	return(vect2(x * s, y * s));
}
vect2 vect2::operator-() const
{
	return(vect2(-x, -y));
}
vect2& vect2::operator+=(const vect2 &v)
{
	x += v.x;
	y += v.y;
	return(*this);
}
vect2& vect2::operator-=(const vect2 &v)
{
	x -= v.x;
	y -= v.y;
	return(*this);
}
vect2& vect2::operator*=(int s)
{
	x *= s;
	y *= s;
	return(*this);
}

vect2& vect2::operator++()
{
	x++;
	y++;
	return(*this);
}
vect2 vect2::operator++(int)
{
	vect2 tmp = *this;
	x++;
	y++;
	return(tmp);
}
vect2& vect2::operator--()
{
	x--;
	y--;
	return(*this);
}
vect2 vect2::operator--(int)
{
	vect2 temp = *this;
	x--;
	y--;
	return(temp);
}

bool vect2::operator==(const vect2 &v) const
{
	return(x == v.x && y == v.y);
}
bool vect2::operator!=(const vect2 &v) const
{
	return(!(x == v.x && y == v.y));
}