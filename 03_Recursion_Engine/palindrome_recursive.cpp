bool testPaliRecur(const char* str, int a, int b){ 
    if(a>b) return 1; 
    else if(str[a]!=str[b]) return 0; 
    return testPaliRecur(str,a+1,b-1); 
}     
     
bool testPalindrome(const char* test){ 
    char onlyText[strlen(test)+1]; 
    int onlyTextIndex(0); 
    for (int i = 0; i < strlen(test); i++){ 
        if(isalpha(test[i])) onlyText[onlyTextIndex++] = tolower(test[i]);  
    } 
    onlyText[onlyTextIndex] = '\0'; // Null-terminate the string 
    return testPaliRecur(onlyText,0,strlen(onlyText)-1); 
}