#include <iostream>
#include <string>
#include <map>

using namespace std;

string arb_to_rim(int arb)
{
    string rim = "";

    map<int, string> nums;
    nums.insert(make_pair(1,    "I"));
    nums.insert(make_pair(5,    "V"));
    nums.insert(make_pair(10,   "X"));
    nums.insert(make_pair(50,   "L"));
    nums.insert(make_pair(100,  "C"));
    nums.insert(make_pair(500,  "D"));
    nums.insert(make_pair(1000, "M"));

    
}

int main()
{
    int a = 1234;

    cout << arb_to_rim(a) << endl;

    return 0;
}