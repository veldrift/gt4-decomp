/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { char pad[8]; unsigned char a,b; signed char c,d; char tail[4]; };
struct Data { int n; char pad[12]; Entry entries[1]; };
struct VEntry { short delta,index; int (*fn)(void *); };
struct Obj { int x; char *vt; char pad[8]; Data *data; };
struct Handle { Obj *p; };
extern "C" void func_0019E508(void *,void *) throw();
extern "C" void func_0019E4B0(void *,int) throw();
extern "C" void func_002ED618(void *,void *);
extern "C" void func_002ED5C0(void *,int);
extern "C" int hArray__size(void *);
extern "C" void func_002EFC48(void *,int);
extern "C" Handle *HArray__operator_index(void *,int);
extern "C" void func_002FE278(void *,int);
extern "C" void func_002FC870(void *,int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_00438150(void *,int);
static inline int number(Handle *h) {
 Obj *obj=h->p;
 VEntry *v=(VEntry*)(obj->vt+0x58);
 return v->fn((char*)obj+v->delta);
}
static inline void assign(Handle *dst,Handle *src) {
 if(dst!=src) { Obj *p=src->p; if(p)func_003285A8(p); if(dst->p)func_003285F8(dst->p); dst->p=p; }
}
struct Slot { Handle h; char pad[12]; };
struct Array : Handle {
 char pad[12];
 Array(int n) {func_002EFC48(this,n);}
 ~Array() {func_002ED5C0(this,2);}
 Handle *index(int n) {return HArray__operator_index(this,n);}
};
struct Integer : Handle {
 char pad[12];
 Integer(int n) {func_002FE278(this,n);}
 ~Integer() {func_002FC870(this,2);}
};
extern "C" void MPlayList__get_play_data(Handle *ret,void *arg,int mode,Handle *input) {
 Slot f[2];
 func_0019E508(&f[0].h,arg);
 Data *data=f[0].h.p->data;
 func_0019E4B0(&f[0].h,2);
 if(mode>0) {
  func_002ED618(&f[0].h,input);
  int i=0;
  int count=hArray__size(f[0].h.p);
  if(i<count) {
   Handle *row=&f[1].h;
   Entry *e=data->entries;
   do {
    func_002ED618(row,HArray__operator_index(&f[0].h,i));
    i++;
    int d=number(HArray__operator_index(row,0));
    int a=number(HArray__operator_index(row,1));
    int b=number(HArray__operator_index(row,2));
    int c=number(HArray__operator_index(row,3));
    e->d=d; e->c=c; e->a=a; e->b=b;
    e++;
    func_002ED5C0(row,2);
   } while(i<count);
  }
  func_00438150(data,count);
  func_002ED5C0(&f[0].h,2);
 } else {
  int count=data->n;
  int i=0;
  func_002EFC48(&f[0].h,count);
  if(i<count) {
   Entry *e=data->entries;
   do {
    { Array row(4);
    {Handle *dst=row.index(0); Integer value(e->d); assign(dst,&value);}
    {Handle *dst=row.index(1); Integer value(e->a); assign(dst,&value);}
    {Handle *dst=row.index(2); Integer value(e->b); assign(dst,&value);}
    {Handle *dst=row.index(3); Integer value(e->c); assign(dst,&value);}
    assign(HArray__operator_index(&f[0].h,i),&row); }
    i++;
    e++;
   }while(i<count);
  }
  assign(ret,&f[0].h);
  func_002ED5C0(&f[0].h,2);
 }
}
