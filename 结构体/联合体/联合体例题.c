int main() {
    union Data {
        struct {
            int x;
            int y;
        } s;
        int x;
        int y;
    } d;
    d.x = 1;
    d.y = 2;
    d.s.x = d.x * d.x;
    d.s.y = d.y + d.y;
    printf("%d %d\n", d.s.x, d.s.y);
    return 0;
}
/*d.x=1；///d.x=d.y=d.s.x=1; 
 
  d.y=2;///d.x=d.y=d.s.x=2;
 
  d.s.x=d.x*d.x;///d.x=d.y=d.s.x=2*2=4;  
 
  d.s.y=d.y*d.y;///d.x=d.y=d.s.x=4+4=8; */
 