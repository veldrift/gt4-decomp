struct Entry { void *ptr; int size; };
struct Pool { Entry entry[4096]; int unused,total; };
extern "C" int func_00538C68(void **) throw();
extern "C" int func_005412E8(Pool *p,void **h) {
 int *sizes=&p->entry[0].size;
 unsigned i=0;
 void *remain=*h;
 do {
  int off=i*8;
  void **e=(void **)((char *)p+off);
  i++;
  if(remain==*e) {
   func_00538C68(h);
   int *sz=(int *)((char *)sizes+off);
   *h=0;
   *e=0;
   p->total-=*sz;
   remain=*h;
   *sz=0;
   break;
  }
 } while(i<4096);
 if(remain) func_00538C68(h);
 return 0;
}
