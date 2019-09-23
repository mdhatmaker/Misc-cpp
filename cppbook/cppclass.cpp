#include <iostream>

using namespace std;

class Cube
{
public:
    int side;
    int getVolume() {
        return side*side*side;
    }
};

int main()
{
    Cube c;
    c.side = 4;
    cout << "volume: " << c.getVolume() << "\n";
}