#include <iostream>
#include <string>
#include <map>
using namespace std;

//converts the values
int Rom_Num_Converter(string input, map<char, int> values) {
    int sum = 0;
    //parses through the string input
    for(int i = 0; i < input.size(); i++) {

        //checks that it can compare with next element
        //checks that current is larger
        if(i != input.size()-1 && values[input[i]] < values[input[i+1]]) {
            sum -= values[input[i]];
        }
        else
            sum += values[input[i]];
    }

    return sum;
}

string runProgram() {
    cout << "Roman Numeral Calculator\n";
    cout << "Input your own numeral or input \"test\" for a sample value\n";
    string input;
    cout << "Input: ";
    cin >> input;

    if(input == "test") {
        return "XCIV";
    }
    return input;

}

int main() {
    //sets input to
    string input = runProgram();

    //creates a key pair list of roman numeral values
    //placed here to reduce amount of times it's redundantly run
    map<char, int> values;
    values.insert({'I', 1});
    values.insert({'V', 5});
    values.insert({'X', 10});
    values.insert({'L', 50});
    values.insert({'C', 100});
    values.insert({'D', 500});
    values.insert({'M', 1000});

    //for how many inputs there are, convert the value
    cout << Rom_Num_Converter(input, values) << endl;

    return 0;
}
