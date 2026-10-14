struct Block { char data[0x700]; };
struct Source { Block blocks[2]; char pad[0x10]; int index; };
struct Entry { short delta, index; int (*fn)(void *, float); };
struct Target { char pad[0x7dc]; Entry *vt; };
extern "C" void *func_003B05A8(void *);
extern "C" void *func_003B05B8(void *, void *);
extern "C" void func_003B0630(void *, void *, void *, float);
extern "C" void func_003B0940(void *, void *, void *);
extern "C" int func_0033B718(Source *self, Target *out, float t) {
    char temp[0x60];
    int one = 1;
    int i = self->index;
    func_003B0940((char *)out + 0x10, self->blocks[i].data + 0x10, self->blocks[one-i].data + 0x10);
    func_003B05A8(temp);
    int j = self->index;
    one -= j;
    func_003B0630(temp, self->blocks[j].data + 0x6b0, self->blocks[one].data + 0x6b0, t);
    func_003B05B8((char *)out + 0x7e0, temp);
    Entry *e = (Entry *)((char *)out->vt + 0x10);
    return e->fn((char *)out + e->delta, 0.0f);
}
