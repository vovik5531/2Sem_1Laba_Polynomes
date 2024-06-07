#include "function_methods.h"

Poly* New_Poly(size_t capacity, void* (*add)(const void*, const void*), void* (*scalar_result)(const void*, const void*), void  (*print)(const void*), void* (*power_value)(const void*, const int))
{
    Poly* polynome = (Poly*) malloc(sizeof(Poly)); 
    polynome->add = add; 
    polynome->capacity = capacity; 
    polynome->size = 0; 
    polynome->data = malloc(sizeof(void*) * capacity);  
    polynome->scalar_result = scalar_result; 
    polynome->print = print; 
    polynome->power_value = power_value;
    return polynome; 
} 
size_t polynome_size(const Poly* poly)
{
    return poly->size; 
}
void printp(const Poly* poly) {
    printf("[");
    for (size_t i = 0; i < poly->size; i++) {
        poly->print(poly->data[i]);  
        if (i < poly->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void poly_push_back(Poly* v, const void* value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, sizeof(void*) * v->capacity);
    }
    v->data[v->size++] = value;  
}


Poly* poly_add(const  Poly* poly1, const Poly* poly2)
{
    Poly* copy_polynome;  
    size_t minsize = polynome_size(poly1) < polynome_size(poly2) ? polynome_size(poly1) : polynome_size(poly2); 
    size_t maxsize = polynome_size(poly1) > polynome_size(poly2) ? polynome_size(poly1) : polynome_size(poly2); 
    if (polynome_size(poly1) <= polynome_size(poly2))
    {
        copy_polynome = New_Poly(poly2->size, poly2->add, poly2->scalar_result, poly2->print, poly2->power_value);
        for(size_t i=0; i< minsize; i++)
        {
            poly_push_back(copy_polynome, poly2->add(poly1->data[i], poly2->data[i]));
        }
        
        for(size_t i=minsize;  i<maxsize; ++i)
        {
            poly_push_back(copy_polynome, poly2->data[i]);
        }
    }
    if (polynome_size(poly1) > polynome_size(poly2))
    {
        copy_polynome = New_Poly(poly1->size, poly1->add, poly1->scalar_result, poly1->print, poly1->power_value);
        for(size_t i=0; i< minsize; i++){
            poly_push_back(copy_polynome, poly1->add(poly1->data[i], poly2->data[i]));
        }
        for(size_t i=minsize; i<maxsize; ++i)
        {
            poly_push_back(copy_polynome, poly1->data[i]);
        }
    } 
    
    printp(poly1);
    printf("+\n");  
    printp(poly2);
    printf("=\n");
    printp(copy_polynome); 
    return copy_polynome; 
}

Poly* scalar_product(const Poly* polynome, const void* scalar)//умножение на скалярную величину всех коэффициентов многочлена
{
    Poly* scalared_polynome = New_Poly(polynome->capacity, polynome->add, polynome->scalar_result, polynome->print, polynome->power_value);
    for(size_t i=0; i<polynome_size(polynome); ++i)
    {
        scalared_polynome->data[i] = polynome->scalar_result(polynome->data[i], scalar);
    }
    scalared_polynome->size=polynome_size(polynome);

    
    return scalared_polynome; 
}
void* power(const Poly *polynome, const void *value, const int degree) // возведение в степень элемента на месте degree у  заданного многочлена
{
    return polynome->power_value(value, degree); 
}
void* compose_two_polies(const Poly* poly1, const Poly* poly2, const void* value)//композиция двух многочленов
{
    void* result1; 
    void* temp;
    for( size_t i = 0; i<polynome_size(poly1); ++i)
    {
        temp = poly1->scalar_result(poly1->data[i], power(poly1, value, i) );
        result1 =  poly1->add(result1, temp ); 
    }
    //result1 =  poly1->add(result1, poly1->data[0] );
    return result1; 
}
