/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_v2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:42:27 by lauragm           #+#    #+#             */
/*   Updated: 2026/10/28 21:11:00 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
#define LIFE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void apply_life(char *board, char *next, int wd, int hg);
int count_neighbours(char *board, int wd, int hg, int x, int y);
void print_board(char *board, int wd, int hg);
#endif