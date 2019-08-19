/// program that converts input to coin
#include <iostream>
#include <string>
#include <cassert>
#include <vector>

/// function to test main
int do_main(std::vector<std::string> cliArgs) noexcept
{
    // do whatever
    if (cliArgs.size() != 2)
    {
        std::cerr << "too few or too many args";
        exit(EXIT_FAILURE);
    }
    if (std::string(cliArgs[1]) == "true")
    {
        std::cout << "heads\n";
    } else if (std::string(cliArgs[1]) == "false")
    {
        std::cout << "tails\n";
    } else {
        std::cerr << "nonsense args";
        exit(EXIT_FAILURE);
    }

    return 0;
}

/// main function
int main(int argc, char* argv[]) 
{
    // convert argv to string
    std::vector<std::string> cliArgs(argv, argv + argc);

    // check that some args and no args cases are different
    assert(do_main({cliArgs[0], "1"}) != do_main({cliArgs[0], "2"}));
    assert(do_main({cliArgs[0],"true", "true"}) == 1);
    assert(do_main({cliArgs[0],"blabla"}) == 1);
    assert(do_main({cliArgs[0],"true"}) == 0);
    assert(do_main({cliArgs[0],"false"}) == 0);

    return do_main(cliArgs);
}
