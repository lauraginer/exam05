/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 21:22:52 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/30 21:06:32 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

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
		int& vect2::operator[](int i);
		int vect2::operator[](int i) const;
	
};
#endif