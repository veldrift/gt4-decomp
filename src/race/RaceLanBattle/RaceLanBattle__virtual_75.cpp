/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; void *fn; };
struct Mat { union { long q[8]; float f[16]; }; };
struct In { short a,b,c,d,e,f; };
struct Dst { VEntry *vt; char pad[0xA3C]; Mat m; };
struct Self { char pad0[0x64]; VEntry *vt; char pad1[0xE440-0x68]; int flag; char pad2[0xF364-0xE444]; In in; };
extern "C" void func_001025E8(Mat *, In *);
extern "C" void RaceLanBattle__virtual_75(Self *self) {
    VEntry *e = self->vt + 26;
    Dst *d = ((Dst *(*)(void *, int))e->fn)((char *)self + e->delta, 0);
    VEntry *f = d->vt + 36;
    ((int (*)(void *))f->fn)((char *)d + f->delta);
    Mat m;
    if (self->flag) {
        In *in = &self->in;
        in->c = 0; in->b = 0; in->a = 0; in->f = 0; in->e = 0; in->d = 0;
    }
    func_001025E8(&m, &self->in);
    float *p = &m.f[12];
    *p += 0.0f;
    d->m = m;
}
