#include <stdio.h>
#include "calculate.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ERRO 65535
#define MAX_LEN 5

int calculate(const char *calc_str)
{
    int len = strlen(calc_str);
    if (len<MAX_LEN-1 || len%2==1)
    {
        return ERRO;
    }
    int num = 0;
    int sum = 0;
    char flag = '+';
    int stack[MAX_LEN], top=0;
    int i = 0;
    while(i<len-1)
    {
        if (!isdigit(calc_str[i]) && calc_str[i]!='+'&&calc_str[i]!='-'&&calc_str[i]!='*' && calc_str[i]!='('&&calc_str[i]!=')')
        {
            return ERRO;
        }
        if (isdigit(calc_str[i]))
        {
            if (i>0 && isdigit(calc_str[i-1]))
            {
                return ERRO;
            }
            num = calc_str[i] - '0';
        }
        if (calc_str[i] == '+' ||calc_str[i] == '-' ||calc_str[i] == '*' || i == len-2)
        {
            if (flag == '+')
            {
                stack[top++] = num;
            }
            else if (flag == '-')
            {
                stack[top++] = -num;
            }
            else if (flag == '*')
            {
                stack[top-1] *= num;
            }
            if (top>MAX_LEN)
            {
                return ERRO;
            }
            flag = calc_str[i];
        }
        if (calc_str[i] == '(')
        {
            int count= 0;
            int leftb=i, rightb =i;
            for (rightb=leftb; rightb<len-1;rightb++)
            {
                if (calc_str[rightb] == '(')
                {
                    count++;
                }
                if (calc_str[rightb] == ')')
                {
                    count--;
                }
                if (count == 0)
                {
                    break;
                }
            }
            if (count!= 0)
            {
                return ERRO;
            }
            char *temp = malloc(sizeof(char)*(rightb-leftb));
            memcpy(temp, calc_str+leftb+1, rightb-leftb-1);
            temp[rightb-leftb-1]='=';
            num = calculate(temp);
            free(temp);
            temp = NULL;
            i = rightb-1;
        }
        i++;
    }
    for (i = 0;  i<top; i++)
        {
            sum += stack[i];
        }
        return sum;
}