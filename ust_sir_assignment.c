//THERE ARE TWO APPROACHES DISCUSSED HERE. FIRST ONE WITHOUT THE CONCEPT OF DYNAMIC PROGRAMMING AND SECOND ONE USING THE CONCEPTS OF DYNAMIC PROGRAMMING. IT IS SHOWN HOW DP SOLUTION IS BETTER THAN NON DP SOLUTION IN TERMS OF TIME COMPLEXITY.


//THE FIRST PROPOSED SOLUTION IS WITHOUT USING DYNAMIC PROGRAMMING 

//objective - Provided with a set of positive valued integers, and a sum, say whether there exists a subset of the given set sucht that the sum is equal to the given sum variable's value.


/*
let us take ss(int s[], int n, int sum) as a function to find if there is a subset of s[] with sum equal to sum. n is the number of elements in s[].

The ss problem can be divided into two subproblems
 a) first is to include the last element,and reprobe for n = n-1, sum = sum – s[n-1]
 b) and second is to exclude the last element, reprobe for n = n-1.
 
If after all this, even a single subproblem returns true, then function will return true also. 

Below is the pseudo-code for this problem.

ss(s, n, sum) = ss(s, n-1, sum) || 
                           ss(set, n-1, sum-s[n-1])
Base Cases:
ss(s, n, sum) = false, if sum > 0 and n == 0
ss(s, n, sum) = true, if sum == 0 

*/


//code for first solution
#include <stdio.h> 
int ss(int s[], int n, int sum) 
{ 
   
   if (sum == 0) 
     return 1; 
   if (n == 0 && sum != 0) 
     return 0; 
  
   
   if (s[n-1] > sum) 
     return ss(s, n-1, sum); 
  
  
   return ss(s, n-1, sum) ||  
                        ss(s, n-1, sum-s[n-1]); 
} 
  

int main() 
{ 
  int s[] = {3, 34, 4, 12, 5, 2}; 
  int sum = 9; 
  int n = sizeof(s)/sizeof(s[0]); 
  if (ss(s, n, sum) == 1) 
     printf("Found a subset with given sum"); 
  else
     printf("No subset with given sum"); 
  return 0; 
} 
/*
SAMPLE OUTPUT of first solution without dynamic programming - 
Found a subset with given sum
*/



//SECOND PROPOSED SOULTION IS USING DYNAMIC PROGRAMMING 

/*

our first proposed solution will try to look into all subsets of our set in worst case. So the time complexity of the first proposed solution is gets to exponential. The problem is still NP-Complete .

using dynamic programming we can solve this in pseudo-polynomial time. Let us make a boolean 2D aarray subs[][] and put its values in bottom up manner. The value of subs[i][j] will be true if there is a subset of set[0..j-1] with sum equal to i., otherwise false. Finally, we return subs[sum][n]

*/


//code - 

#include <stdio.h> 
int ss(int s[], int n, int sum) 
{ 
   
    int sub[n+1][sum+1]; 
   
    for (int i = 0; i <= n; i++) 
        sub[i][0] = 1; 
   

    for (int i = 1; i <= sum; i++) 
        sub[0][i] = 0; 
   
     
     for (int i = 1; i <= n; i++) 
     { 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<s[i-1]) 
         sub[i][j] = sub[i-1][j]; 
         if (j >= s[i-1]) 
           sub[i][j] = sub[i-1][j] ||  
                                 sub[i - 1][j-s[i-1]]; 
       } 
     } 
   
     
   
     return sub[n][sum]; 
} 

int main() 
{ 
  int s[] = {3, 34, 4, 12, 5, 2}; 
  int sum = 9; 
  int n = sizeof(s)/sizeof(s[0]); 
  if (ss(s, n, sum) == 1) 
     printf("Found a subset with given sum"); 
  else
     printf("No subset with given sum"); 
  return 0; 
} 

/*
SAMPLE OUTPUT for second solution using dynamic programming - 
Found a subset with given sum

Time complexity of the second proposed solution that uses dynamic programming approach is O(sum*n).
*/



