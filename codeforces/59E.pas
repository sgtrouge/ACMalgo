const
        fi='';
        fo='';
        oo=maxlongint;
type    edge=record
        u,v:longint;
        end;
        spec=record
        u,pre:longint;
        end;
        trip=record
        x,y,z:longint;
        end;
var     vt,ds,dem:array[1..40000]of longint;
        h:array[1..900000]of spec;
        trace:array[0..3000,0..3000]of spec;
        pos,d:array[0..3000,0..3000]of longint;
        b:array[1..100000]of trip;
        n,m,k,top,count:longint;
        res:array[1..3001]of longint;
        a:array[1..20000]of edge;
procedure init;
var     i,start,u,v:longint;
begin
        assign(input,fi);       assign(output,fo);
        reset(input);           rewrite(output);
        readln(n,m,k);          start:=1;
        for i:=1 to m do
        begin
                readln(a[i].u,a[i].v);
                inc(dem[a[i].u]);
                inc(dem[a[i].v]);
        end;
        for i:=1 to n+1 do
        begin
                vt[i]:=start;    start:=start+dem[i];    dem[i]:=vt[i];
        end;
        for i:=1 to m do
        begin
                ds[dem[a[i].u]]:=a[i].v;
                ds[dem[a[i].v]]:=a[i].u;
                inc(dem[a[i].u]);
                inc(dem[a[i].v]);
        end;
        for i:=1 to k do
                readln(b[i].x,b[i].y,b[i].z);
end;

function cmp(a,b:trip):boolean;
begin
        if a.x<b.x then exit(true);     if a.x>b.x then exit(false);
        if a.y<b.y then exit(true);     if a.y>b.y then exit(false);
        if a.z<b.z then exit(true);     if a.z>b.z then exit(false);
        exit(true);
end;

function diff(a,b:trip):boolean;
begin
        if(a.x=b.x)and(a.y=b.y)and(a.z=b.z)then exit(false)
        else            exit(true);
end;
procedure sort(l,r:longint);
var     i,j:longint;
        tmp,pv:trip;
begin
        if l>=r then exit;      i:=l;   j:=r;   pv:=b[random(r-l+1)+l];
        repeat
                while cmp(b[i],pv)and(diff(b[i],pv)) do inc(i);
                while cmp(b[j],pv)and(diff(b[j],pv))=false do dec(j);
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
function find(x,y,z:longint):boolean;
var     l,r,mid:longint;
        tim:trip;
begin
        l:=1;           r:=k;
        tim.x:=x;       tim.y:=y;       tim.z:=z;
        repeat
                mid:=(l+r)div 2;
                if diff(b[mid],tim)=false then exit(true);
                if cmp(b[mid],tim) then l:=mid+1
                else                    r:=mid-1;
        until l>r;
        exit(false);
end;

procedure update(v,truoc:longint);
var     p,c:longint;
begin
        c:=pos[v,truoc];
        if c=0 then
        begin
                inc(top);       c:=top;
        end;
        p:=c div 2;
        while(p>0)and(d[h[p].u,h[p].pre]>d[v,truoc])do
        begin
                h[c]:=h[p];
                pos[h[c].u,h[c].pre]:=c;
                c:=p;
                p:=c div 2;
        end;
        h[c].u:=v;      h[c].pre:=truoc;
        pos[v,truoc]:=c;
end;

function pop:spec;
var     p,c:longint;
        v:spec;
begin
        pop:=h[1];
        v:=h[top];
        dec(top);
        p:=1;
        while(p*2<=top)do
        begin
                c:=p*2;
                if(c<top)and(d[h[c].u,h[c].pre]>d[h[c+1].u,h[c+1].pre]) then inc(c);
                if d[v.u,v.pre]<d[h[c].u,h[c].pre]then break;
                h[p]:=h[c];
                pos[h[p].u,h[p].pre]:=c;
                p:=c;
        end;
        h[p]:=v;
        pos[v.u,v.pre]:=p;
end;
procedure dj;
var     i,j,u,v,truoc,tmpp:longint;
        tmp:spec;
begin
        for i:=1 to n do        for j:=0 to n do        d[i,j]:=oo;
        d[1,0]:=0;              update(1,0);
        while top>0 do
        begin
                tmp:=pop;       u:=tmp.u;       truoc:=tmp.pre;
                if u=n then break;
                for i:=vt[u] to vt[u+1]-1 do
                begin
                        v:=ds[i];
                        if find(truoc,u,v)then continue;
                        if d[u,truoc]+1<d[v,u] then
                        begin
                                trace[v,u].u:=u;
                                trace[v,u].pre:=truoc;
                                d[v,u]:=d[u,truoc]+1;
                                update(v,u);
                        end;
                end;
        end;
        if u<>n then writeln(-1)
        else
        begin
                writeln(d[u,truoc]);
                while u<>0 do
                begin
                        inc(count);
                        res[count]:=u;
                        tmpp:=truoc;
                        truoc:=trace[u,truoc].pre;
                        u:=tmpp;

                end;
                for i:=count downto 1 do
                        write(res[i],' ');
        end;

end;

begin
        init;
        sort(1,k);
        dj;
end.
