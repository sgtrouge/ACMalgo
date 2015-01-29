const
        fi='';
        fo='';
        doi:array['a'..'h']of longint=(1,2,3,4,5,6,7,8);
var     s1,s2,truoc,sau:string;
        luu:array[1..100]of string;
        xa,xb,ya,yb,dx,dy,res,i:longint;
procedure init;
begin
        assign(input,fi);       assign(output,fo);
        reset(input);           rewrite(output);
        readln(s1);             readln(s2);
        xa:=doi[s1[1]];         ya:=ord(s1[2])-48;
        xb:=doi[s2[1]];         yb:=ord(s2[2])-48;
        if xb>xa then
        begin
                truoc:='R';     dx:=1;
        end
        else
        begin
                truoc:='L';     dx:=-1;
        end;
        if yb>ya then
        begin
                sau:='U';       dy:=1;
        end
        else
        begin
                sau:='D';       dy:=-1;
        end;

        while(xa<>xb)and(ya<>yb)do
        begin
                inc(res);
                luu[res]:=truoc+sau;
                xa:=xa+dx;      ya:=ya+dy;
        end;
        if(xa<>xb)then
        begin
                writeln(res+abs(xa-xb));
                if xa>xb then truoc:='L'
                else          truoc:='R';
                for i:=1 to res do writeln(luu[i]);
                for i:=1 to abs(xa-xb) do writeln(truoc);
        end
        else
        begin
                writeln(res+abs(ya-yb));
                if ya>yb then sau:='D'
                else          sau:='U';
                for i:=1 to res do writeln(luu[i]);
                for i:=1 to abs(ya-yb) do writeln(sau);
        end;


end;
begin
        init;
end.
