/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Record {
    float f0, f4, f8;
    float c0[4], c1[4];
    float f2c, f30, f34, f38, f3c;
    float c2[4];
    u8 enabled; u8 pad51[3];
    float f54, f58, f5c, f60;
    float f64, f68, f6c;
    float f70, f74;
    u8 b78, b79, b7a, b7b, b7c; u8 pad7d[3];
    float f80[3], f8c, f90, f94, f98, f9c, fa0;
    char tail[12];
};
extern Record D_008436B0[3];
extern u8 D_0062218C[3][32];
extern u8 D_00622110[];
extern float D_00620264, D_0062025C;
extern "C" void func_0035A818(float *, int, int);
extern "C" int func_00359A38(char *, int, float *, float *, u8 *, u8 *);
extern "C" void func_00353938(void) {
    for(int i=0;i<3;i++) {
        u8 *p = D_0062218C[i];
        D_008436B0[i].f4 = p[0]*0.02f;
        D_008436B0[i].f8 = p[20]*0.02f;
        D_008436B0[i].f0 = p[3]*0.1f;
        func_0035A818(D_008436B0[i].c0,p[1],p[2]);
        func_0035A818(D_008436B0[i].c1,p[21],p[22]);
        D_008436B0[i].f2c = p[5]*0.01f*0.000244140625f;
        D_008436B0[i].f34 = p[7]*0.0017453289f;
        if(p[6]==0) D_008436B0[i].f30=0.0f;
        else D_008436B0[i].f30=p[6]*0.01f/D_008436B0[i].f34;
        D_008436B0[i].f38=p[16]*0.01f;
        D_008436B0[i].f3c=(signed char)p[17]*0.01f/0x1.1df468p-6f;
        func_0035A818(D_008436B0[i].c2,p[18],p[19]);
        D_008436B0[i].enabled=0;
        int a=p[10], b=p[11], c=p[12];
        if(a+b!=0 && c!=0) {
            float x=a,y=b,sum=x+y;
            D_008436B0[i].f54=x/sum;
            D_008436B0[i].f58=y/sum;
            D_008436B0[i].f5c=1.0f/(c*0x1.1df468p-6f);
            D_008436B0[i].f60=p[13]/sum;
            D_008436B0[i].enabled=1;
        }
        D_008436B0[i].f64=D_00622110[0x74]/100.0f;
        D_008436B0[i].f68=8.0f/D_0062025C;
        D_008436B0[i].f6c=8.0f/D_00620264;
        if(D_00622110[0x7a]==0) {
            D_008436B0[i].f70=0.0f;
            D_008436B0[i].b78=D_00622110[0x75];
        } else {
            D_008436B0[i].f70=D_00622110[0x75]*2.55f;
            D_008436B0[i].b78=0;
        }
        D_008436B0[i].f74=D_00622110[0x76]*2.55f;
        D_008436B0[i].b79=D_00622110[0x77];
        D_008436B0[i].b7a=D_00622110[0x78];
        D_008436B0[i].b7b=D_00622110[0x79];
        D_008436B0[i].b7c=p[23];
        for(int j=0;j<3;j++) D_008436B0[i].f80[j]=p[24+j]*0.01f;
        float rate=200.0f;
        if(i!=0) rate=900.0f;
        rate*=60.0f;
        D_008436B0[i].f98=0.0f;
        D_008436B0[i].f94=p[28]*0.01f;
        D_008436B0[i].f90=p[27]*0.01f;
        D_008436B0[i].f8c=1.0f;
        D_008436B0[i].fa0=(p[30]*10)*8192.0f/rate;
        D_008436B0[i].f9c=(p[29]*10)*8192.0f/rate;
        func_00359A38(D_008436B0[i].tail,3,&D_008436B0[i].f98,&D_008436B0[i].f8c,0,0);
    }
}
