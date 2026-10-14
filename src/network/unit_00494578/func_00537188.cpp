typedef unsigned long long u64;
struct P8 { int a,b; };
struct Record { int kind; P8 addr; };
struct Global { int id; char pad4[0x4c]; P8 addr; int active; char pad5c[0x10]; int pending; };
extern "C" Global *D_0064B47C;
extern "C" void *func_00535A18(unsigned int) throw();
extern "C" int func_00535F28(void *, int *) throw();
extern "C" int func_00531C78(void *);
extern "C" int func_00530F98(P8 *) throw();
extern "C" int func_00531F40(int,u64,int,int,int,Record *) throw();
extern "C" int func_00537188(int arg0,int arg1,int arg2,int *arg3) {
    u64 connection;
    Record r;
    int flag = 0;
    if (func_00535F28(func_00535A18(0), &flag) == 0) {
        func_00531C78(&connection);
        Global *g = D_0064B47C;
        int active = g->active;
        if ((active != 0 || flag != 0) && *arg3 == g->id) {
            if (active) r.addr = g->addr;
            else func_00530F98(&r.addr);
            if (flag) r.kind = D_0064B47C->pending;
            else r.kind = D_0064B47C->active;
            func_00531F40(0, connection, 0, 0x14, 0xc, &r);
            return 4;
        } else { return 4; }
    } else { return 4; }
}
