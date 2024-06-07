#include "out.h"
enum Commands
{
    EXIT,
    ENTER_POLY,
    ENTER_COMPLEX_POLY,
    PRINT_POLY,
    COMPOSE_POLY,
    ADD_POLIES,
    SCALAR_PRODUCT,
    TESTS

};
char* command_names[] = {
    "Выход",
    "Ввод многочлена",
    "Ввод комплексного многочлена",
    "Вывод многочлена",
    "Композиция значений",
    "Сложение многочленов",
    "Умножение на скаляр",
    "Тестирование"
};

void poly_free(Poly* v) {
    if(!v) return;
    for(int i=0;i<v->size;i++){
        free(v->data[i]);
    }
    free(v->data);
    free(v);
}

void Start_Program()
{

    Poly* poly1 = NULL;//New_Poly(2, add_real, scalar_result_real,  print_real, power_result_real); 
    Poly* poly2 = NULL;//New_Poly(2, add_real, scalar_result_real,  print_real, power_result_real); 
    
    while(1)
    {
        
        printf("\n Выбери команду:\n");
        for (int i = 0; i < sizeof(command_names) / sizeof(char*); i++) 
        {
            printf("%d. %s\n", i + 1, command_names[i]);
        }
        printf("0. Выход\n");
        int command;
        scanf("%d", &command);
       
        switch (command-1) {
            case EXIT:
                printf("freeing and exiting..\n");
                poly_free(poly1);
                poly_free(poly2);
                return;
            case ENTER_POLY:
                input_polynome(&poly1, &poly2);
                break;
            case ENTER_COMPLEX_POLY:
                input_polynome_complex(&poly1, &poly2);
                break;
            case PRINT_POLY:
                outistic_polynomes(&poly1); 
                break; 
            case COMPOSE_POLY:
                if(poly1->print == print_complex)
                {
                    double im, re;
                    printf("Введите действительную и мнимую часть аргумента:\n");
                    scanf("%lf %lf", &re, &im); 
                    Complex* value1 = calloc(1, sizeof(Complex));
                    value1->module = sqrt(re*re+im*im); 
                    value1->argument = atan2(im, re); 
                    poly1->print(value1);
                    printf(" argument in\n");
                    printp(poly1);
                    printf("in \n= ");  
                    poly1->print(compose_two_polies(poly1, poly2, value1)); 
                    printf("\nthis in: "); 
                    printp(poly2);
                    printf("= ");  
                    poly1->print(compose_two_polies(poly2, poly1, compose_two_polies(poly1, poly2, value1)));
                }
                else
                {
                    double temp; 
                    printf("Введите аргумент:\n"); 
                    void* value=calloc(1,sizeof(double));
                    scanf("%lf", &temp); 
                    *((double*)value) = temp; 
                    poly1->print(value);
                    printf(" argument in\n");
                    printp(poly1);
                    printf("in \n= ");  
                    poly1->print(compose_two_polies(poly1, poly2, value)); 
                    printf("\nthis in: "); 
                    printp(poly2);
                    printf("= ");  
                    poly1->print(compose_two_polies(poly2, poly1, compose_two_polies(poly1, poly2, value)));
                }
                break;
            case ADD_POLIES:
                poly_add(poly1, poly2);
                break;
            case SCALAR_PRODUCT:
                if(poly1->print == print_complex)
                {
                    double im, re;
                    printf("Введите действительную и мнимую часть аргумента:\n");
                    scanf("%lf %lf", &re, &im); 
                    Complex* value1 = calloc(1, sizeof(Complex));
                    value1->module = sqrt(re*re+im*im); 
                    value1->argument = atan2(im, re); 
                    printp(poly1);
                    printf("*\n");  
                    poly1->print(value1); 
                    printf("=\n");
                    printp(scalar_product(poly1, value1));
                    poly_free(scalar_product(poly1, value1));
                }
                else
                {
                    void* value=calloc(1,sizeof(double));
                    double temp; 
                    printf("Введите аргумент:\n"); 
                    scanf("%lf", &temp); 
                    *((double*)value) = temp; 
                    scalar_product(poly1, value);
                    printp(poly1);
                    printf("*\n");  
                    poly1->print(value); 
                    printf("=\n");
                    printp(scalar_product(poly1, value));
                    poly_free(scalar_product(poly1, value));
                }
                break;
            case TESTS: 
                test();
                break;
            default:
                printf("Неизвестная команда\n");
                break;
        }
    }
}
