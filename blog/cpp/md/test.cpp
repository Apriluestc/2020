#include <map>  
#include <string>  
#include <iostream>  

using namespace std;  

int main()  
{  
    map<int, string> mapStudent;
    mapStudent.insert(pair<int, string>(1, "student_one"));
    mapStudent.insert(pair<int, string>(2, "student_two"));
    mapStudent.insert(pair<int, string>(3, "student_three"));
    map<int, string>::iterator iter;
    iter = mapStudent.find(1);
    if(iter != mapStudent.end())
        cout << "Find, the value is " << iter->second << endl;
    else
        cout << "Do not Find" << endl;
    map<int, int> _hash;
    _hash.insert(pair<int, int>(1, 2));
    _hash.insert(pair<int, int>(2, 3));
    _hash.insert(pair<int, int>(8, 1));
    _hash.insert(pair<int, int>(5, 1));
    map<int, int>::iterator iterp;
    for (iterp = _hash.begin(); iterp != _hash.end(); iterp++) {
        cout << iterp->first << " ";
    }
    cout << endl;
    return 0;  
}
