#include <iostream>
#include <random>
#include <fstream>

int main() {
    std::random_device seed;
    std::mt19937 randEngine(seed());
    std::uniform_int_distribution<int> entries(0, 60);

    std::fstream file;

    file.open("transaction_history.txt",std::ios::out);

    if(!file)
    {
        std::cout << "Could not create file" << std::endl;
        return 0;
    }

    std::cout << "File Created." << std::endl;

    for(int i = 0; i < entries(randEngine); i++) {
        std::uniform_int_distribution<int> date(0, 30);
        std::uniform_int_distribution<int> month(1, 12);
        std::uniform_int_distribution<int> year(2012, 2019);
        std::uniform_int_distribution<double> paid(0, 10000);
        std::uniform_int_distribution<int> shares(0, 300);
        std::uniform_int_distribution<int> buySell(0, 1);

        file << "ABCD " << date(randEngine) << " " << month(randEngine) << " " << year(randEngine) << " "
                  << ((buySell(randEngine)) ? "Buy " : "Sell ") << shares(randEngine) << " "
                  << paid(randEngine) << std::endl;
    }

    file.close();
    return 0;
}