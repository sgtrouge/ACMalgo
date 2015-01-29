Uses Math;
Const
        Fi='';
        Fo='';
Var
        N,res:longint;
        Up,down:array[0..10001]of char;
//-------------------------------INIT--------------------------------------
Procedure Init;
Var
        I:longint;
Begin
        Assign(input,fi);
        Assign(output,fo);
        Reset(input);
        Rewrite(output);
        Readln(n);
        For i:=1 to n do
        Begin
                If eoln then readln;
                Read(up[i]);
        End;
        Readln;
        For i:=1 to n do
        Begin
                If eoln then readln;
                Read(down[i]);
        End;
End;
//-------------------------------SOLVE-------------------------------------
Procedure Solve;
Var
        I:longint;
Begin
        Up[0]:='0';     Down[0]:='0';
        Up[n+1]:='0';   Down[n+1]:='0';
        For i:=1 to n do
                If(up[i]='1')then
                Begin
                        If(i=1)or(up[i-1]='0')then
                        Inc(res);
                End;
        For i:=1 to n do
                If(down[i]='1')then
                Begin
                        If(i=1)or(down[i-1]='0')then
                        Inc(res);
                End;
        For i:=1 to n do
        Begin
                If(up[i]<>up[i-1])and(up[i]<>up[i+1])
                and(down[i]<>down[i-1])and(down[i]<>down[i+1])then
                Begin
                        Dec(res);
                        If up[i]='0' then up[i]:='1'
                        Else    up[i]:='0';
                        If down[i]='0' then down[i]:='1'
                        Else    down[i]:='0';
                End;
        End;
        Writeln(res);
End;
//-------------------------------MAIN--------------------------------------
Begin
        INIT;
        SOLVE;
End.


