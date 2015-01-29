uses math;
type spec=record
x,y,sl:integer;
end;
var
        s1,s2:array[1..2000]of char;
        l,xmax,ymax:integer;
        data:array[0..2000,0..2000]of spec;
        f:string;
procedure solve;
var
        i,j:integer;
begin
        l:=0;
        xmax:=0;ymax:=0;
        while not eoln do
        begin
                inc(l);
                read(s1[l]);
        end;
        for i:=1 to l do
        begin
                s2[i]:=s1[l-i+1];
        end;
        for i:=1 to l do
        begin
                for j:=1 to l do
                begin
                        if s1[i]=s2[j] then
                        begin
                                data[i,j]:=data[i-1,j-1];
                                inc(data[i,j].sl);
                                if s1[i-1]=s2[j-1] then
                                begin
                                        data[i,j].x:=i-1;
                                        data[i,j].y:=j-1;
                                end;
                                if data[i,j].sl>=data[xmax,ymax].sl then
                                begin
                                        xmax:=i;
                                        ymax:=j;
                                end;
                        end
                        else
                        begin
                                if data[i-1,j].sl>data[i,j-1].sl then
                                begin
                                        data[i,j]:=data[i-1,j];
                                        if s1[i-1]=s2[j] then
                                        begin
                                                data[i,j].x:=i-1;
                                                data[i,j].y:=j;
                                        end;
                                end
                                else
                                begin
                                        data[i,j]:=data[i,j-1];
                                        if s1[i]=s2[j-1]then
                                        begin
                                                data[i,j].x:=i;
                                                data[i,j].y:=j-1;
                                        end;
                                end;
                        end;

                end;
        end;
        while data[xmax,ymax].sl>0 do
        begin
                write(s1[xmax]);
                i:=xmax;
                xmax:=data[xmax,ymax].x;
                ymax:=data[i,ymax].y;
        end;
        writeln(f);
end;

begin
        solve;
end.

