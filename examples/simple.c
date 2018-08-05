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
#include <stdio.h>

void seed(struct stdev* stdev) {
	for(size_t i = 0; i < 1000; ++i)
		stdev->update(stdev, i % 100);
}

int main(int argc, char** argv) {
	struct stdev* stdev;
	puts("Naive Algorithm");
	stdev = stdev_create(STDEV_TYPE_NAIVE);
	seed(stdev);
	printf("  mean: %lf\n", stdev->mean(stdev));
	printf("  stdev: %lf\n", stdev->stdev(stdev));
	stdev_destroy(stdev);

	puts("Welford Algorithm");
	stdev = stdev_create(STDEV_TYPE_WELFORD);
	seed(stdev);
	printf("  mean: %lf\n", stdev->mean(stdev));
	printf("  stdev: %lf\n", stdev->stdev(stdev));
	stdev_destroy(stdev);

	return 0;
}

