struct A{char p[0x6c];unsigned short count;};struct B{char p[0x74];unsigned short count;};struct O{unsigned short flags,id;};
extern "C" void*func_005A48D8(void*,int,int);
extern "C" void func_0052AA88(A*a,B*b,unsigned short flags,int id,O*out){func_005A48D8(out,0,4);out->flags=(flags&0xf800)|(id&0x7ff);if(flags&0x4000){if(b){out->id=b->count;++b->count;if(!b->count)++b->count;}}else if(flags&0x2000){out->id=a->count;++a->count;if(!a->count)++a->count;}else out->id=0;}
