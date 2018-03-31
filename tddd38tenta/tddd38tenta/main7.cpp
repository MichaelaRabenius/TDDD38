//#include <iostream>
//#include <List>
//using namespace std;
//
//namespace assignment
//{
//	template<typename Itr, typename Func>
//	Itr Find(Itr start, Itr end, Func fun)
//	{
//		for (auto it = start; it != end; ++it)
//		{
//			if (fun(*it))
//				return it;
//		}
//		return end; // wasn't found
//	}
//}
//
//
//int main()
//{
//	/*int arr[] = { 1, 2, 5, 2, 7 ,8 };
//	auto pos = assignment::Find(begin(arr), end(arr), 2);
//	if (pos != end(arr))
//		cout << *pos << " found";
//	else
//		cout << "not found";*/
//
//	// After modifications:
//	std::list<int> l{1,6,2,7,0,9};
//	auto val = assignment::Find(begin(l), end(l), [](int i) { return i % 2 == 0; });
//	if ( val != end(l) )
//	cout << "First even number: " << *val << endl;
//
//}