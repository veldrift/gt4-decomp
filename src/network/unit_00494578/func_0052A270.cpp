struct A { char pad[0x50]; int value; };
struct B { int state; char pad[0x80]; int value; };
struct Api { char pad0[0x18]; void (*f18)(int,int,void*); void (*f1c)(int,int,void*); char pad20[0xc]; void (*f2c)(int,int,void*); char pad30[0x24]; void (*f54)(void*); };
extern Api *D_0064B710;
extern "C" int func_005288E8() throw();
extern "C" int func_0052BDD8(A*,B*);
extern "C" int func_0052A270(A *a,B *b) {
    char buf0[0x40];
    char buf1[0x40];
    int r=2;
    if(!a) return r;
    r=0xd2f3;
    if(!b) return r;
    int state=b->state;
    r=0xd2f4;
    if(state != 8) return r;
    b->state=9;
    if(func_005288E8()==1) {
        char *p=buf1;
        D_0064B710->f54(p);
        D_0064B710->f2c(-1,b->value,p);
        D_0064B710->f1c(-1,a->value,buf0);
        D_0064B710->f18(-1,b->value,buf0);
    }
    r=func_0052BDD8(a,b);
    if(r) { b->state=7; r=0xd2f7; }
    return r;
}
