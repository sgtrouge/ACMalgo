uses    math;
const   fi='';
        fo='';
var     s:ansistring;
        f:array[1..2000,1..2000]of boolean;
        tong:array[0..2000]of int64;
        res:int64;
procedure init;
var     i,l,r:longint;
begin
        assign(input,fi);       assign(output,fo);
        reset(input);           rewrite(output);
        readln(s);
        for i:=1 to length(s) do
        begin
                l:=i;   r:=i;
                f[l,r]:=true;
                while(l>1)and(r<length(s))and(s[l-1]=s[r+1])do
                begin
                        inc(r);
                        dec(l);
                        f[l,r]:=true;
                end;
        end;
        for i:=1 to length(s)-1 do
        begin
                l:=i+1; r:=i;
                while(l>1)and(r<length(s))and(s[l-1]=s[r+1])do
                begin
                        inc(r);
                        dec(l);
                        f[l,r]:=true;
                end;
        end;
end;

procedure solve;
var     i,j:longint;
begin
        for i:=1 to length(s) do
        begin
                for j:=i downto 1 do
                begin
                        if f[j,i] then
                        begin
                                inc(tong[i]);
                                res:=res+tong[j-1];
                        end;
                end;
                tong[i]:=tong[i]+tong[i-1];
        end;
        writeln(res);
end;

begin
        init;
        solve;
end.
