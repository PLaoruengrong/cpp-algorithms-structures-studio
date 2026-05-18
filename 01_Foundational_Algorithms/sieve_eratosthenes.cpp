void sieveofEratosthenes(){ 
    const size_t size(997); 
    array<int,size> prime; 
    array<bool,size> checkPrime; 
    for(size_t n=0;n<prime.size();++n){ 
        checkPrime[n]=true; 
        prime[n]=n+2; 
    }     
    for(size_t i=0;i<size;++i){ 
        if(checkPrime[i]){ 
            for(size_t j=i+1;j<size;++j){ 
                if(prime[j]%prime[i]==0) checkPrime[j] =false; 
            } 
        } 
    } 
    for(size_t i=0;i<size;++i){ 
        if(checkPrime[i]) cout<< prime[i] << " "; 
    } 
}