/**
 * @file pi_functions.c
 * @author Mason Dizick (mpdizick@coastal.edu)
 * 
 * @brief Implementation of functions for approximating pi
 * 
 * This file contains the implementation for approximating pi
 * through and infinite series.
 * 
 * @version 1.1
 * @date 2026-02-04
 * 
 * @copyright Copyright (c) 2026
 * 
 */

 #include "pi_functions.h"

 /**
  * @brief Apprimate the value of pi using Leibniz formula
  * 
  * Implementation details:
  * - Uses alternating series: 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
  * - Multiplies final sum by 4 to get pi approximation
  * - Uses integer sign variable for efficiency instead of pow(-1, k)
  * - Accumulates sum in a double precision variable
  * 
  * Time Complexity: O(n)
  * Space Complexity: O(1)
  * 
  * @param n Number of terms in the series
  * @return double The approximation of pi
 */

 double approximate_pi(int n) {
    double sum = 0.0;   //Accumulator for the series sum
    int sign = 1;       //Alternating sign

    //Compute the series sum
    for (int k = 0; k < n; k++) {
        //Calculate sign of current sum
        double term = sign / (2.0 * k + 1);

        //Add term to existing sum
        sum += term;

        //Flip sign for next iteration
        sign = -sign;
    }

    //Multiply by 4 for pi approx
    return 4.0 * sum;
    
 }