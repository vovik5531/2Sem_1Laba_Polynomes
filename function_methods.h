#ifndef FUNCTION_METHODS_H
#define FUNCTION_METHODS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include "liba.h"

typedef struct Poly { 
    size_t size; 

    size_t capacity;

    void** data;

    void* (*add)(const void*, const void*);

    void* (*scalar_result)(const void*, const void*);
    
    void (*print) (const void*);
    
    void* (*power_value) (const void*, const int); 

}Poly;
    Poly* New_Poly(size_t capacity,  void* (*add)(const void*, const void*), void* (*scalar_result)(const void*, const void*), void  (*poly_print)(const void*), void* (*power_value)(const void*, const int));

    void* power(const Poly* polynome, const void* value, const int degree);

    void printp(const Poly* poly); 

    void poly_push_back(Poly* poly, const void* value);

    Poly* poly_add(const  Poly* poly1, const Poly* poly2);

    Poly* scalar_product(const Poly* polynome, const void* scalar);
    
    size_t polynome_size(const Poly* poly);
    
    void* compose_two_polies(const Poly* poly1, const Poly* poly2, const void* value);


#endif /* FUNCTION_METHODS_H */