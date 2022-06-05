/**
 * @file Main.c
 * @author vishal K
 * @brief 
 * @version @ref VERSION
 * @date 2020-12-20
 * @bug No known bugs at the time of development
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "CurveFitting.h"


/**
 * @brief Construct a new test Linear Curve Fit Func object
 * 
 */
static testLinearCurveFitFunc()
{
    sLinearCurveParams_t param = {0,0};
    float arrX[5] = {0,1,2,3,4};
    float arrY[5] = {1,3,5,7,9};

    eErrorCode_t status = LinearCurveFit_ComputeEquation(arrX, arrY, sizeof(arrX)/sizeof(arrX[0]), &param);

    assert(2 == param.slope);
    assert(1 == param.Intercept);

    printf("slope = %d, Intercept =  %d", param.slope, param.Intercept );
}



/**
 * @brief Function entry point
 * 
 * 
 * @return int 
 */
int main()
{
    testLinearCurveFitFunc();
    return 0;

}