# C++ 知识点练习

## STL六大部件（components）

* 容器（Containers）
* 分配器 （Allocator）
* 算法 (Algorithms)
* 迭代器 (Iterators) : 泛化的指针
* 适配器 (Adapters)
* 仿函数 (Functions)

## 常见的算法复杂度
* O(1) or O(c):常数时间
* O(n):线性时间
* O(log2n):次线性时间
* O(n^2):平方时间
* O(n^3):立方时间
* O(2^n):指数时间
* O(nlog2n):介于线性以及二次方之间

容器区间：前闭后开：[)表示头和尾巴，begin()是包含的，end()是不包含的【最后一个元素的下一个元素】

容器结构分类：
* 序列式容器：
  * array:静态数组
    * [a][b][c][d]
  * vector:动态数组
    * [a][b][c][d]->
  * deque:双向队列
    * <-[a][b][c][d]->
  * list:双向链表
    * <->[a]<->[b]<->[c]<->[d]<->
  * forward list：单向链表
    * ->[a][b][c][d]->
* 关联式容器：
  * set（内容不能重复，独一无二）/multiset（内容可以重复）:树：红黑树（高度平衡二叉树）
  * map（内容不能重复，独一无二）/multimap（内容可以重复）：带key的树（高度平衡二叉树）
* 无序容器
  * unordered set（内容不能重复，独一无二）/multiset（内容可以重复）：哈希表
  * unordered map（内容不能重复，独一无二）/multimap（内容可以重复）：带key的哈希表