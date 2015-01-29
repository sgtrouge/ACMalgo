Uses Math;
Const
        MaxC=30001;
        Fi='';
        Fo='';
Type    Spec=record
        Gt,vt:longint;
        End;
        Spec2=record
        I,j,tt:longint;
        End;
Var
        N,Query:longint;
        F:array[1..200000]of Longint;
        Check:array[0..30001]of Longint;
        Tree:array[1..30001]of Longint;
        A:array[1..30000]of Longint;
        B:array[0..30000]of Spec;
        Q:array[1..200000]of Spec2;
//-----------------------------------TREE-----------------------------------
Function Find(u:longint):longint;
Begin
        If u<1 then
                Exit(0);
        Find:=tree[u]+find(u-u and (-u));
End;

Procedure Update(u:longint);
Begin
        If u>maxC then exit;
        Tree[u]:=(tree[u]+1);
        Update(u+u and(-u));
End;
//-----------------------------------INIT-----------------------------------
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
                Read(A[i]);
                B[i].gt:=A[i];
                B[i].vt:=i;
        End;
        Readln(Query);
        For i:=1 to Query do
        Begin
                Readln(Q[i].i,Q[i].j);
                Q[i].tt:=i;
        End;
End;
//-----------------------------------SORT1----------------------------------
Procedure Sort1(l,r:longint);
Var
        I,j:longint;
        Pv,Tmp:Spec;
Begin
        If l>=r then Exit;
        I:=l;
        J:=r;
        Pv:=B[(l+r)div 2];
        Repeat
                While(B[i].gt<Pv.gt)or((B[i].gt=Pv.gt)and(B[i].vt<Pv.vt))do Inc(i);
                While(B[j].gt>Pv.gt)or((B[j].gt=Pv.gt)and(B[j].vt>Pv.vt))do Dec(j);
                If I<=j then
                Begin
                        Tmp:=B[i];
                        B[i]:=B[j];
                        B[j]:=Tmp;
                        Inc(i);
                        Dec(j);
                End;
        Until I>=j;
        Sort1(l,j);
        Sort1(i,r);
End;
//-----------------------------------SORT2----------------------------------
Procedure Sort2(l,r:longint);
Var
        I,j,Pv:longint;
        Tmp:Spec2;
Begin
        If l>=r then Exit;
        I:=l;
        J:=r;
        Pv:=Q[(l+r)div 2].j;
        Repeat
                While Q[i].j<Pv do Inc(i);
                While Q[j].j>Pv do Dec(j);
                If I<=j then
                Begin
                        Tmp:=Q[i];
                        Q[i]:=Q[j];
                        Q[j]:=Tmp;
                        Inc(i);
                        Dec(j);
                End;
        Until I>=j;
        Sort2(l,j);
        Sort2(i,r);
End;
//-----------------------------------INIT2----------------------------------
Procedure INIT2;
Var
        I:longint;
Begin
        B[0].gt:=0;
        For I:=1 to n do
        Begin
                If B[i].gt=B[i-1].gt then
                Check[B[i].vt]:=B[i-1].vt
                Else
                Check[B[i].vt]:=0;
        End;
End;
//-----------------------------------SOLVE----------------------------------
Procedure Solve;
Var
        I,j:longint;
Begin
        J:=1;
        For i:=1 to n do
        Begin
                Update(MaxC-Check[i]);
                While Q[j].j=i do
                Begin
                        F[Q[j].tt]:=Q[j].j-Q[j].i+1-Find(MaxC-Q[j].i);
                        Inc(j);
                End;
        End;
        For i:=1 to Query do
        Writeln(F[i]);
End;
//-----------------------------------MAIN-----------------------------------
Begin
        INIT;
        SORT1(1,N);
        SORT2(1,QUERY);
        INIT2;
        SOLVE;
End.

