/*

problem statement: an arithmatic array is an array that contains at least two int and the difference btw consecutive int are equal. EG: [9,10], [3,3,3] and [9,7,5,3] are arithmatic arrays, while [1,3,3,7] is not.
saraswati has an array of N non-negative int. the i-th int of the array is A-i. She wants to choose a continous arithmatic subarray from her array that has the maximum length. please help her to determine the length of the longest continous arithmatic sub array.

input:
the first line of the input gives the number of test cases T. T test cases follow. Each test case begins with a line containing the integer N. the second line contain N in. the i-th in A.

output:
for each test case , output one line containing Case #x:y, where x is the test case number starting fom 1 and y is the length of the longest continous arithmatic subarray.

constraints:
time limit: 20 sec per test case.
memory limit: 1gb.
1<=T<=100
0<=A-i<=100
test set 1
2<=N<=2000
test set 2
2<=N<=2*10^5 at most 10 test cases
for the remaining cases, 2<=N<=2000

1sec = 10^8 ops
20sec = 2*10^9 ops
N = 2000 -> O(n^2) = 4*10^6 -> yes
N = 2*10^5 -> O(n^2) = 4*10^10 -> no
N > 10^8 (memory exceed)

*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for (int i = 0; i<n; i++){
            cin>>a[i];
        }

        int ans = 2;
        int pd = a[1]-a[0];
        int j = 2;
        int curr = 2;
        while(j<n){
            if(a[j]-a[j-1] == pd){
                curr++;
            }
            else{
                pd = a[j]-a[j-1];
                curr = 2;
            }
            ans = max(curr, ans);
            j++;
        }
        cout<<"Case "<<t+1<<": "<<ans<<endl;
    }

    return 0;
}