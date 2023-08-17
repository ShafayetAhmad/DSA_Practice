#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.length();
        int n2=num2.length();
        int sum=0,i,j,k=0;
        string st;
            j=n2-1;
       int s1,s2;
            i=n1-1;
        while(i>=0 && j>=0){

            s1=(num1[i]-48);
            s2=(num2[j]-48);
            sum=s1+s2+sum;
            if(sum>9){
                int mod=sum%10;
                string s=to_string(mod);
                st=s+st;
                sum=sum/10;
            }else{
                string s=to_string(sum);
                st=s+st;
                sum=0;
            }
             i--;
            j--;
            }
        
        while(i>=0){
            s1=(num1[i]-48);
            
            sum=s1+sum;
            
            if(sum>9){
                int mod=sum%10;
                string s=to_string(mod);
                st=s+st;
                sum=sum/10;
            }else{
                string s=to_string(sum);
                st=s+st;
                sum=0;
            }
            i--;
        }
                
        while(j>=0){
            s2=(num2[j]-48);
            
            sum=s2+sum;
            
            if(sum>9){
                int mod=sum%10;
                string s=to_string(mod);
                st=s+st;
                sum=sum/10;
            }else{
                string s=to_string(sum);
                st=s+st;
                sum=0;
            }
            j--;
        }
        if(sum>0){
            string s=to_string(sum);
            st=s+st;
        }
        return st;
    }
};

int main() {
    Solution solution;

    // Test cases
    string num1 = "123";
    string num2 = "456";
    string result = solution.addStrings(num1, num2);
    cout << "Sum: " << result << endl;

    string num3 = "999";
    string num4 = "1";
    string result2 = solution.addStrings(num3, num4);
    cout << "Sum: " << result2 << endl;

    return 0;
}
