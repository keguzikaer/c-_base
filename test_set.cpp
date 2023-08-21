#include <iostream>
#include <set>

using namespace std;

struct hh
{
    int b;
    int c;

    bool operator <(const hh &a1) const 
    {
        if (b != a1.b)
            return b < a1.b;
        return c < a1.c;
    }
};


int main()
{
    set<hh> a_set;
    hh a = {1, 1};
    hh b = {1, 2};
    hh c = {1, 2};
    hh d = {2, 2};
    a_set.insert(a);
    a_set.insert(b);
    a_set.insert(c);
    a_set.insert(d);

    cout << "size:" << a_set.size() << endl;
    return 0;
}