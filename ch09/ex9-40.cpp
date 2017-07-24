#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("1048.txt");
    vector<string> svec;
    svec.reserve(1024);
    string word;
    while (in >> word)
        svec.push_back(word);
    svec.resize(svec.size() + svec.size()/2);
    cout << "size: " << svec.size() << " " << "capacity: " << svec.capacity() << endl;
    return 0;
}
