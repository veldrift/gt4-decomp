/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; void *(*fn)(void *, int); };
struct Obj { char pad[0x64]; char *vtbl; };
extern "C" char D_00645570[];
extern "C" void RaceBase__initializeCamera(Obj *);
extern "C" int func_004F9E60(char *, int);
extern "C" int func_004F9EC0(char *, int);
extern "C" void CameraSys__CameraManager__setTargetCar(void *, int);
extern "C" void RaceNetBattle__virtual_46(Obj *self) {
    RaceBase__initializeCamera(self);
    VEntry *e = (VEntry *)(self->vtbl + 0xd0);
    void *camera = e->fn((char *)self + e->delta, 0);
    CameraSys__CameraManager__setTargetCar(camera, func_004F9EC0(D_00645570, func_004F9E60(D_00645570, *(int *)(D_00645570 + 0xcc4))));
}
