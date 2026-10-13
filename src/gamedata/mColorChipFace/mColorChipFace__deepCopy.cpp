typedef int s32;

struct Entry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Obj {
    char pad0[4];
    Entry *vtable;
};

struct Rep { s32 len, cap, ref, sel; };
struct Str { char *p; };

extern char mColorChipFace__tf[];
extern char hObject__tf[];
extern "C" void mWidget__deepCopy(void *, void *);
extern "C" void *GT4MC__FileGT4GameData__loadInstance(s32, void *, s32, void *, void *, void *);
extern "C" void func_0015A220(char *, Str *, s32);

extern "C" void mColorChipFace__deepCopy(void *self, void *src) {
    mWidget__deepCopy(self, src);
    void *copy = 0;
    if (src != 0) {
        Obj *source = (Obj *)src;
        Entry *entry = source->vtable;
        copy = GT4MC__FileGT4GameData__loadInstance((s32)entry->fn, mColorChipFace__tf, 0,
                             (char *)src + entry->delta, hObject__tf, src);
    }
    if (copy != 0) {
        for (s32 i = 0; i < 2; ++i) {
            func_0015A220((char *)self, (Str *)((char *)copy + 0xA0 + i * 4), i);
        }
    }
}
