#include<iostream>
#include<climits>
using namespace std;

void selection_sort(int arr[],int n){ /*using inplace algorithm*/
    int count=0,swap=0;
    for(int i=0;i<n-1;i++){
        int min= arr[i] ,min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                min_index=j;
            }
            count++;
        }
        int temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
        if(min_index!=i){
        swap++;}
    }
    cout<<"No. of comparisons in selection sort : "<<count<<endl;
    cout<<"No. of swaps in selection sort : "<<swap<<endl<<endl;
}

void bubble_sort(int arr1[],int n){ /*using inplace algorithm*/
    int count=0,swap=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr1[j]>arr1[j+1]){
                int temp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=temp;
                swap++;
            }
            count++;
        }
    }
    cout<<"No. of comparisons in bubble sort : "<<count<<endl;
    cout<<"No. of swaps in bubble sort : "<<swap<<endl<<endl;
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of elements you want in array: "<<endl;
    cin>>n;

    int arr[n],arr1[n];

    cout<<"Enter the elements of the array: "<< endl;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr1[i]=arr[i];
    }

    cout<<"Initial array: "<<endl;
    display(arr,n);
    selection_sort(arr,n);
    cout<<"Sorted array after using selection sort: "<<endl;
    display(arr,n);
    bubble_sort(arr1,n);
    cout<<"Sorted array after using bubble sort: "<<endl;
    display(arr1,n);
    
}

/*  BONUS QUESTION

    TIME COMPLEXITY:

    SELECTION SORT:
    Worst case and average case - The dominating factor in selection sort is traversing through the array and finding the minimum element.
    No. of comparisons- (n-1) + (n-2) + (n-3) + ...... +0 = (n*(n-1))/2    O(n^2)
    Corresponding no. of swaps= 1+1+1+1+..........+1 (n times)     O(n)
    Total time complexity will be O(n^2)

    Best case- 
    No. of comparisons- (n-1) + (n-2) + (n-3) + ...... +0 = (n*(n-1))/2    O(n^2)
    Corresponding no. of swaps= 0     O(1)
    Total time complexity will be O(n^2)
    .....................................................................................................................................
    BUBBLE SORT:
    Wosrt case and average case- 
    At pass 1 : Number of comparisons = (n-1)
        Number of swaps = (n-1)

    At pass 2 :  Number of comparisons = (n-2)
        Number of swaps = (n-2)

    At pass 3 : Number of comparisons = (n-3)
        Number of swaps = (n-3)
                        .
                        .
                        .
                        so on... till
    At pass n-1 : Number of comparisons = 1
        Number of swaps = 1

    Now , calculating total number of comparison required to sort the array
    = (n-1) + (n-2) +  (n-3) + . . . 2 + 1
    = (n-1)*(n-1+1)/2  { by using sum of N natural Number formula }
    = n (n-1)/2  

    Total number of swaps = Total number of comparison
    Total number of comparison (Worst case) = n(n-1)/2 
    Total number of swaps (Worst case) = n(n-1)/2

    So, the worst and average time complexity = O(n^2) (when an array is sorted in reverse order) 

    Best Case Time Complexity: O(n) (when an array is already sorted) */