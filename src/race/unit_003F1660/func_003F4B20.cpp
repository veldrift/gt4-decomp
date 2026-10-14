/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0034C190(char *,int);
extern "C" void func_003F4B20(char *self) {
 int i=0;
 if(*(int *)(self+0xf8a0)>0) {
 char *out=self+0xdecc;
 do {
 char *car=(char *)func_0034C190(self,i);
 int j=0;
 char *src=car+0x104;
 float *src2=(float *)(car+0x648);
 float *dst2=(float *)(out+12);
 do {
 int k=j*4; j++;
 *(float *)(out+k)=*(float *)(src+k);
 float f=*src2++;
 *(float *)((char *)dst2+k)=f;
 } while(j<3);
 i++;
 *(float *)(out+0x20)=*(float *)(src+0x570);
 *(float *)(out+0x2c)=*(float *)(src+0x57c);
 *(float *)(out+0x1c)=*(float *)(src+0x56c);
 *(float *)(out+0x28)=*(float *)(src+0x584);
 *(float *)(out+0x18)=*(float *)(src+0x568);
 *(float *)(out+0x24)=*(float *)(src+0x580);
 *(int *)(out+0x30)=*(int *)(src+0x4a8);
 out+=0x4f0;
 } while(i<*(int *)(self+0xf8a0));
 }
}
