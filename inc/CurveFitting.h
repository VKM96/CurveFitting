/**
 * @file CurveFitting.h
 * @author your name (you@domain.com)
 * @brief  Interface file for CurveFitting.c
 * @version 0.1
 * @date 2022-06-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LINEARCURVEFITTING_H
#define LINEARCURVEFITTING_H

#include <stddef.h>

/**
 * @brief : status enumeration 
 * 
 */
typedef enum
{
    E_SUCCESS,
    E_INVALID_PARAMS,
    E_UNKNOWN_ERROR,
    E_MAX_ERR

}eErrorCode_t;

/**
 * @brief structure that holds slope and intercept for linear curve fitting 
 * 
 */
typedef struct 
{
    float slope;
    float Intercept;
}sLinearCurveParams_t;


eErrorCode_t LinearCurveFit_ComputeEquation(const float* const arrX, const float* const arrY, size_t arrSize, sLinearCurveParams_t* const pInCurveParams );

#endif