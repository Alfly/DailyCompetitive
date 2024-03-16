#include <iostream>
#include <vector>
class A {
public:
  // 无参构造函数
  A () { x = 0; std::cout << "A ()" << std::endl; }
  // 有参构造函数
  A (int x_arg) : x (x_arg) { std::cout << "A (x_arg), x=" << x << std::endl; }
  // 拷贝构造函数
  A (const A &rhs) noexcept { x = rhs.x + rhs.x * 10; std::cout << "A (A &), x=" << x << std::endl; }
  // 移动构造函数
  A (A &&rhs) noexcept { x = rhs.x + rhs.x * 100; std::cout << "A (A &&), x=" << x <<  std::endl; }
  // 析构函数
  ~A() { std::cout << "~A () | " << x << std::endl; }

private:
  int x;
};

void test_emplace_back_1() {
  // emplace_back: 
  //    1) 仅调用 有参构造函数 A (int x_arg) ；
  // push_back：
  //    1) 调用 有参构造函数 A (int x_arg) 创建临时对象；
  //    2) 调用 移动构造函数 A (A &&rhs)   到vector中；
  //    3) 调用    析构函数               销毁临时对象；
  {
    std::vector<A> a;
    std::cout << "call emplace_back: \n";
    a.emplace_back(1);  
  }
    // call emplace_back: 
    // A (x_arg), x=1
    // ~A () | 1
  {
    std::vector<A> a;
    std::cout << "call push_back: \n";
    a.push_back(2);
  }
    // call push_back: 
    // A (x_arg), x=2
    // A (A &&), x=202
    // ~A () | 2
    // ~A () | 202
}

void test_emplace_back_2() {
  // 插入对象都需要三步走：建临时对象->移动->销毁临时对象
  {
    std::vector<A> a;
    std::cout << "call emplace_back: \n";
    a.emplace_back(A(1));
  }
    // call emplace_back: 
    // A (x_arg), x=1
    // A (A &&), x=101
    // ~A () | 1
    // ~A () | 101
  {
    std::vector<A> a;
    std::cout << "call push_back: \n";
    a.push_back(A(2));
  }
    // call push_back: 
    // A (x_arg), x=2
    // A (A &&), x=202
    // ~A () | 2
    // ~A () | 202
}

void test_emplace_back_3() {
  // 注意，这里调用的是 拷贝构造 函数：拷贝->销毁临时对象
  {
    std::vector<A> a;
    std::cout << "call emplace_back: \n";
    A obj(1);
    a.emplace_back(obj);
  }
    // call emplace_back: 
    // A (x_arg), x=1
    // A (A &), x=11
    // ~A () | 1
    // ~A () | 11
  {
    std::vector<A> a;
    std::cout << "call push_back: \n";
    A obj(2);
    a.push_back(obj);
  }
    // call push_back: 
    // A (x_arg), x=2
    // A (A &), x=22
    // ~A () | 2
    // ~A () | 22
}

int main() {
    test_emplace_back_1();
    // test_emplace_back_2();
    // test_emplace_back_3();
}