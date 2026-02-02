/**
 * @file pi_functions.h
 * @author Mason Dizick (mpdizick@coastal.edu)
 * @brief Header file containing function declatartions for pi approximation.
 * 
 * This header file declares the functions used to approximate the value of pi
 * using the Leibniz formuala.
 * 
 * @version 1.1
 * @date 2026-02-04
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef PI_FUNCTIONS_H
#define PI_FUNCTIONS_H

/**
 * @brief Approximated thevalue of pi using the Gregory-Leibniz series formula.
 * 
 * @param n Number of terms to compute in the series (must be positive)
 * @return double Approximation of pi based on n terms
 * 
 * @note Convergence is O(1/n), so accuracy improves slowly
 * @note For n=1000000, error is approximately 10^-6
 * 
 * Example:
 * @code
 *   int n = 1000000;
 *   double pi_value = approximate_pi(n);
 *   printf("Pi approximation: %f\n", pi_value);
 * @endcode
**/

double approximate_pi(int n);

#endif  //PI_FUNCTIONS_H