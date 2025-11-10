#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

int main() {
    system("chcp 65001 > nul");
//    std::cout << "Hello, World!" << std::endl;
//    int age = 25;
//    std::cout << "I am " <<  age  << " years old." << std::endl;
//    double pi = 3.141592653589793;
//    int num = 42;
//    // 设置浮点数显示精度
//    std::cout << "Pi with default precison: " << pi << std::endl;
//    // 设置浮点数显示精度为4位小数
//    std::cout << "Pi with 4 decimal places: " << std::fixed << std::setprecision(4) << pi <<  std::endl;
//
//    //设置字段宽度和对齐方式
//    std::cout << "Number with width 5: | " << std::setw(5) << num << " |" << std::endl;
//    std::cout << "Number left aligned with width 5: | " << std::setw(5) << std::left << num << " |" << std::endl;
//
//    std::cout << "Please enter your name: ";
//    std::string name;
//    std::cin >> name;
//    std::cout << "Hello, " << name << "!" << std::endl;

    //创建一个ofstream对象，并打开文件"output.txt"用于写入
//    std::ofstream outFile("output.txt");
//    if (!outFile){
//        std::cerr << "无法打开文件进行写入" << std::endl;
//        return 1;
//    }
//
//    //向文件写入
//    outFile << "这是第一行.\n";
//    outFile << "这是第二行, 数字为： " << 100 << std::endl;
//    outFile << "浮点数: " << 3.14159 << std::endl;
//    //关闭文件
//    outFile.close();
//    std::cout << "文件写入完成." << std::endl;
//
//    std::ifstream inFile("output.txt");
//    if(!inFile){
//        std::cerr << "无法打开文件进行读取" << std::endl;
//        return 1;
//    }
//
//    std::string line;
//    while(std::getline(inFile, line)){
//        std::cout << line << std::endl;
//    }
//
//    inFile.close();

//    std::fstream file("data.txt", std::ios::in | std::ios::out | std::ios::app);
//    if(!file){
//        std::cerr << "无法打开文件" << std::endl;
//        return 1;
//    }
//    file <<"追加的一行内容.\n";
//    file.seekg(0, std::ios::beg);
//    std::string line;
//    std::cout << "文件内容如下: " << std::endl;
//    while(std::getline(file,line)){
//        std::cout << line << std::endl;
//    }
//    file.close();
    int num = 123;
    std::string str = std::to_string(num);
    std::cout << "str is " << str << std::endl;
    double d = 3.14;
    std::string str2 = std::to_string(d);
    std::cout << "str2 is " << str2 << std::endl;

    double d2 = std::stod(str2);
    std::cout << "d2 is " << d2 << std::endl;

    int num2 = std::stoi(str);
    std::cout << "num2 is " << num2 << std::endl;

    int id = 101;
    std::string name = "Alice";
    double score = 95.5;

    std::stringstream ss;
    ss << "ID: " << id << ", Name: " << name << ", Score: " << score;

    std::string result = ss.str();
    std::cout << result << std::endl;

    ss.clear();
    ss.str("");
    ss << num;
    std::string str3 = ss.str();
    std::cout << "str3 is " << str3 << std::endl;

    std::string str4;
    ss >> str4;
    std::cout << "str4 is " << str4 << std::endl;

    std::string data = "2023 JohnDoe 85.6";
    int year;
    std::string name2;
    double grade;

    std::stringstream ss2(data);
    ss2 >> year >> name2 >> grade;

    std::cout << "Year: " << year << ", Name: "
    << name2 << ", Grade: " << grade << std::endl;

    std::string input = "2023 Bob 75.5";
    std::istringstream iss(input);
    iss >> year >> name2 >> grade;
    std::cout << "Year: " << year << ", Name: " << name2 << ", Grade: "
    << grade << std::endl;

    std::ostringstream oss;
    oss << "Year: " << year << ", Name: " << name2 << ", Grade: " << grade;

    std::string output = oss.str();
    std::cout << output << std::endl;

    std::string csvData = "John,25,80.5";
    std::string name3;
    int age;
    double score2;
    std::stringstream ssv(csvData);
    std::getline(ssv, name3,',');
    ssv >> age;
    ssv.ignore(1);
    ssv >> score2;
    std::cout << "Name: " << name3 << ", Age: " << age << ", Score: " << score2 << std::endl;
    return 0;
}
