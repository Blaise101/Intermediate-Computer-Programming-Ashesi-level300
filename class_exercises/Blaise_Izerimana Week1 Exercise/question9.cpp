#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double radius, height;
    
    cout << "Enter the radius of the cylindrical container: ";
    cin >> radius;
    
    cout << "Enter the height of the cylindrical container: ";
    cin >> height;
    
    // Volume of the cylinder
    double cylinderVolume = M_PI * radius * radius * height;
    // Volume of a cube = side^3
    // Therefore, side = cube root of volume
    double side = cbrt(cylinderVolume);
    
    cout << fixed << setprecision(2);
    cout << "The side of the cube is: " << side << endl;
    
    return 0;
}