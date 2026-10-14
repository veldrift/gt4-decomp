/* compiler: ee-gcc2.96-as2004 */
typedef unsigned long u64 __attribute__((aligned(4)));
typedef unsigned short u16;
struct Packet { char pad0[8]; u64 data8; int data10; char pad14[0x5A]; u16 data6E; };
struct Ops { char pad[0x20]; int (*send)(int, u64, int, void *, int, int *); };
extern Ops *D_0064B4B0;
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_0052CC10(int *o, Packet *p) {
    char buf[6];
    int result = 0;
    func_005A48D8(buf, 0, 6);
    *(u16 *)buf = (p->data6E & 0x3FF) | 0x1000;
    D_0064B4B0->send(*o, p->data8, p->data10, buf, 6, &result);
    return 0;
}
