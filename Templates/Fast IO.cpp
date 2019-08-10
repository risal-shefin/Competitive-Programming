//#define gc getchar_unlocked
#define gc getchar   // for windows
inline void read_int(int &x)

{
    x=0;
    register char c=gc();
    for(;c<'0' || c>'9';c=gc());
    for(;c>='0' && c<='9';c=gc())
    x=(x<<3)+(x<<1)+(c-'0');
}

//#define pc(x) putchar_unlocked(x);
#define pc(x) putchar(x);  // for windows
inline void writeInt (int n)
{
    register int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
    pc('\n');
}
