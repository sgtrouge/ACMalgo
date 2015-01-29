uses math;
const
        fi='';
        fo='';
var
        s:ansistring;
        count:longint;
        c:array[0..1000000]of char;
        gt:array[0..1000001]of longint;
procedure solve;
var
        co:boolean;
        i,last,l,r:longint;
begin
        readln(s);      last:=0;        count:=0;
        fillchar(gt,sizeof(gt),0);
        for i:=1 to length(s) do
        begin
                if s[i]<>c[count] then
                        inc(count);
                c[count]:=s[i];
                inc(gt[count]);
        end;
        while true do
        begin
                while(last<=count)and(gt[last]<>1)do
                begin
                        gt[last]:=gt[last] mod 2;
                        if gt[last]=0 then inc(last);
                end;
                if last>count then break;
                co:=false;
                for i:=last+1 to count do
                begin
                        if gt[i]mod 2<>0 then continue;
                        l:=i-1;         r:=i+1;
                        while(l>=last)and(r<=count)do
                        begin
                                if c[l]=c[r] then
                                begin
                                        if l=last then
                                        begin
                                                co:=true;
                                                last:=r;
                                                dec(gt[r]);
                                                break;
                                        end;
                                        if gt[l]<>gt[r] then break;
                                end
                                else    break;
                                dec(l);         inc(r);
                        end;
                        if co then break;
                end;
                if co=false then
                begin
                        writeln('NO');
                        exit;
                end;
        end;
        writeln('YES');
end;
procedure init;
var
        t:longint;
begin
        assign(input,fi);       assign(output,fo);
        reset(input);           rewrite(output);
        readln(t);
        while t>0 do
        begin
                solve;
                dec(t);
        end;
end;
begin
        init;
end.

