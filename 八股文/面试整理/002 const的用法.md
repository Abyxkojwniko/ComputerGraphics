### const int* a,int const* a,int* const a,const int* const a的区别

如何看const修饰的哪个，那么就是从右往左看，看const在* 的左边还是右边，并且const int和int const等价，const int* 和int const* 都代表const修饰都是int内容，说明指针指向的内容是常量，是常量指针，可以改指针的方向；int* const 代表const修饰的是a这个指针，a指向不能动，但是可以修改值。const int* const代表双重锁定，不能改指向和内容
<!--ID: 1773027655300-->


```
const int * p;  // *p (内容) 不可变
int * const p;  // p (地址) 不可变
```
### const MyClass vs MyClass

**值传递 (`MyClass obj`)：** 会触发拷贝构造函数，把实参复制一份到栈上。如果对象很大（比如存了纹理数据的 `Texture` 类），栈内存可能溢出，且拷贝极慢。
**引用传递 (`const MyClass& obj`)：** 底层实现是指针（只传 8 字节地址），无拷贝，速度快。
**对象切割**：
	场景：** 假设 `MyClass` 是基类，你传了一个子类 `SubClass` 的对象进去。
	**值传递的灾难：** `void func(MyClass obj)`。编译器会只拷贝基类部分的数据到 `obj` 中，子类特有的数据（和虚函数行为）会被**丢弃（Slicing）**！导致多态失效。
	**引用传递：** `void func(const MyClass& obj)`。引用本质是指针，依然指向完整的子类对象，**多态（虚函数）依然有效**。
<!--ID: 1773027655303-->

