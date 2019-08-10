/*

  AUTHOR: MD. HASINUR RAHMAN, RUET'15
  Tested problem: Codechef -> XORMIN
*/
#define lim 200010
/// NODE =  trie nodes
struct NODE
{
    LL f,num;
    NODE *nxt[2];
    NODE()
    {
        f = num = 0;
        nxt[0] = nxt[1] = NULL;
    }
};


NODE *roots[lim]; /// Head of each state
LL a[lim]; /// information array


void Insert( LL pos )
{
    roots[pos] = new NODE;

    NODE *p = roots[pos];

    p->nxt[0] = (roots[pos-1])->nxt[0];

    p->nxt[1] = (roots[pos-1])->nxt[1];

    for( LL i = 20 ; i>=0 ; i-- )
    {
        LL b = CHK(a[ pos ],i)?1:0;
        if( p->nxt[b] == NULL )
        {
            p->nxt[b] = new NODE;
        }
        else
        {
            NODE *q = new NODE;

            q->f = (p->nxt[b])->f;
            q->nxt[0] = (p->nxt[b])->nxt[0];
            q->nxt[1] = (p->nxt[b])->nxt[1];
            p->nxt[b] = q;

        }
        p = p->nxt[b];
        (p->f)++;
    }
    p->num = a[ aof[pos] ];
}


/// Finds maximum a[i] xor K
LL Search( LL L, LL R, LL K )
{

    NODE *LP = roots[L-1], *RP = roots[R];
    for( LL i = 20 ; i>=0 ; i-- )
    {
        LL b = CHK(K,i)?1:0;
        LL lagbe = b^1;
        if( LP == NULL || LP->nxt[lagbe] == NULL )
        {
            if( RP->nxt[lagbe] != NULL )
            {
                RP = RP->nxt[lagbe];
                LP = NULL;
            }
            else
            {
                if(LP!=NULL)
                    LP = LP->nxt[b];
                RP = RP->nxt[b];
            }
        }
        else
        {
            if( RP->nxt[lagbe] != NULL )
            {
                if( (LP->nxt[lagbe])->f < (RP->nxt[lagbe])->f )
                {
                    LP = LP->nxt[lagbe];
                    RP = RP->nxt[lagbe];
                }
                else
                {
                    LP = LP->nxt[b];
                    RP = RP->nxt[b];
                }
            }
            else
            {
                LP = LP->nxt[b];
                RP = RP->nxt[b];
            }
        }

    }
    return (RP->num) ^ K;

}

