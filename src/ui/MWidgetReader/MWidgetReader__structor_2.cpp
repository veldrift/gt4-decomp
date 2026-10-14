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
extern "C" bool MWidgetReader__structor_2(Self *self,Obj **obj,int arg2,int arg3) {
    Str name;
    Str s;
    Reader reader;
    Str *ps=&s;
    const char *src=".mproject";
    Rep *r=&D_00659FA8;
    char *d;
    if(r->sel) d=func_005C2560(r);
    else { d=(char *)(r+1); r->ref++; }
    ps->p=d;
    func_005C2630(ps,0,-1,src,func_0057F260(src));
    func_00213160(&name,arg2,ps);
    RELEASE(*ps);
    Reader *pr=&reader;
    MWidgetReader__structor_3(pr,obj);
    bool result=func_00269290(pr,&name);
    if(result) {
        func_00306638(ps,self->p,obj);
        func_00323B60(ps,2);
        {
            Obj *o=*obj;
            VE *e=(VE *)(o->vt+0x2f0);
            e->fn((char *)o+e->d);
        }
        if(arg3) {
            {
                Obj *o=*obj;
                VE *e=(VE *)(o->vt+0x2b0);
                o=(Obj *)((char *)o+e->d);
                e->fn(o,func_00213158(self));
            }
            {
                Obj *o=*obj;
                VE *e=(VE *)(o->vt+0x2c0);
                o=(Obj *)((char *)o+e->d);
                e->fn(o,func_00213158(self));
            }
        }
    }
    pr->vt=MWidgetReader__vtable;
    MReaderBase__structor_0(pr,0);
    RELEASE(name);
    return result;
}
