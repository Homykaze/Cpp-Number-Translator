#include <iostream>
#include <string>

using namespace std;

string get_text(int input);
string get_data_from_chunk(int chunk);
string get_digits(int digit);
string get_tens(int digits);

int main()
{
    int input;
    string output = "";
    cin >> input;
    if (input == 0)
    {
        cout << "Zero ";
        return 0;
    }
    else if (input < 0)
    {
        output += "Minus ";
        input = -input;
    }  
    output += get_text(input);
    cout << output;
}

string get_text(int input)
{
    string result = "";
    int copy = input;
    int chunk1, chunk2, chunk3, chunk4; //Chunks of threes

    chunk4 = input % 1000;
    input /= 1000;
    chunk3 = input % 1000;
    input /= 1000;
    chunk2 = input % 1000;
    input /= 1000;
    chunk1 = input % 1000;
    input /= 1000;
    
    result += get_data_from_chunk(chunk1);
    if (chunk1 > 0)
        result += "billion ";
    result += get_data_from_chunk(chunk2);
    if (chunk2 > 0)
        result += "million ";
    result += get_data_from_chunk(chunk3);
    if (chunk3 > 0)
        result += "thousand ";
    result += get_data_from_chunk(chunk4);
    //cout << chunk1 << " " << chunk2 << " " << chunk3 << " " << chunk4 << "\n";

    return result;
}

string get_data_from_chunk(int chunk)
{
    string result = "";
    if (chunk > 100)
    {
        result += get_digits(chunk / 100) + "hundred ";
        chunk = chunk % 100;
    }
    if (chunk > 10)
        result += get_tens(chunk);
    if (chunk < 20 && chunk > 10)
        return result;
    else
        result += get_digits(chunk % 10);
    return result;
}

string get_digits(int digit)
{
    if (digit == 1)
        return "one ";
    else if (digit == 2)
        return "two ";
    else if (digit == 3)
        return "three ";
    else if (digit == 4)
        return "four ";
    else if (digit == 5)
        return "five ";
    else if (digit == 6)
        return "six ";
    else if (digit == 7)
        return "seven ";
    else if (digit == 8)
        return "eight ";
    else if (digit == 9)
        return "nine ";
    else
        return "";
}

string get_tens(int digits)
{
    if (digits == 11)
        return "eleven ";
    else if (digits == 12)
        return "twelve ";
    else if (digits == 13)
        return "thirteen ";
    else if (digits == 14)
        return "fourteen ";
    else if (digits == 15)
        return "fiveteen ";
    else if (digits == 16)
        return "sixteen ";
    else if (digits == 17)
        return "seventeen ";
    else if (digits == 18)
        return "eighteen ";
    else if (digits == 19)
        return "nineteen ";
    else if (digits > 19 && digits < 30)
        return "twenty ";
    else if (digits > 29 && digits < 40)
        return "thirty ";
    else if (digits > 39 && digits < 50)
        return "fourty ";
    else if (digits > 49 && digits < 60)
        return "fifty ";
    else if (digits > 59 && digits < 70)
        return "sixty ";
    else if (digits > 69 && digits < 80)
        return "seventy ";
    else if (digits > 79 && digits < 90)
        return "eighty ";
    else if (digits > 89 && digits < 100)
        return "ninety ";
}