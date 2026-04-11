/*
题目描述
编写一个函数 `my_strcpy`，其功能与标准库函数 `strcpy` 类似，用于将源字符串复制到目标字符串中。

要求
- 禁止使用标准库中的字符串操作函数（如 `strcpy`、`strlen` 等）。
- 函数应能够正确处理所有合法的C风格字符串，包括空字符串。
- 确保目标字符串有足够的内存来存放源字符串。
- 函数应返回目标字符串的指针。

*/

#include<iostream>

char* my_strcpy(char* dest,const char *src){
    if(*src=='\0') return dest;
    char *temp=dest;
    while(*src!='\0'){
        *dest=*src;
        src++;
        dest++;
    }
    *dest='\0';
    return temp;
}

int main() {
    const char* source = "Hello, World!";
    char destination[50]; // 确保目标有足够的空间
    my_strcpy(destination, source);
    std::cout << "Source: " << source << std::endl;
    std::cout << "Destination: " << destination << std::endl;
    return 0;
}