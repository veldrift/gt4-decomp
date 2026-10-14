/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Obj;
struct VEntry { s16 delta; s16 index; void (*fn)(void *, s32); };
struct Obj { VEntry *vt; };
struct VT { char data[1]; };

struct Info8 { char pad[8]; s32 *p8; };
struct Info { char pad60[0x60]; Info8 *p60; };
struct Other { char pad[0x80]; s32 i80; };

struct Cam {
    char *vt;
    char pad4[0x138];
    Obj *x13C;
    char pad140[0x9C0 - 0x140];
    char b9C0[0xC40 - 0x9C0];
    Obj *oC40;
    Obj *oC44;
    char padC48[0xC80 - 0xC48];
    char bC80[0xD00 - 0xC80];
    char bD00[0xDD0 - 0xD00];
    char bDD0[0xE28 - 0xDD0];
    char bE28[0xF30 - 0xE28];
    s32 iF30;
    s32 iF34;
};

extern "C" void DevelopCamera__virtual_20(Cam *) throw();
extern "C" void func_003FB430(void *);
extern "C" void CameraSys__CameraControl__init(void *, s32, s32);
extern "C" void func_0036FAE8(void *, s32, s32) throw();
extern "C" void func_003FBAB0(void *, void *, s32, s32);

extern "C" void RacePhotoModeCameraManager__virtual_20(Cam *self, Other *arg) {
    char *s3 = self->bE28;
    DevelopCamera__virtual_20(self);
    func_003FB430(self->b9C0);
    Obj *o1 = self->oC40;
    VEntry *e1 = (VEntry *)((char *)o1->vt + 0x58);
    ((void (*)(void *))e1->fn)((char *)o1 + e1->delta);
    Obj *o2 = self->oC44;
    VEntry *e2 = (VEntry *)((char *)o2->vt + 0x58);
    ((void (*)(void *))e2->fn)((char *)o2 + e2->delta);
    self->x13C = self->oC40;
    func_003FB430(self->bC80);
    CameraSys__CameraControl__init(self->bDD0, 0, 1);
    func_0036FAE8(s3, 0, 0);
    self->iF30 = 0;
    self->iF34 = 0;
    if (arg != 0) {
        Obj *a = self->oC40;
        s32 v = arg->i80;
        VEntry *e3 = (VEntry *)((char *)a->vt + 0x140);
        e3->fn((char *)a + e3->delta, v);
        Obj *b = self->oC44;
        VEntry *e4 = (VEntry *)((char *)b->vt + 0x138);
        e4->fn((char *)b + e4->delta, v);
        func_0036FAE8(s3, v, *((Info *)arg)->p60->p8);
        func_003FBAB0(self->bD00, arg, 0, 0);
    }
}
