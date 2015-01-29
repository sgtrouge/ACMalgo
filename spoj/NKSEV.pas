uses math;
const
        fi='';
        fo='';
        module=1337377;
type
        trie=^node;
        node=record
        count:longint;
        c:array['a'..'z']of trie;
end;
var
        f:array[0..300000]of longint;
        a:array[0..300000]of char;
        s:ansistring;
        p,root:trie;
        dem,n:longint;
function add:trie;
var
        i:char;
begin
        new(add);
        for i:='a' to 'z' do
        add^.c[i]:=nil;
        add^.count:=0;
end;

procedure insert;
var
        i:longint;
begin
        p:=root;
        for i:=length(s) downto 1 do
        begin
                if p^.c[s[i]]=nil then
                        p^.c[s[i]]:=add;
                p:=p^.c[s[i]];
        end;
        inc(p^.count);
end;

procedure find(i:longint);
var
        tmp:longint;
begin
        tmp:=i;
        p:=root^.c[a[i]];
        while(i>0)and(p<>nil)do
        begin
                f[tmp]:=(f[tmp]+f[i-1]*p^.count)mod module;
                p:=p^.c[a[i-1]];
                dec(i);
        end;
end;

procedure init;
var
        i:longint;
begin
        dem:=0;
        assign(input,fi);
        assign(output,fo);
        reset(input);
        rewrite(output);
        while not eoln do
        begin
                inc(dem);
                read(a[dem]);
        end;
        root:=add;
        readln(n);
        for i:=1 to n do
        begin
                readln(s);
                insert;
        end;
        f[0]:=1;
end;

procedure solve;
var
        i:longint;
begin
        for i:=1 to dem do
                find(i);
        writeln(f[dem]);
end;
begin
        init;
        solve;
end.



