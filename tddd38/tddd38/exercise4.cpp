/*
* Basic language constructs, exercise 4.
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//using unsigned_char = unsigned char;
//using const_unsigned_char = const unsigned_char;
//using ptr_to_int = int*;
//using ptr_to_ptr_to_char = char**; //pointer to pointer to char 
//using ptr_to_arr_of_char = char*; //pointer to array with element of type char
//using arr_of_10_ptr_to_int = ptr_to_int[10]; //array with 10 pointer to int
//using ptr_to_arr_of_10_ptr_to_int = arr_of_10_ptr_to_int*; // pointer to an array with 10 pointer to int
//using arr_20_arr_10_of_ptr_to_int = ptr_to_int[20][10]; //array 20 of array 10 with pointer to int
//
//
//int main()
//{
//	unsigned_char uc{};
//	const_unsigned_char cuc{ 'A' };
//	ptr_to_int pi{ new int(4711) };
//
//	char c{ 'X' };
//	char* pc{ &c };
//	ptr_to_ptr_to_char ppc{ &pc };
//
//	char a[]{ "foobar" };
//	ptr_to_arr_of_char pac{ a };
//
//	arr_of_10_ptr_to_int a10pi{ pi };              // the rest is zero initialized
//	ptr_to_arr_of_10_ptr_to_int pa10pi{ &a10pi };
//	arr_20_arr_10_of_ptr_to_int a20a10pi{ pi };    // the rest is zero initialized
//
//	cout << uc << '\n';
//	cout << cuc << '\n';
//	cout << *pi << '\n';
//	cout << **ppc << '\n';
//	cout << pac << '\n';
//	cout << *a10pi[0] << '\n';
//	cout << ***pa10pi << '\n';
//	cout << *a20a10pi[0][0] << '\n';
//
//
//	return 0;
//}