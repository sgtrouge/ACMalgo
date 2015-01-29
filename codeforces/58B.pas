const
        fi='';
        fo='';
var     count,i,n,tmp:longint;
        mu,res:array[1..100]of longint;
begin
        assign(input,fi);       assign(output,fo);
        reset(input);           rewrite(output);
        readln(n);              i:=2;   tmp:=n;
        while i<=trunc(sqrt(n)) do
        begin
                if n mod i=0 then
                begin
                        inc(count);
                        res[count]:=i;
                        while n mod i =0 do
                        begin
                                n:=n div i;
                                inc(mu[count]);
                        end;
                end;
                inc(i);
        end;
        if n<>1 then
        begin
                inc(count);
                res[count]:=n;
                mu[count]:=1;
        end;
        while tmp<>1 do
        begin
                if mu[count]=0 then dec(count);
                write(tmp,' ');
                tmp:=tmp div res[count];
                dec(mu[count]);
        end;
        writeln(1);
end.
