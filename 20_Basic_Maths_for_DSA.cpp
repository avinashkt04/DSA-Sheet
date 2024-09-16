#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

vector<long long> sieve(int n){
    vector<bool> prime(n+1, true);
    vector<long long> ans;
    prime[0] = prime[1] = false;

    for(int i=2; i<=n; i++){
        if(prime[i]){
            ans.push_back(i);
            for(int j=2*i; j<n; j=j+i){
                prime[j] = false;
            }
        }
    }
    return ans;
}

void segSieve(int l, int h){
    long long sq = sqrt(h);
    vector<long long> ans = sieve(sq);
    vector<bool> isPrime(h-l+1, true);

    for(long long p: ans){
        long long sm = (l/p)*p;
        if(sm<l){
            sm = sm + p;
        }
        for(long long m=sm; m<=h; m=m+p){
            isPrime[m-l] = false;
        }
    }

    for(long long i=l; i<=h; i++){
        if(isPrime[i-l]==true){
            cout << i << " ";
        }
    }
}

int gcd(int a, int b){
    if(a==0)
        return b;
    
    if(b==0)
        return a;
        
    while(a!=b){
        if(a>b){
            a = a-b;
        }
        else {
            b = b-a;
        }
    }
    return a;
}

int main()
{
    /*
    int n;
    cin >> n;

    if(isPrime(n)){
        cout << "It is a prime number" << endl;
    } else {
        cout << "It is not a prime number" << endl;
    }
    */

    /*
    //segment of sieve

    int l, h;
    cout << "Enter the lower limit: ";
    cin >> l;
    cout << "Enter the higher limit: ";
    cin >> h;

    segSieve(l, h);
    */

   int a, b;
   cout << "Enter the values of a and b: ";
   cin >> a >> b;

   int ans = gcd(a, b);

   cout << "The GCD of " << a << " & " << b << " is: " << ans << endl;

    return 0;
}
