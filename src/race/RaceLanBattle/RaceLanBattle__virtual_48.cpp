/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { short delta,index; void *(*fn)(void *, int); };
struct Obj { char p[0x64]; V *vt; char q[0xe440-0x68]; int mode; int id; };
struct Info { char p[0x18]; int mount; char q[0x14]; };
extern "C" int func_00336C70(int, Info *) throw();
extern "C" int RaceBase__getCameraMountModeFromOption(int);
extern "C" void CameraSys__CameraManager__initOptionInfo_mount(void *, int, int);
extern "C" void RaceLanBattle__virtual_48(Obj *self) {
    Info info;
    if (self->mode == 0 && func_00336C70(self->id, &info)) {
        V *e = self->vt + 0xd0/8;
        void *cam = e->fn((char *)self + e->delta, 0);
        CameraSys__CameraManager__initOptionInfo_mount(cam, 0, RaceBase__getCameraMountModeFromOption(info.mount));
    }
}
