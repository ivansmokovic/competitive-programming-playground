#include <vector>
#include <string>
#include <iostream>

const std::string original = "test  test lala  ";

void urlify(std::vector<char> &a, const int len){
    std::size_t num_spaces = 0;

    for(auto i = 0; i < len; ++i){
        if(a[i] == ' ') ++num_spaces;
    }

    for(int i = len - 1; i >= 0; --i){
        const auto offset = num_spaces * 2;
        if(a[i] == ' '){
            a[i + offset - 2] = '%';
            a[i + offset - 1] = '2';
            a[i + offset] = '0';
            --num_spaces;
        } else {
            a[i + offset] = a[i];
        }
    }

}

int main(){
    const auto str_len = original.length();
    std::vector<char> a(str_len * 3);
    std::copy(original.begin(), original.end(), a.begin());

    for(const auto &c : a){
        std::cout << c;
    }

    std::cout << std::endl;

    urlify(a, str_len);

    for(const auto &c : a){
        std::cout << c;
    }
    std::cout << std::endl;

}
