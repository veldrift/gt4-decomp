/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Table {u8 ranges[8][2];};
extern "C" Table D_00622320;
extern "C" void func_003F3278(char *self,int index,float x) {
    float *out=(float *)(self+0x10dc);
    if(index<0) index=0;
    else if(index>=4) index=3;
    int dir=1;
    if(!(*(float *)(self+0x230)>0.0f)) dir=0;
    int k=index*2+dir;
    float low=D_00622320.ranges[k][0]*10;
    float high=D_00622320.ranges[k][1]*10;
    if(x<low) {*out=0.0f;return;}
    if(high<=x) {*out=0.75f;return;}
    *out=((x-low)*0.5f)/(high-low)+0.25f;
}
