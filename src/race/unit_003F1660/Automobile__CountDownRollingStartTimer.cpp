/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x694]; short timer; };
extern "C" int Automobile__CountDownRollingStartTimer(Obj *o) {
    int n = o->timer;
    unsigned int u = (unsigned short)o->timer;
    if (n <= 0) return 0;
    int t = u - 1;
    o->timer = t;
    return (t << 16) == 0;
}
