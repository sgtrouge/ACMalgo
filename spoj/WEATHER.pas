Uses Math;
Const
        Fi='';
        Fo='';
Type    Edge=record
        X,y:longint;
        End;
Var
        Res,res1,res2:int64;
        N,m,count:longint;
        A:array[1..10000]of edge;
        Free:array[1..100]of boolean;
        Dem,vt,dsc,low,number,p:array[1..10000]of Longint;
//---------------------------------INIT-----------------------------------
Procedure Init;
Var
        I,start:longint;
Begin
        Assign(input,fi);
        Assign(output,fo);
        Reset(input);
        Rewrite(output);
        Readln(n);
        Readln(m);
        For i:=1 to m do
        Begin
                Readln(A[i].x,A[i].y);
                Inc(Dem[A[i].x]);
                Inc(Dem[A[i].y]);
        End;
        Start:=1;
        For i:=1 to n+1 do
        Begin
                Vt[i]:=start;
                Start:=Start+Dem[i];
                Dem[i]:=Vt[i];
        End;
        For i:=1 to m do
        Begin
                Dsc[Dem[A[i].x]]:=A[i].y;
                Dsc[Dem[A[i].y]]:=A[i].x;
                Inc(Dem[A[i].x]);
                Inc(Dem[A[i].y]);
        End;
End;
//----------------------------------EXAMINE-------------------------------
Procedure DFS(u,so:longint);
Var
        I:longint;
Begin
        If Free[u]=true then
        Begin
                Free[u]:=false;
                If so=1 then Inc(Res1)
                Else    Inc(Res2);
        End;
        For i:=vt[u] to vt[u+1]-1 do
        Begin
                If Free[dsc[i]] then
                        DFS(dsc[i],so);
        End;
End;
//----------------------------------VISIT---------------------------------
Procedure Visit(u,cha:longint);
Var
        I:longint;
Begin
        Inc(Count);
        Free[u]:=false;
        Number[u]:=count;
        Low[u]:=n+1;
        For i:=vt[u] to vt[u+1]-1 do
        Begin
                If dsc[i]<>cha then
                Begin
                        If p[dsc[i]]=0 then
                        Begin
                                p[dsc[i]]:=u;
                                Visit(dsc[i],u);
                                Low[u]:=math.min(low[u],low[dsc[i]]);
                        End
                        Else
                                Low[u]:=math.min(low[u],number[dsc[i]]);
                End;
        End;
End;
//----------------------------------SOLVE---------------------------------
Procedure Solve;
Var
        U,v,kq,i:longint;
Begin
        Fillchar(free,sizeof(free),true);
        Count:=0;
        Kq:=0;
        For i:=1 to n do
                If p[i]=0 then
                Begin
                        P[i]:=-1;
                        Visit(i,-1);
                End;
        For v:=1 to n do
        Begin
                U:=p[v];
                If(U<>-1)and(low[v]>=number[v]) then
                Begin
                        Res1:=0;        Res2:=0;
                        Fillchar(Free,sizeof(Free),true);
                        Free[u]:=false;
                        DFS(v,1);
                        Fillchar(Free,sizeof(Free),true);
                        Free[v]:=false;
                        DFS(u,2);
                        Res:=Res1*Res2+Res;
                End;
        End;
        Writeln(Res);
End;
//----------------------------------MAIN----------------------------------
Begin
        INIT;
        SOLVE;
End.



