/*One of the shops in is offering discount coupons based on a puzzling problem. There are n tags, where each tag has a value denoted by val[i]. A customer needs to choose the tags in such a way that the sum of values is even. The goal is to find the maximum possible even sum of tags that can be chosen.

Note:
It is guaranteed that there is at least one tag with an even value.
The tags can have positive or negative values.
It can be possible to choose no tags at all.
Function description:
Complete the function getMaximumEvenSum in the editor below.

getMaximumEvenSum has the following parameters:

int val[n]: the values of tags in the shop
Returns:
long int: the maximum even sum of tag values */

//..........................................code...........................

#include <iostream>
#include <vector>
#include <limits>
#include <climits>

using namespace std;

// Function prototype
bool checkEven(int x)
{
    if(x%2==0)
        return true;
    else return false ; 
}
long long getMaximumEvenSum(const vector<int>& val)
{   
    int sum = 0;
    int smallest = INT_MAX;
    int min_odd = INT_MAX ; 
    int even_sum =0 ;
    for(auto i :val )
    {  
        if(!checkEven(i)){
            min_odd = min(i,min_odd);
            
        }
        if(checkEven(i)&& i >0 )
            even_sum +=i;
        
        smallest = min(i,smallest);
        sum+= i ;
    }
    cout<<even_sum<<endl;
    if(checkEven(sum))
    {
        if(sum<=0)
        {
            int m = max(even_sum,sum);
            
           return max(0 , m);   
        }
        return sum ; 
    }
     else {
    while(true)
        {
        sum = sum - min_odd ;
        
        
        if(checkEven(sum))
        {
            break ;
        }
        
    }
    
        if(sum<0)
        {
            int m = max(even_sum,sum);
            
           return max(0 , m);   
        }
     return sum ;} 
}

int main() {
    // Example test cases
    vector<vector<int>> testCases = {
        {1, 2, 3, 4},
        {-1, -2, -3, -4},
        {1, 2, 3, 4, 5},
        {3, 5, 7, 9},
        {6},
        {7},
        {-5, 3, -2, 8, 10},
        {-1, -3, -5},
        {2, -3, 4, -1},
        {1000000, 999999, -1000000, -999999}
    };

    // Run test cases
    for (const auto& testCase : testCases) {
        long long result = getMaximumEvenSum(testCase);
        cout << "Input: {";
        for (const int& value : testCase) {
            cout << value << " ";
        }
        cout << "} => Maximum Even Sum: " << result << endl;
    }

    return 0;
}






