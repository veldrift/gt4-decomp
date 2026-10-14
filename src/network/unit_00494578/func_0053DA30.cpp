/* compiler: ee-gcc2.96-as2004 */
typedef unsigned long long U __attribute__((aligned(4)));
struct Obj { int h; char pad[0x18]; U id; int arg; int gap; char timer[12]; int active; };
struct API { char pad[0x20]; void (*send)(int,U,int,void*,int,int*); };
extern API *D_0064B4B0;
extern "C" int func_0053A890(void *,unsigned *) throw();
extern "C" void func_0053A878(void *) throw();
extern "C" int func_0053DA30(Obj *o) {
    char packet[16]; unsigned time; int flag = 0;
    void *timer = o->timer;
    if (o->active) {
        func_0053A890(timer,&time);
        if (time >= 5001U) {
            packet[3] = (char)0xd4;
            D_0064B4B0->send(o->h,o->id,o->arg,packet,4,&flag);
            func_0053A878(timer);
        }
    }
    return 0;
}
