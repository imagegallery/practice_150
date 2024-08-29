#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>

using namespace std;

// 2D max pooling is a widely adopted operation to downsample a given input matrix. To calculate the downsampled output matrix, the max pooling operation involves sliding a two-dimensional NxN filter, also known as the “pooling window”, over the input and outputting the max element inside the window. The pooling window will slide by a constant step, known as the “stride”, vertically and horizontally over the input until every element of the input is filtered. If there are not enough elements inside the filter, there will be no output element. "Padding" refers to zero padding surrounding the input tensor pre pooling.

// For example:
// Input matrix (2x3):
// 1 2 3
// 5 6 7
// Window size: 2
// Stride: 2
// Padding: 0

// Pooling window
// —-----                —-----  
// |1 2 | 3         1 2 | 3   |
// |5 6 | 7   -->   5 6 | 7   |
// —----                —------ 
//    |                   |
//   6                  invalid window         
//2x3/2x2 => 1x2 (stride 1)  ceil((n+2p-f xn+2p-f) /stride)
//2x3/2x2 => 1x1 (stride 2)  
// Output matrix (1x1):
// 6

// Please implement a 2d max pooling operation, with arbitrary input matrix, window size and stride.
// Constraints:
// 1. windowSize is guaranteed to be NO larger than inputTensor's size
// 2. inputTensor won't be empty
void tensorPrintHelper(vector<vector<int>> const& inputTensor)
{
    int m = inputTensor.size();
    int n = inputTensor[0].size();
    cout << "\n\n\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << inputTensor[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n\n";
}
vector<vector<int>> maxPooling2D(vector<vector<int>> const& inputTensor, size_t const windowSize, size_t const stride, size_t const padding = 0)
{
    int r = inputTensor.size();
    int c = inputTensor[0].size();
    vector<vector<int> > padded_input(r+(2*padding) , vector<int>(c + 2*padding, 0));
    
    for(int i = padding; i < r + padding ; i++){
        for(int j = padding; j < c + padding; j++){
            padded_input[i][j] = inputTensor[i-padding][j-padding];
        }
    }
    r = r + (2*padding);
    c = c + (2*padding);
    //int out_r = ceil((float)(r-1)/stride);
    //int out_c = ceil((float)(r-1)/stride);
    int out_r = floor((r -windowSize)/stride + 1);
    int out_c = floor((c -windowSize)/stride + 1);
    vector<vector<int>> output (out_r, vector<int>(out_c, 0));
    int a = 0, b = 0;
    for(int i = 0; i < r; i += stride){
        for(int j = 0; j < c; j+= stride){
            int maxVal = INT_MIN; 
            bool flag = false;
            for(int  p = i; p < i + windowSize; p ++){
                for(int k = j; k < j + windowSize; k++){
                    if(p >= r || k >= c){
                        flag = true;
                        break;
                    }
                    maxVal = max(maxVal, padded_input[p][k]);
                }
            }
            
            if(!flag){
                output[a%out_r][b++%out_c] = maxVal;
            }
        }
        a++;
    }
    
    return output;
    
}



int main() 
{
    vector<vector<int>> testCase = {
        {1, 2, 3},
        {7, 8, 9},
        {7, 1024, -99},
        {0, 1, 0},
    };
    
    // vector<vector<int>> testCase = {
    //     {1, 2, 3},
    //     {5, 6, 7},
    // };
    
    auto output = maxPooling2D(testCase, /*windowSize */ 2, /*stride*/ 1);
    tensorPrintHelper(output);
    
    auto output2 = maxPooling2D(testCase, /*windowSize */ 3, /*stride*/ 2);
    tensorPrintHelper(output2);
    
    auto output3 = maxPooling2D(testCase, /*windowSize */ 1, /*stride*/ 3);
    tensorPrintHelper(output3);
    
    auto output4 = maxPooling2D(testCase, /*windowSize */ 1, /*stride*/ 1);
    tensorPrintHelper(output4);
    
    return 0;
}

