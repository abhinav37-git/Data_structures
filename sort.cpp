//sort elements of array even elements first and odd elements last
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the size of array";
    cin>>n;
    int arr1[10],arr2[10];
    int i, arr[n], a;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0){
            arr1[i]=arr[i];
        }
        else{
            arr2[i]=arr1[i];
        }
    }

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}