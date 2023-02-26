#include <math.h>
#include <stdio.h>

#define pi 3.14

struct figure {
    float x;
    float y;
    float r;
};
typedef struct figure fgr;

int main()
{
    FILE* file;

    file = fopen("test.txt", "r");

    int k = 0;
    char temp_tmp[50];

    while (fgets(temp_tmp, 50, file) != NULL) {
        k++;
    }

    fclose(file);

    file = fopen("test.txt", "r");

    // fgr geom[k];

    char temp[50];
    char str[10];
    k = 0;

    while (fgets(temp, 50, file) != NULL) {
        printf("%s", temp);
        int flag = 1;

        float x = 0;
        float y = 0;
        float r = 0;

        int tmp = 0;
        while ((temp[tmp] >= 'A' && temp[tmp] <= 'Z')
               || (temp[tmp] >= 'a' && temp[tmp] <= 'z')) {
            if (temp[tmp] >= 'A' && temp[tmp] <= 'Z')
                str[tmp] = temp[tmp] - 'A' + 'a';
            else
                str[tmp] = temp[tmp];
            tmp++;
        }

        str[tmp] = '\0';
        tmp++;

        if (((str[0] != 'c') || (str[1] != 'i') || (str[2] != 'r')
             || (str[3] != 'c') || (str[4] != 'l') || (str[5] != 'e')
             || (temp[6] != '('))
            && flag == 1) {
            printf("^\nError at column 0: expected 'circle'\n");
            flag = 0;
        }

        while (temp[tmp] == ' ')
            tmp++;

        while (temp[tmp] >= '0' && temp[tmp] <= '9') {
            x = x * 10 + (temp[tmp] - '0');
            tmp++;
        }

        if (temp[tmp] == '.') {
            tmp++;
            int z = -1;
            while (temp[tmp] >= '0' && temp[tmp] <= '9') {
                x = x + (temp[tmp] - '0') * pow(10, z);
                tmp++;
            }
        }

        if (((temp[tmp] >= 'A' && temp[tmp] <= 'Z')
             || (temp[tmp] >= 'a' && temp[tmp] <= 'z'))
            && flag == 1) {
            for (int i = 0; i < tmp; i++)
                printf(" ");
            printf("^\nError at column %d: expected '<double>'\n", tmp);
            flag = 0;
        }

        while (temp[tmp] == ' ')
            tmp++;

        while (temp[tmp] >= '0' && temp[tmp] <= '9') {
            y = y * 10 + (temp[tmp] - '0');
            tmp++;
        }

        if (temp[tmp] == '.') {
            tmp++;
            int z = -1;
            while (temp[tmp] >= '0' && temp[tmp] <= '9') {
                y = y + (temp[tmp] - '0') * pow(10, z);
                tmp++;
            }
        }

        if (((temp[tmp] >= 'A' && temp[tmp] <= 'Z')
             || (temp[tmp] >= 'a' && temp[tmp] <= 'z'))
            && flag == 1) {
            for (int i = 0; i < tmp; i++)
                printf(" ");
            printf("^\nError at column %d: expected '<double>'\n", tmp);
            flag = 0;
        }

        while (temp[tmp] == ',')
            tmp++;

        while (temp[tmp] == ' ')
            tmp++;

        while (temp[tmp] >= '0' && temp[tmp] <= '9') {
            r = r * 10 + (temp[tmp] - '0');
            tmp++;
        }

        if (temp[tmp] == '.') {
            tmp++;
            int z = -1;
            while (temp[tmp] >= '0' && temp[tmp] <= '9') {
                r = (float)r + (temp[tmp] - '0') * pow(10, z);
                tmp++;
            }
        }

        if (((temp[tmp] >= 'A' && temp[tmp] <= 'Z')
             || (temp[tmp] >= 'a' && temp[tmp] <= 'z'))
            && flag == 1) {
            for (int i = 0; i < tmp; i++)
                printf(" ");
            printf("^\nError at column %d: expected '<double>'\n", tmp);
            flag = 0;
        }

        while (temp[tmp] != ')' && flag == 1) {
            if (temp[tmp] == '(' && flag == 1) {
                for (int i = 0; i < tmp; i++)
                    printf(" ");
                printf("^\nError at column %d: expected ')'\n", tmp);
                flag = 0;
            }
        }

        tmp++;

        while ((tmp < 50 || temp[tmp] != '\0') && flag == 1) {
            if (((temp[tmp] >= 'A' && temp[tmp] <= 'Z')
                 || (temp[tmp] >= 'a' && temp[tmp] <= 'z')
                 || (temp[tmp] >= '0' && temp[tmp] <= '9'))
                && flag == 1) {
                for (int i = 0; i < tmp; i++)
                    printf(" ");
                printf("^\nError at column %d: unexpected token\n", tmp);
                flag = 0;
            }
            tmp++;
        }

        k++;

        // printf("%s(%.f %.f, %.f)\n", str, x, y, r);
    }

    fclose(file);
    return 0;
}
