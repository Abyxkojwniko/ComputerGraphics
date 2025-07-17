#include<iostream>
char* my_strcat(char* dest,const char *src){
    if(*src=='\0') return dest;
    char *temp=dest;
    while(*dest!='\0') dest++;
    while(*src!='\0'){
        *dest=*src;
        src++;
        dest++;
    }
    *dest='\0';
    return temp;
}
int main() {
    char destination[100] = "Hello, "; // 初始内容
    const char* source = "World!";

    my_strcat(destination, source);

    std::cout << "After concatenation: " << destination << std::endl;

    return 0;
}