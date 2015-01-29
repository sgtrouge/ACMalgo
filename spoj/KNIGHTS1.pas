uses math;
const
        fi='';
        fo='';
type    edge=record
        u,v,gt:longint;
        end;
var
        n,m,count,s,t,min:longint;
        p,dem,vt,ds,g:array[1..7000]of longint;
        a,b:array[1..100001]of edge;
procedure sort(l,r:longint);
var
        i,j,pv:longint;
        tmp:edge;
begin
        if l>=r then exit;
        i:=l;                   j:=r;
        pv:=a[(l+r)div 2].gt;
        repeat
                while a[i].gt<pv do inc(i);
                while a[j].gt>pv do dec(j);
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
var
        i:longint;
begin
        assign(input,fi);
        assign(output,fo);
        reset(input);
        rewrite(output);
        readln(n,m);
        for i:=1 to m do
                readln(a[i].u,a[i].v,a[i].gt);
end;

function root(r:longint):longint;
begin
        while p[r]>-1 do r:=p[r];
        exit(r);
end;

procedure unite(r1,r2:longint);
var
        tong:longint;
begin
        tong:=p[r1]+p[r2];
        if p[r1]<p[r2] then
        begin
                p[r1]:=tong;
                p[r2]:=r1;
        end
        else
        begin
                p[r2]:=tong;
                p[r1]:=r2;
        end;
end;

procedure djs;
var
        i,r1,r2:longint;
begin
        for i:=1 to n do p[i]:=-1;
        for i:=1 to m do
        begin
                r1:=root(a[i].u);       r2:=root(a[i].v);
                if r1<>r2 then
                begin
                        unite(r1,r2);
                        inc(count);
                        b[count]:=a[i];
                        inc(dem[a[i].u]);
                        inc(dem[a[i].v]);
                end;
        end;
end;

procedure init2;
var
        i,start:longint;
begin
        start:=1;
        for i:=1 to n+1 do
        begin
                vt[i]:=start;
                start:=start+dem[i];
                dem[i]:=vt[i];
        end;
        for i:=1 to count do
        begin
                ds[dem[b[i].u]]:=b[i].v;
                ds[dem[b[i].v]]:=b[i].u;
                g[dem[b[i].u]]:=b[i].gt;
                g[dem[b[i].v]]:=b[i].gt;
                inc(dem[b[i].u]);
                inc(dem[b[i].v]);
        end;
end;

function dfs(u,cha:longint):boolean;
var
        i,v:longint;
begin
        if u=t then exit(true);
        for i:=vt[u] to vt[u+1]-1 do
        begin
                v:=ds[i];
                if v=cha then continue;
                if dfs(v,u) then
                begin
                        min:=math.max(g[i],min);
                        exit(true);
                end;
        end;
        exit(false);

end;
procedure solve;
var
        i,q,tmp:longint;
begin
        readln(q);
        for i:=1 to q do
        begin
                readln(s,t);
                min:=-maxlongint;
                dfs(s,0);
                writeln(min);
        end;
end;
begin

        init;
        sort(1,m);
        djs;
        init2;
        solve;
end.

