#include<iostream>
using namespace std;
template<typename type>
class list {
private:
	type* arr;
	int maxsize;
	int currentsize;
public:
	list(int s, int cs) {
		maxsize = size;
		currentsize = cs;
		arr = new type[maxsize];
	}
	list(const list& other) {
		maxsize = other.maxsize;
		currentsize = other.currentsize;
		arr = new type[maxsize];
		for (int i = 0; i < maxsize; i++) {
			arr[i] = other, arr[i];
		}
	}

	virtual void addelementatfirstindex(type a) = 0;
	virtual void addelementatlastindex(type b) = 0;
	virtual type removeelementfromend() = 0;
	virtual type removeelementfromstart() = 0;
	virtual ~list() {
		delete[] arr;
	}
};

