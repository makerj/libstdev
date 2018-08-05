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
#ifndef __STDEV_STDEV_H__
#define __STDEV_STDEV_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

enum stdev_type {
	// Online algorithms
	STDEV_TYPE_NAIVE,
	STDEV_TYPE_WELFORD,
};

struct stdev {
	enum stdev_type type;
	double (*mean)(struct stdev* self);
	double (*stdev)(struct stdev* self);
	void (*update)(struct stdev* self, double sample);
};


/**
 * Create a stdev machine
 *
 * @param type type of the algorithm
 * @param ... initial parameter
 *
 * @return newly created stdev machine
 */
struct stdev* stdev_create(enum stdev_type type, ...);
void stdev_destroy(struct stdev* self);
bool stdev_test(struct stdev* self, double sample, double possibility);

#ifdef __cplusplus
}
#endif

#endif

