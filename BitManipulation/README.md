# Bit Manipulation

总结一下位运算的一些常用操作, 有一个网站记录了许多奇技淫巧<http://graphics.stanford.edu/~seander/bithacks.html#ReverseParallel>

```c++
//末位1置零
n = n & (n - 1);
//判断两数是否异号
((x ^ y) < 0)
```
