extern unsigned char D_0064C0F4;
extern int D_0064C0FC;
extern int D_0064C100;
extern int *D_0064C104;
extern unsigned D_0086B3DC;
extern int D_0086B3D8;
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" int func_0053A598(unsigned index) {
    int r=5;
    if (D_0064C0F4 != 1) return r;
    if (!D_0064C0FC) return r;
    if (!D_0064C100) return r;
    int *base=D_0064C104;
    if (!base) return r;
    r=2;
    if (index >= D_0086B3DC) return r;
    int size=D_0086B3D8;
    func_005A48D8(base+index*size,0,size*4);
    return 0;
}
