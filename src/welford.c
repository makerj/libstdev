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
#include "welford.h"
#include <stdlib.h>

static double welford_mean(struct stdev* a_self) {
	struct stdev_welford* self = (struct stdev_welford*)a_self;
	return self->sample_mean;
}

static double welford_stdev(struct stdev* a_self) {
	struct stdev_welford* self = (struct stdev_welford*)a_self;
	if(self->sample_count <= 1)
		return 0;

	return self->sample_M2 / self->sample_count;
}

static void welford_update(struct stdev* a_self, double sample) {
	struct stdev_welford* self = (struct stdev_welford*)a_self;

	double delta = sample - self->sample_mean;

	self->sample_count += 1;
	self->sample_mean = self->sample_mean + (delta / self->sample_count);
	self->sample_M2 += delta * delta;
}

struct stdev* stdev_welford_create(void) {
	struct stdev_welford* self = (struct stdev_welford*)calloc(1, sizeof(struct stdev_welford));
	self->super.mean = welford_mean;
	self->super.stdev = welford_stdev;
	self->super.update = welford_update;
	return (struct stdev*)self;
}

void stdev_welford_destroy(struct stdev* self) {
	free(self);
}

