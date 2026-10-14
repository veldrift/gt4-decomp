struct Event { void *obj; int a,b,c,d; };
struct Obj { char p[0x12c]; int (*cb)(Event *); int data; char q[0x10]; int status; char r[0x34]; unsigned char active; char s[3]; char time[1]; };
extern "C" Obj *func_00535A18(unsigned int) throw();
extern "C" int func_00535A48(Obj *) throw();
extern "C" void func_0053A890(void *, unsigned int *);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_005364A0() {
    Event e;
    unsigned int time[4];
    for (unsigned int i=0; i<4; i++) {
        Obj *o = func_00535A18(i);
        if (o && o->active) {
            func_0053A890(o->time, time);
            if (time[0] >= 501) {
                func_005A48D8(&e, 0, 20);
                Obj *first = func_00535A18(0);
                o->status = 0;
                int data = o->data;
                e.obj = first;
                e.d = data;
                e.a = 0;
                e.b = 0;
                e.c = 0;
                o->cb(&e);
                o->active = 0;
                func_00535A48(o);
            }
        }
    }
    return 0;
}
