//Implement a C function called ex4 such that it achieves 
//the same functionality as the machine code of objs/ex4_sol.o
//Note: you need to figure out ex4()'s function signature yourself; 
//the signature is not void ex4()
  
#include <assert.h>


/* 0:	55                   	push   %rbp			:pushing to create space for stack (due to recursion)
   1:	53                   	push   %rbx			:pushing to create space for stack (due to recursion)
   2:	48 83 ec 08          	sub    $0x8,%rsp		
   6:	48 89 fb             	mov    %rdi,%rbx		:set rbx = rdi (first parameter)
   9:	48 89 f8             	mov    %rdi,%rax		:set rax = rdi (first parameter)
   c:	48 83 ff 01          	cmp    $0x1,%rdi		:compare 1 to parameter
  10:	7e 18                	jle    2a <ex4+0x2a>		:if comparision above is less than one (is equal to 0) jump to line 2a
  12:	48 8d 7f ff          	lea    -0x1(%rdi),%rdi		:rdi = rdi - 2
  16:	e8 00 00 00 00       	callq  1b <ex4+0x1b>		:recursive call using above function and go to line 1b
  1b:	48 89 c5             	mov    %rax,%rbp		:set rbp = rax
  1e:	48 8d 7b fe          	lea    -0x2(%rbx),%rdi		:rdi = rbx(which is original rdi) - 2
  22:	e8 00 00 00 00       	callq  27 <ex4+0x27>		:recursive call using above function and go to line 27
  27:	48 01 e8             	add    %rbp,%rax		:add the two recursive calls together
  2a:	48 83 c4 08          	add    $0x8,%rsp		:point to top of stack 
  2e:	5b                   	pop    %rbx			:stack space no longer needed
  2f:	5d                   	pop    %rbp			:stack space no longer needed
  30:	c3                   	retq   				:return			*/


int
ex4(int a) {
	if (a == 0)
		return 0;
	else if (a == 1)
		return 1;
	else
		return (ex4(a - 1) + ex4(a - 2));
}
