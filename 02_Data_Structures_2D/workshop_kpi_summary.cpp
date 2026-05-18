void workshop(){ 
    const size_t people=3; 
    const size_t product=4; 
    array<array<int,product>,people> stock; 
    for(size_t row=0;row<stock.size();++row) for(size_t 
column=0;column<stock[row].size();++column) stock[row][column]=0; 
    for(int i=0;i<30;i++){ //30 days 
        for(int j=0;j<3;j++){ //3 people 
            for(int k=0;k<rand()%5;k++) stock[j][rand()%4]++; 
        }     
    } 
    cout << "    [1]  [2]  [3]  [4]" << endl; 
    for(size_t i=0;i<people;++i){ 
        cout<<"["<<i+1<<"]"; 
        for(size_t j=0;j<product;++j) cout << setw(4)<<stock[i][j]<<" "; 
        cout<<endl; 
    } 
}