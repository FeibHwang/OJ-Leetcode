/*
Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
Example: 
n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

/*
Not very hard
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> rec;
        for(int i = 1; i <= n; ++i)
        {
            int d3 = i%3;
            int d5 = i%5;
            if(d3==0&&d5==0) rec.push_back("FizzBuzz");
            else if(d3==0) rec.push_back("Fizz");
            else if(d5==0) rec.push_back("Buzz");
            else rec.push_back(to_string(i));
        }
        return rec;
    }
};