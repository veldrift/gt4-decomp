struct Obj { char pad0[0x10]; int f10; char pad14[8]; int f1C; };
struct Ref { int p; };
#define RP ((Obj *)r.p)
struct G { char pad0[4]; int prev; int mode; char padC[0xA5C - 0xC]; int busy; };

struct GPtr { int p; };
extern "C" GPtr D_00622F4C;
extern "C" int D_00620200;
extern "C" char D_00645440[];
extern "C" char D_00645570[];

extern "C" void func_0010C0C0(void);
extern "C" void func_001DC8F0(Ref *r);
extern "C" void func_001DC5F8(void *r, int flags);
extern "C" void func_004F0848(void *self);
extern "C" void func_004F0028(void);
extern "C" void func_004EF278(void *s, int a);
extern "C" void func_004EF1F0(void *s);
extern "C" void func_004F0098(void);
extern "C" void func_00107F68(void);
extern "C" void func_00107FD8(void);
extern "C" void *memset(void *d, int c, unsigned n) __asm__("func_005A48D8");
extern "C" void func_00329F50(char *d, int n, const char *s);
extern "C" void func_0042FBB0(G *g, const char *s);
extern "C" void func_0042FC50(G *g, const char *s);
extern "C" void func_0035F7C8(void);
extern "C" int func_0010B290(void *a, int b);
extern "C" void func_0010BE20(void);
extern "C" void func_0010CA50(G *g, const char *s);
extern "C" int func_00436640(void *s);
extern "C" int func_00436740(void *s);
extern "C" void func_001C79A8(void);
extern "C" void func_001C7A88(void);

extern "C" void func_00113B48(void);
extern "C" void func_00118EF0(void);
extern "C" void func_00115A90(void);
extern "C" void func_00116E20(void);
extern "C" void func_001181C8(void);
extern "C" void func_0010FBD8(void);
extern "C" void func_0011BB60(void);
extern "C" void func_0011ABE0(void);
extern "C" void func_00111498(void);
extern "C" void func_00112620(void);
extern "C" void func_0010C0E8(void);
extern "C" void func_0010D2E0(void);
extern "C" void func_0010ED60(void);
extern "C" void func_0010D520(void);
extern "C" void func_0010D080(void);
extern "C" void func_0010BB80(void);

static inline void setMode(G *g, int next) {
    int m = g->mode;
    g->mode = next;
    g->prev = m;
}

static inline void runMode(G *g, void (*fn)(void)) {
    g->busy = 1;
    D_00620200 = 0;
    fn();
    g->prev = g->mode;
    g->mode = 1;
    g->busy = 0;
}

static inline void runScene(G *g, void (*fn)(void)) {
    g->busy = 1;
    D_00620200 = 0;
    func_00436640((void *)(D_00622F4C.p + 0x38CB0));
    fn();
    func_00436740((void *)(D_00622F4C.p + 0x38CB0));
    g->prev = g->mode;
    g->mode = 1;
    g->busy = 0;
}

static inline void runOnce(G *g, void (*fn)(void)) {
    g->busy = 1;
    D_00620200 = 0;
    fn();
    g->busy = 0;
    g->prev = 1;
    g->mode = 1;
}

extern "C" void func_00108040(void) {
    func_0010C0C0();
    for (;;) {
        Ref r;
        func_001DC8F0(&r);
        if (RP->f1C != 0) {
            func_004F0848(D_00645570);
            RP->f1C = 0;
            RP->f10 = 0;
        }
        if (RP->f10 != 0) {
            func_004F0028();
            func_004EF278(D_00645440, 0);
        } else {
            func_004EF1F0(D_00645440);
            func_004F0098();
        }
        func_001DC5F8(&r, 2);
        G *g = (G *)(D_00622F4C.p + 0x3A368);
        unsigned mode = g->mode;
        g->busy = 0;
        if (mode == 1) {
            func_00107F68();
        } else {
            func_00107FD8();
        }
        switch (mode) {
        case 0: {
            char seq[64] = "menu";
            func_00329F50(seq, 64, "StartSequence");
            func_0042FBB0(g, seq);
            char prj[64] = "err";
            func_00329F50(prj, 64, "StartProject");
            func_0042FC50(g, prj);
            func_0035F7C8();
            break;
        }
        case 1:
            func_0010B290((char *)g + 0x54, 0);
            break;
        case 2: runMode(g, func_00113B48); break;
        case 3: runMode(g, func_00118EF0); break;
        case 4: runMode(g, func_00115A90); break;
        case 5: runMode(g, func_00116E20); break;
        case 6: runMode(g, func_001181C8); break;
        case 7: runMode(g, func_0010FBD8); break;
        case 8: runMode(g, func_0011BB60); break;
        case 9: runMode(g, func_0011ABE0); break;
        case 10: runMode(g, func_00111498); break;
        case 11:
            runOnce(g, func_00112620);
            if (*(unsigned *)(D_00622F4C.p + 0x3A43C) <= 0x157529FE)
                func_0042FC50(g, "ranking");
            break;
        case 12: runOnce(g, func_0010C0E8); break;
        case 13: runScene(g, func_0010D2E0); break;
        case 14: runScene(g, func_0010ED60); break;
        case 15: runScene(g, func_0010D520); break;
        case 16: runScene(g, func_0010D080); break;
        case 17:
            func_0010BE20();
            setMode(g, 1);
            break;
        case 18: func_0010CA50(g, "MODE_LOAD_REPLAY"); break;
        case 19: func_0010CA50(g, "MODE_DEMONSTRATION"); break;
        case 20: runScene(g, func_0010BB80); break;
        case 21: func_001C79A8(); break;
        case 22: func_001C7A88(); break;
        case 23: break;
        }
    }
}
