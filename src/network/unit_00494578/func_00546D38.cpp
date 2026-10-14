/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { char data[0x60]; };
extern Blob D_0064C2E0;
extern "C" int func_005470A8(void *);
extern "C" int func_00546D38(Blob *self) {
 *self = D_0064C2E0;
 return func_005470A8(self->data + 0x54);
}
