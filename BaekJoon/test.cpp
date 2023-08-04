#include <iostream>
#include <string>

using namespace std;




int recursion(string s, int l, int r, int *c){
    *c++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, c);
}

// int isPalindrome(string s, int *c){
//     return recursion(s, 0, s.length(), c);
// }

int main(){
    int n;
    cin>>n;
    int count = 0;
    string str;

    for(int i = 0 ; i < n; i ++) {
        cin >> str;
        cout<< recursion(str, 0, str.length(), &count) << " " <<  count<<endl;

        count = 0;
        str.clear();
    }
}