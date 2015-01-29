uses math;
type spec=record
w,v:longint;
end;
var
        m:array[1..40]of spec;
        s1:array[0..1050000]of spec;
        s2:array[0..1050000]of spec;
        t,kq:longint;
        n:byte;
        k1,k2:longint;
procedure search();
var     l,r:longint;
begin
        l:=0;
        r:=k2;
        while (l<=k1)and(r>=0) do
        begin
                if s1[l].w+s2[r].w<=t then
                begin
                     kq:=math.max(kq,s1[l].v+s2[r].v);
                     inc(l);
                end
                else
                dec(r);
        end;
end;

procedure sinh(tong,tien:longint;vt:byte);
begin
        if vt=n div 2 then
        begin
                inc(k1);
                s1[k1].w:=tong;
                s1[k1].v:=tien;
        end
        else
        begin
                inc(vt);
                sinh(tong+m[vt].w,tien+m[vt].v,vt);
                sinh(tong,tien,vt);
        end;
end;

procedure sinh2(tong,tien:longint;vt:byte);
begin
        if vt=n then
        begin
                inc(k2);
                s2[k2].w:=tong;
                s2[k2].v:=tien;
        end
        else
        begin
                inc(vt);
                sinh2(tong+m[vt].w,tien+m[vt].v,vt);
                sinh2(tong,tien,vt);
        end;
end;


procedure qhd;
var     dem:longint;
        max1,max2:longint;
begin
        max1:=0;max2:=0;
        for dem:=1 to math.max(k1,k2) do
        begin
                max1:=math.max(s1[dem].v,max1);
                max2:=math.max(s2[dem].v,max2);
                s1[dem].v:=max1;
                s2[dem].v:=max2;
        end;

end;
procedure sort(l,r:longint);
var     i,j,pv:longint;
        tmp:spec;

begin
        if l>=r then exit;
        i:=l;
        j:=r;
        pv:=s1[(l+r)div 2].w;
        repeat
                while s1[i].w<pv do inc(i);
                while s1[j].w>pv do dec(j);
                if i<=j then
                begin
                        if i<j then
                        begin
                             tmp:=s1[i];
                             s1[i]:=s1[j];
                             s1[j]:=tmp;
                        end;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        sort(l,j);
        sort(i,r);
end;

procedure sort2(l,r:longint);
var     i,j,pv:longint;
        tmp:spec;

begin
        if l>=r then exit;
        i:=l;
        j:=r;
        pv:=s2[(l+r)div 2].w;
        repeat
                while s2[i].w<pv do inc(i);
                while s2[j].w>pv do dec(j);
                if i<=j then
                begin
                        if i<j then
                        begin
                             tmp:=s2[i];
                             s2[i]:=s2[j];
                             s2[j]:=tmp;
                        end;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        sort2(l,j);
        sort2(i,r);
end;

procedure solve;
var
        dem:byte;
begin

        k1:=0;k2:=0;kq:=0;
        readln(n,t);
        for dem:=1 to n do
                readln(m[dem].w,m[dem].v);
        sinh(0,0,0);
        sinh2(0,0,n div 2);
        sort(1,k1);
        sort2(1,k2);
        s2[0].w:=0;s2[0].v:=0;
        qhd;
        search;
        writeln(kq);
end;
begin
        solve;
end.

