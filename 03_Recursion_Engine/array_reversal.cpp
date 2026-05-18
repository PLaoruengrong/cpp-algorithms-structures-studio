const size_t arraySize{10}; 
void recurReverse(const array<int,arraySize>&,size_t); 
     
int main() { 
    array<int,arraySize>a{1,2,3,4,5,6,7,8,9,10}; 
    cout << "The values in the array are:" << endl; 
    recurReverse(a,0); 
    cout<<endl; 
} 
 
void recurReverse(const array<int,arraySize>&b,size_t current){ 
    if(current<b.size()){ 
        recurReverse(b,current+1); 
        cout<<b[current]<<" "; 
    } 
}