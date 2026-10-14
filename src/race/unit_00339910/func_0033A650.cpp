typedef int s32;
typedef unsigned int u32;

struct Strm { s32 unk0; u32 unk4; u32 unk8; };
struct A2E4 { char b[0x2E4]; };
struct AE20 { char b[0xE20]; };

extern char D_0069F2F0[];
extern "C" void func_0045B620(void *, void *);
extern "C" s32 func_0033A488(void *, void *, void *) throw();
extern "C" void func_003E7538(void *);
extern "C" void func_003C2070(void *);
extern "C" s32 func_0033A610(void *, void *, void *) throw();
extern "C" s32 func_0045B348(void *, void *);
extern "C" s32 func_0045A3F8(void *, void *, void *);
extern "C" void func_00339E40(void *, void *, void *, void *) throw();
extern "C" void func_0033A4F8(void *, void *, void *, s32) throw();
extern "C" void func_0045B740(void *, void *);
extern "C" void func_0045B678(void *, void *);
extern "C" void func_0033A560(void *, void *, void *) throw();
extern "C" void func_0033A5B8(void *, void *, void *) throw();

extern "C" s32 func_0033A650(Strm *arg0, char *arg1, A2E4 *arg2, void *arg3, AE20 *arg4, AE20 *arg5) {
    s32 buf0[4];
    s32 buf1[4];
    char *p5 = arg1 + 0x31D0;
    s32 i = 0;
    char *pf = arg1 + 0x3238;
    func_0045B620(buf0, arg0);
    func_0033A488(arg0, buf0, arg3);
    func_003E7538(p5);
    func_003C2070(pf);
    func_0033A610(buf1, arg0, buf0);
    while (func_0045B348(buf1, D_0069F2F0)) {
        func_0045A3F8(arg0, buf1, arg2++);
        func_00339E40(arg0, buf1, arg4++, arg5);
        arg5++;
        func_0033A4F8(arg0, buf1, p5, i);
        i++;
        func_0045B740(buf1, arg0);
        func_0045B678(buf1, arg0);
    }
    func_0033A560(arg0, buf0, arg1 + 0x35E8);
    func_0033A5B8(arg0, buf0, pf);
    func_0045B740(buf0, arg0);
    u32 v_unk8 = arg0->unk8;
    s32 r = arg0->unk4 >= v_unk8 ? (s32)arg0 : 0;
    return r != 0;
}
