#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>  
#include <stdlib.h>
std::string itoa(int n) // из числа в строку
{
     char buf[20];
     sprintf(buf,"%d",n);
     return buf;
}
int trans_in_dec(unsigned int nb,std::string baseSrc) // перевод в десятичную с.с.
{
    int numeral_sys = baseSrc.length();
    int var = 0;
    for (size_t i = 0; i < 100000000; i++)
    {
        var += (nb % 10) * pow(numeral_sys,i);
        nb /= 10;
        if(nb == 0)
        {
            break;
        }
    }
    return var;
}
std::string itoBase(unsigned int nb, std::string base)
{  
    std::string result;
    char hex[6] = {'A', 'B' ,'C', 'D', 'E', 'F'};
    int tmp_nb;
    int numeral_sys = base.length();
    int flag = numeral_sys-1;
    if(nb <= flag)
    {
        if(nb > 9)
        {
            tmp_nb = (nb%numeral_sys);
            tmp_nb -= 10;
            result = hex[tmp_nb]; 
            return result;
        }
        return result = itoa(nb);
    }
    else if(flag > 10 && nb%numeral_sys > 9)
    {
        tmp_nb = (nb%numeral_sys);    
        tmp_nb -= 10;
        result = hex[tmp_nb]; 
        nb /= numeral_sys;   
        return itoBase(nb,base)+result;
    }
    result = itoa(nb%numeral_sys);
    nb /= numeral_sys;
    return itoBase(nb,base)+result;    
}
std::string itoBase(unsigned int nb, std::string baseSrc,std::string baseDst)
{
    int decimal = trans_in_dec(nb,baseSrc);
    std::string result;
    char hex[6] = {'A', 'B' ,'C', 'D', 'E', 'F'};
    int tmp_nb;
    int numeral_sys = baseDst.length();
    int flag = numeral_sys-1;
    if(decimal <= flag)
    {
        if(decimal > 9)
        {
            tmp_nb = (decimal%numeral_sys);
            tmp_nb -= 10;
            result = hex[tmp_nb]; 
            return result;
        }
        return result = itoa(decimal);
    }
    else if(flag > 10 && decimal%numeral_sys > 9)
    {
        tmp_nb = (decimal%numeral_sys);    
        tmp_nb -= 10;
        result = hex[tmp_nb]; 
        decimal /= numeral_sys;   
        return itoBase(decimal,baseDst)+result;
    }
    result = itoa(decimal%numeral_sys);
    decimal /= numeral_sys;
    return itoBase(decimal,baseDst)+result;    
}
bool check(unsigned int n, std::string base) // проверка на правильность введеного числа
{
    int numeral_sys = base.length();
    int testing = n;
    for (size_t i = 0; i < 1000000; i++)
    {
        testing = n % 10;
        if(testing >= numeral_sys)
        {
            return false;
        }
        else if(n / 10 == 0)
        {
            break;
        }
    }
    return true; 
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Russian"); 
    int choice = 1337;
    int nb;
    bool status;
    std::string base;
    std::string baseDst;
    std::string res;
    try
    {
        while(choice != 0)
        {
            std::cout << std::endl;
            std::cout<< "0-выход; 1-Из десятичной в систему на выбор; 2-Из одной в другую:";
            std::cin >> choice;
            if(choice == 1)
            {
                std::cout<< "(число), (c.c)\t";
                std::cin >> nb >> base;
                res = itoBase(nb,base);
                std::cout << res << std::endl;   
            }
            else if(choice == 2)
            {
                std::cout<< "(число), (с.с), (Другая с.с.)\t";
                std::cin >> nb >> base >> baseDst;
                status = check(nb,base);
                if(status)
                {
                    res = itoBase(nb,base,baseDst);
                    std::cout << res << std::endl; 
                }
                else
                {
                    std::cout << "Неверно указано число, попробуйте еще раз" << std::endl; 
                    continue;  
                }     
            }
            else
            {
                std::cout << "Error: Некоректный ввод попробуйте указать еще раз" << std::endl;
            }
        } 
    }
    catch(const std::exception& e)
    {
          std::cerr << e.what() << '\n';
          std::cout << "Error: Некоректный ввод перезапустите программу";
    } 
   return 0;
}
