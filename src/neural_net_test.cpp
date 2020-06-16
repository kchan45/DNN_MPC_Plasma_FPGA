/*
 * neural network test bench file
 *
 * Author: Kimberly Chan
 * Organization: Mesbah Lab at UC Berkeley
 */

#include <stdio.h>
#include <stdlib.h>
#include "neural_net.h"

#define EPS 0.1

int main() {
	data_t test_input[NUM_INPUTS] = {1.0, 1.0 ,1.0};
	data_t test_output[NUM_OUTPUTS] = {0};
	float verified_output[NUM_OUTPUTS] = {0.999592, 0.901232};

	neural_net(test_input, test_output);

	// FILE* verified_output_file = fopen("out.txt", "r");
	// if (verified_output_file == NULL) {
	// 	printf("Couldn't open file.");
	// 	exit(1);
	// }
	//
	// for (int i=0; i<NUM_OUTPUTS; i++) {
	// 	fscanf(verified_output_file, "%f", &verified_output[i]);
	// }

	int num_correct = 0;
	int total = 0;

	printf("Checking DNN Evaluation ... \n");

	for (int i=0; i<NUM_OUTPUTS; i++) {
		total++;
		float error = (float)test_output[i] - verified_output[i];
		error = error * error;
		if (error > EPS) {
			printf("The value at the %d index does not match!\n", i);
		} else {
			num_correct++;
		}
	}
	printf("Done! %d out of %d were correct.\n", num_correct, total);

	if (num_correct == total) {
		return 0;
	} else {
		return 1;
	}
}
