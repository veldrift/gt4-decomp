/* compiler: ee-gcc2.96-as2004 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct U64 { u32 lo, hi; } U64;
struct Rec { int state; int pad4; U64 addr; int x10; char pad14[0x38]; char timer[8]; char pad54[0x1A]; u16 id; char pad70[0x42C]; };
struct Obj { int handle; struct Rec *records; char pad8[0x2C]; int active; int pad38; char timer[8]; int flag; char pad48[8]; u32 count; char pad54[0xC]; u32 timeout; };
struct Api { char pad0[0x20]; int (*send)(int,U64,int,void*,int,int*); char pad24[0x40]; int (*poll)(void); };
struct Packet { u16 flags; char data[4]; };
extern struct Api *D_0064B4B0;
extern int func_0052AF10(struct Obj *, struct Rec *);
extern int func_0052B508(struct Obj *);
extern int func_0052B610(struct Obj *);
extern void func_0053A860(void *);
extern void func_0053A878(void *);
extern void func_0053A890(void *,u32 *);
extern void *func_005A48D8(void *,int,u32);
int func_0052A3F8(struct Obj *o) {
    struct Packet packet;
    u32 elapsed;
    int result = 0xD2F2;
    u32 i = 0;
    int out = 0;
    struct Rec *p;
    if (o != 0) {
        p = o->records;
        for (; i < o->count; i++, p++) {
            if (p->state != 0) {
                result = func_0052AF10(o,p);
                if (result != 0) return result;
            }
            if (p->state == 13) {
                char *timer = p->timer;
                func_0053A890(timer,&elapsed);
                if (elapsed >= 5001) {
                    func_005A48D8(&packet,0,6);
                    packet.flags |= p->id & 0x3FF;
                    D_0064B4B0->send(o->handle,p->addr,p->x10,&packet,6,&out);
                    func_0053A878(timer);
                }
            }
        }
        if (o->active != 0) {
            char *timer = o->timer;
            func_0053A890(timer,&elapsed);
            if (elapsed >= o->timeout || o->flag != 0) {
                result = func_0052B508(o);
                if (result != 0) return result;
                func_0053A860(timer);
                o->flag = 0;
            }
        }
        D_0064B4B0->poll();
        result = func_0052B610(o);
    }
    return result;
}
