struct Rep { int len, cap, ref, selfish; };
struct Str { char *p; };
struct Heap { const char *name; };
extern "C" void mTextFace__virtual_67(char *);
extern "C" char *mWidget__getRootWindow(char *);
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" char *func_005C2560(Rep *);
static inline void release(Str *s) {
 Rep *r = (Rep *)s->p - 1;
 if (--r->ref == 0) { int cap=r->cap+16; func_00326798(r,cap,4,func_005C11A8()->name); }
}
static inline void assign(Str *s, Str *other) {
 if (other != s) {
 release(s);
 char *p=other->p;
 Rep *r=(Rep *)p-1;
 if (r->selfish != 0) p=func_005C2560(r);
 else ++r->ref;
 s->p=p;
 }
}
extern "C" void mListBox__virtual_67(char *self) {
 mTextFace__virtual_67(self);
 *(int *)(self+0x13c)=0;
 *(int *)(self+0x124)=-1;
 *(int *)(self+0x134)=-1;
 *(int *)(self+0x140)=-1;
 *(int *)(self+0x148)=-1;
 *(int *)(self+0x144)=0;
 char *root=mWidget__getRootWindow(self);
 if (root) assign((Str *)(self+0x154),(Str *)(root+0xdc));
 if (*(int *)(self+0x130)<0) *(int *)(self+0x120)=0;
}
