typedef int s32;
struct Demo { s32 state; char sub[0x20]; char name[0x20]; s32 f44; char p[8]; s32 f50; };
extern char *D_00622F4C;
extern "C" {
void GranTurismo4__LoadingMode(const char *) throw();
s32 func_0010B290(void *, s32) throw();
s32 func_0010BA28(void *, s32, s32, s32) throw();
s32 func_0010BBB0(void *, s32, s32, s32) throw();
void func_0042FC50(void *, void *);
void func_0042FC98(void *, void *);
void func_00434638(void *);
s32 GranTurismo4__Demonstration__next(void *);
s32 func_004349A8(void *, void *);
s32 func_00434918(void *, s32);
s32 func_00436640(void *);
s32 func_00436740(void *);
s32 func_00579358();
s32 func_0057F238(void *, const char *);
s32 func_005A2F88(void *);
char *func_005A609C(char *, char *);
}
extern "C" void func_0010BE20() {
    char buf[0x20];
    char buf2[0x40];
    func_005A609C(buf, D_00622F4C + 0x3A3BC);
    Demo *demo = (Demo *)(D_00622F4C + 0x3B018);
    func_00434638(demo);
    s32 k = (unsigned)(func_00579358() & 0xF) / 5;
    if (k >= 3) k = 2;
    s32 more;
    do {
        k++;
        s32 last;
        if (k >= 3) k = 0;
        last = k == 2;
        more = GranTurismo4__Demonstration__next(demo);
        switch (demo->state) {
        case 1:
        case 3: {
            func_00436640(D_00622F4C + 0x38CB0);
            s32 s1 = func_004349A8(demo, buf2);
            if (s1 != 0) {
                if (func_0010BBB0(buf2, -1, 1, last) == 0) more = 0;
                else if (s1 < demo->f50) more = 0;
            } else {
                switch (demo->state) {
                case 1:
                    if (func_0010BA28(demo->sub, demo->f44, 1, last) == 0) more = 0;
                    break;
                case 3:
                    if (func_0010BBB0(demo->sub, demo->f44, 0, last) == 0) more = 0;
                    break;
                default:
                    break;
                }
            }
            break;
        }
        case 2:
            if (func_00436740(D_00622F4C + 0x38CB0)) GranTurismo4__LoadingMode("black fade in");
            func_0042FC98(D_00622F4C + 0x3A368, demo->name);
            func_0010B290(demo->sub, 0);
            if (func_0057F238(D_00622F4C + 0x3A41C, "terminate") == 0) more = 0;
            break;
        case 4:
            if (func_00434918(demo, func_005A2F88(demo->name)) == 0) {
                if (func_0010BBB0(demo->sub, demo->f44, 0, last) == 0) more = 0;
            }
            break;
        case 0:
        default:
            break;
        }
    } while (more);
    if (func_00436740(D_00622F4C + 0x38CB0)) GranTurismo4__LoadingMode("black fade in");
    func_0042FC50(D_00622F4C + 0x3A368, buf);
}
