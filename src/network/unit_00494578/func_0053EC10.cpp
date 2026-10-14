typedef int s32;
struct Inner { char pad0[8]; s32 unk8; char padC[0x2070 - 0xC]; s32 unk2070; };
struct Obj { char pad0[0x18]; s32 unk18; char pad1C[0x20]; s32 unk3C; s32 unk40; Inner *unk44; };
extern "C" s32 func_0053A878(void *) throw();
extern "C" s32 func_0053C2F0(Obj *, const char *, void *) throw();
extern "C" s32 func_0053EF68(Obj *);
extern "C" void func_0057DA20(void *, const char *, ...);
static inline void start(Obj *arg0, s32 arg2) {
    arg0->unk3C = 9;
    func_0053A878((char *)arg0->unk44 + 0x10);
    arg0->unk44->unk2070 = arg2;
}
extern "C" s32 func_0053EC10(Obj *arg0, s32 arg1, s32 arg2) {
    s32 r = 0;
    if (arg0 == 0) return 2;
    if (arg0->unk3C != 0) return 0xD6DA;
    if (arg2 == 0) return 2;
    if (func_0053EF68(arg0) != 0) return 0x64;
    if (arg0->unk40 != 0) {
        arg0->unk44->unk8 = arg1;
        func_0057DA20((char *)arg0->unk44 + 0x2A7C, "<NewRemoteHost></NewRemoteHost><NewExternalPort>%d</NewExternalPort><NewProtocol>UDP</NewProtocol>", arg0->unk18);
        r = func_0053C2F0(arg0, "DeletePortMapping", (char *)arg0->unk44 + 0x2A7C);
        if (r != 0) goto done;
        start(arg0, arg2);
    } else {
        start(arg0, arg2);
    }
done:
    return r;
}
