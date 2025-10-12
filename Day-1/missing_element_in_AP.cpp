// Comments by ChatGPT
// This code finds the missing element in an arithmetic progression (AP) array 'arr'.
// 'fake_ceil' is a helper function to compute a ceiling-like division handling negative numbers correctly.
// 'findMissing' uses a binary search approach to efficiently locate the missing element in the AP.
// The logic compares differences on the left and right halves to narrow down the missing element.

class Solution {
  public:
    // Helper function to perform ceiling division for both positive and negative numbers
    int fake_ceil(int a, int b){
        if(a % b == 0) return a/b;  // If perfectly divisible, return the quotient
        
        int ans = a/b;
        if(a > 0){
            ans++;  // Adjust upwards for positive numbers
        }
        else{
            ans--;  // Adjust downwards for negative numbers
        }
        return ans;
    }

    int findMissing(vector<int> &arr) {
        // Get the size of the array
        int n = arr.size();
        int high = n-1;
        int low = 0;
        
        // Initial difference in the AP
        int d = arr[1] - arr[0];
        
        // Binary search loop
        while(low < high){
            // If only two elements are left, check where the missing element should be
            if(high == low + 1){
                if(d == arr[high] - arr[low]){
                    return arr[n-1] + d; // Missing element is after the last element
                }
                else{
                    return arr[low] + d;  // Missing element is between low and high
                }
            }
            else{
                int mid = low + (high - low)/2;
                
                // Compute differences on left and right halves using fake_ceil
                int left = fake_ceil(arr[mid] - arr[low], mid-low);
                int right = fake_ceil(arr[high] - arr[mid], high-mid);

                if(d < 0){
                    d = max(left, right);
                    if(left < right){
                        high = mid;  // Missing element is in the left half
                    }
                    else{
                        low = mid;   // Missing element is in the right half
                    }
                }
                else{
                    d = min(left, right);
                    if(left > right){
                        high = mid;  // Missing element is in the left half
                    }
                    else{
                        low = mid;   // Missing element is in the right half
                    }
                }
            }
        }

        // Return 0 if no missing element found (should not reach here for valid AP)
        return 0;
    }
};
