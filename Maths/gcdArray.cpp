#include<bits/stdc++.h>
using namespace std;
/* get the Array Elements from the given GCD Array */

void printArray(int arr[], int size){
    cout<<"Output Array: ";
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void printVector(vector<int> arr){
    cout<<"Output Vector: ";
    for(auto x: arr){
        cout<<x<< " ";
    }
    cout<<endl;
}

int gcdf(int a, int b){
    if(b==0) return a;
    return gcdf(b,a%b);
}

void printAllGCD(int arr[], int size){
    int N = size*size;
    int gcd[N];
    int pos=0;
    for(int i=0;i<size;i++){
        for(int j=0; j<size; j++){
            gcd[pos++] = gcdf(arr[i], arr[j]);
        }
    }
    printArray(gcd, N);
}

void printArrayFromGCD(int gcd[], int N){
    /* get the max element from the gcd[] = a1-> gcd(a1,a1). Now delete a1
    get the new max element from gcd[] = a2 -> gcd(a2,a2). Now delete a2 and also delete gcd(a1,a2), gcd(a2,a1)
    get the new max element from gcd[] = a3 -> gcd(a2,a2). Now delete a3 and also delete gcd(a1,a3), gcd(a3,a1), gcd(a2,a3), gcd(a3,a2)
    .. keep doing same thing... think in term of matrix (a1,a1) - > (a3, a3)
    */
    vector<int> arr(gcd, gcd + N);
    sort(arr.begin(), arr.end());

    int size = sqrt(N); //size of ans Array
    vector<int> ans;
    ans.push_back(arr[N-1]);
    for (int i=0; i<N; i++){
        
        int max_val = arr.back();
        // cout << "Max element: " << max_val << std::endl;
        arr.pop_back();

        for(int j=0; j<size; j++){
            int g = gcdf(ans[j], max_val);
            // Find the iterator to the first occurrence of val
            auto it = find(arr.begin(), arr.end(), g);
            // If found, remove the element
            if (it != arr.end()) {
                arr.erase(it);
            }
        }
        if(i==0) continue;
        ans.push_back(max_val);

    }
    vector<int> ans1(ans.begin(), ans.begin()+size);
    cout<<endl<<"ans: ";
    printVector(ans1);

}

int main(){
    int arr[] = {3,18,10,24};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Given GCD pairs: "<<endl;
    printAllGCD(arr,size);

    int gcd[] = {3, 3, 1, 3, 3, 18, 2, 6, 1, 2, 10, 2, 3, 6, 2, 24};
    int N = sizeof(gcd)/sizeof(gcd[0]);
    printArrayFromGCD(gcd, N);
    return 0;
}