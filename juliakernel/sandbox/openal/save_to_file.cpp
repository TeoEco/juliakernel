#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    double * s;
    int ns = 10;                    //information
    s = new double[ns];

    for (int i = 0 ; i < ns ; ++i)
       s[i] = 17*i + 23;           // i put my information here

    ofstream os("data.txt", ios::binary);
    os.write(reinterpret_cast<const char*> (s), sizeof(double) * ns);
    os.close();

    double * final;
    final = new double[ns];
   
    ifstream is("data.txt", ios::binary);
    is.read(reinterpret_cast<char *>(final), sizeof(double) * ns);
    is.close();
    for (int i=0; i < ns; ++i)
      cout<<s[i]<<" "<<final[i]<<"\n";
      return 0;
}
