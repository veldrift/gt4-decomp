struct B{char data[8];};struct N{char pad[8];B value;int extra;};
extern "C" N* func_0052DD60(void*);
extern "C" int func_00529320(void*self,N*n,B*out,int*extra){if(!self)return 0xD2F2;if(n){*out=n->value;*extra=n->extra;}else{N*q=func_0052DD60((char*)self+12);if(!q)return 3;B*p=&q->value;*out=*p;*extra=*(int*)((char*)p+8);}return 0;}
