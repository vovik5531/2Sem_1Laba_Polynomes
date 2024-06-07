#ifndef FUNCTION_INDETAILS_H
#define FUNCTION_INDETAILS_H
#include "function_methods.h"
#include <inttypes.h>
typedef struct Complex 
{
    double argument; 
    double module;
}Complex;


void print_complex(const void* z);

void* add_complex(const void* z1, const void* z2);

void* scalar_result_complex(const void* z1, const void* scalar);

void* power_result_complex(const void* z1, const int degree);

typedef double Real;

void print_real(const void* r1);

void* add_real(const void* r1, const void* r2);

void* scalar_result_real(const void* r1, const void* r2);

void* power_result_real(const void* r1, const int degree);

void input_polynome(Poly** poly1, Poly** poly2);

void input_polynome_complex(Poly** poly1, Poly** poly2);

void outistic_polynomes(Poly** poly); 
#endif