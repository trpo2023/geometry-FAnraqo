#pragma once

#include <iostream>
#include <stdio.h>
#include <string>

int checking_for_errors(std::string temp);
void filling_in_structure(std::string temp, float* x, float* y, float* r);
void calculation(float* r, float* perimeter, float* area);
void overlay(
        float* xi,
        float* yi,
        float* ri,
        std::string* intersects,
        float* xj,
        float* yj,
        float* rj,
        int j);
void print_structure(
        float* x,
        float* y,
        float* r,
        float* perimeter,
        float* area,
        std::string* intersects,
        int i);