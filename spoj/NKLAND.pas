Uses Math;
Const
        Fi='';
        Fo='';
Type    Point=record
        X,y:int64;
        End;
Const
        MaxN=1000;
Var
        N,m:longint;
        A,b:array[0..MaxN+1]of Point;
//---------------------------------SOLVE-----------------------------------
Function Giao:boolean;
Var
        T:point;
        X,y:extended;
        I,j,sl:longint;
Begin
        Readln(n);
        For i:=n downto 1 do
                Read(A[i].x,A[i].y);
        Readln(m);
        For i:=m downto 1 do
                Read(B[i].x,B[i].y);
        A[0]:=A[n];
        For i:=1 to n do
        Begin
                Sl:=0;
                For j:=1 to m do
                Begin
                        T:=B[j];
                        x:=(a[i].x-t.x)*(t.y-a[i-1].y);
                        y:=(t.x-a[i-1].x)*(a[i].y-t.y);
                        If x-y>=0 then
                        Inc(sl);
                End;
                If Sl=m then
                Exit(False);
        End;
        Exit(True);
End;
//---------------------------------PROCESS---------------------------------
Procedure Process;
Var
        Test:longint;
Begin
        Assign(input,fi);
        Assign(output,fo);
        Reset(input);
        Rewrite(output);
        Readln(Test);
        While Test>0 do
        Begin
                If Giao then
                        Writeln('YES')
                Else
                        Writeln('NO');
                Dec(Test);
        End;
End;
//---------------------------------MAIN------------------------------------
Begin
        PROCESS;
End.

