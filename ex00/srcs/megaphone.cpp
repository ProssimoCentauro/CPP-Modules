#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    size_t  i;
    size_t  j;

    i = 0;
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    while (av[++i])
    {
        j = 0;
        while (av[i][j])
        {
            std::cout << (char)toupper(av[i][j]);
            j++;
        }
    }
    std::cout << "\n";
    return (0);
}
