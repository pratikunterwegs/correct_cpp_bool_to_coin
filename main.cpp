/// program that converts input to coin
#include <iostream>
#include <string>
#include <cassert>

/// function to get text for testing main
std::string get_text(const int argc) noexcept
{
    return argc == 1? "no args" : "some args";
}

/// function to test main
int do_main(const int argc) noexcept
{
    // print output text based on argc
    std::cout << get_text(argc) << '\n';
    return 0;
}

/// main function
int main(int argc, char* argv[]) 
{
    // check that some args and no args cases are different
    assert(get_text(1) != get_text(2));

    if (argc != 2)
    {
        std::cerr << "too few or too many args";
        exit(EXIT_FAILURE);
    }
    if (std::string(argv[1]) == "true")
    {
        std::cout << "heads\n";
    } else if (std::string(argv[1]) == "false")
    {
        std::cout << "tails\n";
    } else {
        exit(EXIT_FAILURE);
    }
    return do_main(argc);
}
