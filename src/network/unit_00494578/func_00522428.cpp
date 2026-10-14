struct S {int value;unsigned char a,b,c,d;int unused[2];};
extern "C" void* func_005A48D8(void*,int,unsigned);
extern "C" void func_00522428(S* s,unsigned color) {
 func_005A48D8(s,0,16);s->value=0;
 s->a=color>>24;s->b=color>>16;s->c=color>>8;s->d=color;
}
