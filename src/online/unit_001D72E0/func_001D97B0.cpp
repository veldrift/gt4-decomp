/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Entry { short delta, index; void *(*fn)(void *, int); };
struct Array { int x; char *vt; };
extern Rep D_00659E20;
extern char D_006957A8[], D_006958C8[], D_006958D8[], D_006958E8[];
extern "C" void func_001D93A8();
extern "C" char *func_001D9700(const char *,const char *,const char *,char *) throw();
extern "C" int hArray__size(void *);
extern "C" void func_00312318(void *,int);
extern "C" void func_00312370(void *,void *);
extern "C" char *func_00314AD8(void *);
extern "C" void func_004E7600(void *,const char *,const char *);
extern "C" void func_004E7E50(void *,const char *,const char *);
extern "C" int func_004EA1B0(void *);
extern "C" int func_004EA2B8(void *);
extern "C" int func_004EC078(void *,void *);
extern "C" void free(void *) throw();
extern "C" int func_0057F260(const char *) throw();
extern "C" char *strobe__toUpper(Rep *);
extern "C" void *strobe__Any__setMember(void *,unsigned,unsigned,const char *,unsigned);
static inline char *cstr(Str *s) {
    int n = ((Rep *)(s->p - 16))->len;
    if (!n) return D_006957A8;
    s->p[n] = 0;
    return s->p;
}
static inline void *get(Array *a,int i) {
    Entry *e = (Entry *)(a->vt + 0x68);
    return e->fn((char *)a + e->delta,i);
}
extern "C" int func_001D97B0(char *self,Str *url,Str *a,Str *b,Str *c,Array **array) {
    int h0[4];
    Str s;
    char hash[48];
    int h1[4];
    char *http = self + 16;
    *(void (**)(void))(http+24)=func_001D93A8;
    *(int *)http=2;
    *(int *)(http+16)=0;
    *(char **)(http+20)=self;
    *(char **)(http+28)=self;
    const char *src=cstr(url);
    Str *ps=&s;
    Rep *r=&D_00659E20;
    char *d;
    if(r->sel) d=strobe__toUpper(r);
    else { d=(char *)(r+1); r->ref++; }
    ps->p=d;
    strobe__Any__setMember(ps,0,-1,src,func_0057F260(src));
    int ok=func_004EC078(http+0x90,ps);
    r=(Rep *)(ps->p-16);
    if(--r->ref==0) free(r);
    if(!ok) return 0;
    func_004E7600(http,D_006958C8,D_006958D8);
    const char *ca=cstr(a);
    const char *cb=cstr(b);
    const char *cc=cstr(c);
    char *v=func_001D9700(ca,cb,cc,hash);
    func_004E7600(http,D_006958E8,v);
    int count=hArray__size(*array);
    for(int i=0;i<count;i+=2) {
        int *ph1=h1;
        func_00312370(h0,get(*array,i));
        func_00312370(ph1,get(*array,i+1));
        const char *x=func_00314AD8((void *)h0[0]);
        const char *y=func_00314AD8((void *)ph1[0]);
        func_004E7E50(http,x,y);
        func_00312318(ph1,2);
        func_00312318(h0,2);
    }
    int result=func_004EA1B0(http);
    if(result) {
        *(int *)(self+0x108)=0;
        *(int *)(self+0x10C)=0;
        result=func_004EA2B8(http)!=0;
    }
    return result;
}
