const   fi='';
        fo='';
var     s:ansistring;
        k,res,count:longint;
        luu:array[1..500]of ansistring;
        f,trace:array[0..500,0..500]of longint;
        zzz:array[1..1000000000,1..10000]of longint; 
procedure init;
var     i,j:longint;
begin
        assign(input,fi);       assign(output,fo);
        reset(input);           rewrite(output);
        readln(s);              readln(k);     res:=length(s);
        for i:=0 to length(s) do
        for j:=0 to length(s) do
                f[i,j]:=length(s);
        f[0,0]:=0;
end;

function check(i,j:longint):longint;
var     tmp:longint;
begin
        tmp:=0;
        while i<j do
        begin
                if s[i]<>s[j] then inc(tmp);
                inc(i);
                dec(j);
        end;
        exit(tmp);
end;

procedure fix(var a:ansistring);
var     i,j:longint;
begin
        i:=1;   j:=length(a);
        while(i<j)do
        begin
                if a[i]<>a[j] then a[i]:=a[j];
                inc(i);
                dec(j);
        end;

end;
procedure back(vt,lan:longint);
begin
        if lan=0 then exit;
        inc(count);
        luu[count]:=copy(s,trace[vt,lan]+1,vt-trace[vt,lan]);
        fix(luu[count]);
        back(trace[vt,lan],lan-1);
end;

procedure solve;
var     i,j,tmp,t,last:longint;
begin
        for i:=1 to length(s) do
        begin
                for j:=i downto 1 do
                begin
                        tmp:=check(j,i);
                        for t:=1 to i do
                        begin
                                if f[i,t]>f[j-1,t-1]+tmp then
                                begin
                                        f[i,t]:=f[j-1,t-1]+tmp;
                                        trace[i,t]:=j-1;
                                end;
                        end;
                end;
        end;
        for i:=k downto 1 do
                if f[length(s),i]<res then
                begin
                        res:=f[length(s),i];
                        last:=i;
                end;
        writeln(res);
        back(length(s),last);
        for i:=count downto 1 do
        begin
                write(luu[i]);
                if i>1 then write('+');
        end;
end;

begin
        init;
        solve;
end.
