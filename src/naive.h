/*
    libstdev: standard deviation algorithms
    Copyright (C) 2018 junhee lee
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef __STDEV_NAIVE_H__
#define __STDEV_NAIVE_H__

#include <stdev/stdev.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

struct stdev_naive {
	struct stdev super;
	size_t sample_count;
	double sample_sum;
	double squre_sample_sum;
};

struct stdev* stdev_naive_create(void);
void stdev_naive_destroy(struct stdev* self);

#ifdef __cplusplus
}
#endif

#endif

