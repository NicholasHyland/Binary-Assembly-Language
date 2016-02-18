//Implement a C function called ex1 such that it achieves 
//the same functionality as the machine code of objs/ex1_sol.o
//Note: you need to figure out ex1()'s function signature yourself; 
//the signature is not void ex1()
  
#include <assert.h>

/* 0:	48 01 f7             	add    %rsi,%rdi	:rdi (first parameter) += rsi (second parameter)
   3:	48 39 d7             	cmp    %rdx,%rdi	:compare rdi and rdx (third parameter)
   6:	0f 94 c0             	sete   %al		:the zero flag is set by the comparison above
   9:	0f b6 c0             	movzbl %al,%eax		:set eax = al, which is what we return
   c:	c3                   	retq   */


long
ex1(long x, long y, long z) {
	y = x + y;
	return (y == z);
}
