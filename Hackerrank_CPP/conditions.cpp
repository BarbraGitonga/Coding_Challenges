#include <iostream>

using namespace std;

void compare(int n){
    const char *words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if (n <= 9){
        cout << words[n-1] << "\n";
    }
    else if( n > 9){
        cout << "Greater than 9 \n";
    }
}

int main(void){
    int n;
    cin >> n;
    compare(n);
    return 0;
}