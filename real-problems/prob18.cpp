#include <iostream>
using namespace std;

int getBit(int n, int pos){
    return ((n & (1<<pos))!=0);
}
int setBit(int n, int pos){
    return (n | (1<<pos));
}

// BIT manipulation problems

int findUnique(int a[], int n){
    int xorsum = 0;
    for(int i = 0; i<n; i++){
        xorsum = xorsum^a[i];
    }
    return xorsum;
}

void findUniqueTwo(int a[], int n){
    int xorsum = 0;
    for(int i = 0; i<n; i++){
        xorsum = xorsum^a[i];
    }
    
    int setBit = 0;
    int pos = 0;
    while(setBit==0){
        setBit = xorsum & (1<<pos);
        pos++;
    }

    int newxor = 0;
    for(int i =0; i<n; i++){
        if(getBit(a[i], pos-1)){
            newxor = newxor^a[i];
        }
    }

    cout<<newxor<<", "<<(xorsum^newxor)<<endl;

}

int findUniqueInTriplet(int a[], int n){
    int result = 0;
    for (int i = 0; i<64; i++){
        int sum = 0;
        for (int j = 0 ; j<n ; j++){
            if(getBit(a[j], i)){
                sum++;
            }
        }
        if(sum%3!=0){
            result = setBit(result, i);
        }
    }
    return result;
}

int main()
{
    int arr1[] = {1,2,3,3,4,2,1};
    cout<< findUnique(arr1, 7)<<endl;

    int arr2[] = {1,2,3,3,5,2,1,7};
    findUniqueTwo(arr2, 8);

    int arr3[] = {1,2,3,3,4,2,1,1,2,3};
    cout<< findUniqueInTriplet(arr3, 10)<<endl;

    return 0;
}