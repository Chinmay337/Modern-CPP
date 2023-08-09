#include <iostream>
#include <sstream>

int main() {
	using namespace std;

	cout << "Code it out" << endl;
	
	string s = "420 truly VIM TIme is it ez?";
	
	istringstream ss(s);

	size_t sizeofStream = sizeof(ss);
	cout << "Size of Stream ss " << sizeofStream << "\n" <<  endl;
	
	for (string w ; ss >> w;) cout << w << endl;

	sizeofStream = sizeof(ss);
	
	cout << "Size after printing stream " << sizeofStream << "\n" << endl;
		
	

	return 0;
}
