void diceRolling(){ 
    const size_t arraySize=7; 
    array<array<int,arraySize>,arraySize> table; 
    for(size_t row=0;row<table.size();++row) for(size_t 
column=0;column<table[row].size();++column) table[row][column]=0; 
    for(int i=0;i<36000000;i++){ 
        int dice1=rand()%6+1; 
        int dice2=rand()%6+1; 
        table[dice1][dice2]++; 
        } 
    cout << "     [1]     [2]     [3]     [4]      [5]     [6]" << endl; 
    for(size_t i=1;i<arraySize;++i){ 
        cout<<"["<<i<<"]"; 
        for(size_t j=1;j<arraySize;++j) cout << setw(7)<<table[i][j]<<" "; 
        cout<<endl; 
    } 
}