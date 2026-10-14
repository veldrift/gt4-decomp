/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Reader { void *vt; char pad[12]; };
struct Self { char pad[0x24]; void *p; };
struct Obj { int x; char *vt; };
struct VE { short d,i; void (*fn)(void *, ...); };
struct Name { const char *name; };
extern Rep D_00659FA8;
extern char MWidgetReader__vtable[];
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" Str *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
extern "C" Name *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" void func_00213160(Str *,int,Str *) throw();
extern "C" int func_00213158(Self *) throw();
extern "C" int MWidgetReader__structor_3(Reader *,Obj **);
extern "C" bool func_00269290(Reader *,Str *);
extern "C" void *func_00306638(Str *,void *,Obj **);
extern "C" void func_00323B60(Str *,int);
extern "C" void MReaderBase__structor_0(Reader *,int);
#define RELEASE(s) { Rep *q=(Rep *)((s).p-16); if (--q->ref==0) { int cap=q->cap+16; func_00326798(q,cap,4,func_005C11A8()->name); } }
struct Handle { void *p; char pad[12]; };
extern "C" void *func_002ECDE0(Handle *);
extern "C" void func_00306E00(Handle *,Str *);
extern "C" void func_002EAD08(void *,Str *,Handle *);
extern "C" void func_002EAFE0(void *,Str *);
extern "C" void func_00305678(Obj *,int);
extern "C" void func_003041B8(Handle *,int);
extern "C" void func_002EA590(Handle *,int);
extern "C" bool MWidgetReader__structor_1(void *,Obj **obj,int arg2,Str *arg3) {
    Str name;
    Reader reader;
    Handle h;
    Handle w;
    Str s;
    func_00213160(&name,arg2,arg3);
    Reader *pr=&reader;
    MWidgetReader__structor_3(pr,obj);
    bool result=func_00269290(pr,&name);
    if(result) {
        Handle *ph=&h;
        func_002ECDE0(ph);
        const char *src="__widget__";
        Rep *r=&D_00659FA8;
        Str *ps=&s;
        char *d;
        if(r->sel) d=func_005C2560(r);
        else { d=(char *)(r+1); r->ref++; }
        ps->p=d;
        func_005C2630(ps,0,-1,src,func_0057F260(src));
        Handle *pw=&w;
        func_00306E00(pw,ps);
        RELEASE(*ps);
        func_00306638(ps,pw->p,obj);
        func_00323B60(ps,2);
        func_002EAD08(ph->p,&name,pw);
        {
            Obj *o=*obj;
            VE *e=(VE *)(o->vt+0x2f0);
            e->fn((char *)o+e->d);
        }
        func_00305678(*obj,0);
        func_002EAFE0(ph->p,&name);
        func_003041B8(pw,2);
        func_002EA590(ph,2);
    }
    pr->vt=MWidgetReader__vtable;
    MReaderBase__structor_0(pr,0);
    RELEASE(name);
    return result;
}
