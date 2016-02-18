//Implement a C function called ex2 such that it achieves 
//the same functionality as the machine code of objs/ex2_sol.o
//Note: you need to figure out ex2()'s function signature yourself; 
//the signature is not void ex2()
  
#include <assert.h>


/* 0:	b8 00 00 00 00       	mov    $0x0,%eax		:set eax = 0
   5:	ba 00 00 00 00       	mov    $0x0,%edx		:set edx = 0
   a:	eb 0e                	jmp    1a <ex2+0x1a>		:jump (unconditionally to line 1a)
   c:	80 f9 61             	cmp    $0x61,%cl		:cl is lower 8 bits of of rcx - we compare this to 'a' (ascii value 61)
   f:	0f 94 c1             	sete   %cl			:set a zero flag based on the comparison above
  12:	0f b6 c9             	movzbl %cl,%ecx			:set ecx = cl (which will be 0 or 1)
  15:	01 c8                	add    %ecx,%eax		:if ecx is 1, increment eax (counter), otherwise add 0 (do nothing)
  17:	83 c2 01             	add    $0x1,%edx		:increment index by 1
  1a:	48 63 ca             	movslq %edx,%rcx		:rcx = edx
  1d:	0f b6 0c 0f          	movzbl (%rdi,%rcx,1),%ecx	:ecx = rdi + 1(rcx)
  21:	84 c9                	test   %cl,%cl			:test cl against null
  23:	75 e7                	jne    c <ex2+0xc>		:jump to line c is test above is not equal
  25:	f3 c3                	repz retq			:return 		*/			

int
ex2(char * a) {
	int counter = 0;
	int i = 0;
	while (a[i] != '\0'){
		if (a[i] == 'a') {
			counter++;
		}
		i++;
	}
	return counter;

}
