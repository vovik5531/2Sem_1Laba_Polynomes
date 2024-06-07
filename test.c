#include "test.h"
#define PI 3.141592
/*
double randt() {
    srand(time(0) + sleep(1));
    return (double)rand() / RAND_MAX * 100.0;
}
*/

void test_poly_complex() {
    double n1 = 1;
    double n2 = 2;
    double n3 = 3;
    double n4 = 4;

    Complex c1 = {n1, n2};
    Complex c2 = {n3, n4};
    Complex *stored_c1 = &c1;
    Complex *stored_c2 = &c2;

    Poly* v = New_Poly(2, add_complex, scalar_result_complex, print_complex, power_result_complex);
    poly_push_back(v, stored_c1);
    poly_push_back(v, stored_c2);


    printp(v);

    Complex* result = (Complex*) scalar_product(v, v);
    printf("Скалярное произведение векторов: %.2f + %.2fi\n", result->module, result->argument);

    assert(fabs((n1 * n3+ n2 * n4) - result->module) < 10e6);
    assert(fabs((n2 * n3 + n4 * n1) - result->argument) < 10e6);

    free(result);
    poly_free(v);
}

void test_poly_real() {
    double r1 = 1;
    double r2 = 2;
    double r3 = 3;

    double *stored_r1 = &r1;
    double *stored_r2 = &r2;
    double *stored_r3 = &r3;

    Poly* v = New_Poly(2, add_real, scalar_result_real, print_real, power_result_real);
    poly_push_back(v, stored_r1);
    poly_push_back(v, stored_r2);

    printp(v);

    Poly* result = (Poly*) scalar_product(v, stored_r3);

    printp(result);
    Complex z1, z2, z3, z4; 
    z1.argument = PI/2;
    z1.module = 3; 

    z2.argument = PI/6;
    z2.module = 1;

    z3.argument = PI/3; 
    z3.module = 4;

    z4.argument = PI; 
    z4.module = 2; 

    Complex* stored_z1 = &z1;
    Complex* stored_z2 = &z2;
    Complex* stored_z3 = &z3;
    Complex* stored_z4 = &z4;

    Poly * compl = New_Poly(3, add_complex, scalar_result_complex, print_complex, power_result_complex);
    poly_push_back(compl, stored_z1);
    poly_push_back(compl, stored_z2);
    poly_push_back(compl, stored_z4);
    
    printp(compl);
    Poly* result_compl = (Poly*) scalar_product(compl, stored_z3);
    //printf("ожидание: %.5f, получено: %.5f\n", (r1 * r1 + r2 * r2 ), *result);

    //assert(fabs((r1 * r1 + r2 * r2 ) - *result) < 1e-6);
    
    free(result);
    poly_free(v);
    free(result_compl);
    poly_free(compl);
}

void test() {
    test_poly_real();
    test_poly_complex();
}
