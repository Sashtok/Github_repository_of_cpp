#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

//class Sashtok
//{
//public:
//	Sashtok(int _a = 0)
//	{}
//	~Sashtok()
//	{}
//private:
//	int _a = 0;
//};
//
//class Sashtok2
//{
//private:
//	int _a = 0;
//};
//
//int main()
//{
//	// 底层是malloc + 构造，为了实现抛异常功能
//	Sashtok* s1 = new Sashtok(1);
//	/* 调试转到反汇编
//	00007FF758E71A1C  mov         ecx, 4
//	00007FF758E71A21  call        operator new (07FF758E7117Ch)  // 申请空间，失败就抛异常
//	00007FF758E71A26  mov         qword ptr[rbp + 108h], rax
//	00007FF758E71A2D  cmp         qword ptr[rbp + 108h], 0
//	00007FF758E71A35  je          main + 51h(07FF758E71A51h)
//	00007FF758E71A37  mov         edx, 1
//	00007FF758E71A3C  mov         rcx, qword ptr[rbp + 108h]
//	00007FF758E71A43  call        Sashtok::Sashtok(07FF758E71280h)  // 调用构造函数
//	00007FF758E71A48  mov         qword ptr[rbp + 118h], rax
//	00007FF758E71A4F  jmp         main + 5Ch(07FF758E71A5Ch)
//	00007FF758E71A51  mov         qword ptr[rbp + 118h], 0
//	00007FF758E71A5C  mov         rax, qword ptr[rbp + 118h]
//	00007FF758E71A63  mov         qword ptr[rbp + 0E8h], rax
//	00007FF758E71A6A  mov         rax, qword ptr[rbp + 0E8h]
//	00007FF758E71A71  mov         qword ptr[s], rax
//	*/
//	delete s1;
//	/*
//	00007FF7E4911A00  mov         dword ptr [rsp+10h],edx
//	00007FF7E4911A04  mov         qword ptr [rsp+8],rcx
//	00007FF7E4911A09  push        rbp
//	00007FF7E4911A0A  push        rdi
//	00007FF7E4911A0B  sub         rsp,0E8h
//	00007FF7E4911A12  lea         rbp,[rsp+20h]
//	00007FF7E4911A17  mov         rcx,qword ptr [this]
//	00007FF7E4911A1E  call        Sashtok::~Sashtok (07FF7E491144Ch) // 析构函数
//	00007FF7E4911A23  nop
//	00007FF7E4911A24  mov         eax,dword ptr [rbp+0E8h]
//	00007FF7E4911A2A  and         eax,1
//	00007FF7E4911A2D  test        eax,eax
//	00007FF7E4911A2F  je          Sashtok::`scalar deleting destructor'+43h (07FF7E4911A43h)
//	00007FF7E4911A31  mov         edx,4
//	00007FF7E4911A36  mov         rcx,qword ptr [this]
//	00007FF7E4911A3D  call        operator delete (07FF7E491126Ch) // 调用 _free_dbg
//	00007FF7E4911A42  nop
//	00007FF7E4911A43  mov         rax,qword ptr [this]
//	00007FF7E4911A4A  lea         rsp,[rbp+0C8h]
//	00007FF7E4911A51  pop         rdi
//	00007FF7E4911A52  pop         rbp
//	*/
//
//	Sashtok* s2 = new Sashtok(1);
//	free(s2);// 不要混用，要是析构函数什么都没干，就不会内存泄漏
//			 // 要是析构函数delete了什么，那就会内存泄漏
//
//	int* a = new int[10];
//	delete a;// 不会内存泄漏，因为new对于内置类型来说，底层只涉及malloc
//			// delete对于内置类型来说，底层只涉及free
//			// malloc后free，内存不会泄露
//
//////////////////////////////////////////////////////////////////////////////////////////////
//	Sashtok* s3 = new Sashtok[10];
//	/*
//	// 实际上s3的地址从这里开始
//	0x000002986A209B00  0a 00 00 00  .... // 多开了8字节，存了一个0000000a，也就是数组个数10
//	0x000002986A209B04  00 00 00 00  ....
//	0x000002986A209B08  00 00 00 00  .... // s3的地址，往下40个字节
//	0x000002986A209B0C  00 00 00 00  ....
//	0x000002986A209B10  00 00 00 00  ....
//	0x000002986A209B14  00 00 00 00  ....
//	0x000002986A209B18  00 00 00 00  ....
//	0x000002986A209B1C  00 00 00 00  ....
//	0x000002986A209B20  00 00 00 00  ....
//	0x000002986A209B24  00 00 00 00  ....
//	0x000002986A209B28  00 00 00 00  ....
//	0x000002986A209B2C  00 00 00 00  ....
//	*/
//	delete s3;
//	Sashtok2* s4 = new Sashtok2[10];
//	/*
//	0x000001CD4121556C  fd fd fd fd  ???? // s4上面是随机值，没有多开空间
//	0x000001CD41215570  00 00 00 00  .... // s4的地址，往下40个字节
//	0x000001CD41215574  00 00 00 00  ....
//	0x000001CD41215578  00 00 00 00  ....
//	0x000001CD4121557C  00 00 00 00  ....
//	0x000001CD41215580  00 00 00 00  ....
//	0x000001CD41215584  00 00 00 00  ....
//	0x000001CD41215588  00 00 00 00  ....
//	0x000001CD4121558C  00 00 00 00  ....
//	0x000001CD41215590  00 00 00 00  ....
//	0x000001CD41215594  00 00 00 00  ....
//	*/
//	delete s4;
//	// 两个类的大小都是4字节，但是s3会报内存错误，s4没问题
//	// 转到反汇编后，可以看到s3是48字节，s4是40字节
//	// 也就是说10个Sashtok对象是48字节，10个Sashtok2对象是40字节
//	// s3报错是因为释放空间时从中间开始释放了，这是不允许的
//	// 如果s3用delete[]，那么释放空间时会往前偏移8字节
//	// s4不报错，是因为s4释放的位置是对的
//	// 那为什么s4不存个数呢？
//	// 其实存的个数是给delete[]用的，告诉它需要调用多少次析构函数
//	// 而Sashtok2没有主动写析构函数，编译器优化后也就没有多开空间去存个数
//	// 这件事告诉我们，一定要匹配使用
//
//	return 0;
//}