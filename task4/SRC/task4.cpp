#include<iostream>
#include<string>
#include<cstdlib>
int main(int argc, char const *argv[])
{
    std::string first_str;
    std::string second_str;
    std::string answer = "OK";
    std::cin>>first_str>>second_str;
    if((first_str.length() == second_str.length()) && answer == "OK")
    {
        for (size_t i = 0; i < first_str.length(); i++)
        {
            if(second_str[i] != first_str[i] && second_str[i] != '*')
            {
                    answer = "KO";
                    break;
            }
            else
            {
                answer = "OK";
            }
        }
        std::cout<<answer<<std::endl;
    }
    else
    {
        for (size_t i = 0; i < second_str.length(); i++)
        {
            for (size_t k = 0; k < first_str.length(); k++)
            {
                if(second_str[i] != first_str[k] && second_str[i] != '*')
                {
                    answer = "KO";
                }
                else
                {
                    answer = "OK";
                }
            }  
        }
        std::cout<<answer<<std::endl;
    }
    system("pause");
    return 0;
}
