const     fi='';
          fo='';
          oo=maxlongint*1000;
type      edge=record
          u,v,g:longint;
          end;
var       ds,dsg,dem,vt,c,t,dd:array[1..2000]of int64;
          d:array[1..2000,1..2000]of int64;
          a:array[1..2000]of edge;
          h,pos:array[1..20000]of longint;
          check:array[1..2000]of boolean;
          n,m,x,y,count:longint;
procedure init;
var       i,j,start:longint;
begin
          assign(input,fi);   assign(output,fo);
          reset(input);       rewrite(output);
          readln(n,m);        start:=1;      readln(x,y);
          for i:=1 to m do
          begin
               readln(a[i].u,a[i].v,a[i].g);
               inc(dem[a[i].u]);
               inc(dem[a[i].v]);
          end;
          for i:=1 to n+1 do
          begin
               vt[i]:=start;  start:=start+dem[i];     dem[i]:=vt[i];
          end;
          for i:=1 to m do
          begin
               ds[dem[a[i].u]]:=a[i].v;
               ds[dem[a[i].v]]:=a[i].u;
               dsg[dem[a[i].u]]:=a[i].g;
               dsg[dem[a[i].v]]:=a[i].g;
               inc(dem[a[i].u]);
               inc(dem[a[i].v]);
          end;
          for i:=1 to n do
               readln(t[i],c[i]);
          for i:=1 to n do
          for j:=1 to n do
               d[i,j]:=oo;
          for i:=1 to n do
               dd[i]:=oo;
end;

procedure insert(goc,v:longint);
var       p,c:longint;
begin
          c:=pos[v];
          if c=0 then
          begin
               inc(count);    c:=count;
          end;
          p:=c div 2;
          while(p>0)and(d[goc,h[p]]>d[goc,v]) do
          begin
               h[c]:=h[p];
               pos[h[c]]:=c;
               c:=p;
               p:=c div 2;
          end;
          h[c]:=v;
          pos[h[c]]:=c;
end;

function  pop(goc:longint):longint;
var       p,c,v:longint;
begin
          pop:=h[1];
          v:=h[count];
          dec(count);
          p:=1;
          while(p*2<=count)do
          begin
               c:=p*2;
               if(c<count)and(d[goc,h[c]]>d[goc,h[c+1]]) then inc(c);
               if(d[goc,v]<d[goc,h[p]]) then break;
               h[p]:=h[c];
               pos[h[p]]:=p;
               p:=c;
          end;
          h[p]:=v;
          pos[h[p]]:=p;
end;

procedure dijkstra(goc:longint);
var       u,i,v:longint;
begin
          d[goc,goc]:=0;
          insert(goc,goc);
          while count>0 do
          begin
                    u:=pop(goc);
                    for i:=vt[u] to vt[u+1]-1 do
                    begin
                         v:=ds[i];
                         if d[goc,v]>d[goc,u]+dsg[i] then
                         begin
                              d[goc,v]:=d[goc,u]+dsg[i];
                              insert(goc,v);
                         end;
                    end;
          end;
end;

procedure solve;
var       i,u:longint;
          max:int64;
begin
          for i:=1 to n do
          begin
               fillchar(h,sizeof(h),0);
               fillchar(pos,sizeof(pos),0);
               count:=0;
               dijkstra(i);
          end;

          fillchar(check,sizeof(check),true);
          dd[x]:=0;
          repeat
               max:=oo;    u:=0;
               for i:=1 to n do
                    if(dd[i]<max)and(check[i]) then
                    begin
                         u:=i;
                         max:=dd[i];
                    end;
               if(u=0)or(u=y)then break;
               check[u]:=false;
               for i:=1 to n do
                    if(d[u,i]<=t[u])and(dd[u]+c[u]<dd[i])then
                         dd[i]:=dd[u]+c[u];
          until false;
          if dd[y]=oo then writeln(-1)
          else             writeln(dd[y]);
end;
begin
          init;
          solve;
end.
