#include <libgeometry/functions.h>

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

struct figure
{
    float x = 0;
    float y = 0;
    float r = 0;
    float perimeter = 0;
    float area = 0;
    string intersects;
};
typedef struct figure figure;

int main()
{
    ifstream f;
    string file = "test";
    f.open(file);

    int k = 0;
    int flag = 0;

    if (!f.is_open())
    {
        cout << "Файл не открыт" << endl;
        return 0;
    } 
    else
        while (!f.eof())
        {
            string temp;
            getline(f, temp);
            if (checking_for_errors(temp) != 0) flag = 1;
            k ++;
        }

    if (flag != 0)
    {
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        printf("\nВ файле есть ошибки в оформлении данных");
        printf(", исправьте их и запустите программу заново)\n");
        f.close();
        return 0;
    }

    f.close();

    figure fgr[k];
    k = 0;
    
    f.open(file);
    if (!f.is_open())
    {
        cout << "Файл не открыт" << endl;
        return 0;
    } 
    else
        while (!f.eof())
        {
            string temp;
            getline(f, temp);
            filling_in_structure(temp, &fgr[k].x, &fgr[k].y, &fgr[k].r);
            k ++;
        }

    for (int i = 0; i < k; i++)
    {
        calculation(&fgr[i].r, &fgr[i].perimeter, &fgr[i].area);
        for (int j = 0; j < k; j++)
            if (i != j)
                overlay(
                    &fgr[i].x, 
                    &fgr[i].y, 
                    &fgr[i].r, 
                    &fgr[i].intersects, 
                    &fgr[j].x, 
                    &fgr[j].y, 
                    &fgr[j].r, 
                    j);
    }

    for (int i = 0; i < k; i++)
    {
        print_structure(
            &fgr[i].x, 
            &fgr[i].y, 
            &fgr[i].r, 
            &fgr[i].perimeter, 
            &fgr[i].area, 
            &fgr[i].intersects, 
            i);
    }
    
    return 0;
}