// using prims to find minimum spanning tree c++
#include <iostream>
using namespace std;

int mst(int arr[], int n)
{
    int min=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min){
            min=arr[i];
        }
    }
}
int main()
{
    int n;
    cout<<"enter the number of vertices"<<endl;
    cin>>n;

    int arr[n][n];
    cout<<"enter the adjacency matric"<<endl;

    for(int i=0;i<n;i++)

}