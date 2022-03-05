#include <iostream>
#include <algorithm>
// на вход дана строка из цифр 1 - 9. вернуть все возможные комбинации букв, которые можно получить из данного набор цифр
// 1 - ""
// 2 - "ABC"
// 3 - "DEF"
// 4 - "GHI"
// 5 - "JKL"
// 6 - "MNO"
// 7 - "PQRS"
// 8 - "TUV"
// 9 - "WXYZ"
//

const int N = 26;
const int MAX_ITEM_SIZE = 4;


struct HashItem {
    std::string items[MAX_ITEM_SIZE];
    int currentSize = 0;

    void push(std::string &str) {
        items[currentSize] = str;
        ++currentSize;
    }

    bool find(std::string &str) {
        for (const std::string &elem : items) {
            if (elem == str) {
                return true;
            }
        }
        return false;
    }

};


struct MyHashTable {
    HashItem values[N];

    static int hash(std::string &input_str) {
        int result = int(input_str[0]) - int('A');
        std::cout << input_str[0] << ' ' << result << '\n';
        return result;
    }

    void push(std::string str) {
        values[hash(str)].push(str);
    }

    bool find(std::string str) {
        if (values[hash(str)].find(str)) {
            return true;
        }
        return false;
    }
};


std::string super_iter_func(std::string numbers, MyHashTable &T9, int start_ind = 0) {
    std::string numbers_2;
    std::string cur_string;
    if (numbers.empty()) {
        cur_string = " ";
        return cur_string;
    }
    for (size_t i = 1; i < numbers.size(); ++i) {
        numbers_2.push_back(numbers[i]);
    }
    int ind;
    std::string res;
    for (int i = 0; i < 4; ++i) {
        ind = static_cast<int>((char)numbers[0]) - (int)('0');

        cur_string += T9.values[ind].items[i];
        res = super_iter_func(numbers_2, T9);
        cur_string += res;
        if (res == " ") {
            break;
        }

    }

    return cur_string;
}


int main() {
    MyHashTable T9;

    std::string mass[10] = {" ", " ", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

    for (int i = 1; i < 10; ++i) {
        for (size_t j = 0; j < mass[i].size(); ++j) {
            T9.values[i].items[j] = mass[i][j];
        }
    }

    std::string numbers;
    std::getline(std::cin, numbers);
    std::cout << super_iter_func(numbers, T9);


    int array[2][3] = {{1, 2, 3}, {1, 2, 3}};
    for (auto & i : array) {
        for (int &el : i) {
            std::cout << el << '\n';
        }

    }

}
