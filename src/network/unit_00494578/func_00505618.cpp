/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef void (*Fn)(void);
typedef void *(*Alloc)(int);
typedef void (*Free)(void *);
typedef void *(*Resize)(void *,int);
typedef void *(*Align)(int,int);
typedef int (*Size)(void *);
typedef void (*Release)(void *,int);
struct Arg { int x0,x4; Alloc x8,xc; Size x10,x14; Free x18,x1c; Resize x20,x24; Align x28,x2c; Release x30,x34; int x38,x3c,x40; };
struct Req { int x0,x4; char p8[0x4c]; int x54,x58; char p5c[0x24]; };
struct Table { char p0[0xc]; Alloc xc; Free x10; Resize x14; Align x18; char p1c[0x10]; Size x2c; Release x30; };
extern short D_0064A164;
extern int D_0064A154,D_0064A168;
extern Table D_008A0120,D_008A0158;
extern char D_006C1260[];
extern "C" int func_0052E510(Req *);
extern "C" int func_0052E568(Req *,void *);
extern "C" void func_00504630(int) throw();
extern "C" int func_0053A228(unsigned,unsigned,Fn);
extern "C" int func_0057D9C0(const char *,...);
extern "C" void func_00504EC8(void);
extern "C" void func_00504F00(void);
extern "C" void func_00504F60(void);
extern "C" void func_00504C30(void);
extern "C" void func_00504D48(void);
extern "C" void func_00504E90(void);
extern "C" void func_00504D10(void);
extern "C" void func_00504CA0(void);
extern "C" void func_00504CD8(void);
extern "C" void func_00504FD0(void);
extern "C" void func_00504F98(void);
extern "C" void func_00504C68(void);
extern "C" void func_00505008(void);
extern "C" int func_00505618(volatile Arg *a,int *out) {
    Req req; char result[32]; int r=0;int e=0;
    if(D_0064A164==1) {*out=-6;return -18;}
    func_0052E510(&req);
    req.x54=a->x0;D_0064A154=a->x38;req.x4=a->x3c;req.x58=a->x40;
    if(a->x4==1) {D_0064A168=1;e=func_0052E568(&req,result);}
    else D_0064A168=0;
    func_00504630(0);
    if(e==0) {
    r=func_0053A228(2,3,func_00504EC8);
    if(r==0) {
    r=func_0053A228(4,3,func_00504F00);
    if(r==0) {
    r=func_0053A228(6,3,func_00504F60);
    if(r==0) {
    r=func_0053A228(7,3,func_00504C30);
    if(r==0) {
    r=func_0053A228(9,3,func_00504D48);
    if(r==0) {
    r=func_0053A228(11,3,func_00504E90);
    if(r==0) {
    r=func_0053A228(13,3,func_00504D10);
    if(r==0) {
    r=func_0053A228(16,3,func_00504CA0);
    if(r==0) {
    r=func_0053A228(18,3,func_00504CD8);
    if(r==0) {
    r=func_0053A228(21,3,func_00504FD0);
    if(r==0) {
    r=func_0053A228(23,3,func_00504F98);
    if(r==0) {
    r=func_0053A228(24,3,func_00504C68);
    if(r==0) {
    r=func_0053A228(26,3,func_00505008);
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    Table *t=&D_008A0120; Table *u=&D_008A0158;
    t->xc=((Arg *)a)->xc;
    Alloc ua=a->x8;
    Size ts=a->x14,us=a->x10;
    t->x2c=ts;
    Free uf=a->x18,tf=a->x1c;
    Resize ur=a->x20;
    t->x10=tf;
    Align ul=a->x28;
    Resize tr=a->x24;
    Release ud=a->x30;
    t->x14=tr;u->x30=ud;
    t->x18=a->x2c;u->xc=ua;u->x2c=us;
    t->x30=a->x34;u->x14=ur;u->x18=ul;u->x10=uf;
    if(r==0 && e==0) {*out=0;D_0064A164=1;return 0;}
    func_0057D9C0(D_006C1260,0);*out=-6;return -6;
}
