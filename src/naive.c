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
#include "naive.h"
#include <stdlib.h>

static double naive_mean(struct stdev* a_self) {
	struct stdev_naive* self = (struct stdev_naive*)a_self;
	return self->sample_sum / self->sample_count;
}

static double naive_stdev(struct stdev* a_self) {
	struct stdev_naive* self = (struct stdev_naive*)a_self;
	if(self->sample_count <= 1)
		return 0;

	size_t n = self->sample_count;
	double sum = self->sample_sum;
	double sqsum = self->squre_sample_sum;

	return (sqsum - (sum * sum) / n) / (n - 1);
}

static void naive_update(struct stdev* a_self, double sample) {
	struct stdev_naive* self = (struct stdev_naive*)a_self;
	self->sample_count += 1;
	self->sample_sum += sample;
	self->squre_sample_sum += sample * sample;
}

struct stdev* stdev_naive_create(void) {
	struct stdev_naive* self = (struct stdev_naive*)calloc(1, sizeof(struct stdev_naive));
	self->super.mean = naive_mean;
	self->super.stdev = naive_stdev;
	self->super.update = naive_update;
	return (struct stdev*)self;
}

void stdev_naive_destroy(struct stdev* self) {
	free(self);
}

