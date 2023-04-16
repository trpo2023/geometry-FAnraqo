#pragma once

int checking_for_errors(string temp);
void filling_in_structure(string temp, float *x, float *y, float *r, int k);
void calculation(float *x, float *y, float *r, float *perimeter, float *area, int k);
void overlay(float *xi, float *yi, float *ri, string *intersects, float *xj, float *yj, float *rj, int j);
void print_structure(float *x, float *y, float *r, float *perimeter, float *area, string *intersects, int i);