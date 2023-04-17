#include <libgeometry/functions.h>

#include <iostream>
#include <stdio.h>
#include <string>

#include <cmath>
#define _USE_MATH_DEFINES

int check_of_digit(std::string temp, int tmp)
{
    while (temp[tmp] >= '0' && temp[tmp] <= '9')
        tmp++;
    return tmp;
}

void error_pointer(std::string temp, int tmp)
{
    std::cout << temp << std::endl;
        for (int i = 0; i < tmp; i++)
            printf(" ");
}

int checking_for_errors(std::string temp)
{
    std::string figur;
    figur.insert(0, temp, 0, 7);

    if (figur != "circle("){
        std::cout << temp << std::endl;
        printf("^\nError at column 0: expected 'circle'\n\n");
        return 1;
    }
    
    int tmp = 7;

    while (temp[tmp] == ' ') tmp++;
    
    tmp = check_of_digit(temp, tmp);
    
    if (temp[tmp] == '.') tmp++;

    tmp = check_of_digit(temp, tmp);
    
    if ((temp[tmp] >= 'A' && temp[tmp] <= 'Z')
         || (temp[tmp] >= 'a' && temp[tmp] <= 'z')){
        error_pointer(temp, tmp);
        printf("^\nError at column %d: expected '<double>'\n\n", tmp);
        return 1;
    }
    
    while (temp[tmp] == ' ') tmp++;

    tmp = check_of_digit(temp, tmp);

    if (temp[tmp] == '.') tmp++;

    tmp = check_of_digit(temp, tmp);

    if ((temp[tmp] >= 'A' && temp[tmp] <= 'Z')
         || (temp[tmp] >= 'a' && temp[tmp] <= 'z')){
        error_pointer(temp, tmp);
        printf("^\nError at column %d: expected '<double>'\n\n", tmp);
        return 1;
    }

    while (temp[tmp] == ',') tmp++;

    while (temp[tmp] == ' ') tmp++;

    tmp = check_of_digit(temp, tmp);

    if (temp[tmp] == '.') tmp++;

    tmp = check_of_digit(temp, tmp);

    if ((temp[tmp] >= 'A' && temp[tmp] <= 'Z')
         || (temp[tmp] >= 'a' && temp[tmp] <= 'z')){
        error_pointer(temp, tmp);
        printf("^\nError at column %d: expected '<double>'\n\n", tmp);
        return 1;
    }

    while (temp[tmp] != ')') {
        if (temp[tmp] == '(') {
            error_pointer(temp, tmp);
            printf("^\nError at column %d: expected ')'\n\n", tmp);
            return 1;
        }
        tmp ++;
    }

    tmp++;

    while (tmp < (int)temp.length()) {
        if ((temp[tmp] >= 'A' && temp[tmp] <= 'Z')
             || (temp[tmp] >= 'a' && temp[tmp] <= 'z')
             || (temp[tmp] >= '0' && temp[tmp] <= '9')){
            error_pointer(temp, tmp);
            printf("^\nError at column %d: unexpected token\n\n", tmp);
            return 1;
        }
        tmp++;
    }

    return 0;
}

void filling_in_structure(std::string temp, float *x, float *y, float *r)
{
    int tmp = 7;

    while (temp[tmp] == ' ') tmp++;

    int flag = 0;

    if (temp[tmp] == '-')
    {
        flag = 1;
        tmp ++;
    }
    
    while (temp[tmp] >= '0' && temp[tmp] <= '9')
    {
        *x = *x * 10 + (temp[tmp] - '0');
        tmp++;
    }
    
    if (temp[tmp] == '.')
    {
        tmp++;
        int z = -1;
        while (temp[tmp] >= '0' && temp[tmp] <= '9')
        {
            *x = *x + (temp[tmp] - '0') * pow(10, z);
            tmp++;
        }
    }

    if (flag == 1)
        *x *= -1;
    
    while (temp[tmp] == ' ') tmp++;

    flag = 0;

    if (temp[tmp] == '-')
    {
        flag = 1;
        tmp ++;
    }

    while (temp[tmp] >= '0' && temp[tmp] <= '9')
    {
        *y = *y * 10 + (temp[tmp] - '0');
        tmp++;
    }

    if (temp[tmp] == '.')
    {
        tmp++;
        int z = -1;
        while (temp[tmp] >= '0' && temp[tmp] <= '9')
        {
            *y = *y + (temp[tmp] - '0') * pow(10, z);
            tmp++;
        }
    }

    if (flag == 1)
        *y *= -1;

    while (temp[tmp] == ',') tmp++;

    while (temp[tmp] == ' ') tmp++;

    while (temp[tmp] >= '0' && temp[tmp] <= '9')
    {
        *r = *r * 10 + (temp[tmp] - '0');
        tmp++;
    }

    if (temp[tmp] == '.') 
    {
        tmp++;
        int z = -1;
        while (temp[tmp] >= '0' && temp[tmp] <= '9')
        {
            *r = *r + (temp[tmp] - '0') * pow(10, z);
            tmp++;
        }
    }
}

void calculation(float *r, float *perimeter, float *area)
{
    *perimeter = *r * 2 * 3.14;
    *area = (float)M_PI * pow(*r, 2);
}

void overlay(
    float *xi, 
    float *yi, 
    float *ri, 
    std::string *intersects, 
    float *xj, 
    float *yj, 
    float *rj, 
    int j)
{
    if (pow(*ri - *rj, 2) <= pow(*xi - *xj, 2) + pow(*yi - *yj, 2) &&
        pow(*xi - *xj, 2) + pow(*yi - *yj, 2) <= pow(*ri + *rj, 2))
        *intersects = *intersects + std::to_string(j + 1) + " circle ";
}

void print_structure(
    float *x, 
    float *y, 
    float *r, 
    float *perimeter, 
    float *area, 
    std::string *intersects, 
    int i)
{
    std::cout << i + 1 << ". circle(" << *x << ' ' 
              << *y << ", " << *r << ')' << std::endl << 
                "\tperimeter = " << *perimeter << std::endl <<
                "\tarea = " << *area << std::endl << 
                "\tintersects:" << std::endl;
    
    std::string temp = *intersects;
    int tmp = 0;

    while (tmp < (int)temp.length())
    {
        if (temp[tmp] >= '0' && temp[tmp] <= '9'){
            std::cout << "\t   " << temp[tmp];
            tmp ++;
        }
        if (temp[tmp] == ' '){
            std::cout << ' ';
            tmp ++;
        }
        while ((temp[tmp] >= 'A' && temp[tmp] <= 'Z')
            || (temp[tmp] >= 'a' && temp[tmp] <= 'z'))
        {
            std::cout << temp[tmp];
            tmp ++;
        }
        std::cout << std::endl;
        tmp ++;
    }
}