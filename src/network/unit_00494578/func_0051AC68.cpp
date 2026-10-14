typedef unsigned char u8;
struct Obj { char pad[0x104]; int index; };
struct Entry { u8 state,b1,active,slot,pending,ready; char pad[0xa]; int value,other; char rest[0x14]; char sub[4]; };
struct Global { char pad[0xA5B8]; int (*callbacks[16])(int,u8); int flags[16]; };
extern Global *D_0064B4B4;
extern "C" Entry *func_00515EE8(u8);
extern "C" int func_00515F98(int *,Obj *) throw();
extern "C" void func_00531738(int *);
extern "C" int func_00538068(void *);
extern "C" int func_0051AC68(Obj *o,int unused,int arg2,u8 *msg) {
    int out=0x100;
    if (!o) return -1;
    Entry *e=func_00515EE8(*msg);
    if (!e) return 1;
    if (e->state==2) {
        int (*cb)(int,u8)=D_0064B4B4->callbacks[e->slot];
        if (cb) cb(arg2,*msg);
        func_00515F98(&out,o);
        if (o->index==out && e->ready && D_0064B4B4->flags[e->slot]) {
            e->pending=1;
        } else {
            e->state=1;
            if (e->active) {
                int *p=&e->value;
                func_00531738(p);
                func_00538068(e->sub);
                *p=0;
                e->other=0;
            }
        }
    }
    return 1;
}
