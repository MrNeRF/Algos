#include "Tri.hpp"
#include <iostream>

using namespace std;

void printTri(const Tri& tri)
{
}

int main(void)
{
    Tri tri;
    tri.Insert("Hello");
    tri.Insert("Test");
    tri.Insert("hel");

    cout << tri.Search("Hallo") << endl;
    cout << tri.Search("Hello") << endl;
    cout << tri.Search("gel") << endl;
    cout << tri.Search("hel") << endl;
    cout << tri.Search("Hel") << endl;
    cout << tri.Search("Test") << endl;

    std::vector<string> allwords;
    tri.Traverse(allwords);

    for (const std::string& word : allwords)
    {
        std::cout << word << std::endl;
    }
    return 0;
}
