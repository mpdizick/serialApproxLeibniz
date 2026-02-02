/**
 * @file main.c
 * @author Mason Dizick (mpdizick@coastal.edu)
 * @brief Main driverprogram for approximating pi using the Leibniz formula.
 * 
 * This program calculates an approximation of pi using the infinite series:
 * pi = 4 * SUM(k=0 to n-1) of ((-1)^k / (2k+1))
 * 
 * The program accepts a command-line argument for the number of terms (n)
 * and measures the execution time of the computation.
 * 
 * @version 1.1
 * @date 2026-02-04
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#define _POSIX_C_SOURCE 199309L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "pi_functions.h"

// gcc main.c -o pi_approx
// ./pi_approx n

/**
 * @brief Main entry point for the program
 * 
 * Parse command-line arguements, validate, compute approximation with timing
 * information, and output results.
 * 
 * @param argc Number of command-line arguments
 * @param argv Array of command-line strings
 * @return int Exit status, 0 for success, 1 for error
 */

 int main(int argc, char *argv[]) {
    // Validate
    if (argc != 2) {
        printf("Usage: %s <n>\n",argv[0]);
        printf("    where n is the number of terms to compute\n");
        printf("\nExample: %s 1000000\n", argv[0]);
        return 1;
    }

    // Convert to int
    int n = atoi(argv[1]);

    //Validate
    if (n <=0) {
        fprintf(stderr, "Error: n must b a positive integer\n");
        return 1;
    }

    // Header
    printf("======================================\n");
    printf("Pi approximation using Leibniz Formula");

    // Timing
    struct timespec start_time, end_time;
    double elapsed_time;

    //Record start time
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    //Compute
    double pi_approx = approximate_pi(n);

    //Record end time
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    //Calculate elapsed time in seconds
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    //Calculate error
    double error = fabs(M_PI - pi_approx);

    //Diplay Output
    printf("Results:\n");
    printf("-----------------------------------------\n");
    printf("Approximation:       %.15f\n", pi_approx);
    printf("Actual pi:           %.15f\n", M_PI);
    printf("Absolute Error:      %.15f\n", error);
    printf("Relative Error:      %.15f\n", error / M_PI);
    printf("-----------------------------------------\n");
    printf("Computation Time:    %.9f seconds\n", elapsed_time);
    printf("=========================================\n");

    //Output in CSV
    printf("CSV Format: n, seconds");
    printf("\nCSV_OUTPUT: %d,%.9f\n", n , elapsed_time);


    return 0;
 }
