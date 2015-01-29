const   fi='';
        fo='';
type    edge=record
        u,v:longint;
        end;
var     a:array[1..201]of edge;
        check,check2:array[1..201]of boolean;
        dem,vt,ds:array[1..400]of longint;
        n,res,xa,sau:longint;
function max(a,b:longint):longint;
begin
        if a>b then exit(a)
        else        exit(b);
end;

procedure init;
var     i,start:longint;
begin
        assign(input,fi);       assign(output,fo);
        reset(input);           rewrite(output);
        readln(n);              start:=1;
        for i:=1 to n-1 do
        begin
                readln(a[i].u,a[i].v);
                inc(dem[a[i].u]);
                inc(dem[a[i].v]);
        end;
        for i:=1 to n+1 do
        begin
                vt[i]:=start;   start:=start+dem[i];    dem[i]:=vt[i];
        end;
        for i:=1 to n-1 do
        begin
                ds[dem[a[i].u]]:=a[i].v;        ds[dem[a[i].v]]:=a[i].u;
                inc(dem[a[i].u]);               inc(dem[a[i].v]);
        end;
end;

procedure dfs2(u,cha,l:longint;gan:boolean);
var     i,v:longint;
begin
        if check[u] then exit;
        if check2[u] then exit;
        check2[u]:=gan;
        if l>xa then
        begin
                xa:=l;
                sau:=u;
        end;
        for i:=vt[u] to vt[u+1]-1 do
        begin
                v:=ds[i];       if v=cha then continue;
                dfs2(v,u,l+1,gan);
        end;

end;
procedure dfs(u,cha,l:longint);
var     i,v:longint;
begin
        check[u]:=true;
        fillchar(check2,sizeof(check2),false);
        for i:=1 to n do
        begin
                if l=0 then break;
                if check2[i] then continue;
                sau:=i;         xa:=0;
                dfs2(i,0,0,false);
                                xa:=0;
                dfs2(sau,0,0,true);
                res:=max(res,xa*l);
        end;
        for i:=vt[u] to vt[u+1]-1 do
        begin
                v:=ds[i];       if v=cha then continue;
                dfs(v,u,l+1);
        end;
        check[u]:=false;

end;


procedure solve;
var     i:longint;
begin
        for i:=1 to n do
                dfs(i,0,0);
        writeln(res);
end;
begin
        init;
        solve;
end.
