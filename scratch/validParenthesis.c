bool isValid(char * s){
// '(' must be closed by ')'' before NULL terminator
// dont close outer loop before closing inner loop

    char push[10000];
    int count = 0;
    
    while(*s != '\0') {
    
        if(*s == '(') {
            push[count] = ')';
            s++;
            count++;
        } else if (*s == '[') {
            push[count] = ']';
            s++;
            count++;
        } else if (*s == '{') { 
            push[count] = '}';
            s++;
            count++;
        } else if(*s == ')' || *s == ']' || *s == '}') { 
            if(count == 0){
                return false;
            }
            else if(*s != push[count - 1]){
                return false;
            } else {
                count--;
                s++;
            }
        }
    } 
    if (count!= 0) {
        return false;
    }
    return true;
}