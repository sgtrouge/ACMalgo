uses    math;
const   fi='';
        fo='';
type    spec=record
        c,s,vt:int64;
        end;
        spec2=record
        sum,c:int64;
        end;

var     n:longint;
        a:array[1..100001]of spec;
        h:array[1..100001]of int64;
        m:array[1..100001]of longint;
        res,rc1,rc2,rh1,rh2:int64;
        r1,r2,tmp:array[0..100000]of longint;
        q,qt:array[1..100001]of spec2;
procedure sort(l,r:longint);
var     i,j:longint;
        pv,tmp:spec;
begin
        if l>=r then exit;
        i:=l;   j:=r;   pv:=a[l+random(r-l+1)];
        repeat
                while(a[i].c<pv.c)or((a[i].c=pv.c)and(a[i].s>pv.s))do inc(i);
                while(a[j].c>pv.c)or((a[j].c=pv.c)and(a[j].s<pv.s))do dec(j);
                if i<=j then
                begin
                        tmp:=a[i];
                        a[i]:=a[j];
                        a[j]:=tmp;
                        inc(i);
                        dec(j);
                end;
        until i>=j;
        sort(l,j);
        sort(i,r);
end;
procedure init;
var     i:longint;
begin
        assign(input,fi);       assign(output,fo);
        reset(input);           rewrite(output);
        readln(n);
        for i:=1 to n do
        begin
                a[i].vt:=i;
                readln(a[i].c,a[i].s);
        end;
end;

procedure cmp(h1,h2:longint);
begin
        if(h1=0)or(qt[h1].c=0)then exit;
        if qt[h1].sum+q[h2].sum>res then
        begin
                res:=qt[h1].sum+q[h2].sum;
                rh1:=h1;
                rh2:=h2;
                rc1:=qt[h1].c;
                rc2:=q[h2].c;
        end;
end;

procedure solve;
var     sum,cao:int64;
        i,j:longint;
begin
        cao:=0;         sum:=0;
        for i:=1 to n do
        begin
                inc(cao);
                inc(sum,a[i].s);

                q[cao].c:=a[i].c;
                q[cao].sum:=sum;

                if a[i].c<>a[i+1].c then
                begin
                        for j:=1 to cao do
                        begin
                                cmp(j-1,j);
                                cmp(j,j);
                                cmp(j+1,j);
                        end;
                        for j:=1 to cao do
                        begin
                                if q[j].sum>qt[j].sum then
                                qt[j]:=q[j];
                        end;
                        cao:=0;
                        sum:=0;
                end;
        end;
end;

procedure outp;
var     i,d1,d2:longint;
begin
        r1[0]:=rh1;     r2[0]:=rh2;
        d1:=0;          d2:=0;
        writeln(res);
        writeln(rh1+rh2);
        for i:=1 to n do
        begin
                if(rh1>0)and(a[i].c=rc1)then
                begin
                        r1[rh1]:=a[i].vt;
                        dec(rh1);
                end;
                if(rh2>0)and(a[i].c=rc2)then
                begin
                        r2[rh2]:=a[i].vt;
                        dec(rh2);
                end;
        end;

        if r1[0]<=r2[0] then
        begin
                tmp:=r1;
                r1:=r2;
                r2:=tmp;
        end;

        for i:=1 to r1[0]+r2[0] do
                if i mod 2=1 then
                begin
                        inc(d1);
                        write(r1[d1],' ');
                end
                else
                begin
                        inc(d2);
                        write(r2[d2],' ');
                end;
end;

begin
        init;
        sort(1,n);
        solve;
        outp;
end.
