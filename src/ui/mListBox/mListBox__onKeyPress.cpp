typedef int s32;
struct Ev {
    char pad0[0x20];
    s32 u20;
    char pad24[0xC];
    s32 u30;
};
struct Obj {
    char padA[0xEC];
    s32 uEC;
    s32 uF0;
    char padF4[0x30];
    s32 u124;
    char pad128[0xC];
    s32 u134;
    char pad138[0x14];
    s32 u14C;
};
extern "C" s32 mWidget__onKeyPress(Obj *self, s32 arg1, Ev *arg2);
extern "C" s32 mListBox__is_left(Obj *self, s32 key) throw();
extern "C" s32 mListBox__is_right(Obj *self, s32 key) throw();
extern "C" s32 func_002B3BC0(Obj *self, s32 n);
extern "C" s32 func_002B3C88(Obj *self, s32 n);

extern "C" s32 mListBox__onKeyPress(Obj *self, s32 arg1, Ev *ev) {
    s32 r = mWidget__onKeyPress(self, arg1, ev);
    if (r == 0) {
        s32 key = ev->u20;
        if (mListBox__is_left(self, key) != 0 || mListBox__is_right(self, key) != 0) {
            if (ev->u30 == 0) self->u134 = self->u124;
        }
        s32 a = self->u124;
        s32 b = self->u134;
        s32 d = a - b;
        if (d < 0) d = b - a;
        s32 n;
        if (d < 10) n = self->uEC;
        else n = self->uF0;
        s32 moved = 0;
        if (mListBox__is_left(self, key) != 0) moved = func_002B3C88(self, n);
        else if (mListBox__is_right(self, key) != 0) moved = func_002B3BC0(self, n);
        if (moved != 0) {
            r = 1;
            self->u14C = 2;
        } else {
            self->u134 = self->u124;
        }
        if (mListBox__is_left(self, key) != 0 || mListBox__is_right(self, key) != 0) {
            if (ev->u30 != 0) r = 1;
        }
    }
    return r;
}
