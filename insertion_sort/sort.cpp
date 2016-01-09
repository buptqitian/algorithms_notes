#include <iostream>
using namespace std;

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}


void in_sort(int* nums, int n)
{
    int i, j;
    for(int i = 1; i < n; i++)
    {
        for(j = i -1; j >=0 && nums[j + 1] < nums[j]; j--)
            swap(nums[j+1], nums[j]);
    }
}

void print_array(int* nums, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}


int main()
{
    int a[] = {1, 4, 3, 6, 9, 2};
    int length = sizeof(a)/sizeof(int);
    in_sort(a, length);
    print_array(a, length);
    cout << endl;

}
