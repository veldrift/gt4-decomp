typedef int s32;
typedef float f32;

struct Rep;
extern "C" char *func_005C2560(Rep *src) throw();
struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
    char *data() { return (char *)(this + 1); }
    char *grab() {
        if (sel)
            return func_005C2560(this);
        ++ref;
        return data();
    }
};

extern Rep D_00659FA8;
struct Str {
    char *dat;
    Str() : dat(D_00659FA8.grab()) {}
};
inline void *operator new(unsigned int, void *p) { return p; }
extern char mListBox__vtable[];
extern "C" void mScrollable__structor_0(void *);
extern "C" int func_002FA120(void *);
extern "C" void func_00268418(void *, s32);

#define F(off, T) (*(T *)((char *)self + (off)))

extern "C" void mListBox__structor_0(char *self) {
    s32 pad[4];
    mScrollable__structor_0(self);
    F(0x4, char *) = mListBox__vtable;
    F(0xBC, s32) = 0;
    F(0xC0, f32) = 16.0f;
    F(0xC4, f32) = 16.0f;
    {
        s32 i = 1;
        s32 *v = (s32 *)(self + 0xC8);
        for (; i != -1; --i, v += 4) {
            v[1] = 0;
            v[2] = 0;
            v[3] = 0;
        }
    }
    F(0xE8, s32) = 0;
    F(0xEC, s32) = 1;
    F(0xF0, s32) = 1;
    F(0x108, s32) = 1;
    F(0xF4, f32) = 0x1.999998p-3f;
    F(0xF8, f32) = 1.0f;
    F(0xFC, f32) = 0.5f;
    F(0x100, s32) = 0;
    F(0x104, s32) = 0;
    F(0x10C, s32) = 0;
    func_002FA120(self + 0x110);
    func_002FA120(self + 0x114);
    func_002FA120(self + 0x118);
    F(0x11C, s32) = 0;
    F(0x120, s32) = 0;
    F(0x124, s32) = -1;
    F(0x128, s32) = -1;
    F(0x12C, s32) = -1;
    F(0x130, s32) = -1;
    F(0x134, s32) = -1;
    F(0x13C, s32) = 0;
    F(0x140, s32) = -1;
    F(0x144, s32) = 0;
    F(0x148, s32) = -1;
    F(0x14C, s32) = 0;
    F(0x150, s32) = 0;
    new (self + 0x154) Str();
    func_00268418(self, 0);
}
