/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0055C398(int,int,int,float);
extern "C" void func_00462D30(int channel,float volume){
 float scaled=volume*16383.0f;
 func_0055C398((int)scaled,channel,0,scaled);
}
