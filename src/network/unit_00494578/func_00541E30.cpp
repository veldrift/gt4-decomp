struct S {char pad[268];int* data;int count;};
extern "C" int func_00541208(void*,int**,int);
extern "C" void func_005412E8(void*,int**);
extern "C" void* func_005A4724(void*,const void*,unsigned);
extern "C" int func_00541E30(void* heap,S* s,int item) {
 int* p=0;
 if(heap) {
  if(!s)return 2;
  if(!item)return 2;
  int r=func_00541208(heap,&p,s->count*4+4);
  if(r)return r;
  {
   func_005A4724(p,s->data,s->count*4);
   int n=s->count;s->count=n+1;p[n]=item;
   func_005412E8(heap,&s->data);s->data=p;return 0;
  }
 }
 return 2;
}
