#include <iostream>
#include "osm.h"
#include <cmath>
#include <sys/time.h>

#define ROLLING_FACTOR 10

void empty_function()
{
}
/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time(unsigned int iterations)
{
    if (iterations == 0)
    {
        return -1;
    }
    struct timeval start_tv = {};
    struct timeval end_tv = {};
    int x = 0;
    gettimeofday(&start_tv, NULL);
    for (int i = 0; i < ceil(iterations / (double) ROLLING_FACTOR); i++)
    {
        x = 5 + 10;
        x = 5 + 10;
        x = 5 + 10;
        x = 5 + 10;
        x = 5 + 10;
        x = 5 + 10;
        x = 5 + 10;
        x = 5 + 10;
        x = 5 + 10;
        x = 5 + 10;
    }
    gettimeofday(&end_tv, NULL);
    time_t start = start_tv.tv_sec * 1e9 + start_tv.tv_usec * 1e3;
    time_t end = end_tv.tv_sec * 1e9 + end_tv.tv_usec * 1e3;

    return (double)(end - start) / iterations;
}

/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_function_time(unsigned int iterations)
{
    if (iterations == 0)
    {
        return -1;
    }
    struct timeval start_tv = {};
    struct timeval end_tv = {};
    gettimeofday(&start_tv, NULL);
    for (int i = 0; i < ceil(iterations / (double) ROLLING_FACTOR); i++)
    {
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
    }
    gettimeofday(&end_tv, NULL);
    time_t start = start_tv.tv_sec * 1e9 + start_tv.tv_usec * 1e3;
    time_t end = end_tv.tv_sec * 1e9 + end_tv.tv_usec * 1e3;

    return (double)(end - start) / iterations;
}

/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations)
{
    if (iterations == 0)
    {
        return -1;
    }
    struct timeval start_tv = {};
    struct timeval end_tv = {};
    gettimeofday(&start_tv, NULL);
    for (int i = 0; i < ceil(iterations / (double) ROLLING_FACTOR); i++)
    {
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
    }
    gettimeofday(&end_tv, NULL);
    time_t start = start_tv.tv_sec * 1e9 + start_tv.tv_usec * 1e3;
    time_t end = end_tv.tv_sec * 1e9 + end_tv.tv_usec * 1e3;

    return (double)(end - start) / iterations;
}

