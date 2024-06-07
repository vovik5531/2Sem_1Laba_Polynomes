#include "function_in_details.h"

void print_complex(const void* z)
{
    const Complex* complex = z;
    double real, imag; 
    real = cos(complex->argument); 
    imag = sin(complex->argument); 
    if(imag >= 0 )
    {
        printf("%.4f + i%.4f", complex->module*real, complex->module*imag);
    }
    else
    {
        printf("%.4f - i%.4f", complex->module*real, (-1)*complex->module*imag);
    }
}

void* add_complex(const void* z1, const void* z2) {
    const Complex* complex1 = z1;
    const Complex* complex2 = z2;
    Complex* result = malloc(sizeof(Complex));
    double real1, imag1, real2, imag2, res_imag, res_real; 
    real1 = complex1->module*cos(complex1->argument); 
    imag1 = complex1->module*sin(complex1->argument); 
    real2 = complex2->module*cos(complex2->argument); 
    imag2 = complex2->module*sin(complex2->argument);
    res_imag = imag1 + imag2;
    res_real = real1 + real2; 
    result->module = sqrt(res_imag*res_imag+res_real*res_real);
    result->argument = atan2(res_imag, res_real);
    return result;
}
void* scalar_result_complex(const void* z1, const void* scalar)
{
    Complex* complex1 = (Complex* )z1; 
    Complex* complex2 = (Complex* )scalar; 
    Complex* result = malloc(sizeof(Complex)); 
    result->argument = complex1->argument + complex2->argument; 
    result->module = complex1->module * complex2->module; 
    return result; 
}

void* power_result_complex(const void* z1, const int degree)
{
    Complex* complex1 = (Complex*)z1; 
    Complex* result = malloc(sizeof(Complex)); 
    result->argument = complex1->argument * degree; 
    result->module = pow(complex1->module, (double)degree);
    return result; 
}

typedef double Real;

void print_real(const void* r1)
{
    const Real* result = r1; 
    printf("%.4lf", *result);
}
void* add_real(const void* r1, const void* r2)
{
    const Real* real1 = r1; 
    const Real* real2 = r2; 
    Real* result = malloc(sizeof(Real)); 
    *result = *real1+*real2; 
    return result; 
}

void* scalar_result_real(const void* r1, const void* r2)
{
    const Real* real1 = (const Real*)r1;
    const Real* real2 = (const Real*)r2;
    Real* result = malloc(sizeof(Real));
    *result = (*real1) * (*real2);
    return result;
}

void* power_result_real(const void* r1, const int degree)
{
    const Real* real1 = (const Real*)r1; 
    Real* result = malloc(sizeof(Real)); 
    *result = pow(*real1, degree); 
    return result; 
}

void input_polynome(Poly** poly1, Poly** poly2)
{
    printf("Введите размеры многочленов 1 (space) 2: ");
    int size1, size2;
    scanf("%d %d", &size1, &size2);
    *poly1 =  New_Poly(size1, add_real, scalar_result_real, print_real, power_result_real);
    *poly2 =  New_Poly(size2, add_real, scalar_result_real, print_real, power_result_real);
    printf("Введите коэффициенты 1 многолчена:\n");
    for (int i = 0; i < size1; i++) {
        double value;
        scanf("%lf", &value);
        double* element = malloc(sizeof(double));
        *element = value;
        poly_push_back(*poly1, element); 
    }
    printf("Введите коэффициенты 2 многолчена:\n");
    for (int i = 0; i < size2; i++) {
        double value;
        scanf("%lf", &value);
        double* element = malloc(sizeof(double));
        *element = value;
        poly_push_back(*poly2, element); 
    }

     printp(*poly1);
     printf("\n");  
     printp(*poly2); 

}
void outistic_polynomes(Poly** poly)
{
    printp(*poly); 
}
void input_polynome_complex(Poly** poly1, Poly** poly2)
{
    printf("Введите размеры многочленов 1 (space) 2: ");
    int size1, size2;
    scanf("%d %d", &size1, &size2);
    *poly1 =  New_Poly(size1, add_complex, scalar_result_complex, print_complex, power_result_complex);
    printf("Введите коэффициенты 1 многолчена (Re, Im):\n");
    for (int i = 0; i < size1; i++) {
        double real_part, imag_part;
        scanf("%lf %lf", &real_part, &imag_part);
        Complex* element = malloc(sizeof(Complex));
        element->module = sqrt(real_part*real_part+imag_part*imag_part);
        element->argument = atan2(imag_part, real_part); 
        poly_push_back(*poly1, element);  
    }

    *poly2 =  New_Poly(size2, add_complex, scalar_result_complex, print_complex, power_result_complex);
    printf("Введите коэффициенты 2 многолчена (Re, Im):\n");
    for (int i = 0; i < size2; i++) {
        double real_part, imag_part;
        scanf("%lf %lf", &real_part, &imag_part);
        Complex* element = malloc(sizeof(Complex));
        element->module = sqrt(real_part*real_part+imag_part*imag_part);
        element->argument = atan2(imag_part, real_part); 
        poly_push_back(*poly2, element);  
    }
    printp(*poly1);
    printf("\n");  
    printp(*poly2); 
}

