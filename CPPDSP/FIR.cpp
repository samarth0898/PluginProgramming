#include "FIR.h"


/*
* fir_filter - Performs FIR filtering sample by sample on floats
* ingests an array of filter coefficients and pointer to history
* returns one output sample for each input sample (N input gives N output)
*/


float fir_filter(float input, float* coeff, int n, float* history)
{
	float* hist1_ptr, * hist_ptr;
	float* coef_ptr = coeff + n - 1; //Point to the last coefficient 
	float output;

	hist_ptr = history;
	hist1_ptr = hist_ptr;

	// Multiply and accumulate 

	output = *hist_ptr++ * (*coef_ptr--);
	for (int i = 2; i < n; i++) {
		*hist1_ptr++ = *hist_ptr;
		output += (*hist_ptr++) * (*coef_ptr--);
	}
	output += input * (*coef_ptr);

	//Modifies by reference 
	*hist1_ptr = input;


	return output;
}