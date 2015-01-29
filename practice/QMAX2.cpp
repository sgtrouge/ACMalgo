Uses Math;
Const
        Fi='';
        Fo='';
Type    Spec=record
        Max,tang:longint;
        End;
Var
        U,v,t,max,n,m:longint;
        Tree:array[1..200000]of spec;
//------------------------------------UPDATE---------------------------------
Procedure Update(k,l,r:longint);
Var
        Mid:longint;
Begin
        If l>r then Exit;
        If(v<l)or(u>r) then Exit;
        If(l>=u)and(r<=v) then
        Begin
                Tree[k].max:=Tree[k].max+t;
                Tree[k].tang:=Tree[k].tang+t;
        End
        Else
        Begin
                Mid:=(l+r)div 2;
                Update(2*k,l,mid);
                Update(2*k+1,mid+1,r);
                Tree[k].max:=math.max(Tree[2*k].max+Tree[k].tang,Tree[2*k+1].max+Tree[k].tang);
        End;
End;

//------------------------------------GET------------------------------------
Procedure Get(k,l,r,them:longint);
Var
        Mid:longint;
Begin
        If l>r then Exit;
        If(v<l)or(u>r)then Exit;
        If(u<=l)and(r<=v) then
        Begin
                Max:=Math.max(Max,Tree[k].max+them);
                Exit;
        End;
        Mid:=(l+r)div 2;
        Get(2*k,l,mid,them+Tree[k].tang);
        Get(2*k+1,mid+1,r,them+Tree[k].tang);

End;
//------------------------------------SOLVE----------------------------------
Procedure Solve;
Var
        I,c:longint;
Begin
        Assign(input,fi);
        Assign(output,fo);
        Reset(input);
        Rewrite(output);
        Readln(n,m);
        For i:=1 to m do
        Begin
                Read(c);
                If c=0 then
                Begin
                        Readln(u,v,t);
                        Update(1,1,n);
                End
                Else
                Begin
                        Readln(u,v);
                        Max:=0;
                        Get(1,1,n,0);
                        Writeln(Max);
                End;
        End;
End;

//------------------------------------MAIN-----------------------------------
Begin
        SOLVE;
End.


