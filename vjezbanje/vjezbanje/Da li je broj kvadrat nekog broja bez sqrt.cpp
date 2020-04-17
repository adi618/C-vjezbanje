//#include <iostream>
//using namespace std;
//
//int Sqrt(int n)
//{
//	int mid, left = 0, right = n;
//
//	while (left <= right)
//	{
//		mid = left + (right - left) / 2;
//
//		if (mid*mid == n)
//			return mid;
//
//		if (mid * mid > n)
//			right = mid - 1;
//		else
//			left = mid + 1;
//	}
//	return -1;
//}
//
//int main()
//{
//	int n;
//	cout << "\n\n\tUnesite broj: ";
//	cin >> n;
//	
//	int sqrt = Sqrt(n);
//
//	if (sqrt == -1)
//		cout << "\n\n\tUneseni broj nije kvadrat nekog broja\n\n\n";
//	else
//		cout << "\n\n\tUneseni broj je kvadrat broja: " << sqrt << "\n\n\n";
//
//}