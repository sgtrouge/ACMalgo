uses    math;
const   fi='';
        fo='';
type    item=record
        c:longint;
        t:real;
        vt:longint;
        end;
var     a:array[1..1000]of item;
        n,k,dem:longint;
        min,res:real;
procedure init;
var     i:longint;
begin
        assign(input,fi);       assign(output,fo);
        reset(input);           rewrite(output);
        readln(n,k);            min:=maxlongint;
        for i:=1 to n do
        begin
                a[i].vt:=i;
                readln(a[i].c,a[i].t);
                res:=res+a[i].c;
                min:=math.min(min,a[i].c);
                if a[i].t=1 then inc(dem);
        end;
end;

procedure sort(l,r:longint);
var     i,j:longint;
        pv,tmp:item;
begin
        if l>=r then exit;      i:=l;   j:=r;   pv:=a[l+random(r-l+1)];
        repeat
                while(a[i].t>pv.t)or((a[i].t=pv.t)and(a[i].c<pv.c))do inc(i);
                while(a[j].t<pv.t)or((a[j].t=pv.t)and(a[j].c>pv.c))do dec(j);
                if i<=j then
                begin
                        tmp:=a[i];
                        a[i]:=a[j];
                        a[j]:=tmp;
                        inc(i);
                        dec(j);
                end;
        until i>=j;
        sort(l,j);              sort(i,r);
end;

procedure solve;
var     i,j:longint;
begin
        for i:=n downto n-k+2 do
        begin
                if a[i].t=1 then res:=res-a[i].c/2
                else             break;
        end;
        if dem>=k then           res:=res-min/2;
        writeln(res:0:1);
        for i:=n downto n-k+2   do writeln(1,' ',a[i].vt);
        write(n-k+1,' ');
        for i:=n-k+1 downto 1   do write(a[i].vt,' ');
end;

begin
        init;
        sort(1,n);
        solve;
end.
