extern "C" int func_004C92D8(const unsigned char*a,const unsigned char*b,unsigned int n){
 if(n==0)return 0;
 do{
 if(*a!=*b++)return (int)(unsigned char)*a-(int)(unsigned char)b[-1];
 if(!*a++)break;
 }while(--n);
 return 0;
}
