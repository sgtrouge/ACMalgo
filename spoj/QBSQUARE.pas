Uses Math;
Const
        Fi='';
        Fo='';
Type    Spec=record
        L,r,max,mau:longint;
        End;
Var
        N,m:longint;
        U,v,com:longint;
        Tree:array[1..160000]of Spec;
//------------------------------------TREE----------------------------------
Procedure Insert(k,l,r,mau:longint);
Var
        Mid:longint;
Begin
        If l>r then Exit;
        If(u>r)or(v<l)then Exit;
        Mid:=(l+r)div 2;
        If(l>=u)and(r<=v)then
        Begin
                Tree[k].mau:=3;
                Tree[2*k+1].mau:=com;
                Tree[2*k].mau:=com;
                If com=1 then
                Begin
                        Tree[2*k].l:=mid-l+1;
                        Tree[2*k].r:=mid-l+1;
                        Tree[2*k].max:=mid-l+1;
                        Tree[2*k+1].l:=r-mid;
                        Tree[2*k+1].r:=r-mid;
                        Tree[2*k+1].max:=r-mid;
                        Tree[k].l:=r-l+1;
                        Tree[k].r:=r-l+1;
                        Tree[k].max:=r-l+1;
                End
                Else
                Begin
                        Tree[2*k].l:=0;
                        Tree[2*k].r:=0;
                        Tree[2*k].max:=0;
                        Tree[2*k+1]:=Tree[2*k];
                        Tree[k].l:=0;
                        Tree[k].r:=0;
                        Tree[k].max:=0;
                End;
                Exit;
        End
        Else
        If(mau<>0)or(tree[k].mau<>3) then
        Begin
                If Mau=0 then
                Mau:=Tree[k].mau;
                Tree[k].mau:=3;
                Tree[2*k+1].mau:=mau;
                Tree[2*k].mau:=mau;
                If mau=1 then
                Begin
                        Tree[2*k].l:=mid-l+1;
                        Tree[2*k].r:=mid-l+1;
                        Tree[2*k].max:=mid-l+1;
                        Tree[2*k+1].l:=r-mid;
                        Tree[2*k+1].r:=r-mid;
                        Tree[2*k+1].max:=r-mid;
                        Tree[k].l:=r-l+1;
                        Tree[k].r:=r-l+1;
                        Tree[k].max:=r-l+1;
                End
                Else
                Begin
                        Tree[2*k].l:=0;
                        Tree[2*k].r:=0;
                        Tree[2*k].max:=0;
                        Tree[2*k+1]:=Tree[2*k];
                        Tree[k].max:=0;
                        Tree[k].l:=0;
                        Tree[k].r:=0;
                End;
        End;

        Insert(2*k,l,mid,mau);
        Insert(2*k+1,mid+1,r,mau);

        Tree[k].l:=tree[2*k].l;
        If Tree[k].l=mid-l+1 then
        If tree[2*k].l=tree[2*k].max then
                Tree[k].l:=tree[2*k].l+tree[2*k+1].l;

        Tree[k].r:=tree[2*k+1].r;
        If tree[k].r=r-mid then
        If tree[2*k+1].r=tree[2*k+1].max then
                Tree[k].r:=tree[2*k+1].r+tree[2*k].r;
        Tree[k].max:=Tree[2*k].r+Tree[2*k+1].l;

        Tree[k].max:=Math.max(tree[k].max,tree[2*k].max);
        Tree[k].max:=Math.max(tree[k].max,tree[2*k+1].max);
End;
//------------------------------------INIT----------------------------------
Procedure Process;
Var
        I:longint;
Begin

        Assign(input,fi);
        Assign(output,fo);
        Reset(input);
        Rewrite(output);
        Readln(n);        Readln(m);
        Tree[1].l:=n;     Tree[1].r:=n;
        Tree[1].max:=n;   Tree[1].mau:=1;
        For i:=1 to m do
        Begin
                Read(com);
                If com<>3 then
                Begin
                        Readln(u,v);
                        Insert(1,1,n,0);
                End
                Else
                        Writeln(Tree[1].max);
        End;
End;
Procedure Init;
Var
        I:longint;
Begin
        For i:=1 to 160000 do Tree[i].mau:=3;
End;
//------------------------------------MAIN----------------------------------
Begin
        INIT;
        PROCESS;
End.


