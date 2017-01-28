#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "optional.h"
using namespace std;

struct my_obj {
	int w;
	
	my_obj() {
		cout << "in constructor()\n";
	}
	my_obj(int e) {
		cout << "in constructor(int)\n";
	}
	my_obj(int e, int r) {
		cout << "in constructor(int, int)\n";
	}
	my_obj(const my_obj& obj) {
		cout << "in constructor(const my_obj&)\n";
	}
	my_obj(my_obj&& obj) {
		cout << "in constructor(my_obj&&)\n";
	}
	
	my_obj& operator=(const my_obj& obj) {
		cout << "in operator=(const my_obj&)\n";
		return *this;
	}
	my_obj& operator=(const my_obj&& obj) {
		cout << "in operator=(const my_obj&&)\n";
		return *this;
	}
	
	~my_obj() {
		cout << "in destructor\n";
	}
	
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int q, w, e, r, t;
	
	my_obj m_o;
	
	{
		optional<my_obj> c;
		
		c.emplace(56);
		
		optional<my_obj> c2;
		cout << "-- 1\n";
		optional<my_obj> c3(m_o);
		cout << "-- 2\n";
		
		c2 = c;
		cout << "-- 3\n";
		
		c2 = c3;
		cout << "-- 4\n";
		
		my_obj c4 = c2.value_or(1);
		
		cout << "-- 5\n";
		
		c2.reset();
		
		cout << "\n";
		
		c4 = c2.value_or(1);
		
		cout << "-- 6\n";
	}
	cout << "############################\n";
	
	{
		optional<my_obj> c1, c2(in_place, 2, 3);
		cout << "---\n";
		
		cout << c1.is_valid() << " " << c2.is_valid() << "\n";
		
		swap(c1, c2);
		
		cout << c1.is_valid() << " " << c2.is_valid() << "\n";
		
		swap(c1, c2);
		
		cout << c1.is_valid() << " " << c2.is_valid() << "\n";
		
		c1 = c2;
		cout << "---\n";
		swap(c1, c2);
		cout << c1.is_valid() << " " << c2.is_valid() << "\n";
		cout << "----\n";
		swap(c1, c1);
		cout << "----\n";
	}
	cout << "#########################\n";
	
	
	
	
	
	return 0;
}
