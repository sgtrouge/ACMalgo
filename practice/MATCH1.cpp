Uses Math;
Const
        Fi='';
        Fo='';
Var
        N,m:longint;
        A:array[0..100,0..100]of boolean;
        M1,m2,trace,q:array[1..100]of longint;
//------------------------------INIT----------------------------------------
Procedure Init;
Var
        I,j:longint;
Begin
        Assign(input,fi);
        Assign(output,fo);
        Reset(input);
        Rewrite(output);
        Readln(m,n);
        While not eof do
        Begin
                Readln(i,j);
                A[i,j]:=true;
        End;
End;
//------------------------------FIND----------------------------------------
Function Find:longint;
Var
        I,u,v,front,rear:longint;
Begin
        Front:=1;       Rear:=0;
        Fillchar(trace,sizeof(trace),0);
        For i:=1 to m do
                If m1[i]=0 then
                Begin
                        Inc(rear);
                        Q[rear]:=i;
                End;
        While Front<=rear do
        Begin
                U:=Q[front];
                For v:=1 to n do
                If(trace[v]=0)and(a[u,v])then
                Begin
                        Trace[v]:=u;
                        If m2[v]=0 then Exit(v);
                        Inc(Rear);
                        Q[rear]:=m2[v];
                End;
                Inc(front);
        End;
        Exit(0);
End;
//------------------------------INCEDGE-------------------------------------
Procedure IncEdge(y:longint);
Var
        X,next:longint;
Begin
        Repeat
                X:=trace[y];
                Next:=m1[x];
                M1[x]:=y;
                M2[y]:=x;
                Y:=next;
        Until Y=0;
End;
//------------------------------SOLVE---------------------------------------
Procedure Solve;
Var
        Tmp,i,res:longint;
Begin
        Res:=0;
        While true do
        Begin
                Tmp:=find;
                If tmp=0 then Break;
                IncEdge(tmp);
        End;
        For i:=1 to m do
                If m1[i]<>0 then Inc(res);
        Writeln(res);
        For i:=1 to m do
                If m1[i]<>0 then Writeln(i,' ',m1[i]);
End;
//------------------------------MAIN----------------------------------------
Begin
        INIT;
        SOLVE;
End.