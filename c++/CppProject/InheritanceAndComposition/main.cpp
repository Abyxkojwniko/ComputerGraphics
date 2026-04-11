#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

// 统一的打印函数，增加地址显示
void log(const std::string& msg, const void* addr = nullptr) {
    std::cout << msg;
    if (addr) {
        std::cout << " [地址: " << addr << "]";
    }
    std::cout << std::endl;
}

class Component {
    std::string name;
public:
    Component(std::string n) : name(n) { 
        log("  [构造] 组件 (位置: " + name + ")", this); 
    }
    ~Component() { 
        log("  [析构] 组件 (位置: " + name + ")", this); 
    }
};

// 情况 1: Component 在 Derived 内部
class Base1 {
public:
    Base1() { log("[构造] Base1 (基类)", this); }
    virtual ~Base1() { log("[析构] Base1 (基类)", this); }
};

class DerivedWithComp : public Base1 {
public:
    Component comp;
    DerivedWithComp() : comp("Derived 内部") { 
        log("[构造] Derived (派生类)", this); 
    }
    ~DerivedWithComp() { 
        log("[析构] Derived (派生类)", this); 
    }
};

// 情况 2: Component 在 Base 内部
class BaseWithComp {
public:
    Component comp;
    BaseWithComp() : comp("Base 内部") { 
        log("[构造] Base (带组件的基类)", this); 
    }
    virtual ~BaseWithComp() { 
        log("[析构] Base (带组件的基类)", this); 
    }
};

class DerivedEmpty : public BaseWithComp {
public:
    DerivedEmpty() { 
        log("[构造] Derived (纯派生类)", this); 
    }
    ~DerivedEmpty() { 
        log("[析构] Derived (纯派生类)", this); 
    }
};

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    log("=== 场景 1: Component 属于 Derived ===");
    {
        DerivedWithComp obj1;
        log("--- obj1 整体起始地址", &obj1);
        log("--- obj1 准备销毁 ---");
    }

    log("\n" + std::string(50, '-') + "\n");

    log("=== 场景 2: Component 属于 Base ===");
    {
        DerivedEmpty obj2;
        log("--- obj2 整体起始地址", &obj2);
        log("--- obj2 准备销毁 ---");
    }

    return 0;
}