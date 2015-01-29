Uses Math;
const
        fin = '';
        fout = '';

var
        p,r,pos,d,ind: array[0..150000] of longint;
        check: array[0..150000] of boolean;
        h,ke,cost,first: array[0..150000] of longint;
        n,m,nHeap,res,count: longint;
        u,v,t: array[0..50000] of longint;
procedure readf;
var
        i,j,tmp: longint;
begin
        assign(input, fin); reset(input);
        assign(output, fout); rewrite(output);
        readln(m,n);
        For i:=1 to n do
                Read(First[i]);
        For j:=1 to n-1 do
        Begin
                Inc(count);
                Read(t[count]);
                Inc(p[j]);
                Inc(p[j+1]);
                U[count]:=j;
                V[count]:=j+1;
        End;
        For i:=1 to m-1 do
        Begin
                tmp:=(i-1)*n;
                For j:=1 to n do
                Begin
                        Inc(count);
                        Read(t[count]);
                        Inc(p[tmp+j]);
                        Inc(p[tmp+j+n]);
                        u[count]:=tmp+j;
                        v[count]:=tmp+j+n;
                End;
                For j:=1 to n-1 do
                Begin
                        Inc(count);
                        Read(t[count]);
                        Inc(p[tmp+j+n]);
                        Inc(p[tmp+j+1+n]);
                        u[count]:=tmp+j+n;
                        v[count]:=tmp+j+1+n;
                End;
        End;
        for i:=1 to n*m do p[i]:=p[i-1]+p[i];
        p[n*m+1]:=2*count+1;
        for i:=1 to count do
        begin
                ke[p[u[i]]]:=v[i];
                ke[p[v[i]]]:=u[i];
                cost[p[u[i]]]:=t[i];
                cost[p[v[i]]]:=t[i];
                dec(p[u[i]]);
                dec(p[v[i]]);
        end;
end;
procedure update(v: longint);
var
         child,parent: longint;
begin
        child:=pos[v];
        if child = 0 then
        begin
                inc(nHeap); child:=nHeap;
        end;
        parent:= child div 2;
        while (parent>0) and (d[h[parent]]>d[v]) do
        begin
                h[child]:=h[parent];
                pos[h[child]]:=child;
                child:=parent;
                parent:=child div 2;
        end;
        h[child]:=v;
        pos[v]:=child;
end;
function pop: longint;
var c,r,v: longint;
begin
        pop:=h[1];
        v:=h[nHeap];
        dec(nHeap);
        r:=1;
        while (r*2<=nHeap) do
        begin
                c:=r*2;
                if (d[h[c]]>d[h[c+1]]) and (c<nHeap) then inc(c);
                if d[v]<=d[h[c]] then break;
                h[r]:=h[c];
                pos[h[r]]:=r;
                r:=c;
        end;
        h[r]:=v;
        pos[v]:=r;
end;
procedure init(s: longint);
var i: longint;
begin
        fillchar(check,sizeof(check),false);
        for i:=1 to n*m do d[i]:=maxlongint;
        d[s]:=first[s];
        nHeap:=0;
        fillchar(pos,sizeof(pos),0);
end;
procedure dijkstra(s: longint);
var i,imin: longint;
begin
        init(s);
        update(s);
        while nHeap>0 do
        begin
                imin:=pop;
                check[imin]:=true;
                for i:=p[imin]+1 to p[imin+1] do                
                        if d[ke[i]]>d[imin]+cost[i] then
                        begin
                                d[ke[i]]:=d[imin]+cost[i];
                                update(ke[i]);
                        end;
                
        end;
        Res:=Math.min(res,d[m*n]);
end;

procedure proceed;
var i,j: longint;
begin
        Res:=maxlongint;
        for i:=1 to n do
        begin
                dijkstra(i);
        end;
        writeln(Res);
end;
begin
        readf;
        proceed;
end.



