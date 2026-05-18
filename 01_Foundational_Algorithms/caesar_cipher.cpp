string encoder(string s, int key); 
string decoder(string s, int key); 
 
int main(){ 
int mode(3); 
    while(mode>2 || mode<1){ 
        cout << "Choose mode (1 for encoder, 2 for decoder): "; 
        cin >> mode; 
        if(mode>2 || mode<1) cout << "Invalid mode chosen!" << endl; 
    } 
    cin.ignore(); 
    if(mode==1){ 
// Encoder 
        cout << "Mode: Encoder" << endl; 
        string s; 
        int key(0); 
        cout << "Input key: "; 
        cin >> key; 
        cin.ignore(); 
        cout << "Input text: "; 
        getline (cin,s); 
        string s_encoded = encoder(s, key); 
        cout << "Encoded string: " << s_encoded << endl; 
    }else{ 
        cout << "Mode: decoder" << endl; 
        string s; 
        int key(0); 
        cout << "Input key: "; 
        cin >> key; 
        cin.ignore(); 
        cout << "Input encoded text: "; 
        getline (cin,s); 
        string s_decoded = decoder(s, key); 
        cout << "Decoded string: " << s_decoded << endl; 
    } 
    return 0; 
} 
string encoder(string s, int key){ 
    string s_encoded = s; 
    if(key>26) key=key%26; 
    for(int i=0;i<s.length();i++){ 
        if(s[i]<65 || (s[i]>90 && s[i]<97) || s[i]>122) continue; 
        if(s[i]<=90){ 
            if(s[i] + key>90) s_encoded[i] = (char)('A' + key - (90-s[i])); 
            else s_encoded[i] = (char)(s[i] + key); 
        } 
        if(s[i]>=97){ 
            if(s[i]+key>122) s_encoded[i] = (char)('a' + key - (122-s[i])); 
            else s_encoded[i] = (char)(s[i] + key); 
        } 
    } 
    return s_encoded; 
} 
string decoder(string s, int key){ 
    string s_decoded = s; 
    if(key>26) key=key%26; 
    for(int i=0;i<s.length();i++){ 
        if(s[i]<65 || (s[i]>90 && s[i]<97) || s[i]>122) continue; 
        if(s[i]<=90){ 
            if(s[i] - key<65) s_decoded[i] = (char)('Z' + key - (s[i]-65)); 
            else s_decoded[i] = (char)(s[i] - key); 
        } 
        if(s[i]>=97){ 
            if(s[i]+key<97) s_decoded[i] = (char)('z' + key - (s[i]-97)); 
            else s_decoded[i] = (char)(s[i] - key); 
        } 
    } 
    return s_decoded; 
}