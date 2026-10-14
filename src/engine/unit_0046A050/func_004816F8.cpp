struct R{int a,b,refs,cap;};
struct Val;
extern "C" void func_004768C0(Val *);
extern "C" Val *func_00476768(Val *, const Val *);
struct Val { int type; int v; Val() : type(1) {} ~Val() { func_004768C0(this); } };
struct Str{char*p;Str(const char*);};
extern R D_00659E20;extern char D_006ADF30[];
extern "C" char* strobe__toUpper(R*);extern "C" int func_0057F260(const char*);
extern "C" Str* strobe__Any__setMember(Str*,int,int,const char*,int);
extern "C" Val* func_00481410(void*,Str*);
extern "C" void func_00477208(Val*, int);
extern "C" Val* func_00476790(Val*, Val*);
extern "C" void free(R*);
inline Str::Str(const char*c){R*r=&D_00659E20;char*t=(char*)(r)+16;if(r->cap)t=strobe__toUpper(r);else ++r->refs;p=t;strobe__Any__setMember(this,0,-1,c,func_0057F260(c));}
struct O { char pad[0x14]; int f14; };
extern "C" void func_004816F8(O *o, int a) {
    o->f14 = a;
    Val t;
    func_00477208(&t, a);
    Str v(D_006ADF30); Str *pv = &v;
    func_00476790(func_00481410(o, &v), &t);
    R*r=(R*)pv->p-1;if(--r->refs==0)free(r);
}
