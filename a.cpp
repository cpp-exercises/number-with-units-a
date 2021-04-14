#include <iostream>
using namespace std;

class t
{
public:
    int a;
    std::string b;
    friend std::istream &operator>>(std::istream &in, t &num);
};
std::istream &operator>>(std::istream &in, t &num)
{
    double tmpNum;
    try
    {
        in >> tmpNum;
    }
    catch (exception)
    {
        cout << "fail";
    }


    string tmpStr;
    in >> tmpStr;
    cout << tmpStr << " -  " << tmpNum << endl;
    return in;
}
int main()
{
    //fun() = 30;
    t x;
    cin >> x;
    return 0;
}