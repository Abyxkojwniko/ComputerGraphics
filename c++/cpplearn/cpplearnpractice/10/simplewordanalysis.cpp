/*
简易文本分析器
创建一个程序，接受用户输入的一段文本，并提供以下功能：
- 统计单词数量
- 统计每个单词出现的次数
- 查找指定单词的出现次数
- 输出最长的单词
*/

#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<algorithm>
int main(){
    std::string text;
    std::cout<<"please input text:\n";
    std::ostringstream oss;
    std::string line;
    while(std::getline(std::cin,line)){
        oss<<line<<" ";
    }
    text=oss.str();
    std::stringstream ss(text);
    std::string word;
    std::map<std::string,int> wordCount;
    size_t totoalwords=0;
    std::string longestWord;
    while(ss>>word){
        word.erase(std::remove_if(word.begin(),word.end(),[](char c){return ispunct(c);}),word.end());
        std::transform(word.begin(),word.end(),word.begin(),::tolower);
        if(!word.empty()){
            wordCount[word]++;
            totoalwords++;
            if(word.length()>longestWord.length()) longestWord=word;
        }
    }
    std::cout << "\n统计结果:\n";
    std::cout << "总单词数: " << totoalwords<< std::endl;
    std::cout << "每个单词出现的次数:\n";
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "最长的单词: " << longestWord << std::endl;

    // 查找指定单词的出现次数
    std::string searchWord;
    std::cout << "\n请输入要查找的单词: ";
    std::cin >> searchWord;
    // 转为小写
    std::transform(searchWord.begin(), searchWord.end(), searchWord.begin(), ::tolower);
    auto it = wordCount.find(searchWord);
    if (it != wordCount.end()) {
        std::cout << "'" << searchWord << "' 出现了 " << it->second << " 次。" << std::endl;
    } else {
        std::cout << "'" << searchWord << "' 未在文本中找到。" << std::endl;
    }

    return 0;
}