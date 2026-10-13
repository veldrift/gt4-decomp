/* RaceDisplay__virtual_38 (RaceDisplay__virtual_38). */
typedef int s32;
typedef unsigned char u8;

struct Obj {
    s32 f0;
    s32 f4;
    char pad[0x2F];
    u8 f37;
};

struct Ev {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
};

extern "C" s32 RaceDisplay__is_play_mode(Obj *arg0);
extern "C" void *RaceDisplayInformationEvent__structor_0(Ev *arg0);
extern "C" void RaceDisplayEventBase__put(Ev *o, s32 t);

extern "C" void RaceDisplay__virtual_38(Obj *arg0) {
    if (RaceDisplay__is_play_mode(arg0) != 0) {
        if (arg0->f37 != 0) {
            Ev ev;
            RaceDisplayInformationEvent__structor_0(&ev);
            ev.f8 = 4;
            s32 t = arg0->f4;
            ev.f0 = 0;
            RaceDisplayEventBase__put(&ev, t);
        }
    }
}
