extern int D_0064B450;
extern char D_00863EC0[];
extern int D_00863F00[];
extern int func_00522480(void *);
extern int func_0056F568(void *,int *,int,int,int *,int);
extern void *func_005A48D8(void *,int,unsigned int);
int func_00523510(int *out) {
    int buf[4];
    if(D_0064B450<0) return 0xC350;
    func_005A48D8(buf,0,16);
    if(func_0056F568(D_00863EC0,D_00863F00,D_0064B450,11,buf,16)!=0) return 0xC350;
    *out=func_00522480(buf);
    return 0;
}
