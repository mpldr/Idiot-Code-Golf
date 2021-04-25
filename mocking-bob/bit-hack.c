double P=3.141592653;//Nothing-up-my-sleeve!
main(int n,char**v){char*c=v[1];while(*c)putchar((*(int*)&P>>(*c&31)&1)<<5^*c++);}
