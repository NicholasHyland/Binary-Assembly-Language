//Implement a C function called ex5 such that it achieves 
//the same functionality as the machine code of objs/ex5_sol.o
//Note: you need to figure out ex5()'s function signature yourself; 
//the signature is not void ex5(node *n). However, as a hint, 
//ex5 does take node * as an argument.
 
#include <assert.h>
#include "ex5.h"


/*   0:	48 85 ff             	test   %rdi,%rdi 		:testing the first parameter
   3:	75 0d                	jne    12 <ex5+0x12>		:jump to line 12 if rdi is not equal to null
   5:	eb 17                	jmp    1e <ex5+0x1e>		:jump unconditinally to 1e (above command does not run)
   7:	48 8b 17             	mov    (%rdi),%rdx		:set rdx to dereferenced rax (node->value)
   a:	48 89 c7             	mov    %rax,%rdi		:set rdi = rax (node = node->next)
   d:	48 3b 10             	cmp    (%rax),%rdx		:compare rdx and dereferenced rax (node->next->value)
  10:	7f 12                	jg     24 <ex5+0x24>		:jump if rdx is greater than (rax)
  12:	48 8b 47 08          	mov    0x8(%rdi),%rax		:rax = rdi(first parameter) + 8		//move 8 bytes, meaning to the next node
  16:	48 85 c0             	test   %rax,%rax		:test node->next
  19:	75 ec                	jne    7 <ex5+0x7>		:jump if above is not equal to null
  1b:	b0 01                	mov    $0x1,%al			:set return = 0
  1d:	c3                   	retq   				:return
  1e:	b8 01 00 00 00       	mov    $0x1,%eax		:set return = 0
  23:	c3                   	retq   				:return
  24:	b8 00 00 00 00       	mov    $0x0,%eax		:set return = 0
  29:	c3                   	retq   				:return			*/


int
ex5(node *n) {
	if (n == 0) {
		return 1;
	}
	while (n->next != 0) {
		if (n->value > n->next->value){
			return 0;
		}
		n = n->next;
	}
	return 1;
}
