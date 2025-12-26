#define integer int

#include <iostream>
#include <map>
#include <sstream>

using namespace std;

static map<int, int> fiboMap;

int goldRabbits(int n) {
    if (n == -1)
    {
        cout << "fibo(-1):\n";
        cout << "Fibo Map contents:\n";
        for (auto& p : fiboMap) {
            cout << p.first << ":" << p.second << "\n";
        }
        cout << "end of Fibo map\n";
        return -1;
    }

    if (n == 0 || n == 1)
    {
        fiboMap[n] = 1;
        return 1;
    }

    if (fiboMap.count(n))
        return fiboMap[n];

    int value1 = goldRabbits(n - 1);
    int value2 = goldRabbits(n - 2);

    static string Overflow = "";

    if (value1 < 0 || value2 < 0 || value1 > numeric_limits<int>::max() - value2) {
        fiboMap[n] = value1 + value2;

        if (Overflow.empty())
        {
            Overflow = to_string(n);
        }

        throw Overflow;
    }

    int result = value1 + value2;
    fiboMap[n] = result;
    return result;
}

bool isInteger(const string& s) {
    if (s.empty() || ((s[0] != '-' && !isdigit(s[0])) && !isdigit(s[0])))
        return false;
    char* p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i)
    {
        string arg = argv[i];
        if (!isInteger(arg))
        {
            cout << arg << " is not an integer\n";
            continue;
        }

        int n;
        stringstream ss(arg);
        ss >> n;

        try{
            int result = goldRabbits(n);
            if (n != -1)
                cout << "fibo(" << n << "):\t" << result << "\n";
        } catch (string x) {
            int fibo = fiboMap[stoi(x)];
            cout << "fibo(" << n << "):\toverflow error at fib(" << x << "):" << fibo << "\n";
        }
    }

    return 0;
}
