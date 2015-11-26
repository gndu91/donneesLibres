#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string s = "123";
    int x;
    istringstream(s) >> x;
    cout << x << endl;
}
