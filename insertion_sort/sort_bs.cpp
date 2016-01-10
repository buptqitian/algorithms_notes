#include <iostream>
using namespace std;

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int _binary_search(int *nums, int left, int right, int value)
{
    int mid = (right + left)/2;
    if(value == nums[mid])
        return mid;
    if(value < nums[mid])
    {
        if(left <=(mid - 1))
            return _binary_search(nums, left, mid - 1, value);
        else
            return left;
    }

    if(value > nums[mid])
    {
        if((mid + 1) <= right)
            return _binary_search(nums, mid + 1, right, value);
        else
            return right + 1;
    }

}


int binary_search(int *nums, int length, int value)
{
    return _binary_search(nums, 0, length - 1, value);
}

int sort(int *nums, int n)
{
    int i ,j;
    for(i = 1; i < n; i++)
    {
        int pos = binary_search(nums, i, nums[i]);
        for(int j = pos; j < i ; j++)
            swap(nums[j + 1], nums[j]);
    }
}

void print_array(int *nums, int length)
{
    for(int i = 0; i < length; i++)
    {
        cout << nums[i] << " ";
    }
}


int main()
{
    //int a[] = {1, 2, 5, 7, 9};
    //int length = sizeof(a)/sizeof(int);
    //int result = binary_search(a, length, 10);
    //cout << result << endl;
    int a[] = {2, 1, 4, 9, 7};
    int length = sizeof(a)/sizeof(int);
    sort(a, length);
    print_array(a, length);
    cout << endl;

}
