#include <iostream>

int main()
{
  const int temp = 1;//1.修饰变量 不可改变 所以初始化的时候必须赋值
  
  int temp_a = 2;
  const int a = temp_a;//1.1初始化可以是任意的表达式
                       //const 的实现方式是 将所用用到const变量的地方替换成变量的值
   




  return 0;
}
