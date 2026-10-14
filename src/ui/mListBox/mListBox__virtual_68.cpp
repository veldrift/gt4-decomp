/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Handle { void *p; ~Handle() __asm__("func_002B5E70"); };
struct Vec { int allocator; Handle *begin,*end,*capacity; };
struct Rep { int len,cap,ref,selfish; };
struct Str { char *p; };
struct Heap { const char *name; };
extern Rep D_00659FA8;
extern "C" {
void mTextFace__virtual_68(char *,int);
int mListBox__get_total_item_count(char *);
void func_002B4FD8(char *,int,int,int);
void func_002B50F8(char *,int,int);
void mListBox__setDragIcon(char *,int,int);
void func_002B5E70(void *,int);
void func_002F9B08(Handle *,void **);
void func_002F9B38(void *,int);
void func_003285A8(void *);
void func_003285F8(void *);
Heap *func_005C11A8();
void func_00326798(void *,int,int,const char *);
char *func_005C2560(Rep *);
}
static inline void assign(Handle *,Handle *);
static inline Handle *copy_range(Handle *first,Handle *last,Handle *out) {
 for (int n=last-first;n>0;--n,++first,++out) assign(out,first);
 return out;
}
template<class I> inline Handle *value_type(const I &) { return 0; }
template<class I> inline void destroy_aux(I first,I last) {
 for (;first!=last;++first) first->~Handle();
}
template<class I,class T> inline void destroy_dispatch(I first,I last,T *) { destroy_aux(first,last); }
template<class I> inline void destroy_range(I first,I last) {destroy_dispatch(first,last,value_type(first));}
static inline void erase_range(Vec *v,Handle *first,Handle *last) {
 Handle *i=copy_range(last,v->end,first);
 destroy_range(i,v->end);
 v->end=(Handle *)((int)v->end-((int)last-(int)first));
}
static inline void clear(Vec *v) {erase_range(v,v->begin,v->end);}
static inline void assign(Handle *s,Handle *t) {
 if(s!=t) {
  void *p=t->p;
  if(p)func_003285A8(p);
  if(s->p)func_003285F8(s->p);
  s->p=p;
 }
}
static inline void release(Str *s) {
 Rep *r=(Rep *)s->p-1;
 if(--r->ref==0) {int cap=r->cap+16;func_00326798(r,cap,4,func_005C11A8()->name);}
}
static inline void assign_str(Str *s,Str *other) {
 if(other!=s) {
  release(s);
  char *p=other->p;
  Rep *r=(Rep *)p-1;
  if(r->selfish!=0)p=func_005C2560(r);
  else ++r->ref;
  s->p=p;
 }
}
extern "C" void mListBox__virtual_68(char *self,int arg) {
 mTextFace__virtual_68(self,arg);
 *(int *)(self+0x130)=*(int *)(self+0x124);
 int n=mListBox__get_total_item_count(self);
 for(int i=0;i<n;i++)func_002B4FD8(self,i,arg,0);
 clear((Vec *)(self+0xc8));
 clear((Vec *)(self+0xd8));
 void *frame[7];
 func_002B50F8(self,arg,0);
 mListBox__setDragIcon(self,arg,0);
 Handle *temp=(Handle *)&frame[0];
 Handle *dest=(Handle *)(self+0x110);
 frame[4]=0;
 func_002F9B08(temp,&frame[4]);
 assign(dest,temp);
 func_002F9B38(temp,2);
 dest=(Handle *)(self+0x114);
 frame[5]=0;
 func_002F9B08(temp,&frame[5]);
 assign(dest,temp);
 func_002F9B38(temp,2);
 dest=(Handle *)(self+0x118);
 frame[6]=0;
 func_002F9B08(temp,&frame[6]);
 assign(dest,temp);
 func_002F9B38(temp,2);
 Str *str=(Str *)temp;
 Str *destStr=(Str *)(self+0x154);
 Rep *r=&D_00659FA8;
 char *p;
 if(r->selfish!=0)p=func_005C2560(r);
 else {p=(char *)(r+1);++r->ref;}
 str->p=p;
 assign_str(destStr,str);
 release(str);
}
