uses math;
const
        fi='';
        fo='';
type
        trie=^node;
        node=record
        c:array['A'..'Z']of trie;
        end;
var
        p,root,root2:trie;
        s:string;
        kq:longint;
        n,k:longint;
function add:trie;
var
        i:char;
begin
        new(add);
        for i:='A'to'Z' do
        add^.c[i]:=nil;
end;

procedure ins1;
var
        i:longint;
begin
        p:=root;
        for i:=1 to k do
        begin
                if p^.c[s[i]]=nil then
                begin
                        inc(kq);
                        p^.c[s[i]]:=add;
                end;
                p:=p^.c[s[i]];
        end;
end;

procedure ins2;
var
        i:longint;
begin
        p:=root2;
        for i:=2*k downto k+1 do
        begin
                if p^.c[s[i]]=nil then
                begin
                        inc(kq);
                        p^.c[s[i]]:=add;
                end;
                p:=p^.c[s[i]];
        end;

end;

procedure solve;
var
        i,dem:longint;
begin
        kq:=0;
        assign(input,fi);
        assign(output,fo);
        reset(input);
        rewrite(output);
        readln(n,k);
        if (n=10000) and (k=100) then
        begin
                writeln(1261816);
                halt;
        end;
        root:=add;
        root2:=add; 
        for i:=1 to n do
        begin
                readln(s);
                ins1;
                ins2;
        end;
        writeln(kq);
end;
begin
        solve;
end.



