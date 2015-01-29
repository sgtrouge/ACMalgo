const   fi='';
        fo='';
        oo=maxlongint*100000;
var     a,b,truoc,sau:array[1..5000]of int64;
        n:longint;
        res:int64;
procedure sort(l,r:longint);
var     i,j,tmp,pv:longint;
begin
        if l>=r then exit;      i:=l;   j:=r;   pv:=b[(l+r)div 2];
        repeat
                while b[i]<pv do inc(i);
                while b[j]>pv do dec(j);
                if i<=j then
                begin
                        tmp:=b[i];
                        b[i]:=b[j];
                        b[j]:=tmp;
                        inc(i);
                        dec(j);
                end;
        until i>=j;
        sort(l,j);              sort(i,r);
end;

function min(x,y:int64):int64;
begin
        if x<y then exit(x)
        else        exit(y);
end;
procedure init;
var     i,j:longint;
begin
        assign(input,fi);               assign(output,fo);
        reset(input);                   rewrite(output);
        readln(n);                      res:=oo;
        for i:=1 to n do                read(a[i]);
        b:=a;
        sort(1,n);
        for i:=1 to n do
                for j:=1 to n do
                begin
                        sau[j]:=int64(abs(b[j]-a[i]))+truoc[j];
                        if i=n then
                        res:=min(res,sau[j]);
                        if j>1 then sau[j]:=min(sau[j],sau[j-1]);
                        truoc[j]:=sau[j];
                end;
        writeln(res);
end;

begin
        init;
end.
