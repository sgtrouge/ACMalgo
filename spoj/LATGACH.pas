uses math;
type bigint=array[0..100]of byte;
var
        b,a:array[0..100]of byte;
        data:array[1..100]of bigint;
function c(x,y:bigint):bigint;
var
        dem,i,j,nho:integer;
begin
        c[0]:=math.max(x[0],y[0]);
        nho:=0;
        for dem:=1 to c[0] do
        begin
                if dem<=x[0] then
                i:=x[dem]
                else i:=0;
                if dem<=y[0] then
                j:=y[dem]
                else j:=0;
                c[dem]:=i+j+nho;
                if c[dem]>=10 then
                begin
                        nho:=1;
                        c[dem]:=c[dem]mod 10;
                end
                else
                nho:=0;
        end;
        if nho=1 then
        begin
                inc(c[0]);
                c[c[0]]:=1;
        end;
end;
procedure output(i:integer);
var
        dem:integer;
begin
        for dem:=data[i][0] downto 1 do
        begin
                write(data[i][dem]);
        end;
end;
procedure solve;
var
        T,i,j,dem:integer;
begin
        a[0]:=1;a[1]:=1;
        b[0]:=1;b[1]:=2;
        data[1]:=a;
        data[2]:=b;
        for dem:=3 to 100 do
        begin
                data[dem]:=c(a,b);
                a:=b;
                b:=data[dem];
        end;
        readln(T);
        for i:=1 to T do
        begin
                readln(j);
                output(j);
                writeln;
        end;

end;
begin
        solve;
end.
