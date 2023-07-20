#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return -1;
    }

    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j])){
                std::cerr << "Error" << std::endl;
                return 0;
            }
        }
    }

    char* endptr;
    for (int i = 1; i < argc; ++i) {
        long value = std::strtol(argv[i], &endptr, 10);
        if (*endptr != '\0' || value <= 0 || value > std::numeric_limits<int>::max()) {
            std::cerr << "Error\n";
            return 1;
        }
    }
    merge mrg(argc, argv);

    mrg.sort();
}