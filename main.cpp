/// program that converts input to coin
#include <iostream>
#include <string>
#include <cassert>
#include <vector>

/// function to test main
int do_main(std::vector<std::string> cliArgs) noexcept
{
    // check if vector size is not equal to 2
    if (cliArgs.size() < 2)
    {
        std::cerr << "too few args\n";
        return 1;
    }
    else if (cliArgs.size() > 2) {
        std::cerr << "too many args\n";
        return 1;
    }

    // check if vector is true or false and convert
    if (cliArgs[1] == "true")
    {
        std::cout << "heads\n";

    }
    else if (cliArgs[1] == "false") {
        std::cout << "tails\n";
    }
    // handle nonsense args
    else {
        std::cerr << "nonsense args\n";
        return 1;
    }

    return 0;

}

/// main function
int main(int argc, char* argv[]) 
{
    // convert argv to string
    std::vector<std::string> cliArgs(argv, argv + argc);

    // check no args case
    assert(do_main({"bool_to_coin"}) == 1);
    // check many args case
    assert(do_main({"bool_to_coin", "some", "some"}) == 1);
    // check true and false
    assert(do_main({"bool_to_coin", "true"}) == 0);
    assert(do_main({"bool_to_coin", "false"}) == 0);
    // check nonsense
    assert(do_main({"bool_to_coin", "nonsense"}) == 1);

    return do_main(cliArgs);
}
