#include <mex.h>
#include <stdio.h>
#include "../src/wcmLinearMath.c"

void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[])
{
	if (nlhs != 1 || nrhs != 5)
		mexErrMsgTxt("y = distortion_test(d, p, a, h, x)");
	double d = mxGetScalar(prhs[0]);
	double p = mxGetScalar(prhs[1]);
	double a = mxGetScalar(prhs[2]);
	double h = mxGetScalar(prhs[3]);
	double* x = mxGetPr(prhs[4]);
	double poly[4];
	distortionCorrectionComputePolynomial(d, p, a, h, poly);
	
	int n = mxGetNumberOfElements(prhs[4]);
	plhs[0] = mxCreateDoubleMatrix(1, n, mxREAL);
	double* y = mxGetPr(plhs[0]);
	
	for (int i = 0; i < n; ++i) {
		if (x[i] < d) {
			y[i] = 0.0;
			for (int k = 0; k < 4; ++k) {
				y[i] *= x[i];
				y[i] += poly[k];
			}
		} else {
			y[i] = x[i];
		}
	}
}
