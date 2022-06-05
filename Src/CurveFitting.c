/**
 * @file CurveFitting.c 
 * @author vishal 
 * @brief : Utility file to perform curve fitting 
 * @version 0.1
 * @date 2022-06-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "CurveFitting.h"
#include <stdint.h>
#include <math.h>
#include <assert.h>

/**
 * @brief Routine to compute square of a number 
 * 
 * @param num : number to be squared 
 * @return uint32_t : square of num 
 */
static inline float computeSquare(float num)
{
    return num*num ;
}

/**
 * @brief Computes slope and intercept given a pair of x and Y values,  
 * Y = Slope * X + Intercept 
 * @param arrX : Independent value x 
 * @param arrY : Dependent value y 
 * @param arrSize : array size , assumed to be the same for x and y 
 * @param pInCurveParams : @see sLinearCurveParams_t, encloses slope and intercept 
 * @return eErrorCode_t 
 */
eErrorCode_t LinearCurveFit_ComputeEquation(const float* const arrX, const float* const arrY, size_t arrSize, sLinearCurveParams_t* const pInCurveParams )
{
    eErrorCode_t status = E_SUCCESS;
    float sumX = 0 , sumY = 0,  sumx2 = 0,  sumxy = 0 ;
    float slope = 0, intercept = 0;

    ///> Ensure no null pointers 
    assert(NULL != arrX);
    assert(NULL != arrY);
    assert(NULL != pInCurveParams);

    for(int i = 0; i < arrSize; i++)
    {
        sumX += arrX[i];
        sumY += arrY[i];
        sumxy += arrX[i] * arrY[i];
        sumx2 += pow(arrX[i], 2); //> Use computeSquare is math.h unavailable 
    }

    ///> Compute slope and intercept using method of least squares 
    slope = (arrSize*sumxy - sumX*sumY)/(arrSize*sumx2 - pow(sumX,2));
    intercept = (sumY - slope*sumX)/arrSize;

    pInCurveParams->slope = slope ;
    pInCurveParams->Intercept = intercept;

    return status;
}