#include<iostream>
#include<iomanip>

using namespace std;
class objeto {
public:
	objeto(); 
};

int main() {
	{objeto vida(); }


	return 0;
}
objeto::objeto() {
	cout << "ya naci" << endl;
}
