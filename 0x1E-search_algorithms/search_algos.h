#ifndef SEARCH_ALOGS_H_
#define SEARCH_ALOGS_H_

#include <stdio.h>

int linear_search(int *array, size_t size, int value);

int binary_search(int *array, size_t size, int value);

int jump_search(int *array, size_t size, int value);

int interpolation_search(int *array, size_t size, int value);

int exponential_search(int *array, size_t size, int value);

#endif /* SEARCH_ALOGS_H_ */
