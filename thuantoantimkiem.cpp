#include <iostream>
#include<string> 

//tim kiem tuyen tinh
int LinearSearch(int A[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (A[i] == x)
            return i;
    return -1; // duyệt hết mảng, không tìm thấy x
}

//tim kiem nhi phan
int BinarySearch(int A[], int n, int x){
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (A[mid] == x)
            return mid; // tìm thấy x, trả về mid là vị trí của x trong mảng A
        if (A[mid] > x)
            right = mid - 1; // Giới hạn khoảng tìm kiếm lại là nửa khoảng trước
        else if (A[mid] < x)
            left = mid + 1; // Giới hạn khoảng tìm kiếm lại là nửa khoảng sau
    }
    return -1; // không tìm thấy x
}

//tim kiem nội suy
int InterpolationSearch(int A[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right && x >= A[left] && x <= A[right])
    {
        mid = left + (right - left) * (x - A[left]) / (A[right] - A[left]);
        if (A[mid] == x)
            return mid;
        if (A[mid] > x)
            right = mid - 1;
        else if (A[mid] < x)
            left = mid + 1;
    }
    return -1; // Không tìm thấy x
}
