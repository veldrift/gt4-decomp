/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { long words[0x810 / 8]; };
extern int D_006464DC;
extern "C" void func_00437B10(Blob *, int);
extern "C" void RaceLanBattle__virtual_102(char *self) {
    Blob tmp;
    int id = D_006464DC;
    func_00437B10(&tmp, id ? id : 0x12345678);
    *(Blob *)(self + 0xd150) = tmp;
}
