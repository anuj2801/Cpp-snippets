Prime Factorization
//O(sqrt(n))
vector<long long> prime_factors;
map<long long,long long> times_present;
void primeFactors(long long n) 
{ 
    while(n%2 == 0) 
    { 
      if(times_present[2]==0)
        prime_factors.push_back(2);
      times_present[2]++;
      n=n/2; 
    } 

    for(long long i=3;i<=sqrt(n);i=i+2) 
    { 
        while (n%i == 0) 
        { 
            if(times_present[i]==0)
             prime_factors.push_back(i);
            times_present[i]++;
            n=n/i; 
        } 
    } 
    if(n>2) 
    prime_factors.push_back(n),times_present[n]++;
} 