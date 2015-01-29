uses math;
const
        fi='';
        fo='';
type    edge=record
        u,v,g:longint;
        end;
var
        n,x,y:longint;
        p,min,max:array[1..100000,0..20]of longint;
        ds,dsg,dem,vt,l:array[1..200000]of longint;
        a:array[1..100000]of edge;
procedure init;
var
        i,start:longint;
begin
        assign(input,fi);
        assign(output,fo);
        reset(input);
        rewrite(output);
        readln(n);
        for i:=1 to n-1 do
        begin
                readln(a[i].u,a[i].v,a[i].g);
                inc(dem[a[i].u]);
                inc(dem[a[i].v]);
        end;
        start:=1;
        for i:=1 to n+1 do
        begin
                vt[i]:=start;
                start:=start+dem[i];
                dem[i]:=vt[i];
        end;
        for i:=1 to n-1 do
        begin
                ds[dem[a[i].u]]:=a[i].v;
                ds[dem[a[i].v]]:=a[i].u;
                dsg[dem[a[i].u]]:=a[i].g;
                dsg[dem[a[i].v]]:=a[i].g;
                inc(dem[a[i].u]);
                inc(dem[a[i].v]);
        end;
end;

procedure dfs(u,cha,level:longint);
var
        i,v:longint;
begin
        p[u,0]:=cha;
        l[u]:=level;
        for i:=vt[u] to vt[u+1]-1 do
        begin
                v:=ds[i];
                if v=cha then continue;
                min[v,0]:=dsg[i];
                max[v,0]:=dsg[i];
                dfs(v,u,level+1);
        end;
end;
procedure prep;
var
        i,j:longint;
begin
        for i:=1 to n do
        for j:=1 to 17 do
        begin
                p[i,j]:=-1;
                min[i,j]:=maxlongint;
                max[i,j]:=-maxlongint;
        end;
        for j:=1 to 17 do
        for i:=1 to n do
        begin
                if p[i,j-1]<>-1 then
                begin
                        p[i,j]:=p[p[i,j-1],j-1];
                        max[i,j]:=math.max(max[i,j-1],max[p[i,j-1],j-1]);
                        min[i,j]:=math.min(min[i,j-1],min[p[i,j-1],j-1]);
                end;
        end;
end;

procedure LCA(u,v:longint);
var
        i,j,tmp:longint;
begin
        x:=-maxlongint;       y:=maxlongint;
        if l[u]<l[v] then
        begin
                tmp:=u;
                u:=v;
                v:=tmp;
        end;
        for i:=17 downto 0 do
        begin
                if l[u]-1 shl i>=l[v] then
                begin
                        x:=math.max(max[u,i],x);
                        y:=math.min(min[u,i],y);
                        u:=p[u,i];
                end;
        end;
        if u=v then exit;
        for i:=17 downto 0 do
        begin
                if(p[u,i]<>-1)and(p[u,i]<>p[v,i])then
                begin
                        x:=math.max(max[u,i],x);
                        x:=math.max(max[v,i],x);
                        y:=math.min(min[u,i],y);
                        y:=math.min(min[v,i],y);
                        u:=p[u,i];
                        v:=p[v,i];
                end;
        end;
        x:=math.max(max[u,0],x);
        x:=math.max(max[v,0],x);
        y:=math.min(min[u,0],y);
        y:=math.min(min[v,0],y);
end;

procedure solve;
var
        i,k,u,v:longint;
begin
        readln(k);
        for i:=1 to k do
        begin
                readln(u,v);
                LCA(u,v);
                writeln(y,' ',x);
        end;
end;

begin
        init;
        dfs(1,-1,1);
        prep;
        solve;
end.

