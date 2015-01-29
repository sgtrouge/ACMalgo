const   fi='';
        fo='';
var     dem:array[1..5000]of longint;
        tmp,res,n:longint;
procedure init;
var     i:longint;
begin
        assign(input,fi);       assign(output,fo);
        reset(input);           rewrite(output);
        readln(n);
        for i:=1 to n do
        begin
                read(tmp);
                if tmp>n then inc(res);
                inc(dem[tmp]);
        end;
        for i:=1 to n do
                if dem[i]>1 then
                res:=res+dem[i]-1;
        writeln(res);
end;

begin
        init;
end.
