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
#include <stdev/stdev.h>
#include <stdlib.h>
#include "naive.h"
#include "welford.h"

struct stdev* stdev_create(enum stdev_type type, ...) {
	struct stdev* self = NULL;

	switch(type) {
		case STDEV_TYPE_NAIVE:
			self = stdev_naive_create();
			break;
		case STDEV_TYPE_WELFORD:
			self = stdev_welford_create();
			break;
		default:
			break;
	}

	return self;
}

void stdev_destroy(struct stdev* self) {
	switch (self->type) {
		case STDEV_TYPE_NAIVE:
			stdev_naive_destroy(self);
			break;
		case STDEV_TYPE_WELFORD:
			stdev_welford_destroy(self);
			break;
		default:
			break;
	}
}
