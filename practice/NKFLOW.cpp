uses    math;
const   fi='';
        fo='';
var     f,c:array[1..1000,1..1000]of longint;
        n,m,s,t,res:longint;
        trace,q:array[1..1000]of longint;
procedure init;
var     i,u,v:longint;
begin
        assign(input,fi);       assign(output,fo);
        reset(input);           rewrite(output);
        readln(n,m,s,t);
        for i:=1 to m do
                readln(u,v,c[u,v]);
end;

function find:boolean;
var     l,r,u,v:longint;
begin
        fillchar(trace,sizeof(trace),0);
        q[1]:=s;
        l:=1;           r:=1;
        while l<=r do
        begin
                u:=q[l];
                for v:=1 to n do
                begin
                	if v=s then continue;	
                        if(trace[v]=0)and(c[u,v]>f[u,v])then
                        begin
                                inc(r);
                                q[r]:=v;
                                trace[v]:=u;
                                if v=t then exit(true);
                        end;
                end;
                inc(l);
        end;
        exit(false);
end;

procedure incflow;
var     u,v,hieu:longint;
begin
        v:=t;	hieu:=maxlongint;
        repeat
                u:=trace[v];
                hieu:=min(hieu,c[u,v]-f[u,v]);
                v:=u;
        until v=s;
        v:=t;
        repeat
                u:=trace[v];
                f[u,v]:=f[u,v]+hieu;
                f[v,u]:=f[v,u]-hieu;
                v:=u;
        until v=s;
end;

procedure solve;
var     i:longint;
begin
        while true do
        begin
                if find=false then break;
                incflow;
        end;
        for i:=1 to n do
                res:=res+f[s,i];
        writeln(res);
end;
begin
        init;
        solve;
end.