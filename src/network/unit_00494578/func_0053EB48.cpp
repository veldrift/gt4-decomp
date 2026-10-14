typedef int s32;
struct Inner { char pad0[8]; s32 unk8; char padC[0x206C - 0xC]; s32 unk206C; };
struct Obj { char pad0[0x18]; s32 unk18; char pad1C[0x20]; s32 unk3C; char pad40[4]; Inner *unk44; };
extern "C" s32 func_0053A878(void *) throw();
extern "C" s32 func_0053C2F0(Obj *, const char *, void *) throw();
extern "C" s32 func_0053EF68(Obj *);
extern "C" void func_0057DA20(void *, const char *, ...);
extern "C" s32 func_0053EB48(Obj *arg0, s32 arg1, s32 arg2) {
    s32 r;
    if (arg0 == 0) return 2;
    if (arg0->unk3C != 0) return 0xD6DA;
    if (arg2 == 0) return 2;
    if (func_0053EF68(arg0) != 0) return 0x64;
    arg0->unk44->unk8 = arg1;
    func_0057DA20((char *)arg0->unk44 + 0x2A7C, "<NewRemoteHost></NewRemoteHost><NewExternalPort>%d</NewExternalPort><NewProtocol>UDP</NewProtocol>", arg0->unk18);
    r = func_0053C2F0(arg0, "GetSpecificPortMappingEntry", (char *)arg0->unk44 + 0x2A7C);
    if (r == 0) {
        char *q = (char *)arg0->unk44 + 0x10;
        arg0->unk3C = 8;
        func_0053A878(q);
        arg0->unk44->unk206C = arg2;
    }
    return r;
}
