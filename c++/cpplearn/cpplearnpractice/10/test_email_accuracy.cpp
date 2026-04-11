/*
编写一个程序，接受用户输入的电子邮件地址，并验证其格式是否正确。简单的验证标准：
- 包含一个 `@` 符号
- `@` 后面有一个 `.` 符号
- 不包含空格
*/

#include<iostream>
#include<string>
#include<regex>

bool isValidEmail(const std::string &email){
    const std::regex pattern(R"((\w+)(\.?w+)*@(\w+)(\.\w+)+)");
    /*
    (\w+)：这是一个捕获组。\w表示任何单词字符，相当于 [a-zA-Z0-9_]。+表示一个或多个出现。所以，\w+匹配一个或多个单词字符。
    (\.?\w+)*：这也是一个捕获组。
    分解：
    \.?：一个点 .后跟 ?表示这个点可能出现0次或一次。点是特殊字符，所以需要转义 \.。
    \w+：匹配一个或多个单词字符。
    *：整个 (\.?\w+)组合出现零次或多次。所以，它可以匹配像 .username这样的部分，或直接一个单词，或者多次出现（如 .name.something）
    */
    return std::regex_match(email,pattern);
}

int main() {
    std::string email;
    std::cout << "请输入您的电子邮件地址: ";
    std::cin >> email;
    if (isValidEmail(email)) {
        std::cout << "电子邮件地址有效。" << std::endl;
    } else {
        std::cout << "电子邮件地址无效。" << std::endl;
    }
    return 0;
}