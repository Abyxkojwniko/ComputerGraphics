## data 与 methods是否分开

![[Pasted image 20260420100617.png]]

采用GP，containers和algorithms可以通过接口来进行沟通，不需要全部放在一起

![[Pasted image 20260420101156.png]]
为什么list不能用sort，因为没有连续空间，所以不能直接操作
标准库的sort需要一定的条件，不能像vector，deque一样操作去进行全局的排序

### string
![[Pasted image 20260420101920.png]]
字符串比大小的形式，字典形式，不比较长度，只比较当前字符ascii码的大小，
这里我们传入了一个函数，去定义比大小的形式，