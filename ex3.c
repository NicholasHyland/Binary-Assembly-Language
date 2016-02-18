//Implement a C function called ex3 such that it achieves 
//the same functionality as the machine code of objs/ex3_sol.o
//Note: you need to figure out ex3()'s function signature yourself; 
//the signature is not void ex3()
  
#include <assert.h>



/* 0:	b8 00 00 00 00       	mov    $0x0,%eax		:set eax = 0
   5:	eb 1b                	jmp    22 <ex3+0x22>		:jump (unconditinally) to line 22
   7:	48 63 c8             	movslq %eax,%rcx		:set rcx = eax
   a:	4c 8d 04 0f          	lea    (%rdi,%rcx,1),%r8	:set r8 = rdi(first parameter) + 1(rcx)(index),
   e:	45 0f b6 08          	movzbl (%r8),%r9d		:set r9d = r8 (answer above)
  12:	48 01 f1             	add    %rsi,%rcx		:rcx += rsi(second parameter)
  15:	44 0f b6 11          	movzbl (%rcx),%r10d		:set r10d = rcx
  19:	45 88 10             	mov    %r10b,(%r8)		:assign r8 to r10b	 //swapping occurs
  1c:	44 88 09             	mov    %r9b,(%rcx)		:assign r9b to rcx	 //swapping occurs
  1f:	83 c0 01             	add    $0x1,%eax		:increment index counter by 1
  22:	39 d0                	cmp    %edx,%eax		:compare edx and eax (index to parameter c)
  24:	7c e1                	jl     7 <ex3+0x7>		:jump to line 7 if eax < edx
  26:	f3 c3                	repz retq */

void
ex3(char* a, char* b, int c) {
	for(int i = 0; i < c; i++) {
		char temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}	
}
