uses    math;
const   fi='';
        fo='';
var     dem:array['a'..'z']of longint;
        n,k:longint;
        s:string;
        BIT,v:array['a'..'z',1..200000]of longint;
        check:array[1..200000]of boolean;
procedure init;
var     i:longint;
begin
        assign(input,fi);       assign(output,fo);
        reset(input);           rewrite(output);
        readln(k);
        readln(s);
        for i:=1 to length(s) do
        begin
                inc(dem[s[i]]);
                v[s[i],dem[s[i]]]:=i;
        end;
end;

function find(c:char;u:longint):longint;
begin
        if u<=0 then exit(0);
        find:=BIT[c,u]+find(c,u-u and -u);
end;

procedure update(c:char;u:longint);
begin
        if u>k*length(s) then exit;
        inc(BIT[c,u]);
        update(c,u+u and -u);
end;

procedure solve;
var     i,l,r,p,mid,tmp,vt:longint;
        c:char;
begin
        readln(n);
        for i:=1 to n do
        begin
                read(p);        read(c);        read(c);
                l:=1;           r:=dem[c]*k;
                while true do
                begin
                        mid:=(l+r)div 2;
                        vt:=(mid-1)div dem[c];
                        vt:=vt*length(s);
                        tmp:=mid mod dem[c];
                        if tmp=0 then tmp:=dem[c];
                        vt:=vt+v[c,tmp];
                        tmp:=find(c,vt);

                        if check[vt] then
                        begin
                                if mid-tmp>=p then
                                        r:=mid-1
                                else    l:=mid+1;
                        end
                        else
                        begin
                                if mid-tmp=p then
                                begin
                                        check[vt]:=true;
                                        update(c,vt);
                                        break;
                                end;
                                if mid-tmp>p then
                                        r:=mid-1
                                else    l:=mid+1;

                        end;
                end;
        end;
end;

procedure outp;
var     i,tt:longint;
begin
        for i:=1 to k*length(s) do
        begin
                if check[i]=false then
                begin
                        tt:=i mod length(s);
                        if tt=0 then tt:=length(s);
                        write(s[tt]);
                end;
        end;
end;

begin
        init;
        solve;
        outp;
end.
